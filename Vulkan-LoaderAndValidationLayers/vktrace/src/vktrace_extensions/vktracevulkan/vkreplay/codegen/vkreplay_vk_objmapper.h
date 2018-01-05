/* THIS FILE IS GENERATED.  DO NOT EDIT. */

/*
 *
 * Copyright (C) 2015 Valve Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Author: Jon Ashburn <jon@lunarg.com>
 * Author: Tobin Ehlis <tobin@lunarg.com>
 * Author: Peter Lohrmann <peterl@valvesoftware.com>
 */

#pragma once

#include <set>
#include <map>
#include <vector>
#include <string>
#include "vulkan/vulkan.h"
#include "vulkan/vk_ext_debug_report.h"
#include "vulkan/vk_lunarg_debug_marker.h"

#define VKTRACE_VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN (VkObjectType)-1

typedef struct _VKAllocInfo {
    VkDeviceSize size;
    uint8_t *pData;
    bool rangeUpdated;
} VKAllocInfo;

class objMemory {
public:
    objMemory() : m_numAllocations(0), m_pMemReqs(NULL) {}
    ~objMemory() { free(m_pMemReqs);}
    void setCount(const uint32_t num)
    {
        m_numAllocations = num;
    }

    void setReqs(const VkMemoryRequirements *pReqs, const uint32_t num)
    {
        if (m_numAllocations != num && m_numAllocations != 0)
            vktrace_LogError("objMemory::setReqs, internal mismatch on number of allocations.");
        if (m_pMemReqs == NULL && pReqs != NULL)
        {
            m_pMemReqs = (VkMemoryRequirements *) vktrace_malloc(num * sizeof(VkMemoryRequirements));
            if (m_pMemReqs == NULL)
            {
                vktrace_LogError("objMemory::setReqs out of memory.");
                return;
            }
            memcpy(m_pMemReqs, pReqs, num * sizeof(VkMemoryRequirements));
        }
    }

private:
    uint32_t m_numAllocations;
    VkMemoryRequirements *m_pMemReqs;
};

class gpuMemory {
public:
    gpuMemory() : m_pendingAlloc(false) {m_allocInfo.allocationSize = 0;}
    ~gpuMemory() {}
// memory mapping functions for app writes into mapped memory
    bool isPendingAlloc()
    {
        return m_pendingAlloc;
    }

    void setAllocInfo(const VkMemoryAllocateInfo *info, const bool pending)
    {
        m_pendingAlloc = pending;
        m_allocInfo = *info;
    }

    void setMemoryDataAddr(void *pBuf)
    {
        if (m_mapRange.empty())
        {
            vktrace_LogError("gpuMemory::setMemoryDataAddr() m_mapRange is empty.");
            return;
        }
        MapRange mr = m_mapRange.back();
        if (mr.pData != NULL)
            vktrace_LogWarning("gpuMemory::setMemoryDataAddr() data already mapped overwrite old mapping.");
        else if (pBuf == NULL)
            vktrace_LogWarning("gpuMemory::setMemoryDataAddr() adding NULL pointer.");
        mr.pData = (uint8_t *) pBuf;
    }

    void setMemoryMapRange(void *pBuf, const size_t size, const size_t offset, const bool pending)
    {
        MapRange mr;
        mr.pData = (uint8_t *) pBuf;
        if (size == 0)
            mr.size = (size_t)m_allocInfo.allocationSize - offset;
        else
            mr.size = size;
        mr.offset = offset;
        mr.pending = pending;
        m_mapRange.push_back(mr);
        assert((size_t)m_allocInfo.allocationSize >= (size + offset));
    }

    void copyMappingData(const void* pSrcData, bool entire_map, size_t size, size_t offset)
    {
        if (m_mapRange.empty())
        {
            vktrace_LogError("gpuMemory::copyMappingData() m_mapRange is empty.");
            return;
        }
        MapRange mr = m_mapRange.back();
        if (!pSrcData || !mr.pData)
        {
            if (!pSrcData)
                vktrace_LogError("gpuMemory::copyMappingData() null src pointer.");
            else
                vktrace_LogError("gpuMemory::copyMappingData() null dest pointer totalSize=%u.", m_allocInfo.allocationSize);
            m_mapRange.pop_back();
            return;
        }
        if (entire_map)
        {
            size = mr.size;
            offset = mr.offset;
        }
        else
        {
            assert(offset >= mr.offset);
            assert(size <= mr.size && (size + offset) <= mr.size);
        }
        memcpy(mr.pData + offset, pSrcData, size);
        if (!mr.pending && entire_map)
            m_mapRange.pop_back();
    }

