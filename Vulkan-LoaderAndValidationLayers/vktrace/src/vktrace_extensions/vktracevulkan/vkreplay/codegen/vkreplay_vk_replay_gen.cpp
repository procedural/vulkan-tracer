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

#include "vkreplay_vkreplay.h"

#include "vkreplay.h"

#include "vkreplay_main.h"

#include <algorithm>
#include <queue>


extern "C" {
#include "vktrace_vk_vk_packets.h"
#include "vktrace_vk_vk_ext_debug_report_packets.h"
#include "vktrace_vk_vk_lunarg_debug_marker_packets.h"
#include "vktrace_vk_packet_id.h"

void vkFuncs::init_funcs(void * handle)
{
    m_libHandle = handle;
    real_vkCreateInstance = (type_vkCreateInstance)(vktrace_platform_get_library_entrypoint(handle, "vkCreateInstance"));
    real_vkDestroyInstance = (type_vkDestroyInstance)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyInstance"));
    real_vkEnumeratePhysicalDevices = (type_vkEnumeratePhysicalDevices)(vktrace_platform_get_library_entrypoint(handle, "vkEnumeratePhysicalDevices"));
    real_vkGetPhysicalDeviceFeatures = (type_vkGetPhysicalDeviceFeatures)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceFeatures"));
    real_vkGetPhysicalDeviceFormatProperties = (type_vkGetPhysicalDeviceFormatProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceFormatProperties"));
    real_vkGetPhysicalDeviceImageFormatProperties = (type_vkGetPhysicalDeviceImageFormatProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceImageFormatProperties"));
    real_vkGetPhysicalDeviceProperties = (type_vkGetPhysicalDeviceProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceProperties"));
    real_vkGetPhysicalDeviceQueueFamilyProperties = (type_vkGetPhysicalDeviceQueueFamilyProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceQueueFamilyProperties"));
    real_vkGetPhysicalDeviceMemoryProperties = (type_vkGetPhysicalDeviceMemoryProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceMemoryProperties"));
    real_vkGetInstanceProcAddr = (type_vkGetInstanceProcAddr)(vktrace_platform_get_library_entrypoint(handle, "vkGetInstanceProcAddr"));
    real_vkGetDeviceProcAddr = (type_vkGetDeviceProcAddr)(vktrace_platform_get_library_entrypoint(handle, "vkGetDeviceProcAddr"));
    real_vkCreateDevice = (type_vkCreateDevice)(vktrace_platform_get_library_entrypoint(handle, "vkCreateDevice"));
    real_vkDestroyDevice = (type_vkDestroyDevice)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyDevice"));
    real_vkEnumerateInstanceExtensionProperties = (type_vkEnumerateInstanceExtensionProperties)(vktrace_platform_get_library_entrypoint(handle, "vkEnumerateInstanceExtensionProperties"));
    real_vkEnumerateDeviceExtensionProperties = (type_vkEnumerateDeviceExtensionProperties)(vktrace_platform_get_library_entrypoint(handle, "vkEnumerateDeviceExtensionProperties"));
    real_vkEnumerateInstanceLayerProperties = (type_vkEnumerateInstanceLayerProperties)(vktrace_platform_get_library_entrypoint(handle, "vkEnumerateInstanceLayerProperties"));
    real_vkEnumerateDeviceLayerProperties = (type_vkEnumerateDeviceLayerProperties)(vktrace_platform_get_library_entrypoint(handle, "vkEnumerateDeviceLayerProperties"));
    real_vkGetDeviceQueue = (type_vkGetDeviceQueue)(vktrace_platform_get_library_entrypoint(handle, "vkGetDeviceQueue"));
    real_vkQueueSubmit = (type_vkQueueSubmit)(vktrace_platform_get_library_entrypoint(handle, "vkQueueSubmit"));
    real_vkQueueWaitIdle = (type_vkQueueWaitIdle)(vktrace_platform_get_library_entrypoint(handle, "vkQueueWaitIdle"));
    real_vkDeviceWaitIdle = (type_vkDeviceWaitIdle)(vktrace_platform_get_library_entrypoint(handle, "vkDeviceWaitIdle"));
    real_vkAllocateMemory = (type_vkAllocateMemory)(vktrace_platform_get_library_entrypoint(handle, "vkAllocateMemory"));
    real_vkFreeMemory = (type_vkFreeMemory)(vktrace_platform_get_library_entrypoint(handle, "vkFreeMemory"));
    real_vkMapMemory = (type_vkMapMemory)(vktrace_platform_get_library_entrypoint(handle, "vkMapMemory"));
    real_vkUnmapMemory = (type_vkUnmapMemory)(vktrace_platform_get_library_entrypoint(handle, "vkUnmapMemory"));
    real_vkFlushMappedMemoryRanges = (type_vkFlushMappedMemoryRanges)(vktrace_platform_get_library_entrypoint(handle, "vkFlushMappedMemoryRanges"));
    real_vkInvalidateMappedMemoryRanges = (type_vkInvalidateMappedMemoryRanges)(vktrace_platform_get_library_entrypoint(handle, "vkInvalidateMappedMemoryRanges"));
    real_vkGetDeviceMemoryCommitment = (type_vkGetDeviceMemoryCommitment)(vktrace_platform_get_library_entrypoint(handle, "vkGetDeviceMemoryCommitment"));
    real_vkBindBufferMemory = (type_vkBindBufferMemory)(vktrace_platform_get_library_entrypoint(handle, "vkBindBufferMemory"));
    real_vkBindImageMemory = (type_vkBindImageMemory)(vktrace_platform_get_library_entrypoint(handle, "vkBindImageMemory"));
    real_vkGetBufferMemoryRequirements = (type_vkGetBufferMemoryRequirements)(vktrace_platform_get_library_entrypoint(handle, "vkGetBufferMemoryRequirements"));
    real_vkGetImageMemoryRequirements = (type_vkGetImageMemoryRequirements)(vktrace_platform_get_library_entrypoint(handle, "vkGetImageMemoryRequirements"));
    real_vkGetImageSparseMemoryRequirements = (type_vkGetImageSparseMemoryRequirements)(vktrace_platform_get_library_entrypoint(handle, "vkGetImageSparseMemoryRequirements"));
    real_vkGetPhysicalDeviceSparseImageFormatProperties = (type_vkGetPhysicalDeviceSparseImageFormatProperties)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceSparseImageFormatProperties"));
    real_vkQueueBindSparse = (type_vkQueueBindSparse)(vktrace_platform_get_library_entrypoint(handle, "vkQueueBindSparse"));
    real_vkCreateFence = (type_vkCreateFence)(vktrace_platform_get_library_entrypoint(handle, "vkCreateFence"));
    real_vkDestroyFence = (type_vkDestroyFence)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyFence"));
    real_vkResetFences = (type_vkResetFences)(vktrace_platform_get_library_entrypoint(handle, "vkResetFences"));
    real_vkGetFenceStatus = (type_vkGetFenceStatus)(vktrace_platform_get_library_entrypoint(handle, "vkGetFenceStatus"));
    real_vkWaitForFences = (type_vkWaitForFences)(vktrace_platform_get_library_entrypoint(handle, "vkWaitForFences"));
    real_vkCreateSemaphore = (type_vkCreateSemaphore)(vktrace_platform_get_library_entrypoint(handle, "vkCreateSemaphore"));
    real_vkDestroySemaphore = (type_vkDestroySemaphore)(vktrace_platform_get_library_entrypoint(handle, "vkDestroySemaphore"));
    real_vkCreateEvent = (type_vkCreateEvent)(vktrace_platform_get_library_entrypoint(handle, "vkCreateEvent"));
    real_vkDestroyEvent = (type_vkDestroyEvent)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyEvent"));
    real_vkGetEventStatus = (type_vkGetEventStatus)(vktrace_platform_get_library_entrypoint(handle, "vkGetEventStatus"));
    real_vkSetEvent = (type_vkSetEvent)(vktrace_platform_get_library_entrypoint(handle, "vkSetEvent"));
    real_vkResetEvent = (type_vkResetEvent)(vktrace_platform_get_library_entrypoint(handle, "vkResetEvent"));
    real_vkCreateQueryPool = (type_vkCreateQueryPool)(vktrace_platform_get_library_entrypoint(handle, "vkCreateQueryPool"));
    real_vkDestroyQueryPool = (type_vkDestroyQueryPool)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyQueryPool"));
    real_vkGetQueryPoolResults = (type_vkGetQueryPoolResults)(vktrace_platform_get_library_entrypoint(handle, "vkGetQueryPoolResults"));
    real_vkCreateBuffer = (type_vkCreateBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCreateBuffer"));
    real_vkDestroyBuffer = (type_vkDestroyBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyBuffer"));
    real_vkCreateBufferView = (type_vkCreateBufferView)(vktrace_platform_get_library_entrypoint(handle, "vkCreateBufferView"));
    real_vkDestroyBufferView = (type_vkDestroyBufferView)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyBufferView"));
    real_vkCreateImage = (type_vkCreateImage)(vktrace_platform_get_library_entrypoint(handle, "vkCreateImage"));
    real_vkDestroyImage = (type_vkDestroyImage)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyImage"));
    real_vkGetImageSubresourceLayout = (type_vkGetImageSubresourceLayout)(vktrace_platform_get_library_entrypoint(handle, "vkGetImageSubresourceLayout"));
    real_vkCreateImageView = (type_vkCreateImageView)(vktrace_platform_get_library_entrypoint(handle, "vkCreateImageView"));
    real_vkDestroyImageView = (type_vkDestroyImageView)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyImageView"));
    real_vkCreateShaderModule = (type_vkCreateShaderModule)(vktrace_platform_get_library_entrypoint(handle, "vkCreateShaderModule"));
    real_vkDestroyShaderModule = (type_vkDestroyShaderModule)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyShaderModule"));
    real_vkCreatePipelineCache = (type_vkCreatePipelineCache)(vktrace_platform_get_library_entrypoint(handle, "vkCreatePipelineCache"));
    real_vkDestroyPipelineCache = (type_vkDestroyPipelineCache)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyPipelineCache"));
    real_vkGetPipelineCacheData = (type_vkGetPipelineCacheData)(vktrace_platform_get_library_entrypoint(handle, "vkGetPipelineCacheData"));
    real_vkMergePipelineCaches = (type_vkMergePipelineCaches)(vktrace_platform_get_library_entrypoint(handle, "vkMergePipelineCaches"));
    real_vkCreateGraphicsPipelines = (type_vkCreateGraphicsPipelines)(vktrace_platform_get_library_entrypoint(handle, "vkCreateGraphicsPipelines"));
    real_vkCreateComputePipelines = (type_vkCreateComputePipelines)(vktrace_platform_get_library_entrypoint(handle, "vkCreateComputePipelines"));
    real_vkDestroyPipeline = (type_vkDestroyPipeline)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyPipeline"));
    real_vkCreatePipelineLayout = (type_vkCreatePipelineLayout)(vktrace_platform_get_library_entrypoint(handle, "vkCreatePipelineLayout"));
    real_vkDestroyPipelineLayout = (type_vkDestroyPipelineLayout)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyPipelineLayout"));
    real_vkCreateSampler = (type_vkCreateSampler)(vktrace_platform_get_library_entrypoint(handle, "vkCreateSampler"));
    real_vkDestroySampler = (type_vkDestroySampler)(vktrace_platform_get_library_entrypoint(handle, "vkDestroySampler"));
    real_vkCreateDescriptorSetLayout = (type_vkCreateDescriptorSetLayout)(vktrace_platform_get_library_entrypoint(handle, "vkCreateDescriptorSetLayout"));
    real_vkDestroyDescriptorSetLayout = (type_vkDestroyDescriptorSetLayout)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyDescriptorSetLayout"));
    real_vkCreateDescriptorPool = (type_vkCreateDescriptorPool)(vktrace_platform_get_library_entrypoint(handle, "vkCreateDescriptorPool"));
    real_vkDestroyDescriptorPool = (type_vkDestroyDescriptorPool)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyDescriptorPool"));
    real_vkResetDescriptorPool = (type_vkResetDescriptorPool)(vktrace_platform_get_library_entrypoint(handle, "vkResetDescriptorPool"));
    real_vkAllocateDescriptorSets = (type_vkAllocateDescriptorSets)(vktrace_platform_get_library_entrypoint(handle, "vkAllocateDescriptorSets"));
    real_vkFreeDescriptorSets = (type_vkFreeDescriptorSets)(vktrace_platform_get_library_entrypoint(handle, "vkFreeDescriptorSets"));
    real_vkUpdateDescriptorSets = (type_vkUpdateDescriptorSets)(vktrace_platform_get_library_entrypoint(handle, "vkUpdateDescriptorSets"));
    real_vkCreateFramebuffer = (type_vkCreateFramebuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCreateFramebuffer"));
    real_vkDestroyFramebuffer = (type_vkDestroyFramebuffer)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyFramebuffer"));
    real_vkCreateRenderPass = (type_vkCreateRenderPass)(vktrace_platform_get_library_entrypoint(handle, "vkCreateRenderPass"));
    real_vkDestroyRenderPass = (type_vkDestroyRenderPass)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyRenderPass"));
    real_vkGetRenderAreaGranularity = (type_vkGetRenderAreaGranularity)(vktrace_platform_get_library_entrypoint(handle, "vkGetRenderAreaGranularity"));
    real_vkCreateCommandPool = (type_vkCreateCommandPool)(vktrace_platform_get_library_entrypoint(handle, "vkCreateCommandPool"));
    real_vkDestroyCommandPool = (type_vkDestroyCommandPool)(vktrace_platform_get_library_entrypoint(handle, "vkDestroyCommandPool"));
    real_vkResetCommandPool = (type_vkResetCommandPool)(vktrace_platform_get_library_entrypoint(handle, "vkResetCommandPool"));
    real_vkAllocateCommandBuffers = (type_vkAllocateCommandBuffers)(vktrace_platform_get_library_entrypoint(handle, "vkAllocateCommandBuffers"));
    real_vkFreeCommandBuffers = (type_vkFreeCommandBuffers)(vktrace_platform_get_library_entrypoint(handle, "vkFreeCommandBuffers"));
    real_vkBeginCommandBuffer = (type_vkBeginCommandBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkBeginCommandBuffer"));
    real_vkEndCommandBuffer = (type_vkEndCommandBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkEndCommandBuffer"));
    real_vkResetCommandBuffer = (type_vkResetCommandBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkResetCommandBuffer"));
    real_vkCmdBindPipeline = (type_vkCmdBindPipeline)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBindPipeline"));
    real_vkCmdSetViewport = (type_vkCmdSetViewport)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetViewport"));
    real_vkCmdSetScissor = (type_vkCmdSetScissor)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetScissor"));
    real_vkCmdSetLineWidth = (type_vkCmdSetLineWidth)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetLineWidth"));
    real_vkCmdSetDepthBias = (type_vkCmdSetDepthBias)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetDepthBias"));
    real_vkCmdSetBlendConstants = (type_vkCmdSetBlendConstants)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetBlendConstants"));
    real_vkCmdSetDepthBounds = (type_vkCmdSetDepthBounds)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetDepthBounds"));
    real_vkCmdSetStencilCompareMask = (type_vkCmdSetStencilCompareMask)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetStencilCompareMask"));
    real_vkCmdSetStencilWriteMask = (type_vkCmdSetStencilWriteMask)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetStencilWriteMask"));
    real_vkCmdSetStencilReference = (type_vkCmdSetStencilReference)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetStencilReference"));
    real_vkCmdBindDescriptorSets = (type_vkCmdBindDescriptorSets)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBindDescriptorSets"));
    real_vkCmdBindIndexBuffer = (type_vkCmdBindIndexBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBindIndexBuffer"));
    real_vkCmdBindVertexBuffers = (type_vkCmdBindVertexBuffers)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBindVertexBuffers"));
    real_vkCmdDraw = (type_vkCmdDraw)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDraw"));
    real_vkCmdDrawIndexed = (type_vkCmdDrawIndexed)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDrawIndexed"));
    real_vkCmdDrawIndirect = (type_vkCmdDrawIndirect)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDrawIndirect"));
    real_vkCmdDrawIndexedIndirect = (type_vkCmdDrawIndexedIndirect)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDrawIndexedIndirect"));
    real_vkCmdDispatch = (type_vkCmdDispatch)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDispatch"));
    real_vkCmdDispatchIndirect = (type_vkCmdDispatchIndirect)(vktrace_platform_get_library_entrypoint(handle, "vkCmdDispatchIndirect"));
    real_vkCmdCopyBuffer = (type_vkCmdCopyBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCmdCopyBuffer"));
    real_vkCmdCopyImage = (type_vkCmdCopyImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdCopyImage"));
    real_vkCmdBlitImage = (type_vkCmdBlitImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBlitImage"));
    real_vkCmdCopyBufferToImage = (type_vkCmdCopyBufferToImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdCopyBufferToImage"));
    real_vkCmdCopyImageToBuffer = (type_vkCmdCopyImageToBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCmdCopyImageToBuffer"));
    real_vkCmdUpdateBuffer = (type_vkCmdUpdateBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCmdUpdateBuffer"));
    real_vkCmdFillBuffer = (type_vkCmdFillBuffer)(vktrace_platform_get_library_entrypoint(handle, "vkCmdFillBuffer"));
    real_vkCmdClearColorImage = (type_vkCmdClearColorImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdClearColorImage"));
    real_vkCmdClearDepthStencilImage = (type_vkCmdClearDepthStencilImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdClearDepthStencilImage"));
    real_vkCmdClearAttachments = (type_vkCmdClearAttachments)(vktrace_platform_get_library_entrypoint(handle, "vkCmdClearAttachments"));
    real_vkCmdResolveImage = (type_vkCmdResolveImage)(vktrace_platform_get_library_entrypoint(handle, "vkCmdResolveImage"));
    real_vkCmdSetEvent = (type_vkCmdSetEvent)(vktrace_platform_get_library_entrypoint(handle, "vkCmdSetEvent"));
    real_vkCmdResetEvent = (type_vkCmdResetEvent)(vktrace_platform_get_library_entrypoint(handle, "vkCmdResetEvent"));
    real_vkCmdWaitEvents = (type_vkCmdWaitEvents)(vktrace_platform_get_library_entrypoint(handle, "vkCmdWaitEvents"));
    real_vkCmdPipelineBarrier = (type_vkCmdPipelineBarrier)(vktrace_platform_get_library_entrypoint(handle, "vkCmdPipelineBarrier"));
    real_vkCmdBeginQuery = (type_vkCmdBeginQuery)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBeginQuery"));
    real_vkCmdEndQuery = (type_vkCmdEndQuery)(vktrace_platform_get_library_entrypoint(handle, "vkCmdEndQuery"));
    real_vkCmdResetQueryPool = (type_vkCmdResetQueryPool)(vktrace_platform_get_library_entrypoint(handle, "vkCmdResetQueryPool"));
    real_vkCmdWriteTimestamp = (type_vkCmdWriteTimestamp)(vktrace_platform_get_library_entrypoint(handle, "vkCmdWriteTimestamp"));
    real_vkCmdCopyQueryPoolResults = (type_vkCmdCopyQueryPoolResults)(vktrace_platform_get_library_entrypoint(handle, "vkCmdCopyQueryPoolResults"));
    real_vkCmdPushConstants = (type_vkCmdPushConstants)(vktrace_platform_get_library_entrypoint(handle, "vkCmdPushConstants"));
    real_vkCmdBeginRenderPass = (type_vkCmdBeginRenderPass)(vktrace_platform_get_library_entrypoint(handle, "vkCmdBeginRenderPass"));
    real_vkCmdNextSubpass = (type_vkCmdNextSubpass)(vktrace_platform_get_library_entrypoint(handle, "vkCmdNextSubpass"));
    real_vkCmdEndRenderPass = (type_vkCmdEndRenderPass)(vktrace_platform_get_library_entrypoint(handle, "vkCmdEndRenderPass"));
    real_vkCmdExecuteCommands = (type_vkCmdExecuteCommands)(vktrace_platform_get_library_entrypoint(handle, "vkCmdExecuteCommands"));
    real_vkDestroySurfaceKHR = (type_vkDestroySurfaceKHR)(vktrace_platform_get_library_entrypoint(handle, "vkDestroySurfaceKHR"));
    real_vkGetPhysicalDeviceSurfaceSupportKHR = (type_vkGetPhysicalDeviceSurfaceSupportKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceSurfaceSupportKHR"));
    real_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (type_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    real_vkGetPhysicalDeviceSurfaceFormatsKHR = (type_vkGetPhysicalDeviceSurfaceFormatsKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
    real_vkGetPhysicalDeviceSurfacePresentModesKHR = (type_vkGetPhysicalDeviceSurfacePresentModesKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceSurfacePresentModesKHR"));
    real_vkCreateSwapchainKHR = (type_vkCreateSwapchainKHR)(vktrace_platform_get_library_entrypoint(handle, "vkCreateSwapchainKHR"));
    real_vkDestroySwapchainKHR = (type_vkDestroySwapchainKHR)(vktrace_platform_get_library_entrypoint(handle, "vkDestroySwapchainKHR"));
    real_vkGetSwapchainImagesKHR = (type_vkGetSwapchainImagesKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetSwapchainImagesKHR"));
    real_vkAcquireNextImageKHR = (type_vkAcquireNextImageKHR)(vktrace_platform_get_library_entrypoint(handle, "vkAcquireNextImageKHR"));
    real_vkQueuePresentKHR = (type_vkQueuePresentKHR)(vktrace_platform_get_library_entrypoint(handle, "vkQueuePresentKHR"));
    real_vkCreateXcbSurfaceKHR = (type_vkCreateXcbSurfaceKHR)(vktrace_platform_get_library_entrypoint(handle, "vkCreateXcbSurfaceKHR"));
    real_vkGetPhysicalDeviceXcbPresentationSupportKHR = (type_vkGetPhysicalDeviceXcbPresentationSupportKHR)(vktrace_platform_get_library_entrypoint(handle, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));
    real_vkCreateDebugReportCallbackEXT = (type_vkCreateDebugReportCallbackEXT)NULL;
    real_vkDestroyDebugReportCallbackEXT = (type_vkDestroyDebugReportCallbackEXT)NULL;
    real_vkDebugReportMessageEXT = (type_vkDebugReportMessageEXT)NULL;
    real_vkCmdDbgMarkerBegin = (type_vkCmdDbgMarkerBegin)NULL;
    real_vkCmdDbgMarkerEnd = (type_vkCmdDbgMarkerEnd)NULL;
    real_vkDbgSetObjectTag = (type_vkDbgSetObjectTag)NULL;
    real_vkDbgSetObjectName = (type_vkDbgSetObjectName)NULL;
}
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1550
vktrace_replay::VKTRACE_REPLAY_RESULT vkReplay::replay(vktrace_trace_packet_header *packet)
{
    vktrace_replay::VKTRACE_REPLAY_RESULT returnValue = vktrace_replay::VKTRACE_REPLAY_SUCCESS;
    VkResult replayResult = VK_ERROR_VALIDATION_FAILED_EXT;
    switch (packet->packet_id)
    {
        case VKTRACE_TPI_VK_vkApiVersion:
        {
            packet_vkApiVersion* pPacket = (packet_vkApiVersion*)(packet->pBody);
            if (pPacket->version != VK_API_VERSION)
            {
                vktrace_LogError("Trace file is from Vulkan version 0x%x (%u.%u.%u), but the vktrace plugin only supports version 0x%x (%u.%u.%u).", pPacket->version, (pPacket->version & 0xFFC00000) >> 22, (pPacket->version & 0x003FF000) >> 12, (pPacket->version & 0x00000FFF), VK_API_VERSION, (VK_API_VERSION & 0xFFC00000) >> 22, (VK_API_VERSION & 0x003FF000) >> 12, (VK_API_VERSION & 0x00000FFF));
                returnValue = vktrace_replay::VKTRACE_REPLAY_ERROR;
            }
            break;
        }
        case VKTRACE_TPI_VK_vkCreateInstance:
        {
            packet_vkCreateInstance* pPacket = (packet_vkCreateInstance*)(packet->pBody);
            replayResult = manually_replay_vkCreateInstance(pPacket);
            CHECK_RETURN_VALUE(vkCreateInstance);
            if (replayResult == VK_SUCCESS) {
                VkInstance remappedInstance = m_objMapper.remap_instances(*pPacket->pInstance);
                if (remappedInstance == VK_NULL_HANDLE) {
                    returnValue = vktrace_replay::VKTRACE_REPLAY_ERROR;
                    break;
                }
                VkFlags reportFlags = VK_DEBUG_REPORT_INFO_BIT_EXT | VK_DEBUG_REPORT_WARN_BIT_EXT | VK_DEBUG_REPORT_PERF_WARN_BIT_EXT | VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_DEBUG_BIT_EXT;
                PFN_vkCreateDebugReportCallbackEXT callback = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(remappedInstance, "vkCreateDebugReportCallbackEXT");
                if (callback != NULL) {
                    VkDebugReportCallbackCreateInfoEXT dbgCreateInfo;
                    memset(&dbgCreateInfo, 0, sizeof(dbgCreateInfo));
                    dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
                    dbgCreateInfo.flags = reportFlags;
                    dbgCreateInfo.pfnCallback = g_fpDbgMsgCallback;
                    dbgCreateInfo.pUserData = NULL;
                    if (callback(remappedInstance, &dbgCreateInfo, NULL, &m_dbgMsgCallbackObj) != VK_SUCCESS) {
                        vktrace_LogWarning("Failed to register vulkan callback for replayer error handling.");
                        returnValue = vktrace_replay::VKTRACE_REPLAY_ERROR;
                        break;
                    }
                }
            }
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyInstance:
        {
            packet_vkDestroyInstance* pPacket = (packet_vkDestroyInstance*)(packet->pBody);
            VkInstance remappedinstance = m_objMapper.remap_instances(pPacket->instance);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->instance != VK_NULL_HANDLE && remappedinstance == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            if (m_vkFuncs.real_vkDestroyDebugReportCallbackEXT != NULL)
            {
                m_vkFuncs.real_vkDestroyDebugReportCallbackEXT(remappedinstance, m_dbgMsgCallbackObj, pPacket->pAllocator);
            }
            m_vkFuncs.real_vkDestroyInstance(remappedinstance, pPacket->pAllocator);
            if (replayResult == VK_SUCCESS)
            {
                // TODO need to handle multiple instances and only clearing maps within an instance.
                // TODO this only works with a single instance used at any given time.
                m_objMapper.clear_all_map_handles();
            }
            break;
        }
        case VKTRACE_TPI_VK_vkEnumeratePhysicalDevices:
        {
            packet_vkEnumeratePhysicalDevices* pPacket = (packet_vkEnumeratePhysicalDevices*)(packet->pBody);
            replayResult = manually_replay_vkEnumeratePhysicalDevices(pPacket);
            CHECK_RETURN_VALUE(vkEnumeratePhysicalDevices);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceFeatures:
        {
            packet_vkGetPhysicalDeviceFeatures* pPacket = (packet_vkGetPhysicalDeviceFeatures*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pFeatures
            m_vkFuncs.real_vkGetPhysicalDeviceFeatures(remappedphysicalDevice, pPacket->pFeatures);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceFormatProperties:
        {
            packet_vkGetPhysicalDeviceFormatProperties* pPacket = (packet_vkGetPhysicalDeviceFormatProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap format
            // No need to remap pFormatProperties
            m_vkFuncs.real_vkGetPhysicalDeviceFormatProperties(remappedphysicalDevice, pPacket->format, pPacket->pFormatProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceImageFormatProperties:
        {
            packet_vkGetPhysicalDeviceImageFormatProperties* pPacket = (packet_vkGetPhysicalDeviceImageFormatProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap format
            // No need to remap type
            // No need to remap tiling
            // No need to remap usage
            // No need to remap flags
            // No need to remap pImageFormatProperties
            replayResult = m_vkFuncs.real_vkGetPhysicalDeviceImageFormatProperties(remappedphysicalDevice, pPacket->format, pPacket->type, pPacket->tiling, pPacket->usage, pPacket->flags, pPacket->pImageFormatProperties);
            CHECK_RETURN_VALUE(vkGetPhysicalDeviceImageFormatProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceProperties:
        {
            packet_vkGetPhysicalDeviceProperties* pPacket = (packet_vkGetPhysicalDeviceProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pProperties
            m_vkFuncs.real_vkGetPhysicalDeviceProperties(remappedphysicalDevice, pPacket->pProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceQueueFamilyProperties:
        {
            packet_vkGetPhysicalDeviceQueueFamilyProperties* pPacket = (packet_vkGetPhysicalDeviceQueueFamilyProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pQueueFamilyPropertyCount
            // No need to remap pQueueFamilyProperties
            m_vkFuncs.real_vkGetPhysicalDeviceQueueFamilyProperties(remappedphysicalDevice, pPacket->pQueueFamilyPropertyCount, pPacket->pQueueFamilyProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceMemoryProperties:
        {
            packet_vkGetPhysicalDeviceMemoryProperties* pPacket = (packet_vkGetPhysicalDeviceMemoryProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pMemoryProperties
            m_vkFuncs.real_vkGetPhysicalDeviceMemoryProperties(remappedphysicalDevice, pPacket->pMemoryProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetInstanceProcAddr:
        {
            packet_vkGetInstanceProcAddr* pPacket = (packet_vkGetInstanceProcAddr*)(packet->pBody);
            VkInstance remappedinstance = m_objMapper.remap_instances(pPacket->instance);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->instance != VK_NULL_HANDLE && remappedinstance == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pName
            if (strcmp(pPacket->pName, "vkDestroySurfaceKHR") == 0) {
               m_vkFuncs.real_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkCreateSwapchainKHR") == 0) {
               m_vkFuncs.real_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDestroySwapchainKHR") == 0) {
               m_vkFuncs.real_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkGetSwapchainImagesKHR") == 0) {
               m_vkFuncs.real_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkAcquireNextImageKHR") == 0) {
               m_vkFuncs.real_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkQueuePresentKHR") == 0) {
               m_vkFuncs.real_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkCreateXcbSurfaceKHR") == 0) {
               m_vkFuncs.real_vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkCreateDebugReportCallbackEXT") == 0) {
               m_vkFuncs.real_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDestroyDebugReportCallbackEXT") == 0) {
               m_vkFuncs.real_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDebugReportMessageEXT") == 0) {
               m_vkFuncs.real_vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkCmdDbgMarkerBegin") == 0) {
               m_vkFuncs.real_vkCmdDbgMarkerBegin = (PFN_vkCmdDbgMarkerBegin)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkCmdDbgMarkerEnd") == 0) {
               m_vkFuncs.real_vkCmdDbgMarkerEnd = (PFN_vkCmdDbgMarkerEnd)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDbgSetObjectTag") == 0) {
               m_vkFuncs.real_vkDbgSetObjectTag = (PFN_vkDbgSetObjectTag)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDbgSetObjectName") == 0) {
               m_vkFuncs.real_vkDbgSetObjectName = (PFN_vkDbgSetObjectName)vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            }
            m_vkFuncs.real_vkGetInstanceProcAddr(remappedinstance, pPacket->pName);
            break;
        }
        case VKTRACE_TPI_VK_vkGetDeviceProcAddr:
        {
            packet_vkGetDeviceProcAddr* pPacket = (packet_vkGetDeviceProcAddr*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pName
            if (strcmp(pPacket->pName, "vkCreateSwapchainKHR") == 0) {
               m_vkFuncs.real_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkDestroySwapchainKHR") == 0) {
               m_vkFuncs.real_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkGetSwapchainImagesKHR") == 0) {
               m_vkFuncs.real_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkAcquireNextImageKHR") == 0) {
               m_vkFuncs.real_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            }
            if (strcmp(pPacket->pName, "vkQueuePresentKHR") == 0) {
               m_vkFuncs.real_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            }
            m_vkFuncs.real_vkGetDeviceProcAddr(remappeddevice, pPacket->pName);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateDevice:
        {
            packet_vkCreateDevice* pPacket = (packet_vkCreateDevice*)(packet->pBody);
            replayResult = manually_replay_vkCreateDevice(pPacket);
            CHECK_RETURN_VALUE(vkCreateDevice);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyDevice:
        {
            packet_vkDestroyDevice* pPacket = (packet_vkDestroyDevice*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyDevice(remappeddevice, pPacket->pAllocator);
            if (replayResult == VK_SUCCESS)
            {
                m_pCBDump = NULL;
                m_pDSDump = NULL;
                m_objMapper.rm_from_devices_map(pPacket->device);
                m_display->m_initedVK = false;
            }
            break;
        }
        case VKTRACE_TPI_VK_vkEnumerateInstanceExtensionProperties:
        {
            packet_vkEnumerateInstanceExtensionProperties* pPacket = (packet_vkEnumerateInstanceExtensionProperties*)(packet->pBody);
            // No need to remap pLayerName
            // No need to remap pPropertyCount
            // No need to remap pProperties
            replayResult = m_vkFuncs.real_vkEnumerateInstanceExtensionProperties(pPacket->pLayerName, pPacket->pPropertyCount, pPacket->pProperties);
            if (replayResult == VK_ERROR_LAYER_NOT_PRESENT || replayResult == VK_INCOMPLETE)
            { // ignore errors caused by trace config != replay config
                replayResult = VK_SUCCESS;
            }
            CHECK_RETURN_VALUE(vkEnumerateInstanceExtensionProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkEnumerateDeviceExtensionProperties:
        {
            packet_vkEnumerateDeviceExtensionProperties* pPacket = (packet_vkEnumerateDeviceExtensionProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pLayerName
            // No need to remap pPropertyCount
            // No need to remap pProperties
            replayResult = m_vkFuncs.real_vkEnumerateDeviceExtensionProperties(remappedphysicalDevice, pPacket->pLayerName, pPacket->pPropertyCount, pPacket->pProperties);
            if (replayResult == VK_ERROR_LAYER_NOT_PRESENT || replayResult == VK_INCOMPLETE)
            { // ignore errors caused by trace config != replay config
                replayResult = VK_SUCCESS;
            }
            CHECK_RETURN_VALUE(vkEnumerateDeviceExtensionProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkEnumerateInstanceLayerProperties:
        {
            packet_vkEnumerateInstanceLayerProperties* pPacket = (packet_vkEnumerateInstanceLayerProperties*)(packet->pBody);
            // No need to remap pPropertyCount
            // No need to remap pProperties
            replayResult = m_vkFuncs.real_vkEnumerateInstanceLayerProperties(pPacket->pPropertyCount, pPacket->pProperties);
            if (replayResult == VK_ERROR_LAYER_NOT_PRESENT || replayResult == VK_INCOMPLETE)
            { // ignore errors caused by trace config != replay config
                replayResult = VK_SUCCESS;
            }
            CHECK_RETURN_VALUE(vkEnumerateInstanceLayerProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkEnumerateDeviceLayerProperties:
        {
            packet_vkEnumerateDeviceLayerProperties* pPacket = (packet_vkEnumerateDeviceLayerProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pPropertyCount
            // No need to remap pProperties
            replayResult = m_vkFuncs.real_vkEnumerateDeviceLayerProperties(remappedphysicalDevice, pPacket->pPropertyCount, pPacket->pProperties);
            if (replayResult == VK_ERROR_LAYER_NOT_PRESENT || replayResult == VK_INCOMPLETE)
            { // ignore errors caused by trace config != replay config
                replayResult = VK_SUCCESS;
            }
            CHECK_RETURN_VALUE(vkEnumerateDeviceLayerProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkGetDeviceQueue:
        {
            packet_vkGetDeviceQueue* pPacket = (packet_vkGetDeviceQueue*)(packet->pBody);
            VkQueue local_pQueue;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap queueFamilyIndex
            // No need to remap queueIndex
            m_vkFuncs.real_vkGetDeviceQueue(remappeddevice, pPacket->queueFamilyIndex, pPacket->queueIndex, &local_pQueue);
                m_objMapper.add_to_queues_map(*(pPacket->pQueue), local_pQueue);
            break;
        }
        case VKTRACE_TPI_VK_vkQueueSubmit:
        {
            packet_vkQueueSubmit* pPacket = (packet_vkQueueSubmit*)(packet->pBody);
            replayResult = manually_replay_vkQueueSubmit(pPacket);
            CHECK_RETURN_VALUE(vkQueueSubmit);
            break;
        }
        case VKTRACE_TPI_VK_vkQueueWaitIdle:
        {
            packet_vkQueueWaitIdle* pPacket = (packet_vkQueueWaitIdle*)(packet->pBody);
            VkQueue remappedqueue = m_objMapper.remap_queues(pPacket->queue);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queue != VK_NULL_HANDLE && remappedqueue == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkQueueWaitIdle(remappedqueue);
            CHECK_RETURN_VALUE(vkQueueWaitIdle);
            break;
        }
        case VKTRACE_TPI_VK_vkDeviceWaitIdle:
        {
            packet_vkDeviceWaitIdle* pPacket = (packet_vkDeviceWaitIdle*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkDeviceWaitIdle(remappeddevice);
            CHECK_RETURN_VALUE(vkDeviceWaitIdle);
            break;
        }
        case VKTRACE_TPI_VK_vkAllocateMemory:
        {
            packet_vkAllocateMemory* pPacket = (packet_vkAllocateMemory*)(packet->pBody);
            replayResult = manually_replay_vkAllocateMemory(pPacket);
            CHECK_RETURN_VALUE(vkAllocateMemory);
            break;
        }
        case VKTRACE_TPI_VK_vkFreeMemory:
        {
            packet_vkFreeMemory* pPacket = (packet_vkFreeMemory*)(packet->pBody);
            manually_replay_vkFreeMemory(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkMapMemory:
        {
            packet_vkMapMemory* pPacket = (packet_vkMapMemory*)(packet->pBody);
            replayResult = manually_replay_vkMapMemory(pPacket);
            CHECK_RETURN_VALUE(vkMapMemory);
            break;
        }
        case VKTRACE_TPI_VK_vkUnmapMemory:
        {
            packet_vkUnmapMemory* pPacket = (packet_vkUnmapMemory*)(packet->pBody);
            manually_replay_vkUnmapMemory(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkFlushMappedMemoryRanges:
        {
            packet_vkFlushMappedMemoryRanges* pPacket = (packet_vkFlushMappedMemoryRanges*)(packet->pBody);
            replayResult = manually_replay_vkFlushMappedMemoryRanges(pPacket);
            CHECK_RETURN_VALUE(vkFlushMappedMemoryRanges);
            break;
        }
        case VKTRACE_TPI_VK_vkInvalidateMappedMemoryRanges:
        {
            packet_vkInvalidateMappedMemoryRanges* pPacket = (packet_vkInvalidateMappedMemoryRanges*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap memoryRangeCount
            // No need to remap pMemoryRanges
            replayResult = m_vkFuncs.real_vkInvalidateMappedMemoryRanges(remappeddevice, pPacket->memoryRangeCount, pPacket->pMemoryRanges);
            CHECK_RETURN_VALUE(vkInvalidateMappedMemoryRanges);
            break;
        }
        case VKTRACE_TPI_VK_vkGetDeviceMemoryCommitment:
        {
            packet_vkGetDeviceMemoryCommitment* pPacket = (packet_vkGetDeviceMemoryCommitment*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDeviceMemory remappedmemory = m_objMapper.remap_devicememorys(pPacket->memory);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->memory != VK_NULL_HANDLE && remappedmemory == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCommittedMemoryInBytes
            m_vkFuncs.real_vkGetDeviceMemoryCommitment(remappeddevice, remappedmemory, pPacket->pCommittedMemoryInBytes);
            break;
        }
        case VKTRACE_TPI_VK_vkBindBufferMemory:
        {
            packet_vkBindBufferMemory* pPacket = (packet_vkBindBufferMemory*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDeviceMemory remappedmemory = m_objMapper.remap_devicememorys(pPacket->memory);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->memory != VK_NULL_HANDLE && remappedmemory == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap memoryOffset
            replayResult = m_vkFuncs.real_vkBindBufferMemory(remappeddevice, remappedbuffer, remappedmemory, pPacket->memoryOffset);
            CHECK_RETURN_VALUE(vkBindBufferMemory);
            break;
        }
        case VKTRACE_TPI_VK_vkBindImageMemory:
        {
            packet_vkBindImageMemory* pPacket = (packet_vkBindImageMemory*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDeviceMemory remappedmemory = m_objMapper.remap_devicememorys(pPacket->memory);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->memory != VK_NULL_HANDLE && remappedmemory == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap memoryOffset
            replayResult = m_vkFuncs.real_vkBindImageMemory(remappeddevice, remappedimage, remappedmemory, pPacket->memoryOffset);
            CHECK_RETURN_VALUE(vkBindImageMemory);
            break;
        }
        case VKTRACE_TPI_VK_vkGetBufferMemoryRequirements:
        {
            packet_vkGetBufferMemoryRequirements* pPacket = (packet_vkGetBufferMemoryRequirements*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pMemoryRequirements
            m_vkFuncs.real_vkGetBufferMemoryRequirements(remappeddevice, remappedbuffer, pPacket->pMemoryRequirements);
            break;
        }
        case VKTRACE_TPI_VK_vkGetImageMemoryRequirements:
        {
            packet_vkGetImageMemoryRequirements* pPacket = (packet_vkGetImageMemoryRequirements*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pMemoryRequirements
            m_vkFuncs.real_vkGetImageMemoryRequirements(remappeddevice, remappedimage, pPacket->pMemoryRequirements);
            break;
        }
        case VKTRACE_TPI_VK_vkGetImageSparseMemoryRequirements:
        {
            packet_vkGetImageSparseMemoryRequirements* pPacket = (packet_vkGetImageSparseMemoryRequirements*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pSparseMemoryRequirementCount
            // No need to remap pSparseMemoryRequirements
            m_vkFuncs.real_vkGetImageSparseMemoryRequirements(remappeddevice, remappedimage, pPacket->pSparseMemoryRequirementCount, pPacket->pSparseMemoryRequirements);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSparseImageFormatProperties:
        {
            packet_vkGetPhysicalDeviceSparseImageFormatProperties* pPacket = (packet_vkGetPhysicalDeviceSparseImageFormatProperties*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap format
            // No need to remap type
            // No need to remap samples
            // No need to remap usage
            // No need to remap tiling
            // No need to remap pPropertyCount
            // No need to remap pProperties
            m_vkFuncs.real_vkGetPhysicalDeviceSparseImageFormatProperties(remappedphysicalDevice, pPacket->format, pPacket->type, pPacket->samples, pPacket->usage, pPacket->tiling, pPacket->pPropertyCount, pPacket->pProperties);
            break;
        }
        case VKTRACE_TPI_VK_vkQueueBindSparse:
        {
            packet_vkQueueBindSparse* pPacket = (packet_vkQueueBindSparse*)(packet->pBody);
            VkQueue remappedqueue = m_objMapper.remap_queues(pPacket->queue);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queue != VK_NULL_HANDLE && remappedqueue == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap bindInfoCount
            // No need to remap pBindInfo
            VkFence remappedfence = m_objMapper.remap_fences(pPacket->fence);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->fence != VK_NULL_HANDLE && remappedfence == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkQueueBindSparse(remappedqueue, pPacket->bindInfoCount, pPacket->pBindInfo, remappedfence);
            CHECK_RETURN_VALUE(vkQueueBindSparse);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateFence:
        {
            packet_vkCreateFence* pPacket = (packet_vkCreateFence*)(packet->pBody);
            VkFence local_pFence;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateFence(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pFence);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_fences_map(*(pPacket->pFence), local_pFence);
            }
            CHECK_RETURN_VALUE(vkCreateFence);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyFence:
        {
            packet_vkDestroyFence* pPacket = (packet_vkDestroyFence*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkFence remappedfence = m_objMapper.remap_fences(pPacket->fence);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->fence != VK_NULL_HANDLE && remappedfence == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyFence(remappeddevice, remappedfence, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkResetFences:
        {
            packet_vkResetFences* pPacket = (packet_vkResetFences*)(packet->pBody);
            VkFence* fences = VKTRACE_NEW_ARRAY(VkFence, pPacket->fenceCount);
            for (uint32_t i = 0; i < pPacket->fenceCount; i++)
            {
                fences[i] = m_objMapper.remap_fences(pPacket->pFences[i]);
            }
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap fenceCount
            // No need to remap pFences
            replayResult = m_vkFuncs.real_vkResetFences(remappeddevice, pPacket->fenceCount, fences);
            VKTRACE_DELETE(fences);
            CHECK_RETURN_VALUE(vkResetFences);
            break;
        }
        case VKTRACE_TPI_VK_vkGetFenceStatus:
        {
            packet_vkGetFenceStatus* pPacket = (packet_vkGetFenceStatus*)(packet->pBody);
            do {
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkFence remappedfence = m_objMapper.remap_fences(pPacket->fence);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->fence != VK_NULL_HANDLE && remappedfence == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

                replayResult = m_vkFuncs.real_vkGetFenceStatus(remappeddevice, remappedfence);
            } while (replayResult != pPacket->result  && pPacket->result == VK_SUCCESS);
            if (pPacket->result != VK_NOT_READY || replayResult != VK_SUCCESS)
            CHECK_RETURN_VALUE(vkGetFenceStatus);
            break;
        }
        case VKTRACE_TPI_VK_vkWaitForFences:
        {
            packet_vkWaitForFences* pPacket = (packet_vkWaitForFences*)(packet->pBody);
            replayResult = manually_replay_vkWaitForFences(pPacket);
            CHECK_RETURN_VALUE(vkWaitForFences);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateSemaphore:
        {
            packet_vkCreateSemaphore* pPacket = (packet_vkCreateSemaphore*)(packet->pBody);
            VkSemaphore local_pSemaphore;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateSemaphore(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pSemaphore);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_semaphores_map(*(pPacket->pSemaphore), local_pSemaphore);
            }
            CHECK_RETURN_VALUE(vkCreateSemaphore);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroySemaphore:
        {
            packet_vkDestroySemaphore* pPacket = (packet_vkDestroySemaphore*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkSemaphore remappedsemaphore = m_objMapper.remap_semaphores(pPacket->semaphore);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->semaphore != VK_NULL_HANDLE && remappedsemaphore == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroySemaphore(remappeddevice, remappedsemaphore, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateEvent:
        {
            packet_vkCreateEvent* pPacket = (packet_vkCreateEvent*)(packet->pBody);
            VkEvent local_pEvent;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateEvent(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pEvent);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_events_map(*(pPacket->pEvent), local_pEvent);
            }
            CHECK_RETURN_VALUE(vkCreateEvent);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyEvent:
        {
            packet_vkDestroyEvent* pPacket = (packet_vkDestroyEvent*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyEvent(remappeddevice, remappedevent, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetEventStatus:
        {
            packet_vkGetEventStatus* pPacket = (packet_vkGetEventStatus*)(packet->pBody);
            do {
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

                replayResult = m_vkFuncs.real_vkGetEventStatus(remappeddevice, remappedevent);
            } while ((pPacket->result == VK_EVENT_SET || pPacket->result == VK_EVENT_RESET) && replayResult != pPacket->result);
            if (pPacket->result != VK_NOT_READY || replayResult != VK_SUCCESS)
            CHECK_RETURN_VALUE(vkGetEventStatus);
            break;
        }
        case VKTRACE_TPI_VK_vkSetEvent:
        {
            packet_vkSetEvent* pPacket = (packet_vkSetEvent*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkSetEvent(remappeddevice, remappedevent);
            CHECK_RETURN_VALUE(vkSetEvent);
            break;
        }
        case VKTRACE_TPI_VK_vkResetEvent:
        {
            packet_vkResetEvent* pPacket = (packet_vkResetEvent*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkResetEvent(remappeddevice, remappedevent);
            CHECK_RETURN_VALUE(vkResetEvent);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateQueryPool:
        {
            packet_vkCreateQueryPool* pPacket = (packet_vkCreateQueryPool*)(packet->pBody);
            VkQueryPool local_pQueryPool;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateQueryPool(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pQueryPool);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_querypools_map(*(pPacket->pQueryPool), local_pQueryPool);
            }
            CHECK_RETURN_VALUE(vkCreateQueryPool);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyQueryPool:
        {
            packet_vkDestroyQueryPool* pPacket = (packet_vkDestroyQueryPool*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyQueryPool(remappeddevice, remappedqueryPool, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetQueryPoolResults:
        {
            packet_vkGetQueryPoolResults* pPacket = (packet_vkGetQueryPoolResults*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap firstQuery
            // No need to remap queryCount
            // No need to remap dataSize
            // No need to remap pData
            // No need to remap stride
            // No need to remap flags
            replayResult = m_vkFuncs.real_vkGetQueryPoolResults(remappeddevice, remappedqueryPool, pPacket->firstQuery, pPacket->queryCount, pPacket->dataSize, pPacket->pData, pPacket->stride, pPacket->flags);
            CHECK_RETURN_VALUE(vkGetQueryPoolResults);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateBuffer:
        {
            packet_vkCreateBuffer* pPacket = (packet_vkCreateBuffer*)(packet->pBody);
            bufferObj local_bufferObj;
            VkDevice remappedDevice = m_objMapper.remap_devices(pPacket->device);
            if (remappedDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }
            replayResult = m_vkFuncs.real_vkCreateBuffer(remappedDevice, pPacket->pCreateInfo, NULL, &local_bufferObj.replayBuffer);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_buffers_map(*(pPacket->pBuffer), local_bufferObj);
            }
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyBuffer:
        {
            packet_vkDestroyBuffer* pPacket = (packet_vkDestroyBuffer*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyBuffer(remappeddevice, remappedbuffer, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateBufferView:
        {
            packet_vkCreateBufferView* pPacket = (packet_vkCreateBufferView*)(packet->pBody);
            VkBufferViewCreateInfo createInfo;
            memcpy(&createInfo, pPacket->pCreateInfo, sizeof(VkBufferViewCreateInfo));
            createInfo.buffer = m_objMapper.remap_buffers(pPacket->pCreateInfo->buffer);
            VkBufferView local_pView;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateBufferView(remappeddevice, &createInfo, NULL, &local_pView);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_bufferviews_map(*(pPacket->pView), local_pView);
            }
            CHECK_RETURN_VALUE(vkCreateBufferView);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyBufferView:
        {
            packet_vkDestroyBufferView* pPacket = (packet_vkDestroyBufferView*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBufferView remappedbufferView = m_objMapper.remap_bufferviews(pPacket->bufferView);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->bufferView != VK_NULL_HANDLE && remappedbufferView == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyBufferView(remappeddevice, remappedbufferView, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateImage:
        {
            packet_vkCreateImage* pPacket = (packet_vkCreateImage*)(packet->pBody);
            imageObj local_imageObj;
            VkDevice remappedDevice = m_objMapper.remap_devices(pPacket->device);
            if (remappedDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }
            replayResult = m_vkFuncs.real_vkCreateImage(remappedDevice, pPacket->pCreateInfo, NULL, &local_imageObj.replayImage);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_images_map(*(pPacket->pImage), local_imageObj);
            }
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyImage:
        {
            packet_vkDestroyImage* pPacket = (packet_vkDestroyImage*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyImage(remappeddevice, remappedimage, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetImageSubresourceLayout:
        {
            packet_vkGetImageSubresourceLayout* pPacket = (packet_vkGetImageSubresourceLayout*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pSubresource
            // No need to remap pLayout
            m_vkFuncs.real_vkGetImageSubresourceLayout(remappeddevice, remappedimage, pPacket->pSubresource, pPacket->pLayout);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateImageView:
        {
            packet_vkCreateImageView* pPacket = (packet_vkCreateImageView*)(packet->pBody);
            VkImageViewCreateInfo createInfo;
            memcpy(&createInfo, pPacket->pCreateInfo, sizeof(VkImageViewCreateInfo));
            createInfo.image = m_objMapper.remap_images(pPacket->pCreateInfo->image);
            VkImageView local_pView;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateImageView(remappeddevice, &createInfo, NULL, &local_pView);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_imageviews_map(*(pPacket->pView), local_pView);
            }
            CHECK_RETURN_VALUE(vkCreateImageView);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyImageView:
        {
            packet_vkDestroyImageView* pPacket = (packet_vkDestroyImageView*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImageView remappedimageView = m_objMapper.remap_imageviews(pPacket->imageView);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->imageView != VK_NULL_HANDLE && remappedimageView == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyImageView(remappeddevice, remappedimageView, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateShaderModule:
        {
            packet_vkCreateShaderModule* pPacket = (packet_vkCreateShaderModule*)(packet->pBody);
            VkShaderModule local_pShaderModule;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateShaderModule(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pShaderModule);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_shadermodules_map(*(pPacket->pShaderModule), local_pShaderModule);
            }
            CHECK_RETURN_VALUE(vkCreateShaderModule);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyShaderModule:
        {
            packet_vkDestroyShaderModule* pPacket = (packet_vkDestroyShaderModule*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkShaderModule remappedshaderModule = m_objMapper.remap_shadermodules(pPacket->shaderModule);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->shaderModule != VK_NULL_HANDLE && remappedshaderModule == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyShaderModule(remappeddevice, remappedshaderModule, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreatePipelineCache:
        {
            packet_vkCreatePipelineCache* pPacket = (packet_vkCreatePipelineCache*)(packet->pBody);
            VkPipelineCache local_pPipelineCache;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreatePipelineCache(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pPipelineCache);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_pipelinecaches_map(*(pPacket->pPipelineCache), local_pPipelineCache);
            }
            CHECK_RETURN_VALUE(vkCreatePipelineCache);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyPipelineCache:
        {
            packet_vkDestroyPipelineCache* pPacket = (packet_vkDestroyPipelineCache*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineCache remappedpipelineCache = m_objMapper.remap_pipelinecaches(pPacket->pipelineCache);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipelineCache != VK_NULL_HANDLE && remappedpipelineCache == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyPipelineCache(remappeddevice, remappedpipelineCache, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPipelineCacheData:
        {
            packet_vkGetPipelineCacheData* pPacket = (packet_vkGetPipelineCacheData*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineCache remappedpipelineCache = m_objMapper.remap_pipelinecaches(pPacket->pipelineCache);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipelineCache != VK_NULL_HANDLE && remappedpipelineCache == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pDataSize
            // No need to remap pData
            replayResult = m_vkFuncs.real_vkGetPipelineCacheData(remappeddevice, remappedpipelineCache, pPacket->pDataSize, pPacket->pData);
            CHECK_RETURN_VALUE(vkGetPipelineCacheData);
            break;
        }
        case VKTRACE_TPI_VK_vkMergePipelineCaches:
        {
            packet_vkMergePipelineCaches* pPacket = (packet_vkMergePipelineCaches*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineCache remappeddstCache = m_objMapper.remap_pipelinecaches(pPacket->dstCache);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstCache != VK_NULL_HANDLE && remappeddstCache == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap srcCacheCount
            VkPipelineCache *remappedpSrcCaches = new VkPipelineCache[pPacket->srcCacheCount];
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1386
            for (uint32_t i = 0; i < pPacket->srcCacheCount; i++) {
                remappedpSrcCaches[i] = m_objMapper.remap_pipelinecaches(pPacket->pSrcCaches[i]);
                if (pPacket->pSrcCaches[i] != VK_NULL_HANDLE && remappedpSrcCaches[i] == VK_NULL_HANDLE)
                {
                    return vktrace_replay::VKTRACE_REPLAY_ERROR;
                }
            }

            replayResult = m_vkFuncs.real_vkMergePipelineCaches(remappeddevice, remappeddstCache, pPacket->srcCacheCount, remappedpSrcCaches);
            delete remappedpSrcCaches;
            CHECK_RETURN_VALUE(vkMergePipelineCaches);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateGraphicsPipelines:
        {
            packet_vkCreateGraphicsPipelines* pPacket = (packet_vkCreateGraphicsPipelines*)(packet->pBody);
            replayResult = manually_replay_vkCreateGraphicsPipelines(pPacket);
            CHECK_RETURN_VALUE(vkCreateGraphicsPipelines);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateComputePipelines:
        {
            packet_vkCreateComputePipelines* pPacket = (packet_vkCreateComputePipelines*)(packet->pBody);
            VkPipeline local_pPipelines;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineCache remappedpipelineCache = m_objMapper.remap_pipelinecaches(pPacket->pipelineCache);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipelineCache != VK_NULL_HANDLE && remappedpipelineCache == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap createInfoCount
            // No need to remap pCreateInfos
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateComputePipelines(remappeddevice, remappedpipelineCache, pPacket->createInfoCount, pPacket->pCreateInfos, pPacket->pAllocator, &local_pPipelines);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_pipelines_map(*(pPacket->pPipelines), local_pPipelines);
            }
            CHECK_RETURN_VALUE(vkCreateComputePipelines);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyPipeline:
        {
            packet_vkDestroyPipeline* pPacket = (packet_vkDestroyPipeline*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipeline remappedpipeline = m_objMapper.remap_pipelines(pPacket->pipeline);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipeline != VK_NULL_HANDLE && remappedpipeline == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyPipeline(remappeddevice, remappedpipeline, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreatePipelineLayout:
        {
            packet_vkCreatePipelineLayout* pPacket = (packet_vkCreatePipelineLayout*)(packet->pBody);
            replayResult = manually_replay_vkCreatePipelineLayout(pPacket);
            CHECK_RETURN_VALUE(vkCreatePipelineLayout);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyPipelineLayout:
        {
            packet_vkDestroyPipelineLayout* pPacket = (packet_vkDestroyPipelineLayout*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineLayout remappedpipelineLayout = m_objMapper.remap_pipelinelayouts(pPacket->pipelineLayout);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipelineLayout != VK_NULL_HANDLE && remappedpipelineLayout == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyPipelineLayout(remappeddevice, remappedpipelineLayout, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateSampler:
        {
            packet_vkCreateSampler* pPacket = (packet_vkCreateSampler*)(packet->pBody);
            VkSampler local_pSampler;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateSampler(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pSampler);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_samplers_map(*(pPacket->pSampler), local_pSampler);
            }
            CHECK_RETURN_VALUE(vkCreateSampler);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroySampler:
        {
            packet_vkDestroySampler* pPacket = (packet_vkDestroySampler*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkSampler remappedsampler = m_objMapper.remap_samplers(pPacket->sampler);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->sampler != VK_NULL_HANDLE && remappedsampler == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroySampler(remappeddevice, remappedsampler, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateDescriptorSetLayout:
        {
            packet_vkCreateDescriptorSetLayout* pPacket = (packet_vkCreateDescriptorSetLayout*)(packet->pBody);
            replayResult = manually_replay_vkCreateDescriptorSetLayout(pPacket);
            CHECK_RETURN_VALUE(vkCreateDescriptorSetLayout);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyDescriptorSetLayout:
        {
            packet_vkDestroyDescriptorSetLayout* pPacket = (packet_vkDestroyDescriptorSetLayout*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDescriptorSetLayout remappeddescriptorSetLayout = m_objMapper.remap_descriptorsetlayouts(pPacket->descriptorSetLayout);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->descriptorSetLayout != VK_NULL_HANDLE && remappeddescriptorSetLayout == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyDescriptorSetLayout(remappeddevice, remappeddescriptorSetLayout, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateDescriptorPool:
        {
            packet_vkCreateDescriptorPool* pPacket = (packet_vkCreateDescriptorPool*)(packet->pBody);
            VkDescriptorPool local_pDescriptorPool;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateDescriptorPool(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pDescriptorPool);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_descriptorpools_map(*(pPacket->pDescriptorPool), local_pDescriptorPool);
            }
            CHECK_RETURN_VALUE(vkCreateDescriptorPool);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyDescriptorPool:
        {
            packet_vkDestroyDescriptorPool* pPacket = (packet_vkDestroyDescriptorPool*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDescriptorPool remappeddescriptorPool = m_objMapper.remap_descriptorpools(pPacket->descriptorPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->descriptorPool != VK_NULL_HANDLE && remappeddescriptorPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyDescriptorPool(remappeddevice, remappeddescriptorPool, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkResetDescriptorPool:
        {
            packet_vkResetDescriptorPool* pPacket = (packet_vkResetDescriptorPool*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkDescriptorPool remappeddescriptorPool = m_objMapper.remap_descriptorpools(pPacket->descriptorPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->descriptorPool != VK_NULL_HANDLE && remappeddescriptorPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap flags
            replayResult = m_vkFuncs.real_vkResetDescriptorPool(remappeddevice, remappeddescriptorPool, pPacket->flags);
            CHECK_RETURN_VALUE(vkResetDescriptorPool);
            break;
        }
        case VKTRACE_TPI_VK_vkAllocateDescriptorSets:
        {
            packet_vkAllocateDescriptorSets* pPacket = (packet_vkAllocateDescriptorSets*)(packet->pBody);
            VkDescriptorSet* local_pDescriptorSets = (VkDescriptorSet*)malloc(pPacket->pAllocateInfo->descriptorSetCount * sizeof(VkDescriptorSet));
            VkDescriptorSetLayout* local_pSetLayouts = (VkDescriptorSetLayout*)malloc(pPacket->pAllocateInfo->descriptorSetCount * sizeof(VkDescriptorSetLayout));
            VkDescriptorSetAllocateInfo local_AllocInfo, *local_pAllocateInfo = &local_AllocInfo;
            VkDescriptorPool local_descPool;
            local_descPool = m_objMapper.remap_descriptorpools(pPacket->pAllocateInfo->descriptorPool);
            for (uint32_t i = 0; i < pPacket->pAllocateInfo->descriptorSetCount; i++)
            {
                local_pSetLayouts[i] = m_objMapper.remap_descriptorsetlayouts(pPacket->pAllocateInfo->pSetLayouts[i]);
            }
            memcpy(local_pAllocateInfo, pPacket->pAllocateInfo, sizeof(VkDescriptorSetAllocateInfo));
            local_pAllocateInfo->pSetLayouts = local_pSetLayouts;
            local_pAllocateInfo->descriptorPool = local_descPool;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocateInfo
            replayResult = m_vkFuncs.real_vkAllocateDescriptorSets(remappeddevice, local_pAllocateInfo, local_pDescriptorSets);
            if (replayResult == VK_SUCCESS)
            {
                for (uint32_t i = 0; i < pPacket->pAllocateInfo->descriptorSetCount; i++) {
                    m_objMapper.add_to_descriptorsets_map(pPacket->pDescriptorSets[i], local_pDescriptorSets[i]);
                }
            }
            free(local_pSetLayouts);
            free(local_pDescriptorSets);
            CHECK_RETURN_VALUE(vkAllocateDescriptorSets);
            break;
        }
        case VKTRACE_TPI_VK_vkFreeDescriptorSets:
        {
            packet_vkFreeDescriptorSets* pPacket = (packet_vkFreeDescriptorSets*)(packet->pBody);
            replayResult = manually_replay_vkFreeDescriptorSets(pPacket);
            CHECK_RETURN_VALUE(vkFreeDescriptorSets);
            break;
        }
        case VKTRACE_TPI_VK_vkUpdateDescriptorSets:
        {
            packet_vkUpdateDescriptorSets* pPacket = (packet_vkUpdateDescriptorSets*)(packet->pBody);
            manually_replay_vkUpdateDescriptorSets(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateFramebuffer:
        {
            packet_vkCreateFramebuffer* pPacket = (packet_vkCreateFramebuffer*)(packet->pBody);
            replayResult = manually_replay_vkCreateFramebuffer(pPacket);
            CHECK_RETURN_VALUE(vkCreateFramebuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyFramebuffer:
        {
            packet_vkDestroyFramebuffer* pPacket = (packet_vkDestroyFramebuffer*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkFramebuffer remappedframebuffer = m_objMapper.remap_framebuffers(pPacket->framebuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->framebuffer != VK_NULL_HANDLE && remappedframebuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyFramebuffer(remappeddevice, remappedframebuffer, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateRenderPass:
        {
            packet_vkCreateRenderPass* pPacket = (packet_vkCreateRenderPass*)(packet->pBody);
            replayResult = manually_replay_vkCreateRenderPass(pPacket);
            CHECK_RETURN_VALUE(vkCreateRenderPass);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyRenderPass:
        {
            packet_vkDestroyRenderPass* pPacket = (packet_vkDestroyRenderPass*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkRenderPass remappedrenderPass = m_objMapper.remap_renderpasss(pPacket->renderPass);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->renderPass != VK_NULL_HANDLE && remappedrenderPass == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyRenderPass(remappeddevice, remappedrenderPass, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetRenderAreaGranularity:
        {
            packet_vkGetRenderAreaGranularity* pPacket = (packet_vkGetRenderAreaGranularity*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkRenderPass remappedrenderPass = m_objMapper.remap_renderpasss(pPacket->renderPass);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->renderPass != VK_NULL_HANDLE && remappedrenderPass == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pGranularity
            m_vkFuncs.real_vkGetRenderAreaGranularity(remappeddevice, remappedrenderPass, pPacket->pGranularity);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateCommandPool:
        {
            packet_vkCreateCommandPool* pPacket = (packet_vkCreateCommandPool*)(packet->pBody);
            VkCommandPool local_pCommandPool;
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pCreateInfo
            // No need to remap pAllocator
            replayResult = m_vkFuncs.real_vkCreateCommandPool(remappeddevice, pPacket->pCreateInfo, pPacket->pAllocator, &local_pCommandPool);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.add_to_commandpools_map(*(pPacket->pCommandPool), local_pCommandPool);
            }
            CHECK_RETURN_VALUE(vkCreateCommandPool);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyCommandPool:
        {
            packet_vkDestroyCommandPool* pPacket = (packet_vkDestroyCommandPool*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkCommandPool remappedcommandPool = m_objMapper.remap_commandpools(pPacket->commandPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandPool != VK_NULL_HANDLE && remappedcommandPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroyCommandPool(remappeddevice, remappedcommandPool, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkResetCommandPool:
        {
            packet_vkResetCommandPool* pPacket = (packet_vkResetCommandPool*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkCommandPool remappedcommandPool = m_objMapper.remap_commandpools(pPacket->commandPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandPool != VK_NULL_HANDLE && remappedcommandPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap flags
            replayResult = m_vkFuncs.real_vkResetCommandPool(remappeddevice, remappedcommandPool, pPacket->flags);
            CHECK_RETURN_VALUE(vkResetCommandPool);
            break;
        }
        case VKTRACE_TPI_VK_vkAllocateCommandBuffers:
        {
            packet_vkAllocateCommandBuffers* pPacket = (packet_vkAllocateCommandBuffers*)(packet->pBody);
            replayResult = manually_replay_vkAllocateCommandBuffers(pPacket);
            CHECK_RETURN_VALUE(vkAllocateCommandBuffers);
            break;
        }
        case VKTRACE_TPI_VK_vkFreeCommandBuffers:
        {
            packet_vkFreeCommandBuffers* pPacket = (packet_vkFreeCommandBuffers*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkCommandPool remappedcommandPool = m_objMapper.remap_commandpools(pPacket->commandPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandPool != VK_NULL_HANDLE && remappedcommandPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap commandBufferCount
            VkCommandBuffer *remappedpCommandBuffers = new VkCommandBuffer[pPacket->commandBufferCount];
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1386
            for (uint32_t i = 0; i < pPacket->commandBufferCount; i++) {
                remappedpCommandBuffers[i] = m_objMapper.remap_commandbuffers(pPacket->pCommandBuffers[i]);
                if (pPacket->pCommandBuffers[i] != VK_NULL_HANDLE && remappedpCommandBuffers[i] == VK_NULL_HANDLE)
                {
                    return vktrace_replay::VKTRACE_REPLAY_ERROR;
                }
            }

            m_vkFuncs.real_vkFreeCommandBuffers(remappeddevice, remappedcommandPool, pPacket->commandBufferCount, remappedpCommandBuffers);
            delete remappedpCommandBuffers;
            break;
        }
        case VKTRACE_TPI_VK_vkBeginCommandBuffer:
        {
            packet_vkBeginCommandBuffer* pPacket = (packet_vkBeginCommandBuffer*)(packet->pBody);
            replayResult = manually_replay_vkBeginCommandBuffer(pPacket);
            CHECK_RETURN_VALUE(vkBeginCommandBuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkEndCommandBuffer:
        {
            packet_vkEndCommandBuffer* pPacket = (packet_vkEndCommandBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            replayResult = m_vkFuncs.real_vkEndCommandBuffer(remappedcommandBuffer);
            CHECK_RETURN_VALUE(vkEndCommandBuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkResetCommandBuffer:
        {
            packet_vkResetCommandBuffer* pPacket = (packet_vkResetCommandBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap flags
            replayResult = m_vkFuncs.real_vkResetCommandBuffer(remappedcommandBuffer, pPacket->flags);
            CHECK_RETURN_VALUE(vkResetCommandBuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBindPipeline:
        {
            packet_vkCmdBindPipeline* pPacket = (packet_vkCmdBindPipeline*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pipelineBindPoint
            VkPipeline remappedpipeline = m_objMapper.remap_pipelines(pPacket->pipeline);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->pipeline != VK_NULL_HANDLE && remappedpipeline == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            m_vkFuncs.real_vkCmdBindPipeline(remappedcommandBuffer, pPacket->pipelineBindPoint, remappedpipeline);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetViewport:
        {
            packet_vkCmdSetViewport* pPacket = (packet_vkCmdSetViewport*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap firstViewport
            // No need to remap viewportCount
            // No need to remap pViewports
            m_vkFuncs.real_vkCmdSetViewport(remappedcommandBuffer, pPacket->firstViewport, pPacket->viewportCount, pPacket->pViewports);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetScissor:
        {
            packet_vkCmdSetScissor* pPacket = (packet_vkCmdSetScissor*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap firstScissor
            // No need to remap scissorCount
            // No need to remap pScissors
            m_vkFuncs.real_vkCmdSetScissor(remappedcommandBuffer, pPacket->firstScissor, pPacket->scissorCount, pPacket->pScissors);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetLineWidth:
        {
            packet_vkCmdSetLineWidth* pPacket = (packet_vkCmdSetLineWidth*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap lineWidth
            m_vkFuncs.real_vkCmdSetLineWidth(remappedcommandBuffer, pPacket->lineWidth);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetDepthBias:
        {
            packet_vkCmdSetDepthBias* pPacket = (packet_vkCmdSetDepthBias*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap depthBiasConstantFactor
            // No need to remap depthBiasClamp
            // No need to remap depthBiasSlopeFactor
            m_vkFuncs.real_vkCmdSetDepthBias(remappedcommandBuffer, pPacket->depthBiasConstantFactor, pPacket->depthBiasClamp, pPacket->depthBiasSlopeFactor);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetBlendConstants:
        {
            packet_vkCmdSetBlendConstants* pPacket = (packet_vkCmdSetBlendConstants*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap blendConstants
            m_vkFuncs.real_vkCmdSetBlendConstants(remappedcommandBuffer, pPacket->blendConstants);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetDepthBounds:
        {
            packet_vkCmdSetDepthBounds* pPacket = (packet_vkCmdSetDepthBounds*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap minDepthBounds
            // No need to remap maxDepthBounds
            m_vkFuncs.real_vkCmdSetDepthBounds(remappedcommandBuffer, pPacket->minDepthBounds, pPacket->maxDepthBounds);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilCompareMask:
        {
            packet_vkCmdSetStencilCompareMask* pPacket = (packet_vkCmdSetStencilCompareMask*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap faceMask
            // No need to remap compareMask
            m_vkFuncs.real_vkCmdSetStencilCompareMask(remappedcommandBuffer, pPacket->faceMask, pPacket->compareMask);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilWriteMask:
        {
            packet_vkCmdSetStencilWriteMask* pPacket = (packet_vkCmdSetStencilWriteMask*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap faceMask
            // No need to remap writeMask
            m_vkFuncs.real_vkCmdSetStencilWriteMask(remappedcommandBuffer, pPacket->faceMask, pPacket->writeMask);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetStencilReference:
        {
            packet_vkCmdSetStencilReference* pPacket = (packet_vkCmdSetStencilReference*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap faceMask
            // No need to remap reference
            m_vkFuncs.real_vkCmdSetStencilReference(remappedcommandBuffer, pPacket->faceMask, pPacket->reference);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBindDescriptorSets:
        {
            packet_vkCmdBindDescriptorSets* pPacket = (packet_vkCmdBindDescriptorSets*)(packet->pBody);
            manually_replay_vkCmdBindDescriptorSets(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBindIndexBuffer:
        {
            packet_vkCmdBindIndexBuffer* pPacket = (packet_vkCmdBindIndexBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap offset
            // No need to remap indexType
            m_vkFuncs.real_vkCmdBindIndexBuffer(remappedcommandBuffer, remappedbuffer, pPacket->offset, pPacket->indexType);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBindVertexBuffers:
        {
            packet_vkCmdBindVertexBuffers* pPacket = (packet_vkCmdBindVertexBuffers*)(packet->pBody);
            manually_replay_vkCmdBindVertexBuffers(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDraw:
        {
            packet_vkCmdDraw* pPacket = (packet_vkCmdDraw*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap vertexCount
            // No need to remap instanceCount
            // No need to remap firstVertex
            // No need to remap firstInstance
            m_vkFuncs.real_vkCmdDraw(remappedcommandBuffer, pPacket->vertexCount, pPacket->instanceCount, pPacket->firstVertex, pPacket->firstInstance);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndexed:
        {
            packet_vkCmdDrawIndexed* pPacket = (packet_vkCmdDrawIndexed*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap indexCount
            // No need to remap instanceCount
            // No need to remap firstIndex
            // No need to remap vertexOffset
            // No need to remap firstInstance
            m_vkFuncs.real_vkCmdDrawIndexed(remappedcommandBuffer, pPacket->indexCount, pPacket->instanceCount, pPacket->firstIndex, pPacket->vertexOffset, pPacket->firstInstance);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndirect:
        {
            packet_vkCmdDrawIndirect* pPacket = (packet_vkCmdDrawIndirect*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap offset
            // No need to remap drawCount
            // No need to remap stride
            m_vkFuncs.real_vkCmdDrawIndirect(remappedcommandBuffer, remappedbuffer, pPacket->offset, pPacket->drawCount, pPacket->stride);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDrawIndexedIndirect:
        {
            packet_vkCmdDrawIndexedIndirect* pPacket = (packet_vkCmdDrawIndexedIndirect*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap offset
            // No need to remap drawCount
            // No need to remap stride
            m_vkFuncs.real_vkCmdDrawIndexedIndirect(remappedcommandBuffer, remappedbuffer, pPacket->offset, pPacket->drawCount, pPacket->stride);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDispatch:
        {
            packet_vkCmdDispatch* pPacket = (packet_vkCmdDispatch*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap x
            // No need to remap y
            // No need to remap z
            m_vkFuncs.real_vkCmdDispatch(remappedcommandBuffer, pPacket->x, pPacket->y, pPacket->z);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDispatchIndirect:
        {
            packet_vkCmdDispatchIndirect* pPacket = (packet_vkCmdDispatchIndirect*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedbuffer = m_objMapper.remap_buffers(pPacket->buffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->buffer != VK_NULL_HANDLE && remappedbuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap offset
            m_vkFuncs.real_vkCmdDispatchIndirect(remappedcommandBuffer, remappedbuffer, pPacket->offset);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdCopyBuffer:
        {
            packet_vkCmdCopyBuffer* pPacket = (packet_vkCmdCopyBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedsrcBuffer = m_objMapper.remap_buffers(pPacket->srcBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcBuffer != VK_NULL_HANDLE && remappedsrcBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappeddstBuffer = m_objMapper.remap_buffers(pPacket->dstBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstBuffer != VK_NULL_HANDLE && remappeddstBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap regionCount
            // No need to remap pRegions
            m_vkFuncs.real_vkCmdCopyBuffer(remappedcommandBuffer, remappedsrcBuffer, remappeddstBuffer, pPacket->regionCount, pPacket->pRegions);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdCopyImage:
        {
            packet_vkCmdCopyImage* pPacket = (packet_vkCmdCopyImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedsrcImage = m_objMapper.remap_images(pPacket->srcImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcImage != VK_NULL_HANDLE && remappedsrcImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap srcImageLayout
            VkImage remappeddstImage = m_objMapper.remap_images(pPacket->dstImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstImage != VK_NULL_HANDLE && remappeddstImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstImageLayout
            // No need to remap regionCount
            // No need to remap pRegions
            m_vkFuncs.real_vkCmdCopyImage(remappedcommandBuffer, remappedsrcImage, pPacket->srcImageLayout, remappeddstImage, pPacket->dstImageLayout, pPacket->regionCount, pPacket->pRegions);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBlitImage:
        {
            packet_vkCmdBlitImage* pPacket = (packet_vkCmdBlitImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedsrcImage = m_objMapper.remap_images(pPacket->srcImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcImage != VK_NULL_HANDLE && remappedsrcImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap srcImageLayout
            VkImage remappeddstImage = m_objMapper.remap_images(pPacket->dstImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstImage != VK_NULL_HANDLE && remappeddstImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstImageLayout
            // No need to remap regionCount
            // No need to remap pRegions
            // No need to remap filter
            m_vkFuncs.real_vkCmdBlitImage(remappedcommandBuffer, remappedsrcImage, pPacket->srcImageLayout, remappeddstImage, pPacket->dstImageLayout, pPacket->regionCount, pPacket->pRegions, pPacket->filter);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdCopyBufferToImage:
        {
            packet_vkCmdCopyBufferToImage* pPacket = (packet_vkCmdCopyBufferToImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappedsrcBuffer = m_objMapper.remap_buffers(pPacket->srcBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcBuffer != VK_NULL_HANDLE && remappedsrcBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappeddstImage = m_objMapper.remap_images(pPacket->dstImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstImage != VK_NULL_HANDLE && remappeddstImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstImageLayout
            // No need to remap regionCount
            // No need to remap pRegions
            m_vkFuncs.real_vkCmdCopyBufferToImage(remappedcommandBuffer, remappedsrcBuffer, remappeddstImage, pPacket->dstImageLayout, pPacket->regionCount, pPacket->pRegions);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdCopyImageToBuffer:
        {
            packet_vkCmdCopyImageToBuffer* pPacket = (packet_vkCmdCopyImageToBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedsrcImage = m_objMapper.remap_images(pPacket->srcImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcImage != VK_NULL_HANDLE && remappedsrcImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap srcImageLayout
            VkBuffer remappeddstBuffer = m_objMapper.remap_buffers(pPacket->dstBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstBuffer != VK_NULL_HANDLE && remappeddstBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap regionCount
            // No need to remap pRegions
            m_vkFuncs.real_vkCmdCopyImageToBuffer(remappedcommandBuffer, remappedsrcImage, pPacket->srcImageLayout, remappeddstBuffer, pPacket->regionCount, pPacket->pRegions);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdUpdateBuffer:
        {
            packet_vkCmdUpdateBuffer* pPacket = (packet_vkCmdUpdateBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappeddstBuffer = m_objMapper.remap_buffers(pPacket->dstBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstBuffer != VK_NULL_HANDLE && remappeddstBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstOffset
            // No need to remap dataSize
            // No need to remap pData
            m_vkFuncs.real_vkCmdUpdateBuffer(remappedcommandBuffer, remappeddstBuffer, pPacket->dstOffset, pPacket->dataSize, pPacket->pData);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdFillBuffer:
        {
            packet_vkCmdFillBuffer* pPacket = (packet_vkCmdFillBuffer*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkBuffer remappeddstBuffer = m_objMapper.remap_buffers(pPacket->dstBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstBuffer != VK_NULL_HANDLE && remappeddstBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstOffset
            // No need to remap size
            // No need to remap data
            m_vkFuncs.real_vkCmdFillBuffer(remappedcommandBuffer, remappeddstBuffer, pPacket->dstOffset, pPacket->size, pPacket->data);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdClearColorImage:
        {
            packet_vkCmdClearColorImage* pPacket = (packet_vkCmdClearColorImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap imageLayout
            // No need to remap pColor
            // No need to remap rangeCount
            // No need to remap pRanges
            m_vkFuncs.real_vkCmdClearColorImage(remappedcommandBuffer, remappedimage, pPacket->imageLayout, pPacket->pColor, pPacket->rangeCount, pPacket->pRanges);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdClearDepthStencilImage:
        {
            packet_vkCmdClearDepthStencilImage* pPacket = (packet_vkCmdClearDepthStencilImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedimage = m_objMapper.remap_images(pPacket->image);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->image != VK_NULL_HANDLE && remappedimage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap imageLayout
            // No need to remap pDepthStencil
            // No need to remap rangeCount
            // No need to remap pRanges
            m_vkFuncs.real_vkCmdClearDepthStencilImage(remappedcommandBuffer, remappedimage, pPacket->imageLayout, pPacket->pDepthStencil, pPacket->rangeCount, pPacket->pRanges);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdClearAttachments:
        {
            packet_vkCmdClearAttachments* pPacket = (packet_vkCmdClearAttachments*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap attachmentCount
            // No need to remap pAttachments
            // No need to remap rectCount
            // No need to remap pRects
            m_vkFuncs.real_vkCmdClearAttachments(remappedcommandBuffer, pPacket->attachmentCount, pPacket->pAttachments, pPacket->rectCount, pPacket->pRects);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdResolveImage:
        {
            packet_vkCmdResolveImage* pPacket = (packet_vkCmdResolveImage*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkImage remappedsrcImage = m_objMapper.remap_images(pPacket->srcImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->srcImage != VK_NULL_HANDLE && remappedsrcImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap srcImageLayout
            VkImage remappeddstImage = m_objMapper.remap_images(pPacket->dstImage);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstImage != VK_NULL_HANDLE && remappeddstImage == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstImageLayout
            // No need to remap regionCount
            // No need to remap pRegions
            m_vkFuncs.real_vkCmdResolveImage(remappedcommandBuffer, remappedsrcImage, pPacket->srcImageLayout, remappeddstImage, pPacket->dstImageLayout, pPacket->regionCount, pPacket->pRegions);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdSetEvent:
        {
            packet_vkCmdSetEvent* pPacket = (packet_vkCmdSetEvent*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap stageMask
            m_vkFuncs.real_vkCmdSetEvent(remappedcommandBuffer, remappedevent, pPacket->stageMask);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdResetEvent:
        {
            packet_vkCmdResetEvent* pPacket = (packet_vkCmdResetEvent*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkEvent remappedevent = m_objMapper.remap_events(pPacket->event);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->event != VK_NULL_HANDLE && remappedevent == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap stageMask
            m_vkFuncs.real_vkCmdResetEvent(remappedcommandBuffer, remappedevent, pPacket->stageMask);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdWaitEvents:
        {
            packet_vkCmdWaitEvents* pPacket = (packet_vkCmdWaitEvents*)(packet->pBody);
            manually_replay_vkCmdWaitEvents(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdPipelineBarrier:
        {
            packet_vkCmdPipelineBarrier* pPacket = (packet_vkCmdPipelineBarrier*)(packet->pBody);
            manually_replay_vkCmdPipelineBarrier(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBeginQuery:
        {
            packet_vkCmdBeginQuery* pPacket = (packet_vkCmdBeginQuery*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap query
            // No need to remap flags
            m_vkFuncs.real_vkCmdBeginQuery(remappedcommandBuffer, remappedqueryPool, pPacket->query, pPacket->flags);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdEndQuery:
        {
            packet_vkCmdEndQuery* pPacket = (packet_vkCmdEndQuery*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap query
            m_vkFuncs.real_vkCmdEndQuery(remappedcommandBuffer, remappedqueryPool, pPacket->query);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdResetQueryPool:
        {
            packet_vkCmdResetQueryPool* pPacket = (packet_vkCmdResetQueryPool*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap firstQuery
            // No need to remap queryCount
            m_vkFuncs.real_vkCmdResetQueryPool(remappedcommandBuffer, remappedqueryPool, pPacket->firstQuery, pPacket->queryCount);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdWriteTimestamp:
        {
            packet_vkCmdWriteTimestamp* pPacket = (packet_vkCmdWriteTimestamp*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pipelineStage
            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap query
            m_vkFuncs.real_vkCmdWriteTimestamp(remappedcommandBuffer, pPacket->pipelineStage, remappedqueryPool, pPacket->query);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdCopyQueryPoolResults:
        {
            packet_vkCmdCopyQueryPoolResults* pPacket = (packet_vkCmdCopyQueryPoolResults*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkQueryPool remappedqueryPool = m_objMapper.remap_querypools(pPacket->queryPool);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->queryPool != VK_NULL_HANDLE && remappedqueryPool == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap firstQuery
            // No need to remap queryCount
            VkBuffer remappeddstBuffer = m_objMapper.remap_buffers(pPacket->dstBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->dstBuffer != VK_NULL_HANDLE && remappeddstBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap dstOffset
            // No need to remap stride
            // No need to remap flags
            m_vkFuncs.real_vkCmdCopyQueryPoolResults(remappedcommandBuffer, remappedqueryPool, pPacket->firstQuery, pPacket->queryCount, remappeddstBuffer, pPacket->dstOffset, pPacket->stride, pPacket->flags);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdPushConstants:
        {
            packet_vkCmdPushConstants* pPacket = (packet_vkCmdPushConstants*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkPipelineLayout remappedlayout = m_objMapper.remap_pipelinelayouts(pPacket->layout);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->layout != VK_NULL_HANDLE && remappedlayout == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap stageFlags
            // No need to remap offset
            // No need to remap size
            // No need to remap pValues
            m_vkFuncs.real_vkCmdPushConstants(remappedcommandBuffer, remappedlayout, pPacket->stageFlags, pPacket->offset, pPacket->size, pPacket->pValues);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdBeginRenderPass:
        {
            packet_vkCmdBeginRenderPass* pPacket = (packet_vkCmdBeginRenderPass*)(packet->pBody);
            manually_replay_vkCmdBeginRenderPass(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdNextSubpass:
        {
            packet_vkCmdNextSubpass* pPacket = (packet_vkCmdNextSubpass*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap contents
            m_vkFuncs.real_vkCmdNextSubpass(remappedcommandBuffer, pPacket->contents);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdEndRenderPass:
        {
            packet_vkCmdEndRenderPass* pPacket = (packet_vkCmdEndRenderPass*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            m_vkFuncs.real_vkCmdEndRenderPass(remappedcommandBuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdExecuteCommands:
        {
            packet_vkCmdExecuteCommands* pPacket = (packet_vkCmdExecuteCommands*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap commandBufferCount
            VkCommandBuffer *remappedpCommandBuffers = new VkCommandBuffer[pPacket->commandBufferCount];
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1386
            for (uint32_t i = 0; i < pPacket->commandBufferCount; i++) {
                remappedpCommandBuffers[i] = m_objMapper.remap_commandbuffers(pPacket->pCommandBuffers[i]);
                if (pPacket->pCommandBuffers[i] != VK_NULL_HANDLE && remappedpCommandBuffers[i] == VK_NULL_HANDLE)
                {
                    return vktrace_replay::VKTRACE_REPLAY_ERROR;
                }
            }

            m_vkFuncs.real_vkCmdExecuteCommands(remappedcommandBuffer, pPacket->commandBufferCount, remappedpCommandBuffers);
            delete remappedpCommandBuffers;
            break;
        }
        case VKTRACE_TPI_VK_vkDestroySurfaceKHR:
        {
            packet_vkDestroySurfaceKHR* pPacket = (packet_vkDestroySurfaceKHR*)(packet->pBody);
            VkInstance remappedinstance = m_objMapper.remap_instances(pPacket->instance);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->instance != VK_NULL_HANDLE && remappedinstance == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkSurfaceKHR remappedsurface = m_objMapper.remap_surfacekhrs(pPacket->surface);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->surface != VK_NULL_HANDLE && remappedsurface == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroySurfaceKHR(remappedinstance, remappedsurface, pPacket->pAllocator);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceSupportKHR:
        {
            packet_vkGetPhysicalDeviceSurfaceSupportKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceSupportKHR*)(packet->pBody);
            replayResult = manually_replay_vkGetPhysicalDeviceSurfaceSupportKHR(pPacket);
            CHECK_RETURN_VALUE(vkGetPhysicalDeviceSurfaceSupportKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        {
            packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR*)(packet->pBody);
            replayResult = manually_replay_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(pPacket);
            CHECK_RETURN_VALUE(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfaceFormatsKHR:
        {
            packet_vkGetPhysicalDeviceSurfaceFormatsKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceFormatsKHR*)(packet->pBody);
            replayResult = manually_replay_vkGetPhysicalDeviceSurfaceFormatsKHR(pPacket);
            CHECK_RETURN_VALUE(vkGetPhysicalDeviceSurfaceFormatsKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceSurfacePresentModesKHR:
        {
            packet_vkGetPhysicalDeviceSurfacePresentModesKHR* pPacket = (packet_vkGetPhysicalDeviceSurfacePresentModesKHR*)(packet->pBody);
            replayResult = manually_replay_vkGetPhysicalDeviceSurfacePresentModesKHR(pPacket);
            CHECK_RETURN_VALUE(vkGetPhysicalDeviceSurfacePresentModesKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateSwapchainKHR:
        {
            packet_vkCreateSwapchainKHR* pPacket = (packet_vkCreateSwapchainKHR*)(packet->pBody);
            replayResult = manually_replay_vkCreateSwapchainKHR(pPacket);
            CHECK_RETURN_VALUE(vkCreateSwapchainKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroySwapchainKHR:
        {
            packet_vkDestroySwapchainKHR* pPacket = (packet_vkDestroySwapchainKHR*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkSwapchainKHR remappedswapchain = m_objMapper.remap_swapchainkhrs(pPacket->swapchain);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->swapchain != VK_NULL_HANDLE && remappedswapchain == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pAllocator
            m_vkFuncs.real_vkDestroySwapchainKHR(remappeddevice, remappedswapchain, pPacket->pAllocator);
            if (replayResult == VK_SUCCESS)
            {
                m_objMapper.rm_from_swapchainkhrs_map(pPacket->swapchain);
            }
            break;
        }
        case VKTRACE_TPI_VK_vkGetSwapchainImagesKHR:
        {
            packet_vkGetSwapchainImagesKHR* pPacket = (packet_vkGetSwapchainImagesKHR*)(packet->pBody);
            replayResult = manually_replay_vkGetSwapchainImagesKHR(pPacket);
            CHECK_RETURN_VALUE(vkGetSwapchainImagesKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkAcquireNextImageKHR:
        {
            packet_vkAcquireNextImageKHR* pPacket = (packet_vkAcquireNextImageKHR*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkSwapchainKHR remappedswapchain = m_objMapper.remap_swapchainkhrs(pPacket->swapchain);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->swapchain != VK_NULL_HANDLE && remappedswapchain == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap timeout
            VkSemaphore remappedsemaphore = m_objMapper.remap_semaphores(pPacket->semaphore);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->semaphore != VK_NULL_HANDLE && remappedsemaphore == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            VkFence remappedfence = m_objMapper.remap_fences(pPacket->fence);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->fence != VK_NULL_HANDLE && remappedfence == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pImageIndex
            replayResult = m_vkFuncs.real_vkAcquireNextImageKHR(remappeddevice, remappedswapchain, pPacket->timeout, remappedsemaphore, remappedfence, pPacket->pImageIndex);
            CHECK_RETURN_VALUE(vkAcquireNextImageKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkQueuePresentKHR:
        {
            packet_vkQueuePresentKHR* pPacket = (packet_vkQueuePresentKHR*)(packet->pBody);
            replayResult = manually_replay_vkQueuePresentKHR(pPacket);
            CHECK_RETURN_VALUE(vkQueuePresentKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateXcbSurfaceKHR:
        {
            packet_vkCreateXcbSurfaceKHR* pPacket = (packet_vkCreateXcbSurfaceKHR*)(packet->pBody);
            replayResult = manually_replay_vkCreateXcbSurfaceKHR(pPacket);
            CHECK_RETURN_VALUE(vkCreateXcbSurfaceKHR);
            break;
        }
        case VKTRACE_TPI_VK_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        {
            packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* pPacket = (packet_vkGetPhysicalDeviceXcbPresentationSupportKHR*)(packet->pBody);
            VkPhysicalDevice remappedphysicalDevice = m_objMapper.remap_physicaldevices(pPacket->physicalDevice);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->physicalDevice != VK_NULL_HANDLE && remappedphysicalDevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap queueFamilyIndex
            // No need to remap connection
            // No need to remap visual_id
            m_vkFuncs.real_vkGetPhysicalDeviceXcbPresentationSupportKHR(remappedphysicalDevice, pPacket->queueFamilyIndex, pPacket->connection, pPacket->visual_id);
            break;
        }
        case VKTRACE_TPI_VK_vkCreateDebugReportCallbackEXT:
        {
            packet_vkCreateDebugReportCallbackEXT* pPacket = (packet_vkCreateDebugReportCallbackEXT*)(packet->pBody);
            replayResult = manually_replay_vkCreateDebugReportCallbackEXT(pPacket);
            CHECK_RETURN_VALUE(vkCreateDebugReportCallbackEXT);
            break;
        }
        case VKTRACE_TPI_VK_vkDestroyDebugReportCallbackEXT:
        {
            packet_vkDestroyDebugReportCallbackEXT* pPacket = (packet_vkDestroyDebugReportCallbackEXT*)(packet->pBody);
            manually_replay_vkDestroyDebugReportCallbackEXT(pPacket);
            break;
        }
        case VKTRACE_TPI_VK_vkDebugReportMessageEXT:
        {
            packet_vkDebugReportMessageEXT* pPacket = (packet_vkDebugReportMessageEXT*)(packet->pBody);
            VkInstance remappedinstance = m_objMapper.remap_instances(pPacket->instance);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->instance != VK_NULL_HANDLE && remappedinstance == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap flags
            // No need to remap objType
            // No need to remap object
            // No need to remap location
            // No need to remap msgCode
            // No need to remap pLayerPrefix
            // No need to remap pMsg
            m_vkFuncs.real_vkDebugReportMessageEXT(remappedinstance, pPacket->flags, pPacket->objType, pPacket->object, pPacket->location, pPacket->msgCode, pPacket->pLayerPrefix, pPacket->pMsg);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDbgMarkerBegin:
        {
            packet_vkCmdDbgMarkerBegin* pPacket = (packet_vkCmdDbgMarkerBegin*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap pMarker
            m_vkFuncs.real_vkCmdDbgMarkerBegin(remappedcommandBuffer, pPacket->pMarker);
            break;
        }
        case VKTRACE_TPI_VK_vkCmdDbgMarkerEnd:
        {
            packet_vkCmdDbgMarkerEnd* pPacket = (packet_vkCmdDbgMarkerEnd*)(packet->pBody);
            VkCommandBuffer remappedcommandBuffer = m_objMapper.remap_commandbuffers(pPacket->commandBuffer);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->commandBuffer != VK_NULL_HANDLE && remappedcommandBuffer == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            m_vkFuncs.real_vkCmdDbgMarkerEnd(remappedcommandBuffer);
            break;
        }
        case VKTRACE_TPI_VK_vkDbgSetObjectTag:
        {
            packet_vkDbgSetObjectTag* pPacket = (packet_vkDbgSetObjectTag*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap objType
            // No need to remap object
            // No need to remap tagSize
            // No need to remap pTag
            replayResult = m_vkFuncs.real_vkDbgSetObjectTag(remappeddevice, pPacket->objType, pPacket->object, pPacket->tagSize, pPacket->pTag);
            CHECK_RETURN_VALUE(vkDbgSetObjectTag);
            break;
        }
        case VKTRACE_TPI_VK_vkDbgSetObjectName:
        {
            packet_vkDbgSetObjectName* pPacket = (packet_vkDbgSetObjectName*)(packet->pBody);
            VkDevice remappeddevice = m_objMapper.remap_devices(pPacket->device);
// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #1397
            if (pPacket->device != VK_NULL_HANDLE && remappeddevice == VK_NULL_HANDLE)
            {
                return vktrace_replay::VKTRACE_REPLAY_ERROR;
            }

            // No need to remap objType
            // No need to remap object
            // No need to remap nameSize
            // No need to remap pName
            replayResult = m_vkFuncs.real_vkDbgSetObjectName(remappeddevice, pPacket->objType, pPacket->object, pPacket->nameSize, pPacket->pName);
            CHECK_RETURN_VALUE(vkDbgSetObjectName);
            break;
        }
        default:
            vktrace_LogWarning("Unrecognized packet_id %u, skipping.", packet->packet_id);
            returnValue = vktrace_replay::VKTRACE_REPLAY_INVALID_ID;
            break;
    }
    return returnValue;
}
}
