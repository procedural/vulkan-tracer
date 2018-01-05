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

struct vkFuncs {
    void init_funcs(void * libHandle);
    void *m_libHandle;

    typedef VkResult( VKAPI_PTR * type_vkCreateInstance)(
        const VkInstanceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkInstance* pInstance);
    type_vkCreateInstance real_vkCreateInstance;
    typedef void( VKAPI_PTR * type_vkDestroyInstance)(
        VkInstance instance,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyInstance real_vkDestroyInstance;
    typedef VkResult( VKAPI_PTR * type_vkEnumeratePhysicalDevices)(
        VkInstance instance,
        uint32_t* pPhysicalDeviceCount,
        VkPhysicalDevice* pPhysicalDevices);
    type_vkEnumeratePhysicalDevices real_vkEnumeratePhysicalDevices;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceFeatures)(
        VkPhysicalDevice physicalDevice,
        VkPhysicalDeviceFeatures* pFeatures);
    type_vkGetPhysicalDeviceFeatures real_vkGetPhysicalDeviceFeatures;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceFormatProperties)(
        VkPhysicalDevice physicalDevice,
        VkFormat format,
        VkFormatProperties* pFormatProperties);
    type_vkGetPhysicalDeviceFormatProperties real_vkGetPhysicalDeviceFormatProperties;
    typedef VkResult( VKAPI_PTR * type_vkGetPhysicalDeviceImageFormatProperties)(
        VkPhysicalDevice physicalDevice,
        VkFormat format,
        VkImageType type,
        VkImageTiling tiling,
        VkImageUsageFlags usage,
        VkImageCreateFlags flags,
        VkImageFormatProperties* pImageFormatProperties);
    type_vkGetPhysicalDeviceImageFormatProperties real_vkGetPhysicalDeviceImageFormatProperties;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceProperties)(
        VkPhysicalDevice physicalDevice,
        VkPhysicalDeviceProperties* pProperties);
    type_vkGetPhysicalDeviceProperties real_vkGetPhysicalDeviceProperties;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceQueueFamilyProperties)(
        VkPhysicalDevice physicalDevice,
        uint32_t* pQueueFamilyPropertyCount,
        VkQueueFamilyProperties* pQueueFamilyProperties);
    type_vkGetPhysicalDeviceQueueFamilyProperties real_vkGetPhysicalDeviceQueueFamilyProperties;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceMemoryProperties)(
        VkPhysicalDevice physicalDevice,
        VkPhysicalDeviceMemoryProperties* pMemoryProperties);
    type_vkGetPhysicalDeviceMemoryProperties real_vkGetPhysicalDeviceMemoryProperties;
    typedef PFN_vkVoidFunction( VKAPI_PTR * type_vkGetInstanceProcAddr)(
        VkInstance instance,
        const char* pName);
    type_vkGetInstanceProcAddr real_vkGetInstanceProcAddr;
    typedef PFN_vkVoidFunction( VKAPI_PTR * type_vkGetDeviceProcAddr)(
        VkDevice device,
        const char* pName);
    type_vkGetDeviceProcAddr real_vkGetDeviceProcAddr;
    typedef VkResult( VKAPI_PTR * type_vkCreateDevice)(
        VkPhysicalDevice physicalDevice,
        const VkDeviceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDevice* pDevice);
    type_vkCreateDevice real_vkCreateDevice;
    typedef void( VKAPI_PTR * type_vkDestroyDevice)(
        VkDevice device,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyDevice real_vkDestroyDevice;
    typedef VkResult( VKAPI_PTR * type_vkEnumerateInstanceExtensionProperties)(
        const char* pLayerName,
        uint32_t* pPropertyCount,
        VkExtensionProperties* pProperties);
    type_vkEnumerateInstanceExtensionProperties real_vkEnumerateInstanceExtensionProperties;
    typedef VkResult( VKAPI_PTR * type_vkEnumerateDeviceExtensionProperties)(
        VkPhysicalDevice physicalDevice,
        const char* pLayerName,
        uint32_t* pPropertyCount,
        VkExtensionProperties* pProperties);
    type_vkEnumerateDeviceExtensionProperties real_vkEnumerateDeviceExtensionProperties;
    typedef VkResult( VKAPI_PTR * type_vkEnumerateInstanceLayerProperties)(
        uint32_t* pPropertyCount,
        VkLayerProperties* pProperties);
    type_vkEnumerateInstanceLayerProperties real_vkEnumerateInstanceLayerProperties;
    typedef VkResult( VKAPI_PTR * type_vkEnumerateDeviceLayerProperties)(
        VkPhysicalDevice physicalDevice,
        uint32_t* pPropertyCount,
        VkLayerProperties* pProperties);
    type_vkEnumerateDeviceLayerProperties real_vkEnumerateDeviceLayerProperties;
    typedef void( VKAPI_PTR * type_vkGetDeviceQueue)(
        VkDevice device,
        uint32_t queueFamilyIndex,
        uint32_t queueIndex,
        VkQueue* pQueue);
    type_vkGetDeviceQueue real_vkGetDeviceQueue;
    typedef VkResult( VKAPI_PTR * type_vkQueueSubmit)(
        VkQueue queue,
        uint32_t submitCount,
        const VkSubmitInfo* pSubmits,
        VkFence fence);
    type_vkQueueSubmit real_vkQueueSubmit;
    typedef VkResult( VKAPI_PTR * type_vkQueueWaitIdle)(
        VkQueue queue);
    type_vkQueueWaitIdle real_vkQueueWaitIdle;
    typedef VkResult( VKAPI_PTR * type_vkDeviceWaitIdle)(
        VkDevice device);
    type_vkDeviceWaitIdle real_vkDeviceWaitIdle;
    typedef VkResult( VKAPI_PTR * type_vkAllocateMemory)(
        VkDevice device,
        const VkMemoryAllocateInfo* pAllocateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDeviceMemory* pMemory);
    type_vkAllocateMemory real_vkAllocateMemory;
    typedef void( VKAPI_PTR * type_vkFreeMemory)(
        VkDevice device,
        VkDeviceMemory memory,
        const VkAllocationCallbacks* pAllocator);
    type_vkFreeMemory real_vkFreeMemory;
    typedef VkResult( VKAPI_PTR * type_vkMapMemory)(
        VkDevice device,
        VkDeviceMemory memory,
        VkDeviceSize offset,
        VkDeviceSize size,
        VkMemoryMapFlags flags,
        void** ppData);
    type_vkMapMemory real_vkMapMemory;
    typedef void( VKAPI_PTR * type_vkUnmapMemory)(
        VkDevice device,
        VkDeviceMemory memory);
    type_vkUnmapMemory real_vkUnmapMemory;
    typedef VkResult( VKAPI_PTR * type_vkFlushMappedMemoryRanges)(
        VkDevice device,
        uint32_t memoryRangeCount,
        const VkMappedMemoryRange* pMemoryRanges);
    type_vkFlushMappedMemoryRanges real_vkFlushMappedMemoryRanges;
    typedef VkResult( VKAPI_PTR * type_vkInvalidateMappedMemoryRanges)(
        VkDevice device,
        uint32_t memoryRangeCount,
        const VkMappedMemoryRange* pMemoryRanges);
    type_vkInvalidateMappedMemoryRanges real_vkInvalidateMappedMemoryRanges;
    typedef void( VKAPI_PTR * type_vkGetDeviceMemoryCommitment)(
        VkDevice device,
        VkDeviceMemory memory,
        VkDeviceSize* pCommittedMemoryInBytes);
    type_vkGetDeviceMemoryCommitment real_vkGetDeviceMemoryCommitment;
    typedef VkResult( VKAPI_PTR * type_vkBindBufferMemory)(
        VkDevice device,
        VkBuffer buffer,
        VkDeviceMemory memory,
        VkDeviceSize memoryOffset);
    type_vkBindBufferMemory real_vkBindBufferMemory;
    typedef VkResult( VKAPI_PTR * type_vkBindImageMemory)(
        VkDevice device,
        VkImage image,
        VkDeviceMemory memory,
        VkDeviceSize memoryOffset);
    type_vkBindImageMemory real_vkBindImageMemory;
    typedef void( VKAPI_PTR * type_vkGetBufferMemoryRequirements)(
        VkDevice device,
        VkBuffer buffer,
        VkMemoryRequirements* pMemoryRequirements);
    type_vkGetBufferMemoryRequirements real_vkGetBufferMemoryRequirements;
    typedef void( VKAPI_PTR * type_vkGetImageMemoryRequirements)(
        VkDevice device,
        VkImage image,
        VkMemoryRequirements* pMemoryRequirements);
    type_vkGetImageMemoryRequirements real_vkGetImageMemoryRequirements;
    typedef void( VKAPI_PTR * type_vkGetImageSparseMemoryRequirements)(
        VkDevice device,
        VkImage image,
        uint32_t* pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
    type_vkGetImageSparseMemoryRequirements real_vkGetImageSparseMemoryRequirements;
    typedef void( VKAPI_PTR * type_vkGetPhysicalDeviceSparseImageFormatProperties)(
        VkPhysicalDevice physicalDevice,
        VkFormat format,
        VkImageType type,
        VkSampleCountFlagBits samples,
        VkImageUsageFlags usage,
        VkImageTiling tiling,
        uint32_t* pPropertyCount,
        VkSparseImageFormatProperties* pProperties);
    type_vkGetPhysicalDeviceSparseImageFormatProperties real_vkGetPhysicalDeviceSparseImageFormatProperties;
    typedef VkResult( VKAPI_PTR * type_vkQueueBindSparse)(
        VkQueue queue,
        uint32_t bindInfoCount,
        const VkBindSparseInfo* pBindInfo,
        VkFence fence);
    type_vkQueueBindSparse real_vkQueueBindSparse;
    typedef VkResult( VKAPI_PTR * type_vkCreateFence)(
        VkDevice device,
        const VkFenceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkFence* pFence);
    type_vkCreateFence real_vkCreateFence;
    typedef void( VKAPI_PTR * type_vkDestroyFence)(
        VkDevice device,
        VkFence fence,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyFence real_vkDestroyFence;
    typedef VkResult( VKAPI_PTR * type_vkResetFences)(
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences);
    type_vkResetFences real_vkResetFences;
    typedef VkResult( VKAPI_PTR * type_vkGetFenceStatus)(
        VkDevice device,
        VkFence fence);
    type_vkGetFenceStatus real_vkGetFenceStatus;
    typedef VkResult( VKAPI_PTR * type_vkWaitForFences)(
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences,
        VkBool32 waitAll,
        uint64_t timeout);
    type_vkWaitForFences real_vkWaitForFences;
    typedef VkResult( VKAPI_PTR * type_vkCreateSemaphore)(
        VkDevice device,
        const VkSemaphoreCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSemaphore* pSemaphore);
    type_vkCreateSemaphore real_vkCreateSemaphore;
    typedef void( VKAPI_PTR * type_vkDestroySemaphore)(
        VkDevice device,
        VkSemaphore semaphore,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroySemaphore real_vkDestroySemaphore;
    typedef VkResult( VKAPI_PTR * type_vkCreateEvent)(
        VkDevice device,
        const VkEventCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkEvent* pEvent);
    type_vkCreateEvent real_vkCreateEvent;
    typedef void( VKAPI_PTR * type_vkDestroyEvent)(
        VkDevice device,
        VkEvent event,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyEvent real_vkDestroyEvent;
    typedef VkResult( VKAPI_PTR * type_vkGetEventStatus)(
        VkDevice device,
        VkEvent event);
    type_vkGetEventStatus real_vkGetEventStatus;
    typedef VkResult( VKAPI_PTR * type_vkSetEvent)(
        VkDevice device,
        VkEvent event);
    type_vkSetEvent real_vkSetEvent;
    typedef VkResult( VKAPI_PTR * type_vkResetEvent)(
        VkDevice device,
        VkEvent event);
    type_vkResetEvent real_vkResetEvent;
    typedef VkResult( VKAPI_PTR * type_vkCreateQueryPool)(
        VkDevice device,
        const VkQueryPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkQueryPool* pQueryPool);
    type_vkCreateQueryPool real_vkCreateQueryPool;
    typedef void( VKAPI_PTR * type_vkDestroyQueryPool)(
        VkDevice device,
        VkQueryPool queryPool,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyQueryPool real_vkDestroyQueryPool;
    typedef VkResult( VKAPI_PTR * type_vkGetQueryPoolResults)(
        VkDevice device,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uint32_t queryCount,
        size_t dataSize,
        void* pData,
        VkDeviceSize stride,
        VkQueryResultFlags flags);
    type_vkGetQueryPoolResults real_vkGetQueryPoolResults;
    typedef VkResult( VKAPI_PTR * type_vkCreateBuffer)(
        VkDevice device,
        const VkBufferCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkBuffer* pBuffer);
    type_vkCreateBuffer real_vkCreateBuffer;
    typedef void( VKAPI_PTR * type_vkDestroyBuffer)(
        VkDevice device,
        VkBuffer buffer,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyBuffer real_vkDestroyBuffer;
    typedef VkResult( VKAPI_PTR * type_vkCreateBufferView)(
        VkDevice device,
        const VkBufferViewCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkBufferView* pView);
    type_vkCreateBufferView real_vkCreateBufferView;
    typedef void( VKAPI_PTR * type_vkDestroyBufferView)(
        VkDevice device,
        VkBufferView bufferView,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyBufferView real_vkDestroyBufferView;
    typedef VkResult( VKAPI_PTR * type_vkCreateImage)(
        VkDevice device,
        const VkImageCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkImage* pImage);
    type_vkCreateImage real_vkCreateImage;
    typedef void( VKAPI_PTR * type_vkDestroyImage)(
        VkDevice device,
        VkImage image,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyImage real_vkDestroyImage;
    typedef void( VKAPI_PTR * type_vkGetImageSubresourceLayout)(
        VkDevice device,
        VkImage image,
        const VkImageSubresource* pSubresource,
        VkSubresourceLayout* pLayout);
    type_vkGetImageSubresourceLayout real_vkGetImageSubresourceLayout;
    typedef VkResult( VKAPI_PTR * type_vkCreateImageView)(
        VkDevice device,
        const VkImageViewCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkImageView* pView);
    type_vkCreateImageView real_vkCreateImageView;
    typedef void( VKAPI_PTR * type_vkDestroyImageView)(
        VkDevice device,
        VkImageView imageView,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyImageView real_vkDestroyImageView;
    typedef VkResult( VKAPI_PTR * type_vkCreateShaderModule)(
        VkDevice device,
        const VkShaderModuleCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkShaderModule* pShaderModule);
    type_vkCreateShaderModule real_vkCreateShaderModule;
    typedef void( VKAPI_PTR * type_vkDestroyShaderModule)(
        VkDevice device,
        VkShaderModule shaderModule,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyShaderModule real_vkDestroyShaderModule;
    typedef VkResult( VKAPI_PTR * type_vkCreatePipelineCache)(
        VkDevice device,
        const VkPipelineCacheCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkPipelineCache* pPipelineCache);
    type_vkCreatePipelineCache real_vkCreatePipelineCache;
    typedef void( VKAPI_PTR * type_vkDestroyPipelineCache)(
        VkDevice device,
        VkPipelineCache pipelineCache,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyPipelineCache real_vkDestroyPipelineCache;
    typedef VkResult( VKAPI_PTR * type_vkGetPipelineCacheData)(
        VkDevice device,
        VkPipelineCache pipelineCache,
        size_t* pDataSize,
        void* pData);
    type_vkGetPipelineCacheData real_vkGetPipelineCacheData;
    typedef VkResult( VKAPI_PTR * type_vkMergePipelineCaches)(
        VkDevice device,
        VkPipelineCache dstCache,
        uint32_t srcCacheCount,
        const VkPipelineCache* pSrcCaches);
    type_vkMergePipelineCaches real_vkMergePipelineCaches;
    typedef VkResult( VKAPI_PTR * type_vkCreateGraphicsPipelines)(
        VkDevice device,
        VkPipelineCache pipelineCache,
        uint32_t createInfoCount,
        const VkGraphicsPipelineCreateInfo* pCreateInfos,
        const VkAllocationCallbacks* pAllocator,
        VkPipeline* pPipelines);
    type_vkCreateGraphicsPipelines real_vkCreateGraphicsPipelines;
    typedef VkResult( VKAPI_PTR * type_vkCreateComputePipelines)(
        VkDevice device,
        VkPipelineCache pipelineCache,
        uint32_t createInfoCount,
        const VkComputePipelineCreateInfo* pCreateInfos,
        const VkAllocationCallbacks* pAllocator,
        VkPipeline* pPipelines);
    type_vkCreateComputePipelines real_vkCreateComputePipelines;
    typedef void( VKAPI_PTR * type_vkDestroyPipeline)(
        VkDevice device,
        VkPipeline pipeline,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyPipeline real_vkDestroyPipeline;
    typedef VkResult( VKAPI_PTR * type_vkCreatePipelineLayout)(
        VkDevice device,
        const VkPipelineLayoutCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkPipelineLayout* pPipelineLayout);
    type_vkCreatePipelineLayout real_vkCreatePipelineLayout;
    typedef void( VKAPI_PTR * type_vkDestroyPipelineLayout)(
        VkDevice device,
        VkPipelineLayout pipelineLayout,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyPipelineLayout real_vkDestroyPipelineLayout;
    typedef VkResult( VKAPI_PTR * type_vkCreateSampler)(
        VkDevice device,
        const VkSamplerCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSampler* pSampler);
    type_vkCreateSampler real_vkCreateSampler;
    typedef void( VKAPI_PTR * type_vkDestroySampler)(
        VkDevice device,
        VkSampler sampler,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroySampler real_vkDestroySampler;
    typedef VkResult( VKAPI_PTR * type_vkCreateDescriptorSetLayout)(
        VkDevice device,
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorSetLayout* pSetLayout);
    type_vkCreateDescriptorSetLayout real_vkCreateDescriptorSetLayout;
    typedef void( VKAPI_PTR * type_vkDestroyDescriptorSetLayout)(
        VkDevice device,
        VkDescriptorSetLayout descriptorSetLayout,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyDescriptorSetLayout real_vkDestroyDescriptorSetLayout;
    typedef VkResult( VKAPI_PTR * type_vkCreateDescriptorPool)(
        VkDevice device,
        const VkDescriptorPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorPool* pDescriptorPool);
    type_vkCreateDescriptorPool real_vkCreateDescriptorPool;
    typedef void( VKAPI_PTR * type_vkDestroyDescriptorPool)(
        VkDevice device,
        VkDescriptorPool descriptorPool,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyDescriptorPool real_vkDestroyDescriptorPool;
    typedef VkResult( VKAPI_PTR * type_vkResetDescriptorPool)(
        VkDevice device,
        VkDescriptorPool descriptorPool,
        VkDescriptorPoolResetFlags flags);
    type_vkResetDescriptorPool real_vkResetDescriptorPool;
    typedef VkResult( VKAPI_PTR * type_vkAllocateDescriptorSets)(
        VkDevice device,
        const VkDescriptorSetAllocateInfo* pAllocateInfo,
        VkDescriptorSet* pDescriptorSets);
    type_vkAllocateDescriptorSets real_vkAllocateDescriptorSets;
    typedef VkResult( VKAPI_PTR * type_vkFreeDescriptorSets)(
        VkDevice device,
        VkDescriptorPool descriptorPool,
        uint32_t descriptorSetCount,
        const VkDescriptorSet* pDescriptorSets);
    type_vkFreeDescriptorSets real_vkFreeDescriptorSets;
    typedef void( VKAPI_PTR * type_vkUpdateDescriptorSets)(
        VkDevice device,
        uint32_t descriptorWriteCount,
        const VkWriteDescriptorSet* pDescriptorWrites,
        uint32_t descriptorCopyCount,
        const VkCopyDescriptorSet* pDescriptorCopies);
    type_vkUpdateDescriptorSets real_vkUpdateDescriptorSets;
    typedef VkResult( VKAPI_PTR * type_vkCreateFramebuffer)(
        VkDevice device,
        const VkFramebufferCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkFramebuffer* pFramebuffer);
    type_vkCreateFramebuffer real_vkCreateFramebuffer;
    typedef void( VKAPI_PTR * type_vkDestroyFramebuffer)(
        VkDevice device,
        VkFramebuffer framebuffer,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyFramebuffer real_vkDestroyFramebuffer;
    typedef VkResult( VKAPI_PTR * type_vkCreateRenderPass)(
        VkDevice device,
        const VkRenderPassCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkRenderPass* pRenderPass);
    type_vkCreateRenderPass real_vkCreateRenderPass;
    typedef void( VKAPI_PTR * type_vkDestroyRenderPass)(
        VkDevice device,
        VkRenderPass renderPass,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyRenderPass real_vkDestroyRenderPass;
    typedef void( VKAPI_PTR * type_vkGetRenderAreaGranularity)(
        VkDevice device,
        VkRenderPass renderPass,
        VkExtent2D* pGranularity);
    type_vkGetRenderAreaGranularity real_vkGetRenderAreaGranularity;
    typedef VkResult( VKAPI_PTR * type_vkCreateCommandPool)(
        VkDevice device,
        const VkCommandPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkCommandPool* pCommandPool);
    type_vkCreateCommandPool real_vkCreateCommandPool;
    typedef void( VKAPI_PTR * type_vkDestroyCommandPool)(
        VkDevice device,
        VkCommandPool commandPool,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyCommandPool real_vkDestroyCommandPool;
    typedef VkResult( VKAPI_PTR * type_vkResetCommandPool)(
        VkDevice device,
        VkCommandPool commandPool,
        VkCommandPoolResetFlags flags);
    type_vkResetCommandPool real_vkResetCommandPool;
    typedef VkResult( VKAPI_PTR * type_vkAllocateCommandBuffers)(
        VkDevice device,
        const VkCommandBufferAllocateInfo* pAllocateInfo,
        VkCommandBuffer* pCommandBuffers);
    type_vkAllocateCommandBuffers real_vkAllocateCommandBuffers;
    typedef void( VKAPI_PTR * type_vkFreeCommandBuffers)(
        VkDevice device,
        VkCommandPool commandPool,
        uint32_t commandBufferCount,
        const VkCommandBuffer* pCommandBuffers);
    type_vkFreeCommandBuffers real_vkFreeCommandBuffers;
    typedef VkResult( VKAPI_PTR * type_vkBeginCommandBuffer)(
        VkCommandBuffer commandBuffer,
        const VkCommandBufferBeginInfo* pBeginInfo);
    type_vkBeginCommandBuffer real_vkBeginCommandBuffer;
    typedef VkResult( VKAPI_PTR * type_vkEndCommandBuffer)(
        VkCommandBuffer commandBuffer);
    type_vkEndCommandBuffer real_vkEndCommandBuffer;
    typedef VkResult( VKAPI_PTR * type_vkResetCommandBuffer)(
        VkCommandBuffer commandBuffer,
        VkCommandBufferResetFlags flags);
    type_vkResetCommandBuffer real_vkResetCommandBuffer;
    typedef void( VKAPI_PTR * type_vkCmdBindPipeline)(
        VkCommandBuffer commandBuffer,
        VkPipelineBindPoint pipelineBindPoint,
        VkPipeline pipeline);
    type_vkCmdBindPipeline real_vkCmdBindPipeline;
    typedef void( VKAPI_PTR * type_vkCmdSetViewport)(
        VkCommandBuffer commandBuffer,
        uint32_t firstViewport,
        uint32_t viewportCount,
        const VkViewport* pViewports);
    type_vkCmdSetViewport real_vkCmdSetViewport;
    typedef void( VKAPI_PTR * type_vkCmdSetScissor)(
        VkCommandBuffer commandBuffer,
        uint32_t firstScissor,
        uint32_t scissorCount,
        const VkRect2D* pScissors);
    type_vkCmdSetScissor real_vkCmdSetScissor;
    typedef void( VKAPI_PTR * type_vkCmdSetLineWidth)(
        VkCommandBuffer commandBuffer,
        float lineWidth);
    type_vkCmdSetLineWidth real_vkCmdSetLineWidth;
    typedef void( VKAPI_PTR * type_vkCmdSetDepthBias)(
        VkCommandBuffer commandBuffer,
        float depthBiasConstantFactor,
        float depthBiasClamp,
        float depthBiasSlopeFactor);
    type_vkCmdSetDepthBias real_vkCmdSetDepthBias;
    typedef void( VKAPI_PTR * type_vkCmdSetBlendConstants)(
        VkCommandBuffer commandBuffer,
        const float blendConstants[4]);
    type_vkCmdSetBlendConstants real_vkCmdSetBlendConstants;
    typedef void( VKAPI_PTR * type_vkCmdSetDepthBounds)(
        VkCommandBuffer commandBuffer,
        float minDepthBounds,
        float maxDepthBounds);
    type_vkCmdSetDepthBounds real_vkCmdSetDepthBounds;
    typedef void( VKAPI_PTR * type_vkCmdSetStencilCompareMask)(
        VkCommandBuffer commandBuffer,
        VkStencilFaceFlags faceMask,
        uint32_t compareMask);
    type_vkCmdSetStencilCompareMask real_vkCmdSetStencilCompareMask;
    typedef void( VKAPI_PTR * type_vkCmdSetStencilWriteMask)(
        VkCommandBuffer commandBuffer,
        VkStencilFaceFlags faceMask,
        uint32_t writeMask);
    type_vkCmdSetStencilWriteMask real_vkCmdSetStencilWriteMask;
    typedef void( VKAPI_PTR * type_vkCmdSetStencilReference)(
        VkCommandBuffer commandBuffer,
        VkStencilFaceFlags faceMask,
        uint32_t reference);
    type_vkCmdSetStencilReference real_vkCmdSetStencilReference;
    typedef void( VKAPI_PTR * type_vkCmdBindDescriptorSets)(
        VkCommandBuffer commandBuffer,
        VkPipelineBindPoint pipelineBindPoint,
        VkPipelineLayout layout,
        uint32_t firstSet,
        uint32_t descriptorSetCount,
        const VkDescriptorSet* pDescriptorSets,
        uint32_t dynamicOffsetCount,
        const uint32_t* pDynamicOffsets);
    type_vkCmdBindDescriptorSets real_vkCmdBindDescriptorSets;
    typedef void( VKAPI_PTR * type_vkCmdBindIndexBuffer)(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset,
        VkIndexType indexType);
    type_vkCmdBindIndexBuffer real_vkCmdBindIndexBuffer;
    typedef void( VKAPI_PTR * type_vkCmdBindVertexBuffers)(
        VkCommandBuffer commandBuffer,
        uint32_t firstBinding,
        uint32_t bindingCount,
        const VkBuffer* pBuffers,
        const VkDeviceSize* pOffsets);
    type_vkCmdBindVertexBuffers real_vkCmdBindVertexBuffers;
    typedef void( VKAPI_PTR * type_vkCmdDraw)(
        VkCommandBuffer commandBuffer,
        uint32_t vertexCount,
        uint32_t instanceCount,
        uint32_t firstVertex,
        uint32_t firstInstance);
    type_vkCmdDraw real_vkCmdDraw;
    typedef void( VKAPI_PTR * type_vkCmdDrawIndexed)(
        VkCommandBuffer commandBuffer,
        uint32_t indexCount,
        uint32_t instanceCount,
        uint32_t firstIndex,
        int32_t vertexOffset,
        uint32_t firstInstance);
    type_vkCmdDrawIndexed real_vkCmdDrawIndexed;
    typedef void( VKAPI_PTR * type_vkCmdDrawIndirect)(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset,
        uint32_t drawCount,
        uint32_t stride);
    type_vkCmdDrawIndirect real_vkCmdDrawIndirect;
    typedef void( VKAPI_PTR * type_vkCmdDrawIndexedIndirect)(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset,
        uint32_t drawCount,
        uint32_t stride);
    type_vkCmdDrawIndexedIndirect real_vkCmdDrawIndexedIndirect;
    typedef void( VKAPI_PTR * type_vkCmdDispatch)(
        VkCommandBuffer commandBuffer,
        uint32_t x,
        uint32_t y,
        uint32_t z);
    type_vkCmdDispatch real_vkCmdDispatch;
    typedef void( VKAPI_PTR * type_vkCmdDispatchIndirect)(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset);
    type_vkCmdDispatchIndirect real_vkCmdDispatchIndirect;
    typedef void( VKAPI_PTR * type_vkCmdCopyBuffer)(
        VkCommandBuffer commandBuffer,
        VkBuffer srcBuffer,
        VkBuffer dstBuffer,
        uint32_t regionCount,
        const VkBufferCopy* pRegions);
    type_vkCmdCopyBuffer real_vkCmdCopyBuffer;
    typedef void( VKAPI_PTR * type_vkCmdCopyImage)(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkImageCopy* pRegions);
    type_vkCmdCopyImage real_vkCmdCopyImage;
    typedef void( VKAPI_PTR * type_vkCmdBlitImage)(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkImageBlit* pRegions,
        VkFilter filter);
    type_vkCmdBlitImage real_vkCmdBlitImage;
    typedef void( VKAPI_PTR * type_vkCmdCopyBufferToImage)(
        VkCommandBuffer commandBuffer,
        VkBuffer srcBuffer,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkBufferImageCopy* pRegions);
    type_vkCmdCopyBufferToImage real_vkCmdCopyBufferToImage;
    typedef void( VKAPI_PTR * type_vkCmdCopyImageToBuffer)(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkBuffer dstBuffer,
        uint32_t regionCount,
        const VkBufferImageCopy* pRegions);
    type_vkCmdCopyImageToBuffer real_vkCmdCopyImageToBuffer;
    typedef void( VKAPI_PTR * type_vkCmdUpdateBuffer)(
        VkCommandBuffer commandBuffer,
        VkBuffer dstBuffer,
        VkDeviceSize dstOffset,
        VkDeviceSize dataSize,
        const uint32_t* pData);
    type_vkCmdUpdateBuffer real_vkCmdUpdateBuffer;
    typedef void( VKAPI_PTR * type_vkCmdFillBuffer)(
        VkCommandBuffer commandBuffer,
        VkBuffer dstBuffer,
        VkDeviceSize dstOffset,
        VkDeviceSize size,
        uint32_t data);
    type_vkCmdFillBuffer real_vkCmdFillBuffer;
    typedef void( VKAPI_PTR * type_vkCmdClearColorImage)(
        VkCommandBuffer commandBuffer,
        VkImage image,
        VkImageLayout imageLayout,
        const VkClearColorValue* pColor,
        uint32_t rangeCount,
        const VkImageSubresourceRange* pRanges);
    type_vkCmdClearColorImage real_vkCmdClearColorImage;
    typedef void( VKAPI_PTR * type_vkCmdClearDepthStencilImage)(
        VkCommandBuffer commandBuffer,
        VkImage image,
        VkImageLayout imageLayout,
        const VkClearDepthStencilValue* pDepthStencil,
        uint32_t rangeCount,
        const VkImageSubresourceRange* pRanges);
    type_vkCmdClearDepthStencilImage real_vkCmdClearDepthStencilImage;
    typedef void( VKAPI_PTR * type_vkCmdClearAttachments)(
        VkCommandBuffer commandBuffer,
        uint32_t attachmentCount,
        const VkClearAttachment* pAttachments,
        uint32_t rectCount,
        const VkClearRect* pRects);
    type_vkCmdClearAttachments real_vkCmdClearAttachments;
    typedef void( VKAPI_PTR * type_vkCmdResolveImage)(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkImageResolve* pRegions);
    type_vkCmdResolveImage real_vkCmdResolveImage;
    typedef void( VKAPI_PTR * type_vkCmdSetEvent)(
        VkCommandBuffer commandBuffer,
        VkEvent event,
        VkPipelineStageFlags stageMask);
    type_vkCmdSetEvent real_vkCmdSetEvent;
    typedef void( VKAPI_PTR * type_vkCmdResetEvent)(
        VkCommandBuffer commandBuffer,
        VkEvent event,
        VkPipelineStageFlags stageMask);
    type_vkCmdResetEvent real_vkCmdResetEvent;
    typedef void( VKAPI_PTR * type_vkCmdWaitEvents)(
        VkCommandBuffer commandBuffer,
        uint32_t eventCount,
        const VkEvent* pEvents,
        VkPipelineStageFlags srcStageMask,
        VkPipelineStageFlags dstStageMask,
        uint32_t memoryBarrierCount,
        const VkMemoryBarrier* pMemoryBarriers,
        uint32_t bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier* pBufferMemoryBarriers,
        uint32_t imageMemoryBarrierCount,
        const VkImageMemoryBarrier* pImageMemoryBarriers);
    type_vkCmdWaitEvents real_vkCmdWaitEvents;
    typedef void( VKAPI_PTR * type_vkCmdPipelineBarrier)(
        VkCommandBuffer commandBuffer,
        VkPipelineStageFlags srcStageMask,
        VkPipelineStageFlags dstStageMask,
        VkDependencyFlags dependencyFlags,
        uint32_t memoryBarrierCount,
        const VkMemoryBarrier* pMemoryBarriers,
        uint32_t bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier* pBufferMemoryBarriers,
        uint32_t imageMemoryBarrierCount,
        const VkImageMemoryBarrier* pImageMemoryBarriers);
    type_vkCmdPipelineBarrier real_vkCmdPipelineBarrier;
    typedef void( VKAPI_PTR * type_vkCmdBeginQuery)(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t query,
        VkQueryControlFlags flags);
    type_vkCmdBeginQuery real_vkCmdBeginQuery;
    typedef void( VKAPI_PTR * type_vkCmdEndQuery)(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t query);
    type_vkCmdEndQuery real_vkCmdEndQuery;
    typedef void( VKAPI_PTR * type_vkCmdResetQueryPool)(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uint32_t queryCount);
    type_vkCmdResetQueryPool real_vkCmdResetQueryPool;
    typedef void( VKAPI_PTR * type_vkCmdWriteTimestamp)(
        VkCommandBuffer commandBuffer,
        VkPipelineStageFlagBits pipelineStage,
        VkQueryPool queryPool,
        uint32_t query);
    type_vkCmdWriteTimestamp real_vkCmdWriteTimestamp;
    typedef void( VKAPI_PTR * type_vkCmdCopyQueryPoolResults)(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uint32_t queryCount,
        VkBuffer dstBuffer,
        VkDeviceSize dstOffset,
        VkDeviceSize stride,
        VkQueryResultFlags flags);
    type_vkCmdCopyQueryPoolResults real_vkCmdCopyQueryPoolResults;
    typedef void( VKAPI_PTR * type_vkCmdPushConstants)(
        VkCommandBuffer commandBuffer,
        VkPipelineLayout layout,
        VkShaderStageFlags stageFlags,
        uint32_t offset,
        uint32_t size,
        const void* pValues);
    type_vkCmdPushConstants real_vkCmdPushConstants;
    typedef void( VKAPI_PTR * type_vkCmdBeginRenderPass)(
        VkCommandBuffer commandBuffer,
        const VkRenderPassBeginInfo* pRenderPassBegin,
        VkSubpassContents contents);
    type_vkCmdBeginRenderPass real_vkCmdBeginRenderPass;
    typedef void( VKAPI_PTR * type_vkCmdNextSubpass)(
        VkCommandBuffer commandBuffer,
        VkSubpassContents contents);
    type_vkCmdNextSubpass real_vkCmdNextSubpass;
    typedef void( VKAPI_PTR * type_vkCmdEndRenderPass)(
        VkCommandBuffer commandBuffer);
    type_vkCmdEndRenderPass real_vkCmdEndRenderPass;
    typedef void( VKAPI_PTR * type_vkCmdExecuteCommands)(
        VkCommandBuffer commandBuffer,
        uint32_t commandBufferCount,
        const VkCommandBuffer* pCommandBuffers);
    type_vkCmdExecuteCommands real_vkCmdExecuteCommands;
    typedef void( VKAPI_PTR * type_vkDestroySurfaceKHR)(
        VkInstance instance,
        VkSurfaceKHR surface,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroySurfaceKHR real_vkDestroySurfaceKHR;
    typedef VkResult( VKAPI_PTR * type_vkGetPhysicalDeviceSurfaceSupportKHR)(
        VkPhysicalDevice physicalDevice,
        uint32_t queueFamilyIndex,
        VkSurfaceKHR surface,
        VkBool32* pSupported);
    type_vkGetPhysicalDeviceSurfaceSupportKHR real_vkGetPhysicalDeviceSurfaceSupportKHR;
    typedef VkResult( VKAPI_PTR * type_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)(
        VkPhysicalDevice physicalDevice,
        VkSurfaceKHR surface,
        VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
    type_vkGetPhysicalDeviceSurfaceCapabilitiesKHR real_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    typedef VkResult( VKAPI_PTR * type_vkGetPhysicalDeviceSurfaceFormatsKHR)(
        VkPhysicalDevice physicalDevice,
        VkSurfaceKHR surface,
        uint32_t* pSurfaceFormatCount,
        VkSurfaceFormatKHR* pSurfaceFormats);
    type_vkGetPhysicalDeviceSurfaceFormatsKHR real_vkGetPhysicalDeviceSurfaceFormatsKHR;
    typedef VkResult( VKAPI_PTR * type_vkGetPhysicalDeviceSurfacePresentModesKHR)(
        VkPhysicalDevice physicalDevice,
        VkSurfaceKHR surface,
        uint32_t* pPresentModeCount,
        VkPresentModeKHR* pPresentModes);
    type_vkGetPhysicalDeviceSurfacePresentModesKHR real_vkGetPhysicalDeviceSurfacePresentModesKHR;
    typedef VkResult( VKAPI_PTR * type_vkCreateSwapchainKHR)(
        VkDevice device,
        const VkSwapchainCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSwapchainKHR* pSwapchain);
    type_vkCreateSwapchainKHR real_vkCreateSwapchainKHR;
    typedef void( VKAPI_PTR * type_vkDestroySwapchainKHR)(
        VkDevice device,
        VkSwapchainKHR swapchain,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroySwapchainKHR real_vkDestroySwapchainKHR;
    typedef VkResult( VKAPI_PTR * type_vkGetSwapchainImagesKHR)(
        VkDevice device,
        VkSwapchainKHR swapchain,
        uint32_t* pSwapchainImageCount,
        VkImage* pSwapchainImages);
    type_vkGetSwapchainImagesKHR real_vkGetSwapchainImagesKHR;
    typedef VkResult( VKAPI_PTR * type_vkAcquireNextImageKHR)(
        VkDevice device,
        VkSwapchainKHR swapchain,
        uint64_t timeout,
        VkSemaphore semaphore,
        VkFence fence,
        uint32_t* pImageIndex);
    type_vkAcquireNextImageKHR real_vkAcquireNextImageKHR;
    typedef VkResult( VKAPI_PTR * type_vkQueuePresentKHR)(
        VkQueue queue,
        const VkPresentInfoKHR* pPresentInfo);
    type_vkQueuePresentKHR real_vkQueuePresentKHR;
    typedef VkResult( VKAPI_PTR * type_vkCreateXcbSurfaceKHR)(
        VkInstance instance,
        const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSurfaceKHR* pSurface);
    type_vkCreateXcbSurfaceKHR real_vkCreateXcbSurfaceKHR;
    typedef VkBool32( VKAPI_PTR * type_vkGetPhysicalDeviceXcbPresentationSupportKHR)(
        VkPhysicalDevice physicalDevice,
        uint32_t queueFamilyIndex,
        xcb_connection_t* connection,
        xcb_visualid_t visual_id);
    type_vkGetPhysicalDeviceXcbPresentationSupportKHR real_vkGetPhysicalDeviceXcbPresentationSupportKHR;
    typedef VkResult( VKAPI_PTR * type_vkCreateDebugReportCallbackEXT)(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugReportCallbackEXT* pCallback);
    type_vkCreateDebugReportCallbackEXT real_vkCreateDebugReportCallbackEXT;
    typedef void( VKAPI_PTR * type_vkDestroyDebugReportCallbackEXT)(
        VkInstance instance,
        VkDebugReportCallbackEXT callback,
        const VkAllocationCallbacks* pAllocator);
    type_vkDestroyDebugReportCallbackEXT real_vkDestroyDebugReportCallbackEXT;
    typedef void( VKAPI_PTR * type_vkDebugReportMessageEXT)(
        VkInstance instance,
        VkDebugReportFlagsEXT flags,
        VkDebugReportObjectTypeEXT objType,
        uint64_t object,
        size_t location,
        int32_t msgCode,
        const char * pLayerPrefix,
        const char * pMsg);
    type_vkDebugReportMessageEXT real_vkDebugReportMessageEXT;
    typedef void( VKAPI_PTR * type_vkCmdDbgMarkerBegin)(
        VkCommandBuffer commandBuffer,
        const char* pMarker);
    type_vkCmdDbgMarkerBegin real_vkCmdDbgMarkerBegin;
    typedef void( VKAPI_PTR * type_vkCmdDbgMarkerEnd)(
        VkCommandBuffer commandBuffer);
    type_vkCmdDbgMarkerEnd real_vkCmdDbgMarkerEnd;
    typedef VkResult( VKAPI_PTR * type_vkDbgSetObjectTag)(
        VkDevice device,
        VkDebugReportObjectTypeEXT objType,
        uint64_t object,
        size_t tagSize,
        const void* pTag);
    type_vkDbgSetObjectTag real_vkDbgSetObjectTag;
    typedef VkResult( VKAPI_PTR * type_vkDbgSetObjectName)(
        VkDevice device,
        VkDebugReportObjectTypeEXT objType,
        uint64_t object,
        size_t nameSize,
        const char* pName);
    type_vkDbgSetObjectName real_vkDbgSetObjectName;
};