    size_t getMemoryMapSize()
    {
        return (!m_mapRange.empty()) ? m_mapRange.back().size : 0;
    }

private:
    bool m_pendingAlloc;
    struct MapRange {
        bool pending;
        size_t size;
        size_t offset;
        uint8_t* pData;
    };
    std::vector<MapRange> m_mapRange;
    VkMemoryAllocateInfo m_allocInfo;
};

typedef struct _imageObj {
     objMemory imageMem;
     VkImage replayImage;
 } imageObj;

typedef struct _bufferObj {
     objMemory bufferMem;
     VkBuffer replayBuffer;
 } bufferObj;

typedef struct _gpuMemObj {
     gpuMemory *pGpuMem;
     VkDeviceMemory replayGpuMem;
 } gpuMemObj;


class vkReplayObjMapper {
public:
    vkReplayObjMapper() {}
    ~vkReplayObjMapper() {}

 bool m_adjustForGPU; // true if replay adjusts behavior based on GPU
void init_objMemCount(const uint64_t handle, const VkDebugReportObjectTypeEXT objectType, const uint32_t &num)
 {
    switch (objectType) {
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
        {
            std::map<VkBuffer, bufferObj>::iterator it = m_buffers.find((VkBuffer) handle);
            if (it != m_buffers.end()) {
                objMemory obj = it->second.bufferMem;
                obj.setCount(num);
                return;
            }
            break;
        }
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
        {
            std::map<VkImage, imageObj>::iterator it = m_images.find((VkImage) handle);
            if (it != m_images.end()) {
                objMemory obj = it->second.imageMem;
                obj.setCount(num);
                return;
            }
            break;
        }
        default:
            break;
    }
    return;
}

void init_objMemReqs(const uint64_t handle, const VkDebugReportObjectTypeEXT objectType, const VkMemoryRequirements *pMemReqs, const unsigned int num)
    {
    switch (objectType) {
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
        {
            std::map<VkBuffer, bufferObj>::iterator it = m_buffers.find((VkBuffer) handle);
            if (it != m_buffers.end()) {
                objMemory obj = it->second.bufferMem;
                obj.setReqs(pMemReqs, num);
                return;
            }
            break;
        }
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
        {
            std::map<VkImage, imageObj>::iterator it = m_images.find((VkImage) handle);
            if (it != m_images.end()) {
                objMemory obj = it->second.imageMem;
                obj.setReqs(pMemReqs, num);
                return;
            }
            break;
        }
        default:
            break;
    }
    return;
    }

    void clear_all_map_handles()
    {
        m_buffers.clear();
        m_bufferviews.clear();
        m_commandbuffers.clear();
        m_commandpools.clear();
        m_debugreportcallbackexts.clear();
        m_descriptorpools.clear();
        m_descriptorsetlayouts.clear();
        m_descriptorsets.clear();
        m_devicememorys.clear();
        m_devices.clear();
        m_events.clear();
        m_fences.clear();
        m_framebuffers.clear();
        m_images.clear();
        m_imageviews.clear();
        m_instances.clear();
        m_physicaldevices.clear();
        m_pipelinecaches.clear();
        m_pipelinelayouts.clear();
        m_pipelines.clear();
        m_querypools.clear();
        m_queues.clear();
        m_renderpasss.clear();
        m_samplers.clear();
        m_semaphores.clear();
        m_shadermodules.clear();
        m_surfacekhrs.clear();
        m_swapchainkhrs.clear();
    }

    std::map<VkBuffer, bufferObj> m_buffers;
    void add_to_buffers_map(VkBuffer pTraceVal, bufferObj pReplayVal)
    {
        m_buffers[pTraceVal] = pReplayVal;
    }

