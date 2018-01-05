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

#include "vktrace_platform.h"
#include "vktrace_common.h"
#include "vktrace_lib_helpers.h"
#include "vktrace_vk_vk.h"
#include "vktrace_vk_vk_ext_debug_report.h"
#include "vktrace_vk_vk_lunarg_debug_marker.h"
#include "vktrace_interconnect.h"
#include "vktrace_filelike.h"
#include "vk_struct_size_helper.h"
#ifdef PLATFORM_LINUX
#include <pthread.h>
#endif
#include "vktrace_trace_packet_utils.h"
#include <stdio.h>

#include <string.h>

#ifdef WIN32
INIT_ONCE gInitOnce = INIT_ONCE_STATIC_INIT;
#elif defined(PLATFORM_LINUX)
pthread_once_t gInitOnce = PTHREAD_ONCE_INIT;
#endif

void send_vk_api_version_packet()
{
    packet_vkApiVersion* pPacket;
    vktrace_trace_packet_header* pHeader;
    pHeader = vktrace_create_trace_packet(VKTRACE_TID_VULKAN, VKTRACE_TPI_VK_vkApiVersion, sizeof(packet_vkApiVersion), 0);
    pPacket = interpret_body_as_vkApiVersion(pHeader);
    pPacket->version = VK_API_VERSION;
    vktrace_set_packet_entrypoint_end_time(pHeader);
    FINISH_TRACE_PACKET();
}

extern VKTRACE_CRITICAL_SECTION g_memInfoLock;
void InitTracer(void)
{
    const char *ipAddr = vktrace_get_global_var("VKTRACE_LIB_IPADDR");
    if (ipAddr == NULL)
        ipAddr = "127.0.0.1";
    gMessageStream = vktrace_MessageStream_create(FALSE, ipAddr, VKTRACE_BASE_PORT + VKTRACE_TID_VULKAN);
    vktrace_trace_set_trace_file(vktrace_FileLike_create_msg(gMessageStream));
    vktrace_tracelog_set_tracer_id(VKTRACE_TID_VULKAN);
    vktrace_create_critical_section(&g_memInfoLock);
    if (gMessageStream != NULL)
        send_vk_api_version_packet();
}

// __HOOKED_vkCreateInstance is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyInstance(
    VkInstance instance,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyInstance* pPacket = NULL;
    dispatch_key key = get_dispatch_key(instance);
    CREATE_TRACE_PACKET(vkDestroyInstance, sizeof(VkAllocationCallbacks));
    mid(instance)->instTable.DestroyInstance(instance, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyInstance(pHeader);
    pPacket->instance = instance;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
    g_instanceDataMap.erase(key);
}

