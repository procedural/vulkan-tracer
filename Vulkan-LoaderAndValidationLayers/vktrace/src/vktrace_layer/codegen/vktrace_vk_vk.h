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

#include "vktrace_vk_vk_packets.h"
#include "vktrace_vk_packet_id.h"


void InitTracer(void);


#ifdef WIN32
extern INIT_ONCE gInitOnce;

#elif defined(PLATFORM_LINUX)
extern pthread_once_t gInitOnce;
#endif


#ifdef __cplusplus
extern"C" {
#endif
// Hooked function prototypes

VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
VKTRACER_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL __HOOKED_vkGetInstanceProcAddr(VkInstance instance, const char* pName);
VKTRACER_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL __HOOKED_vkGetDeviceProcAddr(VkDevice device, const char* pName);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueueWaitIdle(VkQueue queue);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkDeviceWaitIdle(VkDevice device);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkUnmapMemory(VkDevice device, VkDeviceMemory memory);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetFenceStatus(VkDevice device, VkFence fence);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetEventStatus(VkDevice device, VkEvent event);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkSetEvent(VkDevice device, VkEvent event);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetEvent(VkDevice device, VkEvent event);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkEndCommandBuffer(VkCommandBuffer commandBuffer);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t x, uint32_t y, uint32_t z);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const uint32_t* pData);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdEndRenderPass(VkCommandBuffer commandBuffer);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
VKTRACER_EXPORT VKAPI_ATTR VkBool32 VKAPI_CALL __HOOKED_vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
#ifdef __cplusplus
}
#endif