    void rm_from_buffers_map(const VkBuffer& key)
    {
        m_buffers.erase(key);
    }

    VkBuffer remap_buffers(const VkBuffer& value)
    {
        if (value == 0) { return 0; }

        std::map<VkBuffer, bufferObj>::const_iterator q = m_buffers.find(value);
        if (q == m_buffers.end()) { vktrace_LogError("Failed to remap VkBuffer."); return value; }

        return q->second.replayBuffer;
    }

    std::map<VkBufferView, VkBufferView> m_bufferviews;
    void add_to_bufferviews_map(VkBufferView pTraceVal, VkBufferView pReplayVal)
    {
        m_bufferviews[pTraceVal] = pReplayVal;
    }

    void rm_from_bufferviews_map(const VkBufferView& key)
    {
        m_bufferviews.erase(key);
    }

    VkBufferView remap_bufferviews(const VkBufferView& value)
    {
        if (value == 0) { return 0; }
        std::map<VkBufferView, VkBufferView>::const_iterator q = m_bufferviews.find(value);
        if (q == m_bufferviews.end()) { vktrace_LogError("Failed to remap VkBufferView."); return value; }
        return q->second;
    }

    std::map<VkCommandBuffer, VkCommandBuffer> m_commandbuffers;
    void add_to_commandbuffers_map(VkCommandBuffer pTraceVal, VkCommandBuffer pReplayVal)
    {
        m_commandbuffers[pTraceVal] = pReplayVal;
    }

    void rm_from_commandbuffers_map(const VkCommandBuffer& key)
    {
        m_commandbuffers.erase(key);
    }

    VkCommandBuffer remap_commandbuffers(const VkCommandBuffer& value)
    {
        if (value == 0) { return 0; }
        std::map<VkCommandBuffer, VkCommandBuffer>::const_iterator q = m_commandbuffers.find(value);
        if (q == m_commandbuffers.end()) { vktrace_LogError("Failed to remap VkCommandBuffer."); return value; }
        return q->second;
    }

    std::map<VkCommandPool, VkCommandPool> m_commandpools;
    void add_to_commandpools_map(VkCommandPool pTraceVal, VkCommandPool pReplayVal)
    {
        m_commandpools[pTraceVal] = pReplayVal;
    }

    void rm_from_commandpools_map(const VkCommandPool& key)
    {
        m_commandpools.erase(key);
    }

    VkCommandPool remap_commandpools(const VkCommandPool& value)
    {
        if (value == 0) { return 0; }
        std::map<VkCommandPool, VkCommandPool>::const_iterator q = m_commandpools.find(value);
        if (q == m_commandpools.end()) { vktrace_LogError("Failed to remap VkCommandPool."); return value; }
        return q->second;
    }

    std::map<VkDebugReportCallbackEXT, VkDebugReportCallbackEXT> m_debugreportcallbackexts;
    void add_to_debugreportcallbackexts_map(VkDebugReportCallbackEXT pTraceVal, VkDebugReportCallbackEXT pReplayVal)
    {
        m_debugreportcallbackexts[pTraceVal] = pReplayVal;
    }

    void rm_from_debugreportcallbackexts_map(const VkDebugReportCallbackEXT& key)
    {
        m_debugreportcallbackexts.erase(key);
    }

    VkDebugReportCallbackEXT remap_debugreportcallbackexts(const VkDebugReportCallbackEXT& value)
    {
        if (value == 0) { return 0; }
        std::map<VkDebugReportCallbackEXT, VkDebugReportCallbackEXT>::const_iterator q = m_debugreportcallbackexts.find(value);
        if (q == m_debugreportcallbackexts.end()) { vktrace_LogError("Failed to remap VkDebugReportCallbackEXT."); return value; }
        return q->second;
    }

    std::map<VkDescriptorPool, VkDescriptorPool> m_descriptorpools;
    void add_to_descriptorpools_map(VkDescriptorPool pTraceVal, VkDescriptorPool pReplayVal)
    {
        m_descriptorpools[pTraceVal] = pReplayVal;
    }

    void rm_from_descriptorpools_map(const VkDescriptorPool& key)
    {
        m_descriptorpools.erase(key);
    }