// __HOOKED_vkEnumeratePhysicalDevices is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceFeatures* pFeatures)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetPhysicalDeviceFeatures* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceFeatures, sizeof(VkPhysicalDeviceFeatures));
    mid(physicalDevice)->instTable.GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceFeatures(pHeader);
    pPacket->physicalDevice = physicalDevice;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pFeatures), sizeof(VkPhysicalDeviceFeatures), pFeatures);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pFeatures));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkFormatProperties* pFormatProperties)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetPhysicalDeviceFormatProperties* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceFormatProperties, sizeof(VkFormatProperties));
    mid(physicalDevice)->instTable.GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceFormatProperties(pHeader);
    pPacket->physicalDevice = physicalDevice;
    pPacket->format = format;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pFormatProperties), sizeof(VkFormatProperties), pFormatProperties);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pFormatProperties));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkImageType type,
    VkImageTiling tiling,
    VkImageUsageFlags usage,
    VkImageCreateFlags flags,
    VkImageFormatProperties* pImageFormatProperties)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkGetPhysicalDeviceImageFormatProperties* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceImageFormatProperties, sizeof(VkImageFormatProperties));
    result = mid(physicalDevice)->instTable.GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceImageFormatProperties(pHeader);
    pPacket->physicalDevice = physicalDevice;
    pPacket->format = format;
    pPacket->type = type;
    pPacket->tiling = tiling;
    pPacket->usage = usage;
    pPacket->flags = flags;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pImageFormatProperties), sizeof(VkImageFormatProperties), pImageFormatProperties);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pImageFormatProperties));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceProperties(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetPhysicalDeviceProperties* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceProperties, sizeof(VkPhysicalDeviceProperties));
    mid(physicalDevice)->instTable.GetPhysicalDeviceProperties(physicalDevice, pProperties);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceProperties(pHeader);
    pPacket->physicalDevice = physicalDevice;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pProperties), sizeof(VkPhysicalDeviceProperties), pProperties);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pProperties));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkGetPhysicalDeviceQueueFamilyProperties is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetPhysicalDeviceMemoryProperties* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceMemoryProperties, sizeof(VkPhysicalDeviceMemoryProperties));
    mid(physicalDevice)->instTable.GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceMemoryProperties(pHeader);
    pPacket->physicalDevice = physicalDevice;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pMemoryProperties), sizeof(VkPhysicalDeviceMemoryProperties), pMemoryProperties);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pMemoryProperties));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkGetInstanceProcAddr is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkGetDeviceProcAddr is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCreateDevice is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDevice(
    VkDevice device,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyDevice* pPacket = NULL;
    dispatch_key key = get_dispatch_key(device);
    CREATE_TRACE_PACKET(vkDestroyDevice, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyDevice(device, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyDevice(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
    g_deviceDataMap.erase(key);
}

// __HOOKED_vkEnumerateInstanceExtensionProperties is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkEnumerateDeviceExtensionProperties is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkEnumerateInstanceLayerProperties is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkEnumerateDeviceLayerProperties is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetDeviceQueue(
    VkDevice device,
    uint32_t queueFamilyIndex,
    uint32_t queueIndex,
    VkQueue* pQueue)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetDeviceQueue* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetDeviceQueue, sizeof(VkQueue));
    mdd(device)->devTable.GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetDeviceQueue(pHeader);
    pPacket->device = device;
    pPacket->queueFamilyIndex = queueFamilyIndex;
    pPacket->queueIndex = queueIndex;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pQueue), sizeof(VkQueue), pQueue);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pQueue));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkQueueSubmit is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueueWaitIdle(
    VkQueue queue)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkQueueWaitIdle* pPacket = NULL;
    CREATE_TRACE_PACKET(vkQueueWaitIdle, 0);
    result = mdd(queue)->devTable.QueueWaitIdle(queue);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkQueueWaitIdle(pHeader);
    pPacket->queue = queue;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkDeviceWaitIdle(
    VkDevice device)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkDeviceWaitIdle* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDeviceWaitIdle, 0);
    result = mdd(device)->devTable.DeviceWaitIdle(device);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDeviceWaitIdle(pHeader);
    pPacket->device = device;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkAllocateMemory is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkFreeMemory is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkMapMemory is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkUnmapMemory is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkFlushMappedMemoryRanges is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkInvalidateMappedMemoryRanges(
    VkDevice device,
    uint32_t memoryRangeCount,
    const VkMappedMemoryRange* pMemoryRanges)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkInvalidateMappedMemoryRanges* pPacket = NULL;
    CREATE_TRACE_PACKET(vkInvalidateMappedMemoryRanges, memoryRangeCount*sizeof(VkMappedMemoryRange));
    result = mdd(device)->devTable.InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkInvalidateMappedMemoryRanges(pHeader);
    pPacket->device = device;
    pPacket->memoryRangeCount = memoryRangeCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pMemoryRanges), memoryRangeCount*sizeof(VkMappedMemoryRange), pMemoryRanges);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pMemoryRanges));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetDeviceMemoryCommitment(
    VkDevice device,
    VkDeviceMemory memory,
    VkDeviceSize* pCommittedMemoryInBytes)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetDeviceMemoryCommitment* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetDeviceMemoryCommitment, sizeof(VkDeviceSize));
    mdd(device)->devTable.GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetDeviceMemoryCommitment(pHeader);
    pPacket->device = device;
    pPacket->memory = memory;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCommittedMemoryInBytes), sizeof(VkDeviceSize), pCommittedMemoryInBytes);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCommittedMemoryInBytes));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkBindBufferMemory(
    VkDevice device,
    VkBuffer buffer,
    VkDeviceMemory memory,
    VkDeviceSize memoryOffset)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkBindBufferMemory* pPacket = NULL;
    CREATE_TRACE_PACKET(vkBindBufferMemory, 0);
    result = mdd(device)->devTable.BindBufferMemory(device, buffer, memory, memoryOffset);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkBindBufferMemory(pHeader);
    pPacket->device = device;
    pPacket->buffer = buffer;
    pPacket->memory = memory;
    pPacket->memoryOffset = memoryOffset;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkBindImageMemory(
    VkDevice device,
    VkImage image,
    VkDeviceMemory memory,
    VkDeviceSize memoryOffset)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkBindImageMemory* pPacket = NULL;
    CREATE_TRACE_PACKET(vkBindImageMemory, 0);
    result = mdd(device)->devTable.BindImageMemory(device, image, memory, memoryOffset);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkBindImageMemory(pHeader);
    pPacket->device = device;
    pPacket->image = image;
    pPacket->memory = memory;
    pPacket->memoryOffset = memoryOffset;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetBufferMemoryRequirements(
    VkDevice device,
    VkBuffer buffer,
    VkMemoryRequirements* pMemoryRequirements)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetBufferMemoryRequirements* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetBufferMemoryRequirements, sizeof(VkMemoryRequirements));
    mdd(device)->devTable.GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetBufferMemoryRequirements(pHeader);
    pPacket->device = device;
    pPacket->buffer = buffer;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pMemoryRequirements), sizeof(VkMemoryRequirements), pMemoryRequirements);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pMemoryRequirements));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageMemoryRequirements(
    VkDevice device,
    VkImage image,
    VkMemoryRequirements* pMemoryRequirements)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetImageMemoryRequirements* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetImageMemoryRequirements, sizeof(VkMemoryRequirements));
    mdd(device)->devTable.GetImageMemoryRequirements(device, image, pMemoryRequirements);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetImageMemoryRequirements(pHeader);
    pPacket->device = device;
    pPacket->image = image;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pMemoryRequirements), sizeof(VkMemoryRequirements), pMemoryRequirements);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pMemoryRequirements));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageSparseMemoryRequirements(
    VkDevice device,
    VkImage image,
    uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetImageSparseMemoryRequirements* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetImageSparseMemoryRequirements, sizeof(uint32_t) + sizeof(VkSparseImageMemoryRequirements));
    mdd(device)->devTable.GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetImageSparseMemoryRequirements(pHeader);
    pPacket->device = device;
    pPacket->image = image;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSparseMemoryRequirementCount), sizeof(uint32_t), pSparseMemoryRequirementCount);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSparseMemoryRequirements), (*pSparseMemoryRequirementCount) * sizeof(VkSparseImageMemoryRequirements), pSparseMemoryRequirements);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSparseMemoryRequirementCount));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSparseMemoryRequirements));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkImageType type,
    VkSampleCountFlagBits samples,
    VkImageUsageFlags usage,
    VkImageTiling tiling,
    uint32_t* pPropertyCount,
    VkSparseImageFormatProperties* pProperties)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetPhysicalDeviceSparseImageFormatProperties* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceSparseImageFormatProperties, sizeof(uint32_t) + sizeof(VkSparseImageFormatProperties));
    mid(physicalDevice)->instTable.GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceSparseImageFormatProperties(pHeader);
    pPacket->physicalDevice = physicalDevice;
    pPacket->format = format;
    pPacket->type = type;
    pPacket->samples = samples;
    pPacket->usage = usage;
    pPacket->tiling = tiling;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pPropertyCount), sizeof(uint32_t), pPropertyCount);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pProperties), (*pPropertyCount) * sizeof(VkSparseImageFormatProperties), pProperties);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pPropertyCount));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pProperties));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueueBindSparse(
    VkQueue queue,
    uint32_t bindInfoCount,
    const VkBindSparseInfo* pBindInfo,
    VkFence fence)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkQueueBindSparse* pPacket = NULL;
    CREATE_TRACE_PACKET(vkQueueBindSparse, bindInfoCount*sizeof(VkBindSparseInfo));
    result = mdd(queue)->devTable.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkQueueBindSparse(pHeader);
    pPacket->queue = queue;
    pPacket->bindInfoCount = bindInfoCount;
    pPacket->fence = fence;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pBindInfo), bindInfoCount*sizeof(VkBindSparseInfo), pBindInfo);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pBindInfo));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateFence(
    VkDevice device,
    const VkFenceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkFence* pFence)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateFence* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateFence, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkFence));
    result = mdd(device)->devTable.CreateFence(device, pCreateInfo, pAllocator, pFence);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateFence(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkFenceCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pFence), sizeof(VkFence), pFence);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pFence));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyFence(
    VkDevice device,
    VkFence fence,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyFence* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyFence, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyFence(device, fence, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyFence(pHeader);
    pPacket->device = device;
    pPacket->fence = fence;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetFences(
    VkDevice device,
    uint32_t fenceCount,
    const VkFence* pFences)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkResetFences* pPacket = NULL;
    CREATE_TRACE_PACKET(vkResetFences, fenceCount*sizeof(VkFence));
    result = mdd(device)->devTable.ResetFences(device, fenceCount, pFences);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkResetFences(pHeader);
    pPacket->device = device;
    pPacket->fenceCount = fenceCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pFences), fenceCount*sizeof(VkFence), pFences);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pFences));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetFenceStatus(
    VkDevice device,
    VkFence fence)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkGetFenceStatus* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetFenceStatus, 0);
    result = mdd(device)->devTable.GetFenceStatus(device, fence);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetFenceStatus(pHeader);
    pPacket->device = device;
    pPacket->fence = fence;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkWaitForFences(
    VkDevice device,
    uint32_t fenceCount,
    const VkFence* pFences,
    VkBool32 waitAll,
    uint64_t timeout)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkWaitForFences* pPacket = NULL;
    CREATE_TRACE_PACKET(vkWaitForFences, fenceCount*sizeof(VkFence));
    result = mdd(device)->devTable.WaitForFences(device, fenceCount, pFences, waitAll, timeout);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkWaitForFences(pHeader);
    pPacket->device = device;
    pPacket->fenceCount = fenceCount;
    pPacket->waitAll = waitAll;
    pPacket->timeout = timeout;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pFences), fenceCount*sizeof(VkFence), pFences);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pFences));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateSemaphore(
    VkDevice device,
    const VkSemaphoreCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSemaphore* pSemaphore)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateSemaphore* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateSemaphore, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkSemaphore));
    result = mdd(device)->devTable.CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateSemaphore(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkSemaphoreCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSemaphore), sizeof(VkSemaphore), pSemaphore);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSemaphore));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySemaphore(
    VkDevice device,
    VkSemaphore semaphore,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroySemaphore* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroySemaphore, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroySemaphore(device, semaphore, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroySemaphore(pHeader);
    pPacket->device = device;
    pPacket->semaphore = semaphore;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateEvent(
    VkDevice device,
    const VkEventCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkEvent* pEvent)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateEvent, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkEvent));
    result = mdd(device)->devTable.CreateEvent(device, pCreateInfo, pAllocator, pEvent);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateEvent(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkEventCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pEvent), sizeof(VkEvent), pEvent);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pEvent));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyEvent(
    VkDevice device,
    VkEvent event,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyEvent, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyEvent(device, event, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyEvent(pHeader);
    pPacket->device = device;
    pPacket->event = event;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetEventStatus(
    VkDevice device,
    VkEvent event)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkGetEventStatus* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetEventStatus, 0);
    result = mdd(device)->devTable.GetEventStatus(device, event);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetEventStatus(pHeader);
    pPacket->device = device;
    pPacket->event = event;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkSetEvent(
    VkDevice device,
    VkEvent event)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkSetEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkSetEvent, 0);
    result = mdd(device)->devTable.SetEvent(device, event);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkSetEvent(pHeader);
    pPacket->device = device;
    pPacket->event = event;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetEvent(
    VkDevice device,
    VkEvent event)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkResetEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkResetEvent, 0);
    result = mdd(device)->devTable.ResetEvent(device, event);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkResetEvent(pHeader);
    pPacket->device = device;
    pPacket->event = event;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateQueryPool(
    VkDevice device,
    const VkQueryPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkQueryPool* pQueryPool)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateQueryPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateQueryPool, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkQueryPool));
    result = mdd(device)->devTable.CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateQueryPool(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkQueryPoolCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pQueryPool), sizeof(VkQueryPool), pQueryPool);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pQueryPool));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyQueryPool(
    VkDevice device,
    VkQueryPool queryPool,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyQueryPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyQueryPool, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyQueryPool(device, queryPool, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyQueryPool(pHeader);
    pPacket->device = device;
    pPacket->queryPool = queryPool;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkGetQueryPoolResults is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateBuffer(
    VkDevice device,
    const VkBufferCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkBuffer* pBuffer)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateBuffer, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkBuffer));
    result = mdd(device)->devTable.CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateBuffer(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkBufferCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pBuffer), sizeof(VkBuffer), pBuffer);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pBuffer));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyBuffer(
    VkDevice device,
    VkBuffer buffer,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyBuffer, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyBuffer(device, buffer, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyBuffer(pHeader);
    pPacket->device = device;
    pPacket->buffer = buffer;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateBufferView(
    VkDevice device,
    const VkBufferViewCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkBufferView* pView)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateBufferView* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateBufferView, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkBufferView));
    result = mdd(device)->devTable.CreateBufferView(device, pCreateInfo, pAllocator, pView);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateBufferView(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkBufferViewCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pView), sizeof(VkBufferView), pView);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pView));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyBufferView(
    VkDevice device,
    VkBufferView bufferView,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyBufferView* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyBufferView, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyBufferView(device, bufferView, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyBufferView(pHeader);
    pPacket->device = device;
    pPacket->bufferView = bufferView;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateImage(
    VkDevice device,
    const VkImageCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImage* pImage)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateImage, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkImage));
    result = mdd(device)->devTable.CreateImage(device, pCreateInfo, pAllocator, pImage);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateImage(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkImageCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pImage), sizeof(VkImage), pImage);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pImage));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyImage(
    VkDevice device,
    VkImage image,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyImage, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyImage(device, image, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyImage(pHeader);
    pPacket->device = device;
    pPacket->image = image;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageSubresourceLayout(
    VkDevice device,
    VkImage image,
    const VkImageSubresource* pSubresource,
    VkSubresourceLayout* pLayout)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetImageSubresourceLayout* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetImageSubresourceLayout, sizeof(VkImageSubresource) + sizeof(VkSubresourceLayout));
    mdd(device)->devTable.GetImageSubresourceLayout(device, image, pSubresource, pLayout);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetImageSubresourceLayout(pHeader);
    pPacket->device = device;
    pPacket->image = image;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSubresource), sizeof(VkImageSubresource), pSubresource);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pLayout), sizeof(VkSubresourceLayout), pLayout);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSubresource));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pLayout));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateImageView(
    VkDevice device,
    const VkImageViewCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImageView* pView)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateImageView* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateImageView, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkImageView));
    result = mdd(device)->devTable.CreateImageView(device, pCreateInfo, pAllocator, pView);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateImageView(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkImageViewCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pView), sizeof(VkImageView), pView);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pView));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyImageView(
    VkDevice device,
    VkImageView imageView,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyImageView* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyImageView, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyImageView(device, imageView, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyImageView(pHeader);
    pPacket->device = device;
    pPacket->imageView = imageView;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateShaderModule(
    VkDevice device,
    const VkShaderModuleCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkShaderModule* pShaderModule)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateShaderModule* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateShaderModule, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkShaderModule));
    result = mdd(device)->devTable.CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateShaderModule(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkShaderModuleCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo->pCode), pPacket->pCreateInfo->codeSize, pCreateInfo->pCode);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pShaderModule), sizeof(VkShaderModule), pShaderModule);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo->pCode));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pShaderModule));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyShaderModule(
    VkDevice device,
    VkShaderModule shaderModule,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyShaderModule* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyShaderModule, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyShaderModule(device, shaderModule, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyShaderModule(pHeader);
    pPacket->device = device;
    pPacket->shaderModule = shaderModule;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkCreatePipelineCache is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipelineCache(
    VkDevice device,
    VkPipelineCache pipelineCache,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyPipelineCache* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyPipelineCache, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyPipelineCache(device, pipelineCache, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyPipelineCache(pHeader);
    pPacket->device = device;
    pPacket->pipelineCache = pipelineCache;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPipelineCacheData(
    VkDevice device,
    VkPipelineCache pipelineCache,
    size_t* pDataSize,
    void* pData)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    size_t _dataSize;
    packet_vkGetPipelineCacheData* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPipelineCacheData, ((pDataSize != NULL) ? sizeof(size_t) : 0) + sizeof(void*));
    result = mdd(device)->devTable.GetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    _dataSize = (pDataSize == NULL || pData == NULL) ? 0 : *pDataSize;
    pPacket = interpret_body_as_vkGetPipelineCacheData(pHeader);
    pPacket->device = device;
    pPacket->pipelineCache = pipelineCache;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pDataSize), sizeof(size_t), &_dataSize);
    //TODO FIXME vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pData), sizeof(void), pData);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pDataSize));
    //TODO FIXME vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pData));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkMergePipelineCaches(
    VkDevice device,
    VkPipelineCache dstCache,
    uint32_t srcCacheCount,
    const VkPipelineCache* pSrcCaches)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkMergePipelineCaches* pPacket = NULL;
    CREATE_TRACE_PACKET(vkMergePipelineCaches, srcCacheCount*sizeof(VkPipelineCache));
    result = mdd(device)->devTable.MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkMergePipelineCaches(pHeader);
    pPacket->device = device;
    pPacket->dstCache = dstCache;
    pPacket->srcCacheCount = srcCacheCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSrcCaches), srcCacheCount*sizeof(VkPipelineCache), pSrcCaches);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSrcCaches));
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkCreateGraphicsPipelines is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCreateComputePipelines is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipeline(
    VkDevice device,
    VkPipeline pipeline,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyPipeline* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyPipeline, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyPipeline(device, pipeline, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyPipeline(pHeader);
    pPacket->device = device;
    pPacket->pipeline = pipeline;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreatePipelineLayout(
    VkDevice device,
    const VkPipelineLayoutCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkPipelineLayout* pPipelineLayout)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreatePipelineLayout* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreatePipelineLayout, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkPipelineLayout));
    result = mdd(device)->devTable.CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreatePipelineLayout(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkPipelineLayoutCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo->pSetLayouts), pCreateInfo->setLayoutCount * sizeof(VkDescriptorSetLayout), pCreateInfo->pSetLayouts);;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pPipelineLayout), sizeof(VkPipelineLayout), pPipelineLayout);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo->pSetLayouts));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pPipelineLayout));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipelineLayout(
    VkDevice device,
    VkPipelineLayout pipelineLayout,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyPipelineLayout* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyPipelineLayout, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyPipelineLayout(device, pipelineLayout, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyPipelineLayout(pHeader);
    pPacket->device = device;
    pPacket->pipelineLayout = pipelineLayout;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateSampler(
    VkDevice device,
    const VkSamplerCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSampler* pSampler)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateSampler* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateSampler, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkSampler));
    result = mdd(device)->devTable.CreateSampler(device, pCreateInfo, pAllocator, pSampler);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateSampler(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkSamplerCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSampler), sizeof(VkSampler), pSampler);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSampler));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySampler(
    VkDevice device,
    VkSampler sampler,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroySampler* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroySampler, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroySampler(device, sampler, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroySampler(pHeader);
    pPacket->device = device;
    pPacket->sampler = sampler;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateDescriptorSetLayout(
    VkDevice device,
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDescriptorSetLayout* pSetLayout)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateDescriptorSetLayout* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateDescriptorSetLayout, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkDescriptorSetLayout));
    result = mdd(device)->devTable.CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateDescriptorSetLayout(pHeader);
    pPacket->device = device;
    add_create_ds_layout_to_trace_packet(pHeader, &pPacket->pCreateInfo, pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSetLayout), sizeof(VkDescriptorSetLayout), pSetLayout);
    pPacket->result = result;
    // pCreateInfo finalized in add_create_ds_layout_to_trace_packet;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSetLayout));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDescriptorSetLayout(
    VkDevice device,
    VkDescriptorSetLayout descriptorSetLayout,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyDescriptorSetLayout* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyDescriptorSetLayout, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyDescriptorSetLayout(pHeader);
    pPacket->device = device;
    pPacket->descriptorSetLayout = descriptorSetLayout;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkCreateDescriptorPool is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDescriptorPool(
    VkDevice device,
    VkDescriptorPool descriptorPool,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyDescriptorPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyDescriptorPool, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyDescriptorPool(device, descriptorPool, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyDescriptorPool(pHeader);
    pPacket->device = device;
    pPacket->descriptorPool = descriptorPool;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetDescriptorPool(
    VkDevice device,
    VkDescriptorPool descriptorPool,
    VkDescriptorPoolResetFlags flags)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkResetDescriptorPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkResetDescriptorPool, 0);
    result = mdd(device)->devTable.ResetDescriptorPool(device, descriptorPool, flags);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkResetDescriptorPool(pHeader);
    pPacket->device = device;
    pPacket->descriptorPool = descriptorPool;
    pPacket->flags = flags;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkAllocateDescriptorSets is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkFreeDescriptorSets is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkUpdateDescriptorSets is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCreateFramebuffer is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyFramebuffer(
    VkDevice device,
    VkFramebuffer framebuffer,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyFramebuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyFramebuffer, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyFramebuffer(device, framebuffer, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyFramebuffer(pHeader);
    pPacket->device = device;
    pPacket->framebuffer = framebuffer;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkCreateRenderPass is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyRenderPass(
    VkDevice device,
    VkRenderPass renderPass,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyRenderPass* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyRenderPass, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyRenderPass(device, renderPass, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyRenderPass(pHeader);
    pPacket->device = device;
    pPacket->renderPass = renderPass;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetRenderAreaGranularity(
    VkDevice device,
    VkRenderPass renderPass,
    VkExtent2D* pGranularity)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkGetRenderAreaGranularity* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetRenderAreaGranularity, sizeof(VkExtent2D));
    mdd(device)->devTable.GetRenderAreaGranularity(device, renderPass, pGranularity);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetRenderAreaGranularity(pHeader);
    pPacket->device = device;
    pPacket->renderPass = renderPass;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pGranularity), sizeof(VkExtent2D), pGranularity);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pGranularity));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateCommandPool(
    VkDevice device,
    const VkCommandPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkCommandPool* pCommandPool)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateCommandPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateCommandPool, get_struct_chain_size((void*)pCreateInfo) + sizeof(VkAllocationCallbacks) + sizeof(VkCommandPool));
    result = mdd(device)->devTable.CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateCommandPool(pHeader);
    pPacket->device = device;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkCommandPoolCreateInfo), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCommandPool), sizeof(VkCommandPool), pCommandPool);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCommandPool));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyCommandPool(
    VkDevice device,
    VkCommandPool commandPool,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyCommandPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyCommandPool, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroyCommandPool(device, commandPool, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyCommandPool(pHeader);
    pPacket->device = device;
    pPacket->commandPool = commandPool;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetCommandPool(
    VkDevice device,
    VkCommandPool commandPool,
    VkCommandPoolResetFlags flags)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkResetCommandPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkResetCommandPool, 0);
    result = mdd(device)->devTable.ResetCommandPool(device, commandPool, flags);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkResetCommandPool(pHeader);
    pPacket->device = device;
    pPacket->commandPool = commandPool;
    pPacket->flags = flags;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkAllocateCommandBuffers is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkFreeCommandBuffers(
    VkDevice device,
    VkCommandPool commandPool,
    uint32_t commandBufferCount,
    const VkCommandBuffer* pCommandBuffers)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkFreeCommandBuffers* pPacket = NULL;
    CREATE_TRACE_PACKET(vkFreeCommandBuffers, commandBufferCount*sizeof(VkCommandBuffer));
    mdd(device)->devTable.FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkFreeCommandBuffers(pHeader);
    pPacket->device = device;
    pPacket->commandPool = commandPool;
    pPacket->commandBufferCount = commandBufferCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCommandBuffers), commandBufferCount*sizeof(VkCommandBuffer), pCommandBuffers);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCommandBuffers));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkBeginCommandBuffer is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEndCommandBuffer(
    VkCommandBuffer commandBuffer)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkEndCommandBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkEndCommandBuffer, 0);
    result = mdd(commandBuffer)->devTable.EndCommandBuffer(commandBuffer);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkEndCommandBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetCommandBuffer(
    VkCommandBuffer commandBuffer,
    VkCommandBufferResetFlags flags)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkResetCommandBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkResetCommandBuffer, 0);
    result = mdd(commandBuffer)->devTable.ResetCommandBuffer(commandBuffer, flags);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkResetCommandBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->flags = flags;
    pPacket->result = result;
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindPipeline(
    VkCommandBuffer commandBuffer,
    VkPipelineBindPoint pipelineBindPoint,
    VkPipeline pipeline)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBindPipeline* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBindPipeline, 0);
    mdd(commandBuffer)->devTable.CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBindPipeline(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->pipelineBindPoint = pipelineBindPoint;
    pPacket->pipeline = pipeline;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetViewport(
    VkCommandBuffer commandBuffer,
    uint32_t firstViewport,
    uint32_t viewportCount,
    const VkViewport* pViewports)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetViewport* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetViewport, viewportCount*sizeof(VkViewport));
    mdd(commandBuffer)->devTable.CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetViewport(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->firstViewport = firstViewport;
    pPacket->viewportCount = viewportCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pViewports), viewportCount*sizeof(VkViewport), pViewports);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pViewports));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetScissor(
    VkCommandBuffer commandBuffer,
    uint32_t firstScissor,
    uint32_t scissorCount,
    const VkRect2D* pScissors)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetScissor* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetScissor, scissorCount*sizeof(VkRect2D));
    mdd(commandBuffer)->devTable.CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetScissor(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->firstScissor = firstScissor;
    pPacket->scissorCount = scissorCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pScissors), scissorCount*sizeof(VkRect2D), pScissors);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pScissors));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetLineWidth(
    VkCommandBuffer commandBuffer,
    float lineWidth)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetLineWidth* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetLineWidth, 0);
    mdd(commandBuffer)->devTable.CmdSetLineWidth(commandBuffer, lineWidth);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetLineWidth(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->lineWidth = lineWidth;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetDepthBias(
    VkCommandBuffer commandBuffer,
    float depthBiasConstantFactor,
    float depthBiasClamp,
    float depthBiasSlopeFactor)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetDepthBias* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetDepthBias, 0);
    mdd(commandBuffer)->devTable.CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetDepthBias(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->depthBiasConstantFactor = depthBiasConstantFactor;
    pPacket->depthBiasClamp = depthBiasClamp;
    pPacket->depthBiasSlopeFactor = depthBiasSlopeFactor;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetBlendConstants(
    VkCommandBuffer commandBuffer,
    const float blendConstants[4])
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetBlendConstants* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetBlendConstants, 0);
    mdd(commandBuffer)->devTable.CmdSetBlendConstants(commandBuffer, blendConstants);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetBlendConstants(pHeader);
    pPacket->commandBuffer = commandBuffer;
    memcpy((void *) pPacket->blendConstants, blendConstants, sizeof(pPacket->blendConstants));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetDepthBounds(
    VkCommandBuffer commandBuffer,
    float minDepthBounds,
    float maxDepthBounds)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetDepthBounds* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetDepthBounds, 0);
    mdd(commandBuffer)->devTable.CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetDepthBounds(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->minDepthBounds = minDepthBounds;
    pPacket->maxDepthBounds = maxDepthBounds;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilCompareMask(
    VkCommandBuffer commandBuffer,
    VkStencilFaceFlags faceMask,
    uint32_t compareMask)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetStencilCompareMask* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetStencilCompareMask, 0);
    mdd(commandBuffer)->devTable.CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetStencilCompareMask(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->faceMask = faceMask;
    pPacket->compareMask = compareMask;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilWriteMask(
    VkCommandBuffer commandBuffer,
    VkStencilFaceFlags faceMask,
    uint32_t writeMask)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetStencilWriteMask* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetStencilWriteMask, 0);
    mdd(commandBuffer)->devTable.CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetStencilWriteMask(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->faceMask = faceMask;
    pPacket->writeMask = writeMask;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilReference(
    VkCommandBuffer commandBuffer,
    VkStencilFaceFlags faceMask,
    uint32_t reference)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetStencilReference* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetStencilReference, 0);
    mdd(commandBuffer)->devTable.CmdSetStencilReference(commandBuffer, faceMask, reference);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetStencilReference(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->faceMask = faceMask;
    pPacket->reference = reference;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindDescriptorSets(
    VkCommandBuffer commandBuffer,
    VkPipelineBindPoint pipelineBindPoint,
    VkPipelineLayout layout,
    uint32_t firstSet,
    uint32_t descriptorSetCount,
    const VkDescriptorSet* pDescriptorSets,
    uint32_t dynamicOffsetCount,
    const uint32_t* pDynamicOffsets)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBindDescriptorSets* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBindDescriptorSets, descriptorSetCount*sizeof(VkDescriptorSet) + dynamicOffsetCount*sizeof(uint32_t));
    mdd(commandBuffer)->devTable.CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBindDescriptorSets(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->pipelineBindPoint = pipelineBindPoint;
    pPacket->layout = layout;
    pPacket->firstSet = firstSet;
    pPacket->descriptorSetCount = descriptorSetCount;
    pPacket->dynamicOffsetCount = dynamicOffsetCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pDescriptorSets), descriptorSetCount*sizeof(VkDescriptorSet), pDescriptorSets);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pDynamicOffsets), dynamicOffsetCount*sizeof(uint32_t), pDynamicOffsets);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pDescriptorSets));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pDynamicOffsets));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindIndexBuffer(
    VkCommandBuffer commandBuffer,
    VkBuffer buffer,
    VkDeviceSize offset,
    VkIndexType indexType)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBindIndexBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBindIndexBuffer, 0);
    mdd(commandBuffer)->devTable.CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBindIndexBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->buffer = buffer;
    pPacket->offset = offset;
    pPacket->indexType = indexType;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindVertexBuffers(
    VkCommandBuffer commandBuffer,
    uint32_t firstBinding,
    uint32_t bindingCount,
    const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBindVertexBuffers* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBindVertexBuffers, bindingCount*sizeof(VkBuffer) + bindingCount*sizeof(VkDeviceSize));
    mdd(commandBuffer)->devTable.CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBindVertexBuffers(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->firstBinding = firstBinding;
    pPacket->bindingCount = bindingCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pBuffers), bindingCount*sizeof(VkBuffer), pBuffers);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pOffsets), bindingCount*sizeof(VkDeviceSize), pOffsets);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pBuffers));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pOffsets));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDraw(
    VkCommandBuffer commandBuffer,
    uint32_t vertexCount,
    uint32_t instanceCount,
    uint32_t firstVertex,
    uint32_t firstInstance)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDraw* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDraw, 0);
    mdd(commandBuffer)->devTable.CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDraw(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->vertexCount = vertexCount;
    pPacket->instanceCount = instanceCount;
    pPacket->firstVertex = firstVertex;
    pPacket->firstInstance = firstInstance;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndexed(
    VkCommandBuffer commandBuffer,
    uint32_t indexCount,
    uint32_t instanceCount,
    uint32_t firstIndex,
    int32_t vertexOffset,
    uint32_t firstInstance)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDrawIndexed* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDrawIndexed, 0);
    mdd(commandBuffer)->devTable.CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDrawIndexed(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->indexCount = indexCount;
    pPacket->instanceCount = instanceCount;
    pPacket->firstIndex = firstIndex;
    pPacket->vertexOffset = vertexOffset;
    pPacket->firstInstance = firstInstance;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndirect(
    VkCommandBuffer commandBuffer,
    VkBuffer buffer,
    VkDeviceSize offset,
    uint32_t drawCount,
    uint32_t stride)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDrawIndirect* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDrawIndirect, 0);
    mdd(commandBuffer)->devTable.CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDrawIndirect(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->buffer = buffer;
    pPacket->offset = offset;
    pPacket->drawCount = drawCount;
    pPacket->stride = stride;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndexedIndirect(
    VkCommandBuffer commandBuffer,
    VkBuffer buffer,
    VkDeviceSize offset,
    uint32_t drawCount,
    uint32_t stride)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDrawIndexedIndirect* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDrawIndexedIndirect, 0);
    mdd(commandBuffer)->devTable.CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDrawIndexedIndirect(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->buffer = buffer;
    pPacket->offset = offset;
    pPacket->drawCount = drawCount;
    pPacket->stride = stride;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDispatch(
    VkCommandBuffer commandBuffer,
    uint32_t x,
    uint32_t y,
    uint32_t z)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDispatch* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDispatch, 0);
    mdd(commandBuffer)->devTable.CmdDispatch(commandBuffer, x, y, z);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDispatch(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->x = x;
    pPacket->y = y;
    pPacket->z = z;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDispatchIndirect(
    VkCommandBuffer commandBuffer,
    VkBuffer buffer,
    VkDeviceSize offset)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdDispatchIndirect* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdDispatchIndirect, 0);
    mdd(commandBuffer)->devTable.CmdDispatchIndirect(commandBuffer, buffer, offset);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdDispatchIndirect(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->buffer = buffer;
    pPacket->offset = offset;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyBuffer(
    VkCommandBuffer commandBuffer,
    VkBuffer srcBuffer,
    VkBuffer dstBuffer,
    uint32_t regionCount,
    const VkBufferCopy* pRegions)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdCopyBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdCopyBuffer, regionCount*sizeof(VkBufferCopy));
    mdd(commandBuffer)->devTable.CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdCopyBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcBuffer = srcBuffer;
    pPacket->dstBuffer = dstBuffer;
    pPacket->regionCount = regionCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkBufferCopy), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyImage(
    VkCommandBuffer commandBuffer,
    VkImage srcImage,
    VkImageLayout srcImageLayout,
    VkImage dstImage,
    VkImageLayout dstImageLayout,
    uint32_t regionCount,
    const VkImageCopy* pRegions)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdCopyImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdCopyImage, regionCount*sizeof(VkImageCopy));
    mdd(commandBuffer)->devTable.CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdCopyImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcImage = srcImage;
    pPacket->srcImageLayout = srcImageLayout;
    pPacket->dstImage = dstImage;
    pPacket->dstImageLayout = dstImageLayout;
    pPacket->regionCount = regionCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkImageCopy), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBlitImage(
    VkCommandBuffer commandBuffer,
    VkImage srcImage,
    VkImageLayout srcImageLayout,
    VkImage dstImage,
    VkImageLayout dstImageLayout,
    uint32_t regionCount,
    const VkImageBlit* pRegions,
    VkFilter filter)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBlitImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBlitImage, regionCount*sizeof(VkImageBlit));
    mdd(commandBuffer)->devTable.CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBlitImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcImage = srcImage;
    pPacket->srcImageLayout = srcImageLayout;
    pPacket->dstImage = dstImage;
    pPacket->dstImageLayout = dstImageLayout;
    pPacket->regionCount = regionCount;
    pPacket->filter = filter;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkImageBlit), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyBufferToImage(
    VkCommandBuffer commandBuffer,
    VkBuffer srcBuffer,
    VkImage dstImage,
    VkImageLayout dstImageLayout,
    uint32_t regionCount,
    const VkBufferImageCopy* pRegions)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdCopyBufferToImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdCopyBufferToImage, regionCount*sizeof(VkBufferImageCopy));
    mdd(commandBuffer)->devTable.CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdCopyBufferToImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcBuffer = srcBuffer;
    pPacket->dstImage = dstImage;
    pPacket->dstImageLayout = dstImageLayout;
    pPacket->regionCount = regionCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkBufferImageCopy), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyImageToBuffer(
    VkCommandBuffer commandBuffer,
    VkImage srcImage,
    VkImageLayout srcImageLayout,
    VkBuffer dstBuffer,
    uint32_t regionCount,
    const VkBufferImageCopy* pRegions)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdCopyImageToBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdCopyImageToBuffer, regionCount*sizeof(VkBufferImageCopy));
    mdd(commandBuffer)->devTable.CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdCopyImageToBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcImage = srcImage;
    pPacket->srcImageLayout = srcImageLayout;
    pPacket->dstBuffer = dstBuffer;
    pPacket->regionCount = regionCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkBufferImageCopy), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdUpdateBuffer(
    VkCommandBuffer commandBuffer,
    VkBuffer dstBuffer,
    VkDeviceSize dstOffset,
    VkDeviceSize dataSize,
    const uint32_t* pData)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdUpdateBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdUpdateBuffer, dataSize);
    mdd(commandBuffer)->devTable.CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdUpdateBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->dstBuffer = dstBuffer;
    pPacket->dstOffset = dstOffset;
    pPacket->dataSize = dataSize;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pData), sizeof(uint32_t), pData);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pData));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdFillBuffer(
    VkCommandBuffer commandBuffer,
    VkBuffer dstBuffer,
    VkDeviceSize dstOffset,
    VkDeviceSize size,
    uint32_t data)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdFillBuffer* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdFillBuffer, 0);
    mdd(commandBuffer)->devTable.CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdFillBuffer(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->dstBuffer = dstBuffer;
    pPacket->dstOffset = dstOffset;
    pPacket->size = size;
    pPacket->data = data;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearColorImage(
    VkCommandBuffer commandBuffer,
    VkImage image,
    VkImageLayout imageLayout,
    const VkClearColorValue* pColor,
    uint32_t rangeCount,
    const VkImageSubresourceRange* pRanges)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdClearColorImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdClearColorImage, sizeof(VkClearColorValue) + rangeCount*sizeof(VkImageSubresourceRange));
    mdd(commandBuffer)->devTable.CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdClearColorImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->image = image;
    pPacket->imageLayout = imageLayout;
    pPacket->rangeCount = rangeCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pColor), sizeof(VkClearColorValue), pColor);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRanges), rangeCount*sizeof(VkImageSubresourceRange), pRanges);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pColor));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRanges));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearDepthStencilImage(
    VkCommandBuffer commandBuffer,
    VkImage image,
    VkImageLayout imageLayout,
    const VkClearDepthStencilValue* pDepthStencil,
    uint32_t rangeCount,
    const VkImageSubresourceRange* pRanges)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdClearDepthStencilImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdClearDepthStencilImage, sizeof(VkClearDepthStencilValue) + rangeCount*sizeof(VkImageSubresourceRange));
    mdd(commandBuffer)->devTable.CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdClearDepthStencilImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->image = image;
    pPacket->imageLayout = imageLayout;
    pPacket->rangeCount = rangeCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pDepthStencil), sizeof(VkClearDepthStencilValue), pDepthStencil);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRanges), rangeCount*sizeof(VkImageSubresourceRange), pRanges);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pDepthStencil));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRanges));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearAttachments(
    VkCommandBuffer commandBuffer,
    uint32_t attachmentCount,
    const VkClearAttachment* pAttachments,
    uint32_t rectCount,
    const VkClearRect* pRects)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdClearAttachments* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdClearAttachments, attachmentCount*sizeof(VkClearAttachment) + rectCount*sizeof(VkClearRect));
    mdd(commandBuffer)->devTable.CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdClearAttachments(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->attachmentCount = attachmentCount;
    pPacket->rectCount = rectCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAttachments), attachmentCount*sizeof(VkClearAttachment), pAttachments);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRects), rectCount*sizeof(VkClearRect), pRects);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAttachments));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRects));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResolveImage(
    VkCommandBuffer commandBuffer,
    VkImage srcImage,
    VkImageLayout srcImageLayout,
    VkImage dstImage,
    VkImageLayout dstImageLayout,
    uint32_t regionCount,
    const VkImageResolve* pRegions)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdResolveImage* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdResolveImage, regionCount*sizeof(VkImageResolve));
    mdd(commandBuffer)->devTable.CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdResolveImage(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->srcImage = srcImage;
    pPacket->srcImageLayout = srcImageLayout;
    pPacket->dstImage = dstImage;
    pPacket->dstImageLayout = dstImageLayout;
    pPacket->regionCount = regionCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pRegions), regionCount*sizeof(VkImageResolve), pRegions);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pRegions));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetEvent(
    VkCommandBuffer commandBuffer,
    VkEvent event,
    VkPipelineStageFlags stageMask)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdSetEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdSetEvent, 0);
    mdd(commandBuffer)->devTable.CmdSetEvent(commandBuffer, event, stageMask);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdSetEvent(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->event = event;
    pPacket->stageMask = stageMask;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResetEvent(
    VkCommandBuffer commandBuffer,
    VkEvent event,
    VkPipelineStageFlags stageMask)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdResetEvent* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdResetEvent, 0);
    mdd(commandBuffer)->devTable.CmdResetEvent(commandBuffer, event, stageMask);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdResetEvent(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->event = event;
    pPacket->stageMask = stageMask;
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkCmdWaitEvents is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCmdPipelineBarrier is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBeginQuery(
    VkCommandBuffer commandBuffer,
    VkQueryPool queryPool,
    uint32_t query,
    VkQueryControlFlags flags)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdBeginQuery* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdBeginQuery, 0);
    mdd(commandBuffer)->devTable.CmdBeginQuery(commandBuffer, queryPool, query, flags);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdBeginQuery(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->queryPool = queryPool;
    pPacket->query = query;
    pPacket->flags = flags;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdEndQuery(
    VkCommandBuffer commandBuffer,
    VkQueryPool queryPool,
    uint32_t query)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdEndQuery* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdEndQuery, 0);
    mdd(commandBuffer)->devTable.CmdEndQuery(commandBuffer, queryPool, query);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdEndQuery(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->queryPool = queryPool;
    pPacket->query = query;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResetQueryPool(
    VkCommandBuffer commandBuffer,
    VkQueryPool queryPool,
    uint32_t firstQuery,
    uint32_t queryCount)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdResetQueryPool* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdResetQueryPool, 0);
    mdd(commandBuffer)->devTable.CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdResetQueryPool(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->queryPool = queryPool;
    pPacket->firstQuery = firstQuery;
    pPacket->queryCount = queryCount;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdWriteTimestamp(
    VkCommandBuffer commandBuffer,
    VkPipelineStageFlagBits pipelineStage,
    VkQueryPool queryPool,
    uint32_t query)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdWriteTimestamp* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdWriteTimestamp, 0);
    mdd(commandBuffer)->devTable.CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdWriteTimestamp(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->pipelineStage = pipelineStage;
    pPacket->queryPool = queryPool;
    pPacket->query = query;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyQueryPoolResults(
    VkCommandBuffer commandBuffer,
    VkQueryPool queryPool,
    uint32_t firstQuery,
    uint32_t queryCount,
    VkBuffer dstBuffer,
    VkDeviceSize dstOffset,
    VkDeviceSize stride,
    VkQueryResultFlags flags)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdCopyQueryPoolResults* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdCopyQueryPoolResults, 0);
    mdd(commandBuffer)->devTable.CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdCopyQueryPoolResults(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->queryPool = queryPool;
    pPacket->firstQuery = firstQuery;
    pPacket->queryCount = queryCount;
    pPacket->dstBuffer = dstBuffer;
    pPacket->dstOffset = dstOffset;
    pPacket->stride = stride;
    pPacket->flags = flags;
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkCmdPushConstants is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCmdBeginRenderPass is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdNextSubpass(
    VkCommandBuffer commandBuffer,
    VkSubpassContents contents)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdNextSubpass* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdNextSubpass, 0);
    mdd(commandBuffer)->devTable.CmdNextSubpass(commandBuffer, contents);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdNextSubpass(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->contents = contents;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdEndRenderPass(
    VkCommandBuffer commandBuffer)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdEndRenderPass* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdEndRenderPass, 0);
    mdd(commandBuffer)->devTable.CmdEndRenderPass(commandBuffer);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdEndRenderPass(pHeader);
    pPacket->commandBuffer = commandBuffer;
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdExecuteCommands(
    VkCommandBuffer commandBuffer,
    uint32_t commandBufferCount,
    const VkCommandBuffer* pCommandBuffers)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkCmdExecuteCommands* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCmdExecuteCommands, commandBufferCount*sizeof(VkCommandBuffer));
    mdd(commandBuffer)->devTable.CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCmdExecuteCommands(pHeader);
    pPacket->commandBuffer = commandBuffer;
    pPacket->commandBufferCount = commandBufferCount;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCommandBuffers), commandBufferCount*sizeof(VkCommandBuffer), pCommandBuffers);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCommandBuffers));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySurfaceKHR(
    VkInstance instance,
    VkSurfaceKHR surface,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroySurfaceKHR* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroySurfaceKHR, sizeof(VkAllocationCallbacks));
    mid(instance)->instTable.DestroySurfaceKHR(instance, surface, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroySurfaceKHR(pHeader);
    pPacket->instance = instance;
    pPacket->surface = surface;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice physicalDevice,
    uint32_t queueFamilyIndex,
    VkSurfaceKHR surface,
    VkBool32* pSupported)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkGetPhysicalDeviceSurfaceSupportKHR* pPacket = NULL;
    CREATE_TRACE_PACKET(vkGetPhysicalDeviceSurfaceSupportKHR, sizeof(VkBool32));
    result = mid(physicalDevice)->instTable.GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkGetPhysicalDeviceSurfaceSupportKHR(pHeader);
    pPacket->physicalDevice = physicalDevice;
    pPacket->queueFamilyIndex = queueFamilyIndex;
    pPacket->surface = surface;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pSupported), sizeof(VkBool32), pSupported);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pSupported));
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkGetPhysicalDeviceSurfaceCapabilitiesKHR is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkGetPhysicalDeviceSurfaceFormatsKHR is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkGetPhysicalDeviceSurfacePresentModesKHR is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCreateSwapchainKHR is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySwapchainKHR(
    VkDevice device,
    VkSwapchainKHR swapchain,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroySwapchainKHR* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroySwapchainKHR, sizeof(VkAllocationCallbacks));
    mdd(device)->devTable.DestroySwapchainKHR(device, swapchain, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroySwapchainKHR(pHeader);
    pPacket->device = device;
    pPacket->swapchain = swapchain;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// __HOOKED_vkGetSwapchainImagesKHR is manually written. Look in vktrace_lib_trace.cpp

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkAcquireNextImageKHR(
    VkDevice device,
    VkSwapchainKHR swapchain,
    uint64_t timeout,
    VkSemaphore semaphore,
    VkFence fence,
    uint32_t* pImageIndex)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkAcquireNextImageKHR* pPacket = NULL;
    CREATE_TRACE_PACKET(vkAcquireNextImageKHR, sizeof(uint32_t));
    result = mdd(device)->devTable.AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkAcquireNextImageKHR(pHeader);
    pPacket->device = device;
    pPacket->swapchain = swapchain;
    pPacket->timeout = timeout;
    pPacket->semaphore = semaphore;
    pPacket->fence = fence;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pImageIndex), sizeof(uint32_t), pImageIndex);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pImageIndex));
    FINISH_TRACE_PACKET();
    return result;
}

// __HOOKED_vkQueuePresentKHR is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkCreateXcbSurfaceKHR is manually written. Look in vktrace_lib_trace.cpp

// __HOOKED_vkGetPhysicalDeviceXcbPresentationSupportKHR is manually written. Look in vktrace_lib_trace.cpp

