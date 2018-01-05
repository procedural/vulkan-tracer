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

#include "vktrace_vk_vk_packets.h"
#include "vktrace_trace_packet_utils.h"
#include "vktrace_trace_packet_identifiers.h"
#include "vktrace_interconnect.h"
#include "vktrace_vk_vk_ext_debug_report_packets.h"
#include "vktrace_vk_vk_lunarg_debug_marker_packets.h"
#ifndef _WIN32
 #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif
#ifndef _WIN32
 #pragma GCC diagnostic warning "-Wwrite-strings"
#endif
#if defined(WIN32)
#define snprintf _snprintf
#endif
#define SEND_ENTRYPOINT_ID(entrypoint) ;
//#define SEND_ENTRYPOINT_ID(entrypoint) vktrace_TraceInfo(#entrypoint);

#define SEND_ENTRYPOINT_PARAMS(entrypoint, ...) ;
//#define SEND_ENTRYPOINT_PARAMS(entrypoint, ...) vktrace_TraceInfo(entrypoint, __VA_ARGS__);

#define CREATE_TRACE_PACKET(entrypoint, buffer_bytes_needed) \
    pHeader = vktrace_create_trace_packet(VKTRACE_TID_VULKAN, VKTRACE_TPI_VK_##entrypoint, sizeof(packet_##entrypoint), buffer_bytes_needed);

#define FINISH_TRACE_PACKET() \
    vktrace_finalize_trace_packet(pHeader); \
    vktrace_write_trace_packet(pHeader, vktrace_trace_get_trace_file()); \
    vktrace_delete_trace_packet(&pHeader);

enum VKTRACE_TRACE_PACKET_ID_VK
{
    VKTRACE_TPI_VK_vkApiVersion = VKTRACE_TPI_BEGIN_API_HERE,
    VKTRACE_TPI_VK_vkCreateInstance,
    VKTRACE_TPI_VK_vkDestroyInstance,
    VKTRACE_TPI_VK_vkEnumeratePhysicalDevices,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceFeatures,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceFormatProperties,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceImageFormatProperties,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceProperties,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceQueueFamilyProperties,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceMemoryProperties,
    VKTRACE_TPI_VK_vkGetInstanceProcAddr,
    VKTRACE_TPI_VK_vkGetDeviceProcAddr,
    VKTRACE_TPI_VK_vkCreateDevice,
    VKTRACE_TPI_VK_vkDestroyDevice,
    VKTRACE_TPI_VK_vkEnumerateInstanceExtensionProperties,
    VKTRACE_TPI_VK_vkEnumerateDeviceExtensionProperties,
    VKTRACE_TPI_VK_vkEnumerateInstanceLayerProperties,
    VKTRACE_TPI_VK_vkEnumerateDeviceLayerProperties,
    VKTRACE_TPI_VK_vkGetDeviceQueue,
    VKTRACE_TPI_VK_vkQueueSubmit,
    VKTRACE_TPI_VK_vkQueueWaitIdle,
    VKTRACE_TPI_VK_vkDeviceWaitIdle,
    VKTRACE_TPI_VK_vkAllocateMemory,
    VKTRACE_TPI_VK_vkFreeMemory,
    VKTRACE_TPI_VK_vkMapMemory,
    VKTRACE_TPI_VK_vkUnmapMemory,
    VKTRACE_TPI_VK_vkFlushMappedMemoryRanges,
    VKTRACE_TPI_VK_vkInvalidateMappedMemoryRanges,
    VKTRACE_TPI_VK_vkGetDeviceMemoryCommitment,
    VKTRACE_TPI_VK_vkBindBufferMemory,
    VKTRACE_TPI_VK_vkBindImageMemory,
    VKTRACE_TPI_VK_vkGetBufferMemoryRequirements,
    VKTRACE_TPI_VK_vkGetImageMemoryRequirements,
    VKTRACE_TPI_VK_vkGetImageSparseMemoryRequirements,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceSparseImageFormatProperties,
    VKTRACE_TPI_VK_vkQueueBindSparse,
    VKTRACE_TPI_VK_vkCreateFence,
    VKTRACE_TPI_VK_vkDestroyFence,
    VKTRACE_TPI_VK_vkResetFences,
    VKTRACE_TPI_VK_vkGetFenceStatus,
    VKTRACE_TPI_VK_vkWaitForFences,
    VKTRACE_TPI_VK_vkCreateSemaphore,
    VKTRACE_TPI_VK_vkDestroySemaphore,
    VKTRACE_TPI_VK_vkCreateEvent,
    VKTRACE_TPI_VK_vkDestroyEvent,
    VKTRACE_TPI_VK_vkGetEventStatus,
    VKTRACE_TPI_VK_vkSetEvent,
    VKTRACE_TPI_VK_vkResetEvent,
    VKTRACE_TPI_VK_vkCreateQueryPool,
    VKTRACE_TPI_VK_vkDestroyQueryPool,
    VKTRACE_TPI_VK_vkGetQueryPoolResults,
    VKTRACE_TPI_VK_vkCreateBuffer,
    VKTRACE_TPI_VK_vkDestroyBuffer,
    VKTRACE_TPI_VK_vkCreateBufferView,
    VKTRACE_TPI_VK_vkDestroyBufferView,
    VKTRACE_TPI_VK_vkCreateImage,
    VKTRACE_TPI_VK_vkDestroyImage,
    VKTRACE_TPI_VK_vkGetImageSubresourceLayout,
    VKTRACE_TPI_VK_vkCreateImageView,
    VKTRACE_TPI_VK_vkDestroyImageView,
    VKTRACE_TPI_VK_vkCreateShaderModule,
    VKTRACE_TPI_VK_vkDestroyShaderModule,
    VKTRACE_TPI_VK_vkCreatePipelineCache,
    VKTRACE_TPI_VK_vkDestroyPipelineCache,
    VKTRACE_TPI_VK_vkGetPipelineCacheData,
    VKTRACE_TPI_VK_vkMergePipelineCaches,
    VKTRACE_TPI_VK_vkCreateGraphicsPipelines,
    VKTRACE_TPI_VK_vkCreateComputePipelines,
    VKTRACE_TPI_VK_vkDestroyPipeline,
    VKTRACE_TPI_VK_vkCreatePipelineLayout,
    VKTRACE_TPI_VK_vkDestroyPipelineLayout,
    VKTRACE_TPI_VK_vkCreateSampler,
    VKTRACE_TPI_VK_vkDestroySampler,
    VKTRACE_TPI_VK_vkCreateDescriptorSetLayout,
    VKTRACE_TPI_VK_vkDestroyDescriptorSetLayout,
    VKTRACE_TPI_VK_vkCreateDescriptorPool,
    VKTRACE_TPI_VK_vkDestroyDescriptorPool,
    VKTRACE_TPI_VK_vkResetDescriptorPool,
    VKTRACE_TPI_VK_vkAllocateDescriptorSets,
    VKTRACE_TPI_VK_vkFreeDescriptorSets,
    VKTRACE_TPI_VK_vkUpdateDescriptorSets,
    VKTRACE_TPI_VK_vkCreateFramebuffer,
    VKTRACE_TPI_VK_vkDestroyFramebuffer,
    VKTRACE_TPI_VK_vkCreateRenderPass,
    VKTRACE_TPI_VK_vkDestroyRenderPass,
    VKTRACE_TPI_VK_vkGetRenderAreaGranularity,
    VKTRACE_TPI_VK_vkCreateCommandPool,
    VKTRACE_TPI_VK_vkDestroyCommandPool,
    VKTRACE_TPI_VK_vkResetCommandPool,
    VKTRACE_TPI_VK_vkAllocateCommandBuffers,
    VKTRACE_TPI_VK_vkFreeCommandBuffers,
    VKTRACE_TPI_VK_vkBeginCommandBuffer,
    VKTRACE_TPI_VK_vkEndCommandBuffer,
    VKTRACE_TPI_VK_vkResetCommandBuffer,
    VKTRACE_TPI_VK_vkCmdBindPipeline,
    VKTRACE_TPI_VK_vkCmdSetViewport,
    VKTRACE_TPI_VK_vkCmdSetScissor,
    VKTRACE_TPI_VK_vkCmdSetLineWidth,
    VKTRACE_TPI_VK_vkCmdSetDepthBias,
    VKTRACE_TPI_VK_vkCmdSetBlendConstants,
    VKTRACE_TPI_VK_vkCmdSetDepthBounds,
    VKTRACE_TPI_VK_vkCmdSetStencilCompareMask,
    VKTRACE_TPI_VK_vkCmdSetStencilWriteMask,
    VKTRACE_TPI_VK_vkCmdSetStencilReference,
    VKTRACE_TPI_VK_vkCmdBindDescriptorSets,
    VKTRACE_TPI_VK_vkCmdBindIndexBuffer,
    VKTRACE_TPI_VK_vkCmdBindVertexBuffers,
    VKTRACE_TPI_VK_vkCmdDraw,
    VKTRACE_TPI_VK_vkCmdDrawIndexed,
    VKTRACE_TPI_VK_vkCmdDrawIndirect,
    VKTRACE_TPI_VK_vkCmdDrawIndexedIndirect,
    VKTRACE_TPI_VK_vkCmdDispatch,
    VKTRACE_TPI_VK_vkCmdDispatchIndirect,
    VKTRACE_TPI_VK_vkCmdCopyBuffer,
    VKTRACE_TPI_VK_vkCmdCopyImage,
    VKTRACE_TPI_VK_vkCmdBlitImage,
    VKTRACE_TPI_VK_vkCmdCopyBufferToImage,
    VKTRACE_TPI_VK_vkCmdCopyImageToBuffer,
    VKTRACE_TPI_VK_vkCmdUpdateBuffer,
    VKTRACE_TPI_VK_vkCmdFillBuffer,
    VKTRACE_TPI_VK_vkCmdClearColorImage,
    VKTRACE_TPI_VK_vkCmdClearDepthStencilImage,
    VKTRACE_TPI_VK_vkCmdClearAttachments,
    VKTRACE_TPI_VK_vkCmdResolveImage,
    VKTRACE_TPI_VK_vkCmdSetEvent,
    VKTRACE_TPI_VK_vkCmdResetEvent,
    VKTRACE_TPI_VK_vkCmdWaitEvents,
    VKTRACE_TPI_VK_vkCmdPipelineBarrier,
    VKTRACE_TPI_VK_vkCmdBeginQuery,
    VKTRACE_TPI_VK_vkCmdEndQuery,
    VKTRACE_TPI_VK_vkCmdResetQueryPool,
    VKTRACE_TPI_VK_vkCmdWriteTimestamp,
    VKTRACE_TPI_VK_vkCmdCopyQueryPoolResults,
    VKTRACE_TPI_VK_vkCmdPushConstants,
    VKTRACE_TPI_VK_vkCmdBeginRenderPass,
    VKTRACE_TPI_VK_vkCmdNextSubpass,
    VKTRACE_TPI_VK_vkCmdEndRenderPass,
    VKTRACE_TPI_VK_vkCmdExecuteCommands,
    VKTRACE_TPI_VK_vkDestroySurfaceKHR,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceSupportKHR,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceCapabilitiesKHR,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceFormatsKHR,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfacePresentModesKHR,
    VKTRACE_TPI_VK_vkCreateSwapchainKHR,
    VKTRACE_TPI_VK_vkDestroySwapchainKHR,
    VKTRACE_TPI_VK_vkGetSwapchainImagesKHR,
    VKTRACE_TPI_VK_vkAcquireNextImageKHR,
    VKTRACE_TPI_VK_vkQueuePresentKHR,
    VKTRACE_TPI_VK_vkCreateXcbSurfaceKHR,
    VKTRACE_TPI_VK_vkGetPhysicalDeviceXcbPresentationSupportKHR,
    VKTRACE_TPI_VK_vkCreateDebugReportCallbackEXT,
    VKTRACE_TPI_VK_vkDestroyDebugReportCallbackEXT,
    VKTRACE_TPI_VK_vkDebugReportMessageEXT,
    VKTRACE_TPI_VK_vkCmdDbgMarkerBegin,
    VKTRACE_TPI_VK_vkCmdDbgMarkerEnd,
    VKTRACE_TPI_VK_vkDbgSetObjectTag,
    VKTRACE_TPI_VK_vkDbgSetObjectName,
};

static const char *vktrace_vk_packet_id_name(const enum VKTRACE_TRACE_PACKET_ID_VK id)
{
    switch(id) {
    case VKTRACE_TPI_VK_vkApiVersion:
    {
        return "vkApiVersion";
    }
    case VKTRACE_TPI_VK_vkCreateInstance:
    {
        return "vkCreateInstance";
    }
    case VKTRACE_TPI_VK_vkDestroyInstance:
    {
        return "vkDestroyInstance";
    }
    case VKTRACE_TPI_VK_vkEnumeratePhysicalDevices:
    {
        return "vkEnumeratePhysicalDevices";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceFeatures:
    {
        return "vkGetPhysicalDeviceFeatures";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceFormatProperties:
    {
        return "vkGetPhysicalDeviceFormatProperties";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceImageFormatProperties:
    {
        return "vkGetPhysicalDeviceImageFormatProperties";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceProperties:
    {
        return "vkGetPhysicalDeviceProperties";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceQueueFamilyProperties:
    {
        return "vkGetPhysicalDeviceQueueFamilyProperties";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceMemoryProperties:
    {
        return "vkGetPhysicalDeviceMemoryProperties";
    }
    case VKTRACE_TPI_VK_vkGetInstanceProcAddr:
    {
        return "vkGetInstanceProcAddr";
    }
    case VKTRACE_TPI_VK_vkGetDeviceProcAddr:
    {
        return "vkGetDeviceProcAddr";
    }
    case VKTRACE_TPI_VK_vkCreateDevice:
    {
        return "vkCreateDevice";
    }
    case VKTRACE_TPI_VK_vkDestroyDevice:
    {
        return "vkDestroyDevice";
    }
    case VKTRACE_TPI_VK_vkEnumerateInstanceExtensionProperties:
    {
        return "vkEnumerateInstanceExtensionProperties";
    }
    case VKTRACE_TPI_VK_vkEnumerateDeviceExtensionProperties:
    {
        return "vkEnumerateDeviceExtensionProperties";
    }
    case VKTRACE_TPI_VK_vkEnumerateInstanceLayerProperties:
    {
        return "vkEnumerateInstanceLayerProperties";
    }
    case VKTRACE_TPI_VK_vkEnumerateDeviceLayerProperties:
    {
        return "vkEnumerateDeviceLayerProperties";
    }
    case VKTRACE_TPI_VK_vkGetDeviceQueue:
    {
        return "vkGetDeviceQueue";
    }
    case VKTRACE_TPI_VK_vkQueueSubmit:
    {
        return "vkQueueSubmit";
    }
    case VKTRACE_TPI_VK_vkQueueWaitIdle:
    {
        return "vkQueueWaitIdle";
    }
    case VKTRACE_TPI_VK_vkDeviceWaitIdle:
    {
        return "vkDeviceWaitIdle";
    }
    case VKTRACE_TPI_VK_vkAllocateMemory:
    {
        return "vkAllocateMemory";
    }
    case VKTRACE_TPI_VK_vkFreeMemory:
    {
        return "vkFreeMemory";
    }
    case VKTRACE_TPI_VK_vkMapMemory:
    {
        return "vkMapMemory";
    }
    case VKTRACE_TPI_VK_vkUnmapMemory:
    {
        return "vkUnmapMemory";
    }
    case VKTRACE_TPI_VK_vkFlushMappedMemoryRanges:
    {
        return "vkFlushMappedMemoryRanges";
    }
    case VKTRACE_TPI_VK_vkInvalidateMappedMemoryRanges:
    {
        return "vkInvalidateMappedMemoryRanges";
    }
    case VKTRACE_TPI_VK_vkGetDeviceMemoryCommitment:
    {
        return "vkGetDeviceMemoryCommitment";
    }
    case VKTRACE_TPI_VK_vkBindBufferMemory:
    {
        return "vkBindBufferMemory";
    }
    case VKTRACE_TPI_VK_vkBindImageMemory:
    {
        return "vkBindImageMemory";
    }
    case VKTRACE_TPI_VK_vkGetBufferMemoryRequirements:
    {
        return "vkGetBufferMemoryRequirements";
    }
    case VKTRACE_TPI_VK_vkGetImageMemoryRequirements:
    {
        return "vkGetImageMemoryRequirements";
    }
    case VKTRACE_TPI_VK_vkGetImageSparseMemoryRequirements:
    {
        return "vkGetImageSparseMemoryRequirements";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceSparseImageFormatProperties:
    {
        return "vkGetPhysicalDeviceSparseImageFormatProperties";
    }
    case VKTRACE_TPI_VK_vkQueueBindSparse:
    {
        return "vkQueueBindSparse";
    }
    case VKTRACE_TPI_VK_vkCreateFence:
    {
        return "vkCreateFence";
    }
    case VKTRACE_TPI_VK_vkDestroyFence:
    {
        return "vkDestroyFence";
    }
    case VKTRACE_TPI_VK_vkResetFences:
    {
        return "vkResetFences";
    }
    case VKTRACE_TPI_VK_vkGetFenceStatus:
    {
        return "vkGetFenceStatus";
    }
    case VKTRACE_TPI_VK_vkWaitForFences:
    {
        return "vkWaitForFences";
    }
    case VKTRACE_TPI_VK_vkCreateSemaphore:
    {
        return "vkCreateSemaphore";
    }
    case VKTRACE_TPI_VK_vkDestroySemaphore:
    {
        return "vkDestroySemaphore";
    }
    case VKTRACE_TPI_VK_vkCreateEvent:
    {
        return "vkCreateEvent";
    }
    case VKTRACE_TPI_VK_vkDestroyEvent:
    {
        return "vkDestroyEvent";
    }
    case VKTRACE_TPI_VK_vkGetEventStatus:
    {
        return "vkGetEventStatus";
    }
    case VKTRACE_TPI_VK_vkSetEvent:
    {
        return "vkSetEvent";
    }
    case VKTRACE_TPI_VK_vkResetEvent:
    {
        return "vkResetEvent";
    }
    case VKTRACE_TPI_VK_vkCreateQueryPool:
    {
        return "vkCreateQueryPool";
    }
    case VKTRACE_TPI_VK_vkDestroyQueryPool:
    {
        return "vkDestroyQueryPool";
    }
    case VKTRACE_TPI_VK_vkGetQueryPoolResults:
    {
        return "vkGetQueryPoolResults";
    }
    case VKTRACE_TPI_VK_vkCreateBuffer:
    {
        return "vkCreateBuffer";
    }
    case VKTRACE_TPI_VK_vkDestroyBuffer:
    {
        return "vkDestroyBuffer";
    }
    case VKTRACE_TPI_VK_vkCreateBufferView:
    {
        return "vkCreateBufferView";
    }
    case VKTRACE_TPI_VK_vkDestroyBufferView:
    {
        return "vkDestroyBufferView";
    }
    case VKTRACE_TPI_VK_vkCreateImage:
    {
        return "vkCreateImage";
    }
    case VKTRACE_TPI_VK_vkDestroyImage:
    {
        return "vkDestroyImage";
    }
    case VKTRACE_TPI_VK_vkGetImageSubresourceLayout:
    {
        return "vkGetImageSubresourceLayout";
    }
    case VKTRACE_TPI_VK_vkCreateImageView:
    {
        return "vkCreateImageView";
    }
    case VKTRACE_TPI_VK_vkDestroyImageView:
    {
        return "vkDestroyImageView";
    }
    case VKTRACE_TPI_VK_vkCreateShaderModule:
    {
        return "vkCreateShaderModule";
    }
    case VKTRACE_TPI_VK_vkDestroyShaderModule:
    {
        return "vkDestroyShaderModule";
    }
    case VKTRACE_TPI_VK_vkCreatePipelineCache:
    {
        return "vkCreatePipelineCache";
    }
    case VKTRACE_TPI_VK_vkDestroyPipelineCache:
    {
        return "vkDestroyPipelineCache";
    }
    case VKTRACE_TPI_VK_vkGetPipelineCacheData:
    {
        return "vkGetPipelineCacheData";
    }
    case VKTRACE_TPI_VK_vkMergePipelineCaches:
    {
        return "vkMergePipelineCaches";
    }
    case VKTRACE_TPI_VK_vkCreateGraphicsPipelines:
    {
        return "vkCreateGraphicsPipelines";
    }
    case VKTRACE_TPI_VK_vkCreateComputePipelines:
    {
        return "vkCreateComputePipelines";
    }
    case VKTRACE_TPI_VK_vkDestroyPipeline:
    {
        return "vkDestroyPipeline";
    }
    case VKTRACE_TPI_VK_vkCreatePipelineLayout:
    {
        return "vkCreatePipelineLayout";
    }
    case VKTRACE_TPI_VK_vkDestroyPipelineLayout:
    {
        return "vkDestroyPipelineLayout";
    }
    case VKTRACE_TPI_VK_vkCreateSampler:
    {
        return "vkCreateSampler";
    }
    case VKTRACE_TPI_VK_vkDestroySampler:
    {
        return "vkDestroySampler";
    }
    case VKTRACE_TPI_VK_vkCreateDescriptorSetLayout:
    {
        return "vkCreateDescriptorSetLayout";
    }
    case VKTRACE_TPI_VK_vkDestroyDescriptorSetLayout:
    {
        return "vkDestroyDescriptorSetLayout";
    }
    case VKTRACE_TPI_VK_vkCreateDescriptorPool:
    {
        return "vkCreateDescriptorPool";
    }
    case VKTRACE_TPI_VK_vkDestroyDescriptorPool:
    {
        return "vkDestroyDescriptorPool";
    }
    case VKTRACE_TPI_VK_vkResetDescriptorPool:
    {
        return "vkResetDescriptorPool";
    }
    case VKTRACE_TPI_VK_vkAllocateDescriptorSets:
    {
        return "vkAllocateDescriptorSets";
    }
    case VKTRACE_TPI_VK_vkFreeDescriptorSets:
    {
        return "vkFreeDescriptorSets";
    }
    case VKTRACE_TPI_VK_vkUpdateDescriptorSets:
    {
        return "vkUpdateDescriptorSets";
    }
    case VKTRACE_TPI_VK_vkCreateFramebuffer:
    {
        return "vkCreateFramebuffer";
    }
    case VKTRACE_TPI_VK_vkDestroyFramebuffer:
    {
        return "vkDestroyFramebuffer";
    }
    case VKTRACE_TPI_VK_vkCreateRenderPass:
    {
        return "vkCreateRenderPass";
    }
    case VKTRACE_TPI_VK_vkDestroyRenderPass:
    {
        return "vkDestroyRenderPass";
    }
    case VKTRACE_TPI_VK_vkGetRenderAreaGranularity:
    {
        return "vkGetRenderAreaGranularity";
    }
    case VKTRACE_TPI_VK_vkCreateCommandPool:
    {
        return "vkCreateCommandPool";
    }
    case VKTRACE_TPI_VK_vkDestroyCommandPool:
    {
        return "vkDestroyCommandPool";
    }
    case VKTRACE_TPI_VK_vkResetCommandPool:
    {
        return "vkResetCommandPool";
    }
    case VKTRACE_TPI_VK_vkAllocateCommandBuffers:
    {
        return "vkAllocateCommandBuffers";
    }
    case VKTRACE_TPI_VK_vkFreeCommandBuffers:
    {
        return "vkFreeCommandBuffers";
    }
    case VKTRACE_TPI_VK_vkBeginCommandBuffer:
    {
        return "vkBeginCommandBuffer";
    }
    case VKTRACE_TPI_VK_vkEndCommandBuffer:
    {
        return "vkEndCommandBuffer";
    }
    case VKTRACE_TPI_VK_vkResetCommandBuffer:
    {
        return "vkResetCommandBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdBindPipeline:
    {
        return "vkCmdBindPipeline";
    }
    case VKTRACE_TPI_VK_vkCmdSetViewport:
    {
        return "vkCmdSetViewport";
    }
    case VKTRACE_TPI_VK_vkCmdSetScissor:
    {
        return "vkCmdSetScissor";
    }
    case VKTRACE_TPI_VK_vkCmdSetLineWidth:
    {
        return "vkCmdSetLineWidth";
    }
    case VKTRACE_TPI_VK_vkCmdSetDepthBias:
    {
        return "vkCmdSetDepthBias";
    }
    case VKTRACE_TPI_VK_vkCmdSetBlendConstants:
    {
        return "vkCmdSetBlendConstants";
    }
    case VKTRACE_TPI_VK_vkCmdSetDepthBounds:
    {
        return "vkCmdSetDepthBounds";
    }
    case VKTRACE_TPI_VK_vkCmdSetStencilCompareMask:
    {
        return "vkCmdSetStencilCompareMask";
    }
    case VKTRACE_TPI_VK_vkCmdSetStencilWriteMask:
    {
        return "vkCmdSetStencilWriteMask";
    }
    case VKTRACE_TPI_VK_vkCmdSetStencilReference:
    {
        return "vkCmdSetStencilReference";
    }
    case VKTRACE_TPI_VK_vkCmdBindDescriptorSets:
    {
        return "vkCmdBindDescriptorSets";
    }
    case VKTRACE_TPI_VK_vkCmdBindIndexBuffer:
    {
        return "vkCmdBindIndexBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdBindVertexBuffers:
    {
        return "vkCmdBindVertexBuffers";
    }
    case VKTRACE_TPI_VK_vkCmdDraw:
    {
        return "vkCmdDraw";
    }
    case VKTRACE_TPI_VK_vkCmdDrawIndexed:
    {
        return "vkCmdDrawIndexed";
    }
    case VKTRACE_TPI_VK_vkCmdDrawIndirect:
    {
        return "vkCmdDrawIndirect";
    }
    case VKTRACE_TPI_VK_vkCmdDrawIndexedIndirect:
    {
        return "vkCmdDrawIndexedIndirect";
    }
    case VKTRACE_TPI_VK_vkCmdDispatch:
    {
        return "vkCmdDispatch";
    }
    case VKTRACE_TPI_VK_vkCmdDispatchIndirect:
    {
        return "vkCmdDispatchIndirect";
    }
    case VKTRACE_TPI_VK_vkCmdCopyBuffer:
    {
        return "vkCmdCopyBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdCopyImage:
    {
        return "vkCmdCopyImage";
    }
    case VKTRACE_TPI_VK_vkCmdBlitImage:
    {
        return "vkCmdBlitImage";
    }
    case VKTRACE_TPI_VK_vkCmdCopyBufferToImage:
    {
        return "vkCmdCopyBufferToImage";
    }
    case VKTRACE_TPI_VK_vkCmdCopyImageToBuffer:
    {
        return "vkCmdCopyImageToBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdUpdateBuffer:
    {
        return "vkCmdUpdateBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdFillBuffer:
    {
        return "vkCmdFillBuffer";
    }
    case VKTRACE_TPI_VK_vkCmdClearColorImage:
    {
        return "vkCmdClearColorImage";
    }
    case VKTRACE_TPI_VK_vkCmdClearDepthStencilImage:
    {
        return "vkCmdClearDepthStencilImage";
    }
    case VKTRACE_TPI_VK_vkCmdClearAttachments:
    {
        return "vkCmdClearAttachments";
    }
    case VKTRACE_TPI_VK_vkCmdResolveImage:
    {
        return "vkCmdResolveImage";
    }
    case VKTRACE_TPI_VK_vkCmdSetEvent:
    {
        return "vkCmdSetEvent";
    }
    case VKTRACE_TPI_VK_vkCmdResetEvent:
    {
        return "vkCmdResetEvent";
    }
    case VKTRACE_TPI_VK_vkCmdWaitEvents:
    {
        return "vkCmdWaitEvents";
    }
    case VKTRACE_TPI_VK_vkCmdPipelineBarrier:
    {
        return "vkCmdPipelineBarrier";
    }
    case VKTRACE_TPI_VK_vkCmdBeginQuery:
    {
        return "vkCmdBeginQuery";
    }
    case VKTRACE_TPI_VK_vkCmdEndQuery:
    {
        return "vkCmdEndQuery";
    }
    case VKTRACE_TPI_VK_vkCmdResetQueryPool:
    {
        return "vkCmdResetQueryPool";
    }
    case VKTRACE_TPI_VK_vkCmdWriteTimestamp:
    {
        return "vkCmdWriteTimestamp";
    }
    case VKTRACE_TPI_VK_vkCmdCopyQueryPoolResults:
    {
        return "vkCmdCopyQueryPoolResults";
    }
    case VKTRACE_TPI_VK_vkCmdPushConstants:
    {
        return "vkCmdPushConstants";
    }
    case VKTRACE_TPI_VK_vkCmdBeginRenderPass:
    {
        return "vkCmdBeginRenderPass";
    }
    case VKTRACE_TPI_VK_vkCmdNextSubpass:
    {
        return "vkCmdNextSubpass";
    }
    case VKTRACE_TPI_VK_vkCmdEndRenderPass:
    {
        return "vkCmdEndRenderPass";
    }
    case VKTRACE_TPI_VK_vkCmdExecuteCommands:
    {
        return "vkCmdExecuteCommands";
    }
    case VKTRACE_TPI_VK_vkDestroySurfaceKHR:
    {
        return "vkDestroySurfaceKHR";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceSupportKHR:
    {
        return "vkGetPhysicalDeviceSurfaceSupportKHR";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
    {
        return "vkGetPhysicalDeviceSurfaceCapabilitiesKHR";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceFormatsKHR:
    {
        return "vkGetPhysicalDeviceSurfaceFormatsKHR";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfacePresentModesKHR:
    {
        return "vkGetPhysicalDeviceSurfacePresentModesKHR";
    }
    case VKTRACE_TPI_VK_vkCreateSwapchainKHR:
    {
        return "vkCreateSwapchainKHR";
    }
    case VKTRACE_TPI_VK_vkDestroySwapchainKHR:
    {
        return "vkDestroySwapchainKHR";
    }
    case VKTRACE_TPI_VK_vkGetSwapchainImagesKHR:
    {
        return "vkGetSwapchainImagesKHR";
    }
    case VKTRACE_TPI_VK_vkAcquireNextImageKHR:
    {
        return "vkAcquireNextImageKHR";
    }
    case VKTRACE_TPI_VK_vkQueuePresentKHR:
    {
        return "vkQueuePresentKHR";
    }
    case VKTRACE_TPI_VK_vkCreateXcbSurfaceKHR:
    {
        return "vkCreateXcbSurfaceKHR";
    }
    case VKTRACE_TPI_VK_vkGetPhysicalDeviceXcbPresentationSupportKHR:
    {
        return "vkGetPhysicalDeviceXcbPresentationSupportKHR";
    }
    case VKTRACE_TPI_VK_vkCreateDebugReportCallbackEXT:
    {
        return "vkCreateDebugReportCallbackEXT";
    }
    case VKTRACE_TPI_VK_vkDestroyDebugReportCallbackEXT:
    {
        return "vkDestroyDebugReportCallbackEXT";
    }
    case VKTRACE_TPI_VK_vkDebugReportMessageEXT:
    {
        return "vkDebugReportMessageEXT";
    }
    case VKTRACE_TPI_VK_vkCmdDbgMarkerBegin:
    {
        return "vkCmdDbgMarkerBegin";
    }
    case VKTRACE_TPI_VK_vkCmdDbgMarkerEnd:
    {
        return "vkCmdDbgMarkerEnd";
    }
    case VKTRACE_TPI_VK_vkDbgSetObjectTag:
    {
        return "vkDbgSetObjectTag";
    }
    case VKTRACE_TPI_VK_vkDbgSetObjectName:
    {
        return "vkDbgSetObjectName";
    }
    default:
        return NULL;
    }
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #524
static vktrace_trace_packet_header* interpret_trace_packet_vk(vktrace_trace_packet_header* pHeader)
{
    if (pHeader == NULL)
    {
        return NULL;
    }
    switch (pHeader->packet_id)
    {
        case VKTRACE_TPI_VK_vkApiVersion:
        {
            return interpret_body_as_vkApiVersion(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateInstance:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateInstance(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyInstance:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyInstance(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEnumeratePhysicalDevices:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEnumeratePhysicalDevices(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceFeatures:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceFeatures(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceFormatProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceFormatProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceImageFormatProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceImageFormatProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceQueueFamilyProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceQueueFamilyProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceMemoryProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceMemoryProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetInstanceProcAddr:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetInstanceProcAddr(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetDeviceProcAddr:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetDeviceProcAddr(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateDevice:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateDevice(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyDevice:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyDevice(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEnumerateInstanceExtensionProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEnumerateInstanceExtensionProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEnumerateDeviceExtensionProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEnumerateDeviceExtensionProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEnumerateInstanceLayerProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEnumerateInstanceLayerProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEnumerateDeviceLayerProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEnumerateDeviceLayerProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetDeviceQueue:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetDeviceQueue(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkQueueSubmit:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkQueueSubmit(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkQueueWaitIdle:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkQueueWaitIdle(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDeviceWaitIdle:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDeviceWaitIdle(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkAllocateMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkAllocateMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkFreeMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkFreeMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkMapMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkMapMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkUnmapMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkUnmapMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkFlushMappedMemoryRanges:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkFlushMappedMemoryRanges(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkInvalidateMappedMemoryRanges:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkInvalidateMappedMemoryRanges(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetDeviceMemoryCommitment:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetDeviceMemoryCommitment(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkBindBufferMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkBindBufferMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkBindImageMemory:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkBindImageMemory(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetBufferMemoryRequirements:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetBufferMemoryRequirements(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetImageMemoryRequirements:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetImageMemoryRequirements(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetImageSparseMemoryRequirements:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetImageSparseMemoryRequirements(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSparseImageFormatProperties:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceSparseImageFormatProperties(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkQueueBindSparse:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkQueueBindSparse(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateFence:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateFence(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyFence:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyFence(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkResetFences:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkResetFences(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetFenceStatus:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetFenceStatus(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkWaitForFences:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkWaitForFences(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateSemaphore:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateSemaphore(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroySemaphore:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroySemaphore(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetEventStatus:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetEventStatus(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkSetEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkSetEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkResetEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkResetEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateQueryPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateQueryPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyQueryPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyQueryPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetQueryPoolResults:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetQueryPoolResults(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateBufferView:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateBufferView(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyBufferView:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyBufferView(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetImageSubresourceLayout:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetImageSubresourceLayout(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateImageView:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateImageView(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyImageView:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyImageView(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateShaderModule:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateShaderModule(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyShaderModule:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyShaderModule(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreatePipelineCache:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreatePipelineCache(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyPipelineCache:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyPipelineCache(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPipelineCacheData:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPipelineCacheData(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkMergePipelineCaches:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkMergePipelineCaches(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateGraphicsPipelines:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateGraphicsPipelines(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateComputePipelines:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateComputePipelines(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyPipeline:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyPipeline(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreatePipelineLayout:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreatePipelineLayout(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyPipelineLayout:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyPipelineLayout(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateSampler:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateSampler(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroySampler:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroySampler(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateDescriptorSetLayout:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateDescriptorSetLayout(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyDescriptorSetLayout:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyDescriptorSetLayout(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateDescriptorPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateDescriptorPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyDescriptorPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyDescriptorPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkResetDescriptorPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkResetDescriptorPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkAllocateDescriptorSets:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkAllocateDescriptorSets(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkFreeDescriptorSets:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkFreeDescriptorSets(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkUpdateDescriptorSets:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkUpdateDescriptorSets(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateFramebuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateFramebuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyFramebuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyFramebuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateRenderPass:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateRenderPass(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyRenderPass:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyRenderPass(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetRenderAreaGranularity:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetRenderAreaGranularity(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateCommandPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateCommandPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroyCommandPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyCommandPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkResetCommandPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkResetCommandPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkAllocateCommandBuffers:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkAllocateCommandBuffers(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkFreeCommandBuffers:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkFreeCommandBuffers(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkBeginCommandBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkBeginCommandBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkEndCommandBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkEndCommandBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkResetCommandBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkResetCommandBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBindPipeline:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBindPipeline(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetViewport:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetViewport(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetScissor:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetScissor(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetLineWidth:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetLineWidth(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetDepthBias:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetDepthBias(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetBlendConstants:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetBlendConstants(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetDepthBounds:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetDepthBounds(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilCompareMask:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetStencilCompareMask(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilWriteMask:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetStencilWriteMask(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilReference:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetStencilReference(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBindDescriptorSets:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBindDescriptorSets(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBindIndexBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBindIndexBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBindVertexBuffers:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBindVertexBuffers(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDraw:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDraw(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndexed:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDrawIndexed(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndirect:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDrawIndirect(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndexedIndirect:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDrawIndexedIndirect(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDispatch:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDispatch(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdDispatchIndirect:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDispatchIndirect(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdCopyBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdCopyBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdCopyImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdCopyImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBlitImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBlitImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdCopyBufferToImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdCopyBufferToImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdCopyImageToBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdCopyImageToBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdUpdateBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdUpdateBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdFillBuffer:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdFillBuffer(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdClearColorImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdClearColorImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdClearDepthStencilImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdClearDepthStencilImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdClearAttachments:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdClearAttachments(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdResolveImage:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdResolveImage(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdSetEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdSetEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdResetEvent:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdResetEvent(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdWaitEvents:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdWaitEvents(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdPipelineBarrier:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdPipelineBarrier(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBeginQuery:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBeginQuery(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdEndQuery:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdEndQuery(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdResetQueryPool:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdResetQueryPool(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdWriteTimestamp:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdWriteTimestamp(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdCopyQueryPoolResults:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdCopyQueryPoolResults(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdPushConstants:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdPushConstants(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdBeginRenderPass:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdBeginRenderPass(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdNextSubpass:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdNextSubpass(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdEndRenderPass:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdEndRenderPass(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCmdExecuteCommands:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdExecuteCommands(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroySurfaceKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroySurfaceKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceSupportKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceSurfaceSupportKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceFormatsKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceSurfaceFormatsKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfacePresentModesKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceSurfacePresentModesKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateSwapchainKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateSwapchainKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkDestroySwapchainKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroySwapchainKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetSwapchainImagesKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetSwapchainImagesKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkAcquireNextImageKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkAcquireNextImageKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkQueuePresentKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkQueuePresentKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateXcbSurfaceKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateXcbSurfaceKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkGetPhysicalDeviceXcbPresentationSupportKHR(pHeader)->header;
        }
        case VKTRACE_TPI_VK_vkCreateDebugReportCallbackEXT:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCreateDebugReportCallbackEXT(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkDestroyDebugReportCallbackEXT:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDestroyDebugReportCallbackEXT(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkDebugReportMessageEXT:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDebugReportMessageEXT(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkCmdDbgMarkerBegin:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDbgMarkerBegin(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkCmdDbgMarkerEnd:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkCmdDbgMarkerEnd(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkDbgSetObjectTag:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDbgSetObjectTag(pHeader)->pHeader;
        }
        case VKTRACE_TPI_VK_vkDbgSetObjectName:
        {
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #542
            return interpret_body_as_vkDbgSetObjectName(pHeader)->pHeader;
        }
        default:
            return NULL;
    }
    return NULL;
}