    VkDescriptorPool remap_descriptorpools(const VkDescriptorPool& value)
    {
        if (value == 0) { return 0; }
        std::map<VkDescriptorPool, VkDescriptorPool>::const_iterator q = m_descriptorpools.find(value);
        if (q == m_descriptorpools.end()) { vktrace_LogError("Failed to remap VkDescriptorPool."); return value; }
        return q->second;
    }

    std::map<VkDescriptorSetLayout, VkDescriptorSetLayout> m_descriptorsetlayouts;
    void add_to_descriptorsetlayouts_map(VkDescriptorSetLayout pTraceVal, VkDescriptorSetLayout pReplayVal)
    {
        m_descriptorsetlayouts[pTraceVal] = pReplayVal;
    }

    void rm_from_descriptorsetlayouts_map(const VkDescriptorSetLayout& key)
    {
        m_descriptorsetlayouts.erase(key);
    }

    VkDescriptorSetLayout remap_descriptorsetlayouts(const VkDescriptorSetLayout& value)
    {
        if (value == 0) { return 0; }
        std::map<VkDescriptorSetLayout, VkDescriptorSetLayout>::const_iterator q = m_descriptorsetlayouts.find(value);
        if (q == m_descriptorsetlayouts.end()) { vktrace_LogError("Failed to remap VkDescriptorSetLayout."); return value; }
        return q->second;
    }

    std::map<VkDescriptorSet, VkDescriptorSet> m_descriptorsets;
    void add_to_descriptorsets_map(VkDescriptorSet pTraceVal, VkDescriptorSet pReplayVal)
    {
        m_descriptorsets[pTraceVal] = pReplayVal;
    }

    void rm_from_descriptorsets_map(const VkDescriptorSet& key)
    {
        m_descriptorsets.erase(key);
    }

    VkDescriptorSet remap_descriptorsets(const VkDescriptorSet& value)
    {
        if (value == 0) { return 0; }
        std::map<VkDescriptorSet, VkDescriptorSet>::const_iterator q = m_descriptorsets.find(value);
        if (q == m_descriptorsets.end()) { vktrace_LogError("Failed to remap VkDescriptorSet."); return value; }
        return q->second;
    }

    std::map<VkDeviceMemory, gpuMemObj> m_devicememorys;
    void add_to_devicememorys_map(VkDeviceMemory pTraceVal, gpuMemObj pReplayVal)
    {
        m_devicememorys[pTraceVal] = pReplayVal;
    }

    void rm_from_devicememorys_map(const VkDeviceMemory& key)
    {
        m_devicememorys.erase(key);
    }

    VkDeviceMemory remap_devicememorys(const VkDeviceMemory& value)
    {
        if (value == 0) { return 0; }

        std::map<VkDeviceMemory, gpuMemObj>::const_iterator q = m_devicememorys.find(value);
        if (q == m_devicememorys.end()) { vktrace_LogError("Failed to remap VkDeviceMemory."); return value; }
        return q->second.replayGpuMem;
    }

    std::map<VkDevice, VkDevice> m_devices;
    void add_to_devices_map(VkDevice pTraceVal, VkDevice pReplayVal)
    {
        m_devices[pTraceVal] = pReplayVal;
    }

    void rm_from_devices_map(const VkDevice& key)
    {
        m_devices.erase(key);
    }

    VkDevice remap_devices(const VkDevice& value)
    {
        if (value == 0) { return 0; }
        std::map<VkDevice, VkDevice>::const_iterator q = m_devices.find(value);
        if (q == m_devices.end()) { vktrace_LogError("Failed to remap VkDevice."); return value; }
        return q->second;
    }

    std::map<VkEvent, VkEvent> m_events;
    void add_to_events_map(VkEvent pTraceVal, VkEvent pReplayVal)
    {
        m_events[pTraceVal] = pReplayVal;
    }

    void rm_from_events_map(const VkEvent& key)
    {
        m_events.erase(key);
    }

    VkEvent remap_events(const VkEvent& value)
    {
        if (value == 0) { return 0; }
        std::map<VkEvent, VkEvent>::const_iterator q = m_events.find(value);
        if (q == m_events.end()) { vktrace_LogError("Failed to remap VkEvent."); return value; }
        return q->second;
    }

    std::map<VkFence, VkFence> m_fences;
    void add_to_fences_map(VkFence pTraceVal, VkFence pReplayVal)
    {
        m_fences[pTraceVal] = pReplayVal;
    }

    void rm_from_fences_map(const VkFence& key)
    {
        m_fences.erase(key);
    }

    VkFence remap_fences(const VkFence& value)
    {
        if (value == 0) { return 0; }
        std::map<VkFence, VkFence>::const_iterator q = m_fences.find(value);
        if (q == m_fences.end()) { vktrace_LogError("Failed to remap VkFence."); return value; }
        return q->second;
    }

    std::map<VkFramebuffer, VkFramebuffer> m_framebuffers;
    void add_to_framebuffers_map(VkFramebuffer pTraceVal, VkFramebuffer pReplayVal)
    {
        m_framebuffers[pTraceVal] = pReplayVal;
    }

    void rm_from_framebuffers_map(const VkFramebuffer& key)
    {
        m_framebuffers.erase(key);
    }

    VkFramebuffer remap_framebuffers(const VkFramebuffer& value)
    {
        if (value == 0) { return 0; }
        std::map<VkFramebuffer, VkFramebuffer>::const_iterator q = m_framebuffers.find(value);
        if (q == m_framebuffers.end()) { vktrace_LogError("Failed to remap VkFramebuffer."); return value; }
        return q->second;
    }

    std::map<VkImage, imageObj> m_images;
    void add_to_images_map(VkImage pTraceVal, imageObj pReplayVal)
    {
        m_images[pTraceVal] = pReplayVal;
    }

    void rm_from_images_map(const VkImage& key)
    {
        m_images.erase(key);
    }

    VkImage remap_images(const VkImage& value)
    {
        if (value == 0) { return 0; }

        std::map<VkImage, imageObj>::const_iterator q = m_images.find(value);
        if (q == m_images.end()) { vktrace_LogError("Failed to remap VkImage."); return value; }

        return q->second.replayImage;
    }

    std::map<VkImageView, VkImageView> m_imageviews;
    void add_to_imageviews_map(VkImageView pTraceVal, VkImageView pReplayVal)
    {
        m_imageviews[pTraceVal] = pReplayVal;
    }

    void rm_from_imageviews_map(const VkImageView& key)
    {
        m_imageviews.erase(key);
    }

    VkImageView remap_imageviews(const VkImageView& value)
    {
        if (value == 0) { return 0; }
        std::map<VkImageView, VkImageView>::const_iterator q = m_imageviews.find(value);
        if (q == m_imageviews.end()) { vktrace_LogError("Failed to remap VkImageView."); return value; }
        return q->second;
    }

    std::map<VkInstance, VkInstance> m_instances;
    void add_to_instances_map(VkInstance pTraceVal, VkInstance pReplayVal)
    {
        m_instances[pTraceVal] = pReplayVal;
    }

    void rm_from_instances_map(const VkInstance& key)
    {
        m_instances.erase(key);
    }

    VkInstance remap_instances(const VkInstance& value)
    {
        if (value == 0) { return 0; }
        std::map<VkInstance, VkInstance>::const_iterator q = m_instances.find(value);
        if (q == m_instances.end()) { vktrace_LogError("Failed to remap VkInstance."); return value; }
        return q->second;
    }

    std::map<VkPhysicalDevice, VkPhysicalDevice> m_physicaldevices;
    void add_to_physicaldevices_map(VkPhysicalDevice pTraceVal, VkPhysicalDevice pReplayVal)
    {
        m_physicaldevices[pTraceVal] = pReplayVal;
    }

    void rm_from_physicaldevices_map(const VkPhysicalDevice& key)
    {
        m_physicaldevices.erase(key);
    }

    VkPhysicalDevice remap_physicaldevices(const VkPhysicalDevice& value)
    {
        if (value == 0) { return 0; }
        std::map<VkPhysicalDevice, VkPhysicalDevice>::const_iterator q = m_physicaldevices.find(value);
        if (q == m_physicaldevices.end()) { vktrace_LogError("Failed to remap VkPhysicalDevice."); return value; }
        return q->second;
    }

    std::map<VkPipelineCache, VkPipelineCache> m_pipelinecaches;
    void add_to_pipelinecaches_map(VkPipelineCache pTraceVal, VkPipelineCache pReplayVal)
    {
        m_pipelinecaches[pTraceVal] = pReplayVal;
    }

    void rm_from_pipelinecaches_map(const VkPipelineCache& key)
    {
        m_pipelinecaches.erase(key);
    }

    VkPipelineCache remap_pipelinecaches(const VkPipelineCache& value)
    {
        if (value == 0) { return 0; }
        std::map<VkPipelineCache, VkPipelineCache>::const_iterator q = m_pipelinecaches.find(value);
        if (q == m_pipelinecaches.end()) { vktrace_LogError("Failed to remap VkPipelineCache."); return value; }
        return q->second;
    }

    std::map<VkPipelineLayout, VkPipelineLayout> m_pipelinelayouts;
    void add_to_pipelinelayouts_map(VkPipelineLayout pTraceVal, VkPipelineLayout pReplayVal)
    {
        m_pipelinelayouts[pTraceVal] = pReplayVal;
    }

    void rm_from_pipelinelayouts_map(const VkPipelineLayout& key)
    {
        m_pipelinelayouts.erase(key);
    }

    VkPipelineLayout remap_pipelinelayouts(const VkPipelineLayout& value)
    {
        if (value == 0) { return 0; }
        std::map<VkPipelineLayout, VkPipelineLayout>::const_iterator q = m_pipelinelayouts.find(value);
        if (q == m_pipelinelayouts.end()) { vktrace_LogError("Failed to remap VkPipelineLayout."); return value; }
        return q->second;
    }

    std::map<VkPipeline, VkPipeline> m_pipelines;
    void add_to_pipelines_map(VkPipeline pTraceVal, VkPipeline pReplayVal)
    {
        m_pipelines[pTraceVal] = pReplayVal;
    }

    void rm_from_pipelines_map(const VkPipeline& key)
    {
        m_pipelines.erase(key);
    }

    VkPipeline remap_pipelines(const VkPipeline& value)
    {
        if (value == 0) { return 0; }
        std::map<VkPipeline, VkPipeline>::const_iterator q = m_pipelines.find(value);
        if (q == m_pipelines.end()) { vktrace_LogError("Failed to remap VkPipeline."); return value; }
        return q->second;
    }

    std::map<VkQueryPool, VkQueryPool> m_querypools;
    void add_to_querypools_map(VkQueryPool pTraceVal, VkQueryPool pReplayVal)
    {
        m_querypools[pTraceVal] = pReplayVal;
    }

    void rm_from_querypools_map(const VkQueryPool& key)
    {
        m_querypools.erase(key);
    }

    VkQueryPool remap_querypools(const VkQueryPool& value)
    {
        if (value == 0) { return 0; }
        std::map<VkQueryPool, VkQueryPool>::const_iterator q = m_querypools.find(value);
        if (q == m_querypools.end()) { vktrace_LogError("Failed to remap VkQueryPool."); return value; }
        return q->second;
    }

    std::map<VkQueue, VkQueue> m_queues;
    void add_to_queues_map(VkQueue pTraceVal, VkQueue pReplayVal)
    {
        m_queues[pTraceVal] = pReplayVal;
    }

    void rm_from_queues_map(const VkQueue& key)
    {
        m_queues.erase(key);
    }

    VkQueue remap_queues(const VkQueue& value)
    {
        if (value == 0) { return 0; }
        std::map<VkQueue, VkQueue>::const_iterator q = m_queues.find(value);
        if (q == m_queues.end()) { vktrace_LogError("Failed to remap VkQueue."); return value; }
        return q->second;
    }

    std::map<VkRenderPass, VkRenderPass> m_renderpasss;
    void add_to_renderpasss_map(VkRenderPass pTraceVal, VkRenderPass pReplayVal)
    {
        m_renderpasss[pTraceVal] = pReplayVal;
    }

    void rm_from_renderpasss_map(const VkRenderPass& key)
    {
        m_renderpasss.erase(key);
    }

    VkRenderPass remap_renderpasss(const VkRenderPass& value)
    {
        if (value == 0) { return 0; }
        std::map<VkRenderPass, VkRenderPass>::const_iterator q = m_renderpasss.find(value);
        if (q == m_renderpasss.end()) { vktrace_LogError("Failed to remap VkRenderPass."); return value; }
        return q->second;
    }

    std::map<VkSampler, VkSampler> m_samplers;
    void add_to_samplers_map(VkSampler pTraceVal, VkSampler pReplayVal)
    {
        m_samplers[pTraceVal] = pReplayVal;
    }

    void rm_from_samplers_map(const VkSampler& key)
    {
        m_samplers.erase(key);
    }

    VkSampler remap_samplers(const VkSampler& value)
    {
        if (value == 0) { return 0; }
        std::map<VkSampler, VkSampler>::const_iterator q = m_samplers.find(value);
        if (q == m_samplers.end()) { vktrace_LogError("Failed to remap VkSampler."); return value; }
        return q->second;
    }

    std::map<VkSemaphore, VkSemaphore> m_semaphores;
    void add_to_semaphores_map(VkSemaphore pTraceVal, VkSemaphore pReplayVal)
    {
        m_semaphores[pTraceVal] = pReplayVal;
    }

    void rm_from_semaphores_map(const VkSemaphore& key)
    {
        m_semaphores.erase(key);
    }

    VkSemaphore remap_semaphores(const VkSemaphore& value)
    {
        if (value == 0) { return 0; }
        std::map<VkSemaphore, VkSemaphore>::const_iterator q = m_semaphores.find(value);
        if (q == m_semaphores.end()) { vktrace_LogError("Failed to remap VkSemaphore."); return value; }
        return q->second;
    }

    std::map<VkShaderModule, VkShaderModule> m_shadermodules;
    void add_to_shadermodules_map(VkShaderModule pTraceVal, VkShaderModule pReplayVal)
    {
        m_shadermodules[pTraceVal] = pReplayVal;
    }

    void rm_from_shadermodules_map(const VkShaderModule& key)
    {
        m_shadermodules.erase(key);
    }

    VkShaderModule remap_shadermodules(const VkShaderModule& value)
    {
        if (value == 0) { return 0; }
        std::map<VkShaderModule, VkShaderModule>::const_iterator q = m_shadermodules.find(value);
        if (q == m_shadermodules.end()) { vktrace_LogError("Failed to remap VkShaderModule."); return value; }
        return q->second;
    }

    std::map<VkSurfaceKHR, VkSurfaceKHR> m_surfacekhrs;
    void add_to_surfacekhrs_map(VkSurfaceKHR pTraceVal, VkSurfaceKHR pReplayVal)
    {
        m_surfacekhrs[pTraceVal] = pReplayVal;
    }

    void rm_from_surfacekhrs_map(const VkSurfaceKHR& key)
    {
        m_surfacekhrs.erase(key);
    }

    VkSurfaceKHR remap_surfacekhrs(const VkSurfaceKHR& value)
    {
        if (value == 0) { return 0; }
        std::map<VkSurfaceKHR, VkSurfaceKHR>::const_iterator q = m_surfacekhrs.find(value);
        if (q == m_surfacekhrs.end()) { vktrace_LogError("Failed to remap VkSurfaceKHR."); return value; }
        return q->second;
    }

    std::map<VkSwapchainKHR, VkSwapchainKHR> m_swapchainkhrs;
    void add_to_swapchainkhrs_map(VkSwapchainKHR pTraceVal, VkSwapchainKHR pReplayVal)
    {
        m_swapchainkhrs[pTraceVal] = pReplayVal;
    }

    void rm_from_swapchainkhrs_map(const VkSwapchainKHR& key)
    {
        m_swapchainkhrs.erase(key);
    }

    VkSwapchainKHR remap_swapchainkhrs(const VkSwapchainKHR& value)
    {
        if (value == 0) { return 0; }
        std::map<VkSwapchainKHR, VkSwapchainKHR>::const_iterator q = m_swapchainkhrs.find(value);
        if (q == m_swapchainkhrs.end()) { vktrace_LogError("Failed to remap VkSwapchainKHR."); return value; }
        return q->second;
    }

};
