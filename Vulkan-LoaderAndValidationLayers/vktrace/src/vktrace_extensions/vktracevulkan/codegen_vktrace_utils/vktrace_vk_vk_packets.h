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

#include "vulkan/vulkan.h"
#include "vktrace_trace_packet_utils.h"


// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #554
//=============================================================================
static void add_VkApplicationInfo_to_packet(vktrace_trace_packet_header*  pHeader, VkApplicationInfo** ppStruct, const VkApplicationInfo *pInStruct)
{
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)ppStruct, sizeof(VkApplicationInfo), pInStruct);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->pApplicationName), (pInStruct->pApplicationName != NULL) ? strlen(pInStruct->pApplicationName) + 1 : 0, pInStruct->pApplicationName);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->pEngineName), (pInStruct->pEngineName != NULL) ? strlen(pInStruct->pEngineName) + 1 : 0, pInStruct->pEngineName);
    vktrace_finalize_buffer_address(pHeader, (void**)&((*ppStruct)->pApplicationName));
    vktrace_finalize_buffer_address(pHeader, (void**)&((*ppStruct)->pEngineName));
    vktrace_finalize_buffer_address(pHeader, (void**)&*ppStruct);
};

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #565
static void add_VkInstanceCreateInfo_to_packet(vktrace_trace_packet_header* pHeader, VkInstanceCreateInfo** ppStruct, VkInstanceCreateInfo *pInStruct)
{
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)ppStruct, sizeof(VkInstanceCreateInfo), pInStruct);
    add_VkApplicationInfo_to_packet(pHeader, (VkApplicationInfo**)&((*ppStruct)->pApplicationInfo), pInStruct->pApplicationInfo);
    uint32_t i, siz = 0;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->ppEnabledLayerNames), pInStruct->enabledLayerCount * sizeof(char*), pInStruct->ppEnabledLayerNames);
    if (pInStruct->enabledLayerCount > 0) 
    {
        for (i = 0; i < pInStruct->enabledLayerCount; i++) {
            siz = (uint32_t) (1 + strlen(pInStruct->ppEnabledLayerNames[i]));
            vktrace_add_buffer_to_trace_packet(pHeader, (void**)(&(*ppStruct)->ppEnabledLayerNames[i]), siz, pInStruct->ppEnabledLayerNames[i]);
            vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledLayerNames[i]);
        }
    }
    vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledLayerNames);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->ppEnabledExtensionNames), pInStruct->enabledExtensionCount * sizeof(char*), pInStruct->ppEnabledExtensionNames);
    if (pInStruct->enabledExtensionCount > 0) 
    {
        for (i = 0; i < pInStruct->enabledExtensionCount; i++) {
            siz = (uint32_t) (1 + strlen(pInStruct->ppEnabledExtensionNames[i]));
            vktrace_add_buffer_to_trace_packet(pHeader, (void**)(&(*ppStruct)->ppEnabledExtensionNames[i]), siz, pInStruct->ppEnabledExtensionNames[i]);
            vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledExtensionNames[i]);
        }
    }
    vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledExtensionNames);
    vktrace_finalize_buffer_address(pHeader, (void**)ppStruct);
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #594
static void add_VkDeviceCreateInfo_to_packet(vktrace_trace_packet_header*  pHeader, VkDeviceCreateInfo** ppStruct, const VkDeviceCreateInfo *pInStruct)
{
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)ppStruct, sizeof(VkDeviceCreateInfo), pInStruct);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(*ppStruct)->pQueueCreateInfos, pInStruct->queueCreateInfoCount*sizeof(VkDeviceQueueCreateInfo), pInStruct->pQueueCreateInfos);
    for (uint32_t i = 0; i < pInStruct->queueCreateInfoCount; i++) {
        vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(*ppStruct)->pQueueCreateInfos[i].pQueuePriorities,
                                   pInStruct->pQueueCreateInfos[i].queueCount*sizeof(float),
                                   pInStruct->pQueueCreateInfos[i].pQueuePriorities);
        vktrace_finalize_buffer_address(pHeader, (void**)&(*ppStruct)->pQueueCreateInfos[i].pQueuePriorities);
    }
    vktrace_finalize_buffer_address(pHeader, (void**)&(*ppStruct)->pQueueCreateInfos);
    uint32_t i, siz = 0;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->ppEnabledLayerNames), pInStruct->enabledLayerCount * sizeof(char*), pInStruct->ppEnabledLayerNames);
    if (pInStruct->enabledLayerCount > 0) 
    {
        for (i = 0; i < pInStruct->enabledLayerCount; i++) {
            siz = (uint32_t) (1 + strlen(pInStruct->ppEnabledLayerNames[i]));
            vktrace_add_buffer_to_trace_packet(pHeader, (void**)(&(*ppStruct)->ppEnabledLayerNames[i]), siz, pInStruct->ppEnabledLayerNames[i]);
            vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledLayerNames[i]);
        }
    }
    vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledLayerNames);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&((*ppStruct)->ppEnabledExtensionNames), pInStruct->enabledExtensionCount * sizeof(char*), pInStruct->ppEnabledExtensionNames);
    if (pInStruct->enabledExtensionCount > 0) 
    {
        for (i = 0; i < pInStruct->enabledExtensionCount; i++) {
            siz = (uint32_t) (1 + strlen(pInStruct->ppEnabledExtensionNames[i]));
            vktrace_add_buffer_to_trace_packet(pHeader, (void**)(&(*ppStruct)->ppEnabledExtensionNames[i]), siz, pInStruct->ppEnabledExtensionNames[i]);
            vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledExtensionNames[i]);
        }
    }
    vktrace_finalize_buffer_address(pHeader, (void **)&(*ppStruct)->ppEnabledExtensionNames);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(*ppStruct)->pEnabledFeatures, sizeof(VkPhysicalDeviceFeatures), pInStruct->pEnabledFeatures);
    vktrace_finalize_buffer_address(pHeader, (void**)&(*ppStruct)->pEnabledFeatures);
    vktrace_finalize_buffer_address(pHeader, (void**)ppStruct);
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #632
//=============================================================================

static VkInstanceCreateInfo* interpret_VkInstanceCreateInfo(vktrace_trace_packet_header*  pHeader, intptr_t ptr_variable)
{
    VkInstanceCreateInfo* pVkInstanceCreateInfo = (VkInstanceCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)ptr_variable);

    uint32_t i;
    if (pVkInstanceCreateInfo != NULL)
    {
        pVkInstanceCreateInfo->pApplicationInfo = (VkApplicationInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->pApplicationInfo);
        VkApplicationInfo** ppApplicationInfo = (VkApplicationInfo**) &pVkInstanceCreateInfo->pApplicationInfo;
        (*ppApplicationInfo)->pApplicationName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->pApplicationInfo->pApplicationName);
        (*ppApplicationInfo)->pEngineName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->pApplicationInfo->pEngineName);
        if (pVkInstanceCreateInfo->enabledLayerCount > 0)
        {
            pVkInstanceCreateInfo->ppEnabledLayerNames = (const char* const*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->ppEnabledLayerNames);
            for (i = 0; i < pVkInstanceCreateInfo->enabledLayerCount; i++) {
                char** ppTmp = (char**)&pVkInstanceCreateInfo->ppEnabledLayerNames[i];
                *ppTmp = (char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->ppEnabledLayerNames[i]);
            }
        }
        if (pVkInstanceCreateInfo->enabledExtensionCount > 0)
        {
            pVkInstanceCreateInfo->ppEnabledExtensionNames = (const char* const*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->ppEnabledExtensionNames);
            for (i = 0; i < pVkInstanceCreateInfo->enabledExtensionCount; i++) {
                char** ppTmp = (char**)&pVkInstanceCreateInfo->ppEnabledExtensionNames[i];
                *ppTmp = (char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkInstanceCreateInfo->ppEnabledExtensionNames[i]);
            }
        }
    }

    return pVkInstanceCreateInfo;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #663
static VkDeviceCreateInfo* interpret_VkDeviceCreateInfo(vktrace_trace_packet_header*  pHeader, intptr_t ptr_variable)
{
    VkDeviceCreateInfo* pVkDeviceCreateInfo = (VkDeviceCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)ptr_variable);

    uint32_t i;
    if (pVkDeviceCreateInfo != NULL)
    {
        if (pVkDeviceCreateInfo->queueCreateInfoCount > 0)
        {
            pVkDeviceCreateInfo->pQueueCreateInfos = (const VkDeviceQueueCreateInfo *)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->pQueueCreateInfos);
            for (i = 0; i < pVkDeviceCreateInfo->queueCreateInfoCount; i++) {
                float** ppQueuePriority = (float**)&pVkDeviceCreateInfo->pQueueCreateInfos[i].pQueuePriorities;
                *ppQueuePriority = (float*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->pQueueCreateInfos[i].pQueuePriorities);
            }
        }
        if (pVkDeviceCreateInfo->enabledLayerCount > 0)
        {
            pVkDeviceCreateInfo->ppEnabledLayerNames = (const char* const*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->ppEnabledLayerNames);
            for (i = 0; i < pVkDeviceCreateInfo->enabledLayerCount; i++) {
                char** ppTmp = (char**)&pVkDeviceCreateInfo->ppEnabledLayerNames[i];
                *ppTmp = (char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->ppEnabledLayerNames[i]);
            }
        }
        if (pVkDeviceCreateInfo->enabledExtensionCount > 0)
        {
            pVkDeviceCreateInfo->ppEnabledExtensionNames = (const char* const*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->ppEnabledExtensionNames);
            for (i = 0; i < pVkDeviceCreateInfo->enabledExtensionCount; i++) {
                char** ppTmp = (char**)&pVkDeviceCreateInfo->ppEnabledExtensionNames[i];
                *ppTmp = (char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->ppEnabledExtensionNames[i]);
            }
        }
        pVkDeviceCreateInfo->pEnabledFeatures = (const VkPhysicalDeviceFeatures*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pVkDeviceCreateInfo->pEnabledFeatures);

    }

    return pVkDeviceCreateInfo;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #698
static void interpret_VkPipelineShaderStageCreateInfo(vktrace_trace_packet_header*  pHeader, VkPipelineShaderStageCreateInfo* pShader)
{
    if (pShader != NULL)
    {
        pShader->pName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pShader->pName);
        // specialization info
        pShader->pSpecializationInfo = (const VkSpecializationInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pShader->pSpecializationInfo);
        if (pShader->pSpecializationInfo != NULL)
        {
            VkSpecializationInfo* pInfo = (VkSpecializationInfo*)pShader->pSpecializationInfo;
            pInfo->pMapEntries = (const VkSpecializationMapEntry*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pShader->pSpecializationInfo->pMapEntries);
            pInfo->pData = (const void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pShader->pSpecializationInfo->pData);
        }
    }
}

//=============================================================================
typedef struct packet_vkApiVersion {
    vktrace_trace_packet_header* header;
    uint32_t version;
} packet_vkApiVersion;

static packet_vkApiVersion* interpret_body_as_vkApiVersion(vktrace_trace_packet_header* pHeader)
{
    packet_vkApiVersion* pPacket = (packet_vkApiVersion*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateInstance {
    vktrace_trace_packet_header* header;
    const VkInstanceCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkInstance* pInstance;
    VkResult result;
} packet_vkCreateInstance;

static packet_vkCreateInstance* interpret_body_as_vkCreateInstance(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateInstance* pPacket = (packet_vkCreateInstance*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = interpret_VkInstanceCreateInfo(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pInstance = (VkInstance*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pInstance);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyInstance {
    vktrace_trace_packet_header* header;
    VkInstance instance;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyInstance;

static packet_vkDestroyInstance* interpret_body_as_vkDestroyInstance(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyInstance* pPacket = (packet_vkDestroyInstance*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEnumeratePhysicalDevices {
    vktrace_trace_packet_header* header;
    VkInstance instance;
    uint32_t* pPhysicalDeviceCount;
    VkPhysicalDevice* pPhysicalDevices;
    VkResult result;
} packet_vkEnumeratePhysicalDevices;

static packet_vkEnumeratePhysicalDevices* interpret_body_as_vkEnumeratePhysicalDevices(vktrace_trace_packet_header* pHeader)
{
    packet_vkEnumeratePhysicalDevices* pPacket = (packet_vkEnumeratePhysicalDevices*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPhysicalDeviceCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPhysicalDeviceCount);
    pPacket->pPhysicalDevices = (VkPhysicalDevice*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPhysicalDevices);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceFeatures {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkPhysicalDeviceFeatures* pFeatures;
} packet_vkGetPhysicalDeviceFeatures;

static packet_vkGetPhysicalDeviceFeatures* interpret_body_as_vkGetPhysicalDeviceFeatures(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceFeatures* pPacket = (packet_vkGetPhysicalDeviceFeatures*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pFeatures = (VkPhysicalDeviceFeatures*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFeatures);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceFormatProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkFormatProperties* pFormatProperties;
} packet_vkGetPhysicalDeviceFormatProperties;

static packet_vkGetPhysicalDeviceFormatProperties* interpret_body_as_vkGetPhysicalDeviceFormatProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceFormatProperties* pPacket = (packet_vkGetPhysicalDeviceFormatProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pFormatProperties = (VkFormatProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFormatProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceImageFormatProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkImageFormatProperties* pImageFormatProperties;
    VkResult result;
} packet_vkGetPhysicalDeviceImageFormatProperties;

static packet_vkGetPhysicalDeviceImageFormatProperties* interpret_body_as_vkGetPhysicalDeviceImageFormatProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceImageFormatProperties* pPacket = (packet_vkGetPhysicalDeviceImageFormatProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pImageFormatProperties = (VkImageFormatProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pImageFormatProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkPhysicalDeviceProperties* pProperties;
} packet_vkGetPhysicalDeviceProperties;

static packet_vkGetPhysicalDeviceProperties* interpret_body_as_vkGetPhysicalDeviceProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceProperties* pPacket = (packet_vkGetPhysicalDeviceProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pProperties = (VkPhysicalDeviceProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceQueueFamilyProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    uint32_t* pQueueFamilyPropertyCount;
    VkQueueFamilyProperties* pQueueFamilyProperties;
} packet_vkGetPhysicalDeviceQueueFamilyProperties;

static packet_vkGetPhysicalDeviceQueueFamilyProperties* interpret_body_as_vkGetPhysicalDeviceQueueFamilyProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceQueueFamilyProperties* pPacket = (packet_vkGetPhysicalDeviceQueueFamilyProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pQueueFamilyPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pQueueFamilyPropertyCount);
    pPacket->pQueueFamilyProperties = (VkQueueFamilyProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pQueueFamilyProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceMemoryProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkPhysicalDeviceMemoryProperties* pMemoryProperties;
} packet_vkGetPhysicalDeviceMemoryProperties;

static packet_vkGetPhysicalDeviceMemoryProperties* interpret_body_as_vkGetPhysicalDeviceMemoryProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceMemoryProperties* pPacket = (packet_vkGetPhysicalDeviceMemoryProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryProperties = (VkPhysicalDeviceMemoryProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetInstanceProcAddr {
    vktrace_trace_packet_header* header;
    VkInstance instance;
    const char* pName;
    PFN_vkVoidFunction result;
} packet_vkGetInstanceProcAddr;

static packet_vkGetInstanceProcAddr* interpret_body_as_vkGetInstanceProcAddr(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetInstanceProcAddr* pPacket = (packet_vkGetInstanceProcAddr*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pName);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetDeviceProcAddr {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const char* pName;
    PFN_vkVoidFunction result;
} packet_vkGetDeviceProcAddr;

static packet_vkGetDeviceProcAddr* interpret_body_as_vkGetDeviceProcAddr(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetDeviceProcAddr* pPacket = (packet_vkGetDeviceProcAddr*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pName);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateDevice {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    const VkDeviceCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkDevice* pDevice;
    VkResult result;
} packet_vkCreateDevice;

static packet_vkCreateDevice* interpret_body_as_vkCreateDevice(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateDevice* pPacket = (packet_vkCreateDevice*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = interpret_VkDeviceCreateInfo(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pDevice = (VkDevice*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDevice);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyDevice {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyDevice;

static packet_vkDestroyDevice* interpret_body_as_vkDestroyDevice(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyDevice* pPacket = (packet_vkDestroyDevice*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEnumerateInstanceExtensionProperties {
    vktrace_trace_packet_header* header;
    const char* pLayerName;
    uint32_t* pPropertyCount;
    VkExtensionProperties* pProperties;
    VkResult result;
} packet_vkEnumerateInstanceExtensionProperties;

static packet_vkEnumerateInstanceExtensionProperties* interpret_body_as_vkEnumerateInstanceExtensionProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkEnumerateInstanceExtensionProperties* pPacket = (packet_vkEnumerateInstanceExtensionProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pLayerName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pLayerName);
    pPacket->pPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPropertyCount);
    pPacket->pProperties = (VkExtensionProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEnumerateDeviceExtensionProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    const char* pLayerName;
    uint32_t* pPropertyCount;
    VkExtensionProperties* pProperties;
    VkResult result;
} packet_vkEnumerateDeviceExtensionProperties;

static packet_vkEnumerateDeviceExtensionProperties* interpret_body_as_vkEnumerateDeviceExtensionProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkEnumerateDeviceExtensionProperties* pPacket = (packet_vkEnumerateDeviceExtensionProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pLayerName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pLayerName);
    pPacket->pPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPropertyCount);
    pPacket->pProperties = (VkExtensionProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEnumerateInstanceLayerProperties {
    vktrace_trace_packet_header* header;
    uint32_t* pPropertyCount;
    VkLayerProperties* pProperties;
    VkResult result;
} packet_vkEnumerateInstanceLayerProperties;

static packet_vkEnumerateInstanceLayerProperties* interpret_body_as_vkEnumerateInstanceLayerProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkEnumerateInstanceLayerProperties* pPacket = (packet_vkEnumerateInstanceLayerProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPropertyCount);
    pPacket->pProperties = (VkLayerProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEnumerateDeviceLayerProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    uint32_t* pPropertyCount;
    VkLayerProperties* pProperties;
    VkResult result;
} packet_vkEnumerateDeviceLayerProperties;

static packet_vkEnumerateDeviceLayerProperties* interpret_body_as_vkEnumerateDeviceLayerProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkEnumerateDeviceLayerProperties* pPacket = (packet_vkEnumerateDeviceLayerProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPropertyCount);
    pPacket->pProperties = (VkLayerProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetDeviceQueue {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    VkQueue* pQueue;
} packet_vkGetDeviceQueue;

static packet_vkGetDeviceQueue* interpret_body_as_vkGetDeviceQueue(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetDeviceQueue* pPacket = (packet_vkGetDeviceQueue*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pQueue = (VkQueue*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pQueue);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkQueueSubmit {
    vktrace_trace_packet_header* header;
    VkQueue queue;
    uint32_t submitCount;
    const VkSubmitInfo* pSubmits;
    VkFence fence;
    VkResult result;
} packet_vkQueueSubmit;

static packet_vkQueueSubmit* interpret_body_as_vkQueueSubmit(vktrace_trace_packet_header* pHeader)
{
    packet_vkQueueSubmit* pPacket = (packet_vkQueueSubmit*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSubmits = (const VkSubmitInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSubmits);
    if (pPacket->pSubmits != NULL)
    {
        uint32_t i;
        for (i = 0; i < pPacket->submitCount; i++) {
           VkCommandBuffer** ppCBs = (VkCommandBuffer**)&pPacket->pSubmits[i].pCommandBuffers;
           *ppCBs = (VkCommandBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSubmits[i].pCommandBuffers);
           VkSemaphore** ppSems = (VkSemaphore**)&pPacket->pSubmits[i].pWaitSemaphores;
           *ppSems = (VkSemaphore*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSubmits[i].pWaitSemaphores);
           ppSems = (VkSemaphore**)&pPacket->pSubmits[i].pSignalSemaphores;
           *ppSems = (VkSemaphore*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSubmits[i].pSignalSemaphores);
        }
    }
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkQueueWaitIdle {
    vktrace_trace_packet_header* header;
    VkQueue queue;
    VkResult result;
} packet_vkQueueWaitIdle;

static packet_vkQueueWaitIdle* interpret_body_as_vkQueueWaitIdle(vktrace_trace_packet_header* pHeader)
{
    packet_vkQueueWaitIdle* pPacket = (packet_vkQueueWaitIdle*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDeviceWaitIdle {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkResult result;
} packet_vkDeviceWaitIdle;

static packet_vkDeviceWaitIdle* interpret_body_as_vkDeviceWaitIdle(vktrace_trace_packet_header* pHeader)
{
    packet_vkDeviceWaitIdle* pPacket = (packet_vkDeviceWaitIdle*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkAllocateMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkMemoryAllocateInfo* pAllocateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkDeviceMemory* pMemory;
    VkResult result;
} packet_vkAllocateMemory;

static packet_vkAllocateMemory* interpret_body_as_vkAllocateMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkAllocateMemory* pPacket = (packet_vkAllocateMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocateInfo = (const VkMemoryAllocateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocateInfo);
    if (pPacket->pAllocateInfo != NULL)
    {
        if (pPacket->pAllocateInfo->sType == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO) {
            VkMemoryAllocateInfo** ppNext = (VkMemoryAllocateInfo**) &(pPacket->pAllocateInfo->pNext);
            *ppNext = (VkMemoryAllocateInfo*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocateInfo->pNext);
        } else {
            // This is unexpected.
            vktrace_LogError("AllocateMemory must have AllocInfo stype of VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO.");
            pPacket->header = NULL;
        }
    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pMemory = (VkDeviceMemory*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemory);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkFreeMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDeviceMemory memory;
    const VkAllocationCallbacks* pAllocator;
} packet_vkFreeMemory;

static packet_vkFreeMemory* interpret_body_as_vkFreeMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkFreeMemory* pPacket = (packet_vkFreeMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkMapMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDeviceMemory memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    void** ppData;
    VkResult result;
} packet_vkMapMemory;

static packet_vkMapMemory* interpret_body_as_vkMapMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkMapMemory* pPacket = (packet_vkMapMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->ppData = (void**)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->ppData);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkUnmapMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDeviceMemory memory;
    void* pData;
} packet_vkUnmapMemory;

static packet_vkUnmapMemory* interpret_body_as_vkUnmapMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkUnmapMemory* pPacket = (packet_vkUnmapMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pData = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pData);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkFlushMappedMemoryRanges {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t memoryRangeCount;
    const VkMappedMemoryRange* pMemoryRanges;
    void** ppData;
    VkResult result;
} packet_vkFlushMappedMemoryRanges;

static packet_vkFlushMappedMemoryRanges* interpret_body_as_vkFlushMappedMemoryRanges(vktrace_trace_packet_header* pHeader)
{
    packet_vkFlushMappedMemoryRanges* pPacket = (packet_vkFlushMappedMemoryRanges*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryRanges = (const VkMappedMemoryRange*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryRanges);
    pPacket->ppData = (void**)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->ppData);
    if (pPacket->ppData != NULL)
    {
        uint32_t i = 0;
        for (i = 0; i < pPacket->memoryRangeCount; i++)
        {
            pPacket->ppData[i] = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->ppData[i]);
        }
    }
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkInvalidateMappedMemoryRanges {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t memoryRangeCount;
    const VkMappedMemoryRange* pMemoryRanges;
    VkResult result;
} packet_vkInvalidateMappedMemoryRanges;

static packet_vkInvalidateMappedMemoryRanges* interpret_body_as_vkInvalidateMappedMemoryRanges(vktrace_trace_packet_header* pHeader)
{
    packet_vkInvalidateMappedMemoryRanges* pPacket = (packet_vkInvalidateMappedMemoryRanges*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryRanges = (const VkMappedMemoryRange*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryRanges);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetDeviceMemoryCommitment {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDeviceMemory memory;
    VkDeviceSize* pCommittedMemoryInBytes;
} packet_vkGetDeviceMemoryCommitment;

static packet_vkGetDeviceMemoryCommitment* interpret_body_as_vkGetDeviceMemoryCommitment(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetDeviceMemoryCommitment* pPacket = (packet_vkGetDeviceMemoryCommitment*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCommittedMemoryInBytes = (VkDeviceSize*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCommittedMemoryInBytes);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkBindBufferMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkBuffer buffer;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    VkResult result;
} packet_vkBindBufferMemory;

static packet_vkBindBufferMemory* interpret_body_as_vkBindBufferMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkBindBufferMemory* pPacket = (packet_vkBindBufferMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkBindImageMemory {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImage image;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    VkResult result;
} packet_vkBindImageMemory;

static packet_vkBindImageMemory* interpret_body_as_vkBindImageMemory(vktrace_trace_packet_header* pHeader)
{
    packet_vkBindImageMemory* pPacket = (packet_vkBindImageMemory*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetBufferMemoryRequirements {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkBuffer buffer;
    VkMemoryRequirements* pMemoryRequirements;
} packet_vkGetBufferMemoryRequirements;

static packet_vkGetBufferMemoryRequirements* interpret_body_as_vkGetBufferMemoryRequirements(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetBufferMemoryRequirements* pPacket = (packet_vkGetBufferMemoryRequirements*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryRequirements = (VkMemoryRequirements*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryRequirements);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetImageMemoryRequirements {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImage image;
    VkMemoryRequirements* pMemoryRequirements;
} packet_vkGetImageMemoryRequirements;

static packet_vkGetImageMemoryRequirements* interpret_body_as_vkGetImageMemoryRequirements(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetImageMemoryRequirements* pPacket = (packet_vkGetImageMemoryRequirements*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryRequirements = (VkMemoryRequirements*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryRequirements);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetImageSparseMemoryRequirements {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImage image;
    uint32_t* pSparseMemoryRequirementCount;
    VkSparseImageMemoryRequirements* pSparseMemoryRequirements;
} packet_vkGetImageSparseMemoryRequirements;

static packet_vkGetImageSparseMemoryRequirements* interpret_body_as_vkGetImageSparseMemoryRequirements(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetImageSparseMemoryRequirements* pPacket = (packet_vkGetImageSparseMemoryRequirements*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSparseMemoryRequirementCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSparseMemoryRequirementCount);
    pPacket->pSparseMemoryRequirements = (VkSparseImageMemoryRequirements*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSparseMemoryRequirements);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceSparseImageFormatProperties {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    uint32_t* pPropertyCount;
    VkSparseImageFormatProperties* pProperties;
} packet_vkGetPhysicalDeviceSparseImageFormatProperties;

static packet_vkGetPhysicalDeviceSparseImageFormatProperties* interpret_body_as_vkGetPhysicalDeviceSparseImageFormatProperties(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceSparseImageFormatProperties* pPacket = (packet_vkGetPhysicalDeviceSparseImageFormatProperties*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPropertyCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPropertyCount);
    pPacket->pProperties = (VkSparseImageFormatProperties*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pProperties);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkQueueBindSparse {
    vktrace_trace_packet_header* header;
    VkQueue queue;
    uint32_t bindInfoCount;
    const VkBindSparseInfo* pBindInfo;
    VkFence fence;
    VkResult result;
} packet_vkQueueBindSparse;

static packet_vkQueueBindSparse* interpret_body_as_vkQueueBindSparse(vktrace_trace_packet_header* pHeader)
{
    packet_vkQueueBindSparse* pPacket = (packet_vkQueueBindSparse*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pBindInfo = (const VkBindSparseInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBindInfo);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateFence {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkFenceCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkFence* pFence;
    VkResult result;
} packet_vkCreateFence;

static packet_vkCreateFence* interpret_body_as_vkCreateFence(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateFence* pPacket = (packet_vkCreateFence*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkFenceCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pFence = (VkFence*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFence);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyFence {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkFence fence;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyFence;

static packet_vkDestroyFence* interpret_body_as_vkDestroyFence(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyFence* pPacket = (packet_vkDestroyFence*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkResetFences {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t fenceCount;
    const VkFence* pFences;
    VkResult result;
} packet_vkResetFences;

static packet_vkResetFences* interpret_body_as_vkResetFences(vktrace_trace_packet_header* pHeader)
{
    packet_vkResetFences* pPacket = (packet_vkResetFences*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pFences = (const VkFence*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFences);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetFenceStatus {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkFence fence;
    VkResult result;
} packet_vkGetFenceStatus;

static packet_vkGetFenceStatus* interpret_body_as_vkGetFenceStatus(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetFenceStatus* pPacket = (packet_vkGetFenceStatus*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkWaitForFences {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t fenceCount;
    const VkFence* pFences;
    VkBool32 waitAll;
    uint64_t timeout;
    VkResult result;
} packet_vkWaitForFences;

static packet_vkWaitForFences* interpret_body_as_vkWaitForFences(vktrace_trace_packet_header* pHeader)
{
    packet_vkWaitForFences* pPacket = (packet_vkWaitForFences*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pFences = (const VkFence*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFences);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateSemaphore {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkSemaphoreCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkSemaphore* pSemaphore;
    VkResult result;
} packet_vkCreateSemaphore;

static packet_vkCreateSemaphore* interpret_body_as_vkCreateSemaphore(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateSemaphore* pPacket = (packet_vkCreateSemaphore*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkSemaphoreCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pSemaphore = (VkSemaphore*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSemaphore);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroySemaphore {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkSemaphore semaphore;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroySemaphore;

static packet_vkDestroySemaphore* interpret_body_as_vkDestroySemaphore(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroySemaphore* pPacket = (packet_vkDestroySemaphore*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateEvent {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkEventCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkEvent* pEvent;
    VkResult result;
} packet_vkCreateEvent;

static packet_vkCreateEvent* interpret_body_as_vkCreateEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateEvent* pPacket = (packet_vkCreateEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkEventCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pEvent = (VkEvent*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pEvent);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyEvent {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkEvent event;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyEvent;

static packet_vkDestroyEvent* interpret_body_as_vkDestroyEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyEvent* pPacket = (packet_vkDestroyEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetEventStatus {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkEvent event;
    VkResult result;
} packet_vkGetEventStatus;

static packet_vkGetEventStatus* interpret_body_as_vkGetEventStatus(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetEventStatus* pPacket = (packet_vkGetEventStatus*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkSetEvent {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkEvent event;
    VkResult result;
} packet_vkSetEvent;

static packet_vkSetEvent* interpret_body_as_vkSetEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkSetEvent* pPacket = (packet_vkSetEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkResetEvent {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkEvent event;
    VkResult result;
} packet_vkResetEvent;

static packet_vkResetEvent* interpret_body_as_vkResetEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkResetEvent* pPacket = (packet_vkResetEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateQueryPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkQueryPoolCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkQueryPool* pQueryPool;
    VkResult result;
} packet_vkCreateQueryPool;

static packet_vkCreateQueryPool* interpret_body_as_vkCreateQueryPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateQueryPool* pPacket = (packet_vkCreateQueryPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkQueryPoolCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pQueryPool = (VkQueryPool*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pQueryPool);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyQueryPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkQueryPool queryPool;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyQueryPool;

static packet_vkDestroyQueryPool* interpret_body_as_vkDestroyQueryPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyQueryPool* pPacket = (packet_vkDestroyQueryPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetQueryPoolResults {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    void* pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
    VkResult result;
} packet_vkGetQueryPoolResults;

static packet_vkGetQueryPoolResults* interpret_body_as_vkGetQueryPoolResults(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetQueryPoolResults* pPacket = (packet_vkGetQueryPoolResults*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pData = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pData);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateBuffer {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkBufferCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkBuffer* pBuffer;
    VkResult result;
} packet_vkCreateBuffer;

static packet_vkCreateBuffer* interpret_body_as_vkCreateBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateBuffer* pPacket = (packet_vkCreateBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkBufferCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pBuffer = (VkBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBuffer);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyBuffer {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkBuffer buffer;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyBuffer;

static packet_vkDestroyBuffer* interpret_body_as_vkDestroyBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyBuffer* pPacket = (packet_vkDestroyBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateBufferView {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkBufferViewCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkBufferView* pView;
    VkResult result;
} packet_vkCreateBufferView;

static packet_vkCreateBufferView* interpret_body_as_vkCreateBufferView(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateBufferView* pPacket = (packet_vkCreateBufferView*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkBufferViewCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pView = (VkBufferView*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pView);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyBufferView {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkBufferView bufferView;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyBufferView;

static packet_vkDestroyBufferView* interpret_body_as_vkDestroyBufferView(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyBufferView* pPacket = (packet_vkDestroyBufferView*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateImage {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkImageCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkImage* pImage;
    VkResult result;
} packet_vkCreateImage;

static packet_vkCreateImage* interpret_body_as_vkCreateImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateImage* pPacket = (packet_vkCreateImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkImageCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pImage = (VkImage*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pImage);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyImage {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImage image;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyImage;

static packet_vkDestroyImage* interpret_body_as_vkDestroyImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyImage* pPacket = (packet_vkDestroyImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetImageSubresourceLayout {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImage image;
    const VkImageSubresource* pSubresource;
    VkSubresourceLayout* pLayout;
} packet_vkGetImageSubresourceLayout;

static packet_vkGetImageSubresourceLayout* interpret_body_as_vkGetImageSubresourceLayout(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetImageSubresourceLayout* pPacket = (packet_vkGetImageSubresourceLayout*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSubresource = (const VkImageSubresource*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSubresource);
    pPacket->pLayout = (VkSubresourceLayout*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pLayout);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateImageView {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkImageViewCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkImageView* pView;
    VkResult result;
} packet_vkCreateImageView;

static packet_vkCreateImageView* interpret_body_as_vkCreateImageView(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateImageView* pPacket = (packet_vkCreateImageView*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkImageViewCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pView = (VkImageView*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pView);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyImageView {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkImageView imageView;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyImageView;

static packet_vkDestroyImageView* interpret_body_as_vkDestroyImageView(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyImageView* pPacket = (packet_vkDestroyImageView*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateShaderModule {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkShaderModuleCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkShaderModule* pShaderModule;
    VkResult result;
} packet_vkCreateShaderModule;

static packet_vkCreateShaderModule* interpret_body_as_vkCreateShaderModule(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateShaderModule* pPacket = (packet_vkCreateShaderModule*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkShaderModuleCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        void** ppCode = (void**)&(pPacket->pCreateInfo->pCode);
        *ppCode = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo->pCode);
    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pShaderModule = (VkShaderModule*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pShaderModule);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyShaderModule {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkShaderModule shaderModule;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyShaderModule;

static packet_vkDestroyShaderModule* interpret_body_as_vkDestroyShaderModule(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyShaderModule* pPacket = (packet_vkDestroyShaderModule*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreatePipelineCache {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkPipelineCacheCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkPipelineCache* pPipelineCache;
    VkResult result;
} packet_vkCreatePipelineCache;

static packet_vkCreatePipelineCache* interpret_body_as_vkCreatePipelineCache(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreatePipelineCache* pPacket = (packet_vkCreatePipelineCache*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkPipelineCacheCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        ((VkPipelineCacheCreateInfo *)pPacket->pCreateInfo)->pInitialData = (const void*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo->pInitialData);

    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pPipelineCache = (VkPipelineCache*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPipelineCache);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyPipelineCache {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineCache pipelineCache;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyPipelineCache;

static packet_vkDestroyPipelineCache* interpret_body_as_vkDestroyPipelineCache(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyPipelineCache* pPacket = (packet_vkDestroyPipelineCache*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPipelineCacheData {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineCache pipelineCache;
    size_t* pDataSize;
    void* pData;
    VkResult result;
} packet_vkGetPipelineCacheData;

static packet_vkGetPipelineCacheData* interpret_body_as_vkGetPipelineCacheData(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPipelineCacheData* pPacket = (packet_vkGetPipelineCacheData*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pDataSize = (size_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDataSize);
    pPacket->pData = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pData);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkMergePipelineCaches {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineCache dstCache;
    uint32_t srcCacheCount;
    const VkPipelineCache* pSrcCaches;
    VkResult result;
} packet_vkMergePipelineCaches;

static packet_vkMergePipelineCaches* interpret_body_as_vkMergePipelineCaches(vktrace_trace_packet_header* pHeader)
{
    packet_vkMergePipelineCaches* pPacket = (packet_vkMergePipelineCaches*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSrcCaches = (const VkPipelineCache*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSrcCaches);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateGraphicsPipelines {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineCache pipelineCache;
    uint32_t createInfoCount;
    const VkGraphicsPipelineCreateInfo* pCreateInfos;
    const VkAllocationCallbacks* pAllocator;
    VkPipeline* pPipelines;
    VkResult result;
} packet_vkCreateGraphicsPipelines;

static packet_vkCreateGraphicsPipelines* interpret_body_as_vkCreateGraphicsPipelines(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateGraphicsPipelines* pPacket = (packet_vkCreateGraphicsPipelines*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfos = (const VkGraphicsPipelineCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos);
    if (pPacket->pCreateInfos != NULL)
    {
        uint32_t i;
        uint32_t j;
        for (i=0; i<pPacket->createInfoCount; i++) {
        if (pPacket->pCreateInfos[i].sType == VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO) {
        // need to make a non-const pointer to the pointer so that we can properly change the original pointer to the interpretted one
        VkGraphicsPipelineCreateInfo* pNonConst = (VkGraphicsPipelineCreateInfo*)&(pPacket->pCreateInfos[i]);
        // shader stages array
        pNonConst->pStages = (VkPipelineShaderStageCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pStages);
        for (j = 0; j < pPacket->pCreateInfos[i].stageCount; j++)
        {
            interpret_VkPipelineShaderStageCreateInfo(pHeader, (VkPipelineShaderStageCreateInfo*)&pPacket->pCreateInfos[i].pStages[j]);
        }
        // Vertex Input State
        pNonConst->pVertexInputState = (VkPipelineVertexInputStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pVertexInputState);
        VkPipelineVertexInputStateCreateInfo* pNonConstVIState = (VkPipelineVertexInputStateCreateInfo*)pNonConst->pVertexInputState;
        if (pNonConstVIState) {
            pNonConstVIState->pVertexBindingDescriptions = (const VkVertexInputBindingDescription*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pVertexInputState->pVertexBindingDescriptions);
            pNonConstVIState->pVertexAttributeDescriptions = (const VkVertexInputAttributeDescription*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pVertexInputState->pVertexAttributeDescriptions);
        }
        // Input Assembly State
        pNonConst->pInputAssemblyState = (const VkPipelineInputAssemblyStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pInputAssemblyState);
        // Tesselation State
        pNonConst->pTessellationState = (const VkPipelineTessellationStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pTessellationState);
        // Viewport State
        pNonConst->pViewportState = (const VkPipelineViewportStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pViewportState);
        // Raster State
        pNonConst->pRasterizationState = (const VkPipelineRasterizationStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pRasterizationState);
        // MultiSample State
        pNonConst->pMultisampleState = (const VkPipelineMultisampleStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pMultisampleState);
        // DepthStencil State
        pNonConst->pDepthStencilState = (const VkPipelineDepthStencilStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pDepthStencilState);
        // DynamicState State
        pNonConst->pDynamicState = (const VkPipelineDynamicStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pDynamicState);
        VkPipelineDynamicStateCreateInfo* pNonConstDyState = (VkPipelineDynamicStateCreateInfo*)pNonConst->pDynamicState;
        if (pNonConstDyState) {
            pNonConstDyState->pDynamicStates = (const VkDynamicState*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pDynamicState->pDynamicStates);
        }
        // ColorBuffer State
        pNonConst->pColorBlendState = (const VkPipelineColorBlendStateCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pColorBlendState);
        VkPipelineColorBlendStateCreateInfo* pNonConstCbState = (VkPipelineColorBlendStateCreateInfo*)pNonConst->pColorBlendState;
        if (pNonConstCbState)
            pNonConstCbState->pAttachments = (const VkPipelineColorBlendAttachmentState*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos[i].pColorBlendState->pAttachments);
        } else {
            // This is unexpected.
            vktrace_LogError("CreateGraphicsPipelines must have CreateInfo stype of VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO.");
            pPacket->header = NULL;
        }
        }

    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pPipelines = (VkPipeline*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPipelines);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateComputePipelines {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineCache pipelineCache;
    uint32_t createInfoCount;
    const VkComputePipelineCreateInfo* pCreateInfos;
    const VkAllocationCallbacks* pAllocator;
    VkPipeline* pPipelines;
    VkResult result;
} packet_vkCreateComputePipelines;

static packet_vkCreateComputePipelines* interpret_body_as_vkCreateComputePipelines(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateComputePipelines* pPacket = (packet_vkCreateComputePipelines*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfos = (const VkComputePipelineCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfos);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pPipelines = (VkPipeline*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPipelines);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyPipeline {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipeline pipeline;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyPipeline;

static packet_vkDestroyPipeline* interpret_body_as_vkDestroyPipeline(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyPipeline* pPacket = (packet_vkDestroyPipeline*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreatePipelineLayout {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkPipelineLayoutCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkPipelineLayout* pPipelineLayout;
    VkResult result;
} packet_vkCreatePipelineLayout;

static packet_vkCreatePipelineLayout* interpret_body_as_vkCreatePipelineLayout(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreatePipelineLayout* pPacket = (packet_vkCreatePipelineLayout*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkPipelineLayoutCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        VkPipelineLayoutCreateInfo* pInfo = (VkPipelineLayoutCreateInfo*)pPacket->pCreateInfo;
        pInfo->pSetLayouts = (VkDescriptorSetLayout*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo->pSetLayouts);

    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pPipelineLayout = (VkPipelineLayout*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPipelineLayout);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyPipelineLayout {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkPipelineLayout pipelineLayout;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyPipelineLayout;

static packet_vkDestroyPipelineLayout* interpret_body_as_vkDestroyPipelineLayout(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyPipelineLayout* pPacket = (packet_vkDestroyPipelineLayout*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateSampler {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkSamplerCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkSampler* pSampler;
    VkResult result;
} packet_vkCreateSampler;

static packet_vkCreateSampler* interpret_body_as_vkCreateSampler(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateSampler* pPacket = (packet_vkCreateSampler*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkSamplerCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pSampler = (VkSampler*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSampler);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroySampler {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkSampler sampler;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroySampler;

static packet_vkDestroySampler* interpret_body_as_vkDestroySampler(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroySampler* pPacket = (packet_vkDestroySampler*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateDescriptorSetLayout {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkDescriptorSetLayout* pSetLayout;
    VkResult result;
} packet_vkCreateDescriptorSetLayout;

static packet_vkCreateDescriptorSetLayout* interpret_body_as_vkCreateDescriptorSetLayout(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateDescriptorSetLayout* pPacket = (packet_vkCreateDescriptorSetLayout*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkDescriptorSetLayoutCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        if (pPacket->pCreateInfo->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO) {
            VkDescriptorSetLayoutCreateInfo* pNext = (VkDescriptorSetLayoutCreateInfo*)pPacket->pCreateInfo;
            do
            {
                // need to make a non-const pointer to the pointer so that we can properly change the original pointer to the interpretted one
                void** ppNextVoidPtr = (void**)&(pNext->pNext);
                *ppNextVoidPtr = (void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pNext->pNext);
                switch(pNext->sType)
                {
                    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
                    {
                        unsigned int i = 0;
                        pNext->pBindings = (VkDescriptorSetLayoutBinding*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pNext->pBindings);
                        for (i = 0; i < pNext->bindingCount; i++)
                        {
                            VkSampler** ppSamplers = (VkSampler**)&(pNext->pBindings[i].pImmutableSamplers);
                            *ppSamplers = (VkSampler*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pNext->pBindings[i].pImmutableSamplers);
                        }
                        break;
                    }
                    default:
                    {
                        vktrace_LogError("Encountered an unexpected type in descriptor set layout create list.");
                        pPacket->header = NULL;
                        pNext->pNext = NULL;
                    }
                }
                pNext = (VkDescriptorSetLayoutCreateInfo*)pNext->pNext;
             }  while (NULL != pNext);
        } else {
             // This is unexpected.
             vktrace_LogError("CreateDescriptorSetLayout must have pCreateInfo->stype of VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO.");
             pPacket->header = NULL;
        }
    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pSetLayout = (VkDescriptorSetLayout*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSetLayout);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyDescriptorSetLayout {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDescriptorSetLayout descriptorSetLayout;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyDescriptorSetLayout;

static packet_vkDestroyDescriptorSetLayout* interpret_body_as_vkDestroyDescriptorSetLayout(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyDescriptorSetLayout* pPacket = (packet_vkDestroyDescriptorSetLayout*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateDescriptorPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkDescriptorPoolCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkDescriptorPool* pDescriptorPool;
    VkResult result;
} packet_vkCreateDescriptorPool;

static packet_vkCreateDescriptorPool* interpret_body_as_vkCreateDescriptorPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateDescriptorPool* pPacket = (packet_vkCreateDescriptorPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkDescriptorPoolCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        VkDescriptorPoolCreateInfo* pInfo = (VkDescriptorPoolCreateInfo*)pPacket->pCreateInfo;
        pInfo->pPoolSizes = (VkDescriptorPoolSize*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo->pPoolSizes);

    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pDescriptorPool = (VkDescriptorPool*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorPool);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyDescriptorPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDescriptorPool descriptorPool;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyDescriptorPool;

static packet_vkDestroyDescriptorPool* interpret_body_as_vkDestroyDescriptorPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyDescriptorPool* pPacket = (packet_vkDestroyDescriptorPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkResetDescriptorPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDescriptorPool descriptorPool;
    VkDescriptorPoolResetFlags flags;
    VkResult result;
} packet_vkResetDescriptorPool;

static packet_vkResetDescriptorPool* interpret_body_as_vkResetDescriptorPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkResetDescriptorPool* pPacket = (packet_vkResetDescriptorPool*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkAllocateDescriptorSets {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkDescriptorSetAllocateInfo* pAllocateInfo;
    VkDescriptorSet* pDescriptorSets;
    VkResult result;
} packet_vkAllocateDescriptorSets;

static packet_vkAllocateDescriptorSets* interpret_body_as_vkAllocateDescriptorSets(vktrace_trace_packet_header* pHeader)
{
    packet_vkAllocateDescriptorSets* pPacket = (packet_vkAllocateDescriptorSets*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocateInfo = (const VkDescriptorSetAllocateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocateInfo);
    if (pPacket->pAllocateInfo != NULL)
    {
        VkDescriptorSetLayout **ppDescSetLayout = (VkDescriptorSetLayout **) &pPacket->pAllocateInfo->pSetLayouts;
        *ppDescSetLayout = (VkDescriptorSetLayout *) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pAllocateInfo->pSetLayouts));
    }
    pPacket->pDescriptorSets = (VkDescriptorSet*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorSets);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkFreeDescriptorSets {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkDescriptorPool descriptorPool;
    uint32_t descriptorSetCount;
    const VkDescriptorSet* pDescriptorSets;
    VkResult result;
} packet_vkFreeDescriptorSets;

static packet_vkFreeDescriptorSets* interpret_body_as_vkFreeDescriptorSets(vktrace_trace_packet_header* pHeader)
{
    packet_vkFreeDescriptorSets* pPacket = (packet_vkFreeDescriptorSets*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pDescriptorSets = (const VkDescriptorSet*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorSets);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkUpdateDescriptorSets {
    vktrace_trace_packet_header* header;
    VkDevice device;
    uint32_t descriptorWriteCount;
    const VkWriteDescriptorSet* pDescriptorWrites;
    uint32_t descriptorCopyCount;
    const VkCopyDescriptorSet* pDescriptorCopies;
} packet_vkUpdateDescriptorSets;

static packet_vkUpdateDescriptorSets* interpret_body_as_vkUpdateDescriptorSets(vktrace_trace_packet_header* pHeader)
{
    packet_vkUpdateDescriptorSets* pPacket = (packet_vkUpdateDescriptorSets*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pDescriptorWrites = (const VkWriteDescriptorSet*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorWrites);
    if (pPacket->pDescriptorWrites != NULL)
    {
        uint32_t i;
        for (i = 0; i < pPacket->descriptorWriteCount; i++) {
            switch (pPacket->pDescriptorWrites[i].descriptorType) {            case VK_DESCRIPTOR_TYPE_SAMPLER:            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:                {                    VkDescriptorImageInfo** ppImageInfo = (VkDescriptorImageInfo**)&pPacket->pDescriptorWrites[i].pImageInfo;
                    *ppImageInfo = (VkDescriptorImageInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorWrites[i].pImageInfo);
                }                break;            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:                {                    VkBufferView** ppTexelBufferView = (VkBufferView**)&pPacket->pDescriptorWrites[i].pTexelBufferView;
                    *ppTexelBufferView = (VkBufferView*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorWrites[i].pTexelBufferView);
                }                break;            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:                {                    VkDescriptorBufferInfo** ppBufferInfo = (VkDescriptorBufferInfo**)&pPacket->pDescriptorWrites[i].pBufferInfo;
                    *ppBufferInfo = (VkDescriptorBufferInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorWrites[i].pBufferInfo);
                }                break;            default:                break;            }        }
    }
    pPacket->pDescriptorCopies = (const VkCopyDescriptorSet*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorCopies);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateFramebuffer {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkFramebufferCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkFramebuffer* pFramebuffer;
    VkResult result;
} packet_vkCreateFramebuffer;

static packet_vkCreateFramebuffer* interpret_body_as_vkCreateFramebuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateFramebuffer* pPacket = (packet_vkCreateFramebuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkFramebufferCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        VkImageView** ppAV = (VkImageView**)&(pPacket->pCreateInfo->pAttachments);
        *ppAV = (VkImageView*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pCreateInfo->pAttachments));
    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pFramebuffer = (VkFramebuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pFramebuffer);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyFramebuffer {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkFramebuffer framebuffer;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyFramebuffer;

static packet_vkDestroyFramebuffer* interpret_body_as_vkDestroyFramebuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyFramebuffer* pPacket = (packet_vkDestroyFramebuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateRenderPass {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkRenderPassCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkRenderPass* pRenderPass;
    VkResult result;
} packet_vkCreateRenderPass;

static packet_vkCreateRenderPass* interpret_body_as_vkCreateRenderPass(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateRenderPass* pPacket = (packet_vkCreateRenderPass*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkRenderPassCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        VkRenderPassCreateInfo* pInfo = (VkRenderPassCreateInfo*)pPacket->pCreateInfo;
        uint32_t i = 0;
        VkAttachmentDescription **ppAD = (VkAttachmentDescription **)&(pInfo->pAttachments);
        *ppAD = (VkAttachmentDescription*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pAttachments);
        VkSubpassDescription** ppSP = (VkSubpassDescription**)&(pInfo->pSubpasses);
        *ppSP = (VkSubpassDescription*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses);
        for (i=0; i<pInfo->subpassCount; i++) {
            VkAttachmentReference** pAR = (VkAttachmentReference**)&(pInfo->pSubpasses[i].pInputAttachments);
            *pAR = (VkAttachmentReference*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses[i].pInputAttachments);
            pAR = (VkAttachmentReference**)&(pInfo->pSubpasses[i].pColorAttachments);
            *pAR = (VkAttachmentReference*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses[i].pColorAttachments);
            pAR = (VkAttachmentReference**)&(pInfo->pSubpasses[i].pResolveAttachments);
            *pAR = (VkAttachmentReference*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses[i].pResolveAttachments);
            pAR = (VkAttachmentReference**)&(pInfo->pSubpasses[i].pDepthStencilAttachment);
            *pAR = (VkAttachmentReference*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses[i].pDepthStencilAttachment);
            pAR = (VkAttachmentReference**)&(pInfo->pSubpasses[i].pPreserveAttachments);
            *pAR = (VkAttachmentReference*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pSubpasses[i].pPreserveAttachments);
        }
        VkSubpassDependency** ppSD = (VkSubpassDependency**)&(pInfo->pDependencies);
        *ppSD = (VkSubpassDependency*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pInfo->pDependencies);

    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pRenderPass = (VkRenderPass*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRenderPass);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyRenderPass {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkRenderPass renderPass;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyRenderPass;

static packet_vkDestroyRenderPass* interpret_body_as_vkDestroyRenderPass(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyRenderPass* pPacket = (packet_vkDestroyRenderPass*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetRenderAreaGranularity {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkRenderPass renderPass;
    VkExtent2D* pGranularity;
} packet_vkGetRenderAreaGranularity;

static packet_vkGetRenderAreaGranularity* interpret_body_as_vkGetRenderAreaGranularity(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetRenderAreaGranularity* pPacket = (packet_vkGetRenderAreaGranularity*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pGranularity = (VkExtent2D*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pGranularity);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateCommandPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkCommandPoolCreateInfo* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkCommandPool* pCommandPool;
    VkResult result;
} packet_vkCreateCommandPool;

static packet_vkCreateCommandPool* interpret_body_as_vkCreateCommandPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateCommandPool* pPacket = (packet_vkCreateCommandPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkCommandPoolCreateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pCommandPool = (VkCommandPool*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCommandPool);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroyCommandPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkCommandPool commandPool;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyCommandPool;

static packet_vkDestroyCommandPool* interpret_body_as_vkDestroyCommandPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyCommandPool* pPacket = (packet_vkDestroyCommandPool*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkResetCommandPool {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkCommandPool commandPool;
    VkCommandPoolResetFlags flags;
    VkResult result;
} packet_vkResetCommandPool;

static packet_vkResetCommandPool* interpret_body_as_vkResetCommandPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkResetCommandPool* pPacket = (packet_vkResetCommandPool*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkAllocateCommandBuffers {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkCommandBufferAllocateInfo* pAllocateInfo;
    VkCommandBuffer* pCommandBuffers;
    VkResult result;
} packet_vkAllocateCommandBuffers;

static packet_vkAllocateCommandBuffers* interpret_body_as_vkAllocateCommandBuffers(vktrace_trace_packet_header* pHeader)
{
    packet_vkAllocateCommandBuffers* pPacket = (packet_vkAllocateCommandBuffers*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocateInfo = (const VkCommandBufferAllocateInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocateInfo);
    pPacket->pCommandBuffers = (VkCommandBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCommandBuffers);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkFreeCommandBuffers {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkCommandPool commandPool;
    uint32_t commandBufferCount;
    const VkCommandBuffer* pCommandBuffers;
} packet_vkFreeCommandBuffers;

static packet_vkFreeCommandBuffers* interpret_body_as_vkFreeCommandBuffers(vktrace_trace_packet_header* pHeader)
{
    packet_vkFreeCommandBuffers* pPacket = (packet_vkFreeCommandBuffers*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCommandBuffers = (const VkCommandBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCommandBuffers);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkBeginCommandBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    const VkCommandBufferBeginInfo* pBeginInfo;
    VkResult result;
} packet_vkBeginCommandBuffer;

static packet_vkBeginCommandBuffer* interpret_body_as_vkBeginCommandBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkBeginCommandBuffer* pPacket = (packet_vkBeginCommandBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pBeginInfo = (const VkCommandBufferBeginInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBeginInfo);
    if (pPacket->pBeginInfo != NULL)
    {
        VkCommandBufferBeginInfo* pInfo = (VkCommandBufferBeginInfo*) pPacket->pBeginInfo;
        pInfo->pInheritanceInfo = (VkCommandBufferInheritanceInfo*) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBeginInfo->pInheritanceInfo);

    }
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkEndCommandBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkResult result;
} packet_vkEndCommandBuffer;

static packet_vkEndCommandBuffer* interpret_body_as_vkEndCommandBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkEndCommandBuffer* pPacket = (packet_vkEndCommandBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkResetCommandBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult result;
} packet_vkResetCommandBuffer;

static packet_vkResetCommandBuffer* interpret_body_as_vkResetCommandBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkResetCommandBuffer* pPacket = (packet_vkResetCommandBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBindPipeline {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
} packet_vkCmdBindPipeline;

static packet_vkCmdBindPipeline* interpret_body_as_vkCmdBindPipeline(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBindPipeline* pPacket = (packet_vkCmdBindPipeline*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetViewport {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    const VkViewport* pViewports;
} packet_vkCmdSetViewport;

static packet_vkCmdSetViewport* interpret_body_as_vkCmdSetViewport(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetViewport* pPacket = (packet_vkCmdSetViewport*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pViewports = (const VkViewport*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pViewports);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetScissor {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    const VkRect2D* pScissors;
} packet_vkCmdSetScissor;

static packet_vkCmdSetScissor* interpret_body_as_vkCmdSetScissor(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetScissor* pPacket = (packet_vkCmdSetScissor*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pScissors = (const VkRect2D*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pScissors);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetLineWidth {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    float lineWidth;
} packet_vkCmdSetLineWidth;

static packet_vkCmdSetLineWidth* interpret_body_as_vkCmdSetLineWidth(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetLineWidth* pPacket = (packet_vkCmdSetLineWidth*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetDepthBias {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;
} packet_vkCmdSetDepthBias;

static packet_vkCmdSetDepthBias* interpret_body_as_vkCmdSetDepthBias(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetDepthBias* pPacket = (packet_vkCmdSetDepthBias*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetBlendConstants {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    const float blendConstants[4];
} packet_vkCmdSetBlendConstants;

static packet_vkCmdSetBlendConstants* interpret_body_as_vkCmdSetBlendConstants(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetBlendConstants* pPacket = (packet_vkCmdSetBlendConstants*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetDepthBounds {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;
} packet_vkCmdSetDepthBounds;

static packet_vkCmdSetDepthBounds* interpret_body_as_vkCmdSetDepthBounds(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetDepthBounds* pPacket = (packet_vkCmdSetDepthBounds*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetStencilCompareMask {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;
} packet_vkCmdSetStencilCompareMask;

static packet_vkCmdSetStencilCompareMask* interpret_body_as_vkCmdSetStencilCompareMask(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetStencilCompareMask* pPacket = (packet_vkCmdSetStencilCompareMask*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetStencilWriteMask {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;
} packet_vkCmdSetStencilWriteMask;

static packet_vkCmdSetStencilWriteMask* interpret_body_as_vkCmdSetStencilWriteMask(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetStencilWriteMask* pPacket = (packet_vkCmdSetStencilWriteMask*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetStencilReference {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;
} packet_vkCmdSetStencilReference;

static packet_vkCmdSetStencilReference* interpret_body_as_vkCmdSetStencilReference(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetStencilReference* pPacket = (packet_vkCmdSetStencilReference*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBindDescriptorSets {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    const VkDescriptorSet* pDescriptorSets;
    uint32_t dynamicOffsetCount;
    const uint32_t* pDynamicOffsets;
} packet_vkCmdBindDescriptorSets;

static packet_vkCmdBindDescriptorSets* interpret_body_as_vkCmdBindDescriptorSets(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBindDescriptorSets* pPacket = (packet_vkCmdBindDescriptorSets*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pDescriptorSets = (const VkDescriptorSet*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDescriptorSets);
    pPacket->pDynamicOffsets = (const uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDynamicOffsets);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBindIndexBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkIndexType indexType;
} packet_vkCmdBindIndexBuffer;

static packet_vkCmdBindIndexBuffer* interpret_body_as_vkCmdBindIndexBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBindIndexBuffer* pPacket = (packet_vkCmdBindIndexBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBindVertexBuffers {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    const VkBuffer* pBuffers;
    const VkDeviceSize* pOffsets;
} packet_vkCmdBindVertexBuffers;

static packet_vkCmdBindVertexBuffers* interpret_body_as_vkCmdBindVertexBuffers(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBindVertexBuffers* pPacket = (packet_vkCmdBindVertexBuffers*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pBuffers = (const VkBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBuffers);
    pPacket->pOffsets = (const VkDeviceSize*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pOffsets);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDraw {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
} packet_vkCmdDraw;

static packet_vkCmdDraw* interpret_body_as_vkCmdDraw(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDraw* pPacket = (packet_vkCmdDraw*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDrawIndexed {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;
} packet_vkCmdDrawIndexed;

static packet_vkCmdDrawIndexed* interpret_body_as_vkCmdDrawIndexed(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDrawIndexed* pPacket = (packet_vkCmdDrawIndexed*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDrawIndirect {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
} packet_vkCmdDrawIndirect;

static packet_vkCmdDrawIndirect* interpret_body_as_vkCmdDrawIndirect(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDrawIndirect* pPacket = (packet_vkCmdDrawIndirect*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDrawIndexedIndirect {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
} packet_vkCmdDrawIndexedIndirect;

static packet_vkCmdDrawIndexedIndirect* interpret_body_as_vkCmdDrawIndexedIndirect(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDrawIndexedIndirect* pPacket = (packet_vkCmdDrawIndexedIndirect*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDispatch {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t x;
    uint32_t y;
    uint32_t z;
} packet_vkCmdDispatch;

static packet_vkCmdDispatch* interpret_body_as_vkCmdDispatch(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDispatch* pPacket = (packet_vkCmdDispatch*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdDispatchIndirect {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
} packet_vkCmdDispatchIndirect;

static packet_vkCmdDispatchIndirect* interpret_body_as_vkCmdDispatchIndirect(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDispatchIndirect* pPacket = (packet_vkCmdDispatchIndirect*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdCopyBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    const VkBufferCopy* pRegions;
} packet_vkCmdCopyBuffer;

static packet_vkCmdCopyBuffer* interpret_body_as_vkCmdCopyBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdCopyBuffer* pPacket = (packet_vkCmdCopyBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkBufferCopy*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdCopyImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageCopy* pRegions;
} packet_vkCmdCopyImage;

static packet_vkCmdCopyImage* interpret_body_as_vkCmdCopyImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdCopyImage* pPacket = (packet_vkCmdCopyImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkImageCopy*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBlitImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageBlit* pRegions;
    VkFilter filter;
} packet_vkCmdBlitImage;

static packet_vkCmdBlitImage* interpret_body_as_vkCmdBlitImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBlitImage* pPacket = (packet_vkCmdBlitImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkImageBlit*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdCopyBufferToImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkBufferImageCopy* pRegions;
} packet_vkCmdCopyBufferToImage;

static packet_vkCmdCopyBufferToImage* interpret_body_as_vkCmdCopyBufferToImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdCopyBufferToImage* pPacket = (packet_vkCmdCopyBufferToImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkBufferImageCopy*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdCopyImageToBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    const VkBufferImageCopy* pRegions;
} packet_vkCmdCopyImageToBuffer;

static packet_vkCmdCopyImageToBuffer* interpret_body_as_vkCmdCopyImageToBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdCopyImageToBuffer* pPacket = (packet_vkCmdCopyImageToBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkBufferImageCopy*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdUpdateBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    const uint32_t* pData;
} packet_vkCmdUpdateBuffer;

static packet_vkCmdUpdateBuffer* interpret_body_as_vkCmdUpdateBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdUpdateBuffer* pPacket = (packet_vkCmdUpdateBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pData = (const uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pData);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdFillBuffer {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;
} packet_vkCmdFillBuffer;

static packet_vkCmdFillBuffer* interpret_body_as_vkCmdFillBuffer(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdFillBuffer* pPacket = (packet_vkCmdFillBuffer*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdClearColorImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    const VkClearColorValue* pColor;
    uint32_t rangeCount;
    const VkImageSubresourceRange* pRanges;
} packet_vkCmdClearColorImage;

static packet_vkCmdClearColorImage* interpret_body_as_vkCmdClearColorImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdClearColorImage* pPacket = (packet_vkCmdClearColorImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pColor = (const VkClearColorValue*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pColor);
    pPacket->pRanges = (const VkImageSubresourceRange*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRanges);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdClearDepthStencilImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    const VkClearDepthStencilValue* pDepthStencil;
    uint32_t rangeCount;
    const VkImageSubresourceRange* pRanges;
} packet_vkCmdClearDepthStencilImage;

static packet_vkCmdClearDepthStencilImage* interpret_body_as_vkCmdClearDepthStencilImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdClearDepthStencilImage* pPacket = (packet_vkCmdClearDepthStencilImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pDepthStencil = (const VkClearDepthStencilValue*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pDepthStencil);
    pPacket->pRanges = (const VkImageSubresourceRange*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRanges);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdClearAttachments {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t attachmentCount;
    const VkClearAttachment* pAttachments;
    uint32_t rectCount;
    const VkClearRect* pRects;
} packet_vkCmdClearAttachments;

static packet_vkCmdClearAttachments* interpret_body_as_vkCmdClearAttachments(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdClearAttachments* pPacket = (packet_vkCmdClearAttachments*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAttachments = (const VkClearAttachment*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAttachments);
    pPacket->pRects = (const VkClearRect*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRects);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdResolveImage {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageResolve* pRegions;
} packet_vkCmdResolveImage;

static packet_vkCmdResolveImage* interpret_body_as_vkCmdResolveImage(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdResolveImage* pPacket = (packet_vkCmdResolveImage*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRegions = (const VkImageResolve*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRegions);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdSetEvent {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;
} packet_vkCmdSetEvent;

static packet_vkCmdSetEvent* interpret_body_as_vkCmdSetEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdSetEvent* pPacket = (packet_vkCmdSetEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdResetEvent {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;
} packet_vkCmdResetEvent;

static packet_vkCmdResetEvent* interpret_body_as_vkCmdResetEvent(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdResetEvent* pPacket = (packet_vkCmdResetEvent*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdWaitEvents {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t eventCount;
    const VkEvent* pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    const VkMemoryBarrier* pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    const VkBufferMemoryBarrier* pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    const VkImageMemoryBarrier* pImageMemoryBarriers;
} packet_vkCmdWaitEvents;

static packet_vkCmdWaitEvents* interpret_body_as_vkCmdWaitEvents(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdWaitEvents* pPacket = (packet_vkCmdWaitEvents*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pEvents = (const VkEvent*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pEvents);
    pPacket->pMemoryBarriers = (const VkMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryBarriers);
    pPacket->pBufferMemoryBarriers = (const VkBufferMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBufferMemoryBarriers);
    pPacket->pImageMemoryBarriers = (const VkImageMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pImageMemoryBarriers);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdPipelineBarrier {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    const VkMemoryBarrier* pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    const VkBufferMemoryBarrier* pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    const VkImageMemoryBarrier* pImageMemoryBarriers;
} packet_vkCmdPipelineBarrier;

static packet_vkCmdPipelineBarrier* interpret_body_as_vkCmdPipelineBarrier(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdPipelineBarrier* pPacket = (packet_vkCmdPipelineBarrier*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pMemoryBarriers = (const VkMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMemoryBarriers);
    pPacket->pBufferMemoryBarriers = (const VkBufferMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pBufferMemoryBarriers);
    pPacket->pImageMemoryBarriers = (const VkImageMemoryBarrier*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pImageMemoryBarriers);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBeginQuery {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
} packet_vkCmdBeginQuery;

static packet_vkCmdBeginQuery* interpret_body_as_vkCmdBeginQuery(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBeginQuery* pPacket = (packet_vkCmdBeginQuery*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdEndQuery {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
} packet_vkCmdEndQuery;

static packet_vkCmdEndQuery* interpret_body_as_vkCmdEndQuery(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdEndQuery* pPacket = (packet_vkCmdEndQuery*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdResetQueryPool {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
} packet_vkCmdResetQueryPool;

static packet_vkCmdResetQueryPool* interpret_body_as_vkCmdResetQueryPool(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdResetQueryPool* pPacket = (packet_vkCmdResetQueryPool*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdWriteTimestamp {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    VkQueryPool queryPool;
    uint32_t query;
} packet_vkCmdWriteTimestamp;

static packet_vkCmdWriteTimestamp* interpret_body_as_vkCmdWriteTimestamp(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdWriteTimestamp* pPacket = (packet_vkCmdWriteTimestamp*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdCopyQueryPoolResults {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
} packet_vkCmdCopyQueryPoolResults;

static packet_vkCmdCopyQueryPoolResults* interpret_body_as_vkCmdCopyQueryPoolResults(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdCopyQueryPoolResults* pPacket = (packet_vkCmdCopyQueryPoolResults*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdPushConstants {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkPipelineLayout layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    const void* pValues;
} packet_vkCmdPushConstants;

static packet_vkCmdPushConstants* interpret_body_as_vkCmdPushConstants(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdPushConstants* pPacket = (packet_vkCmdPushConstants*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pValues = (const void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pValues);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdBeginRenderPass {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    const VkRenderPassBeginInfo* pRenderPassBegin;
    VkSubpassContents contents;
} packet_vkCmdBeginRenderPass;

static packet_vkCmdBeginRenderPass* interpret_body_as_vkCmdBeginRenderPass(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdBeginRenderPass* pPacket = (packet_vkCmdBeginRenderPass*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pRenderPassBegin = (const VkRenderPassBeginInfo*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pRenderPassBegin);
    if (pPacket->pRenderPassBegin != NULL)
    {
        VkClearValue** ppCV = (VkClearValue**)&(pPacket->pRenderPassBegin->pClearValues);
        *ppCV = (VkClearValue*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pRenderPassBegin->pClearValues));
    }
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdNextSubpass {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    VkSubpassContents contents;
} packet_vkCmdNextSubpass;

static packet_vkCmdNextSubpass* interpret_body_as_vkCmdNextSubpass(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdNextSubpass* pPacket = (packet_vkCmdNextSubpass*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdEndRenderPass {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
} packet_vkCmdEndRenderPass;

static packet_vkCmdEndRenderPass* interpret_body_as_vkCmdEndRenderPass(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdEndRenderPass* pPacket = (packet_vkCmdEndRenderPass*)pHeader->pBody;
    pPacket->header = pHeader;
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCmdExecuteCommands {
    vktrace_trace_packet_header* header;
    VkCommandBuffer commandBuffer;
    uint32_t commandBufferCount;
    const VkCommandBuffer* pCommandBuffers;
} packet_vkCmdExecuteCommands;

static packet_vkCmdExecuteCommands* interpret_body_as_vkCmdExecuteCommands(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdExecuteCommands* pPacket = (packet_vkCmdExecuteCommands*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCommandBuffers = (const VkCommandBuffer*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCommandBuffers);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroySurfaceKHR {
    vktrace_trace_packet_header* header;
    VkInstance instance;
    VkSurfaceKHR surface;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroySurfaceKHR;

static packet_vkDestroySurfaceKHR* interpret_body_as_vkDestroySurfaceKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroySurfaceKHR* pPacket = (packet_vkDestroySurfaceKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceSurfaceSupportKHR {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    VkSurfaceKHR surface;
    VkBool32* pSupported;
    VkResult result;
} packet_vkGetPhysicalDeviceSurfaceSupportKHR;

static packet_vkGetPhysicalDeviceSurfaceSupportKHR* interpret_body_as_vkGetPhysicalDeviceSurfaceSupportKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceSurfaceSupportKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceSupportKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSupported = (VkBool32*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSupported);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities;
    VkResult result;
} packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;

static packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* interpret_body_as_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSurfaceCapabilities = (VkSurfaceCapabilitiesKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSurfaceCapabilities);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceSurfaceFormatsKHR {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    uint32_t* pSurfaceFormatCount;
    VkSurfaceFormatKHR* pSurfaceFormats;
    VkResult result;
} packet_vkGetPhysicalDeviceSurfaceFormatsKHR;

static packet_vkGetPhysicalDeviceSurfaceFormatsKHR* interpret_body_as_vkGetPhysicalDeviceSurfaceFormatsKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceSurfaceFormatsKHR* pPacket = (packet_vkGetPhysicalDeviceSurfaceFormatsKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSurfaceFormatCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSurfaceFormatCount);
    pPacket->pSurfaceFormats = (VkSurfaceFormatKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSurfaceFormats);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceSurfacePresentModesKHR {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    uint32_t* pPresentModeCount;
    VkPresentModeKHR* pPresentModes;
    VkResult result;
} packet_vkGetPhysicalDeviceSurfacePresentModesKHR;

static packet_vkGetPhysicalDeviceSurfacePresentModesKHR* interpret_body_as_vkGetPhysicalDeviceSurfacePresentModesKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceSurfacePresentModesKHR* pPacket = (packet_vkGetPhysicalDeviceSurfacePresentModesKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPresentModeCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPresentModeCount);
    pPacket->pPresentModes = (VkPresentModeKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPresentModes);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateSwapchainKHR {
    vktrace_trace_packet_header* header;
    VkDevice device;
    const VkSwapchainCreateInfoKHR* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkSwapchainKHR* pSwapchain;
    VkResult result;
} packet_vkCreateSwapchainKHR;

static packet_vkCreateSwapchainKHR* interpret_body_as_vkCreateSwapchainKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateSwapchainKHR* pPacket = (packet_vkCreateSwapchainKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkSwapchainCreateInfoKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    if (pPacket->pCreateInfo != NULL)
    {
        uint32_t **ppQFI = (uint32_t**)&pPacket->pCreateInfo->pQueueFamilyIndices;
        (*ppQFI) = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pCreateInfo->pQueueFamilyIndices));
    }
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pSwapchain = (VkSwapchainKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSwapchain);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkDestroySwapchainKHR {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkSwapchainKHR swapchain;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroySwapchainKHR;

static packet_vkDestroySwapchainKHR* interpret_body_as_vkDestroySwapchainKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroySwapchainKHR* pPacket = (packet_vkDestroySwapchainKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetSwapchainImagesKHR {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkSwapchainKHR swapchain;
    uint32_t* pSwapchainImageCount;
    VkImage* pSwapchainImages;
    VkResult result;
} packet_vkGetSwapchainImagesKHR;

static packet_vkGetSwapchainImagesKHR* interpret_body_as_vkGetSwapchainImagesKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetSwapchainImagesKHR* pPacket = (packet_vkGetSwapchainImagesKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pSwapchainImageCount = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSwapchainImageCount);
    pPacket->pSwapchainImages = (VkImage*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSwapchainImages);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkAcquireNextImageKHR {
    vktrace_trace_packet_header* header;
    VkDevice device;
    VkSwapchainKHR swapchain;
    uint64_t timeout;
    VkSemaphore semaphore;
    VkFence fence;
    uint32_t* pImageIndex;
    VkResult result;
} packet_vkAcquireNextImageKHR;

static packet_vkAcquireNextImageKHR* interpret_body_as_vkAcquireNextImageKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkAcquireNextImageKHR* pPacket = (packet_vkAcquireNextImageKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pImageIndex = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pImageIndex);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkQueuePresentKHR {
    vktrace_trace_packet_header* header;
    VkQueue queue;
    const VkPresentInfoKHR* pPresentInfo;
    VkResult result;
} packet_vkQueuePresentKHR;

static packet_vkQueuePresentKHR* interpret_body_as_vkQueuePresentKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkQueuePresentKHR* pPacket = (packet_vkQueuePresentKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pPresentInfo = (const VkPresentInfoKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pPresentInfo);
    if (pPacket->pPresentInfo != NULL)
    {
        VkSwapchainKHR **ppSC = (VkSwapchainKHR **)& pPacket->pPresentInfo->pSwapchains;
        *ppSC = (VkSwapchainKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pPresentInfo->pSwapchains));
        VkSemaphore **ppS = (VkSemaphore **) &pPacket->pPresentInfo->pWaitSemaphores;
        *ppS = (VkSemaphore *) vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pPresentInfo->pWaitSemaphores));
        uint32_t **ppII = (uint32_t **) &pPacket->pPresentInfo->pImageIndices;
        *ppII = (uint32_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pPresentInfo->pImageIndices));
        if (pPacket->pPresentInfo->pResults != NULL) {
            VkResult **ppR = (VkResult **) &pPacket->pPresentInfo->pResults;
            *ppR = (VkResult*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)(pPacket->pPresentInfo->pResults));
        }
    }
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkCreateXcbSurfaceKHR {
    vktrace_trace_packet_header* header;
    VkInstance instance;
    const VkXcbSurfaceCreateInfoKHR* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkSurfaceKHR* pSurface;
    VkResult result;
} packet_vkCreateXcbSurfaceKHR;

static packet_vkCreateXcbSurfaceKHR* interpret_body_as_vkCreateXcbSurfaceKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateXcbSurfaceKHR* pPacket = (packet_vkCreateXcbSurfaceKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->pCreateInfo = (const VkXcbSurfaceCreateInfoKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pSurface = (VkSurfaceKHR*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pSurface);
    return pPacket;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #946
typedef struct packet_vkGetPhysicalDeviceXcbPresentationSupportKHR {
    vktrace_trace_packet_header* header;
    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    xcb_connection_t* connection;
    xcb_visualid_t visual_id;
    VkBool32 result;
} packet_vkGetPhysicalDeviceXcbPresentationSupportKHR;

static packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* interpret_body_as_vkGetPhysicalDeviceXcbPresentationSupportKHR(vktrace_trace_packet_header* pHeader)
{
    packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* pPacket = (packet_vkGetPhysicalDeviceXcbPresentationSupportKHR*)pHeader->pBody;
    pPacket->header = pHeader;
    pPacket->connection = (xcb_connection_t*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->connection);
    return pPacket;
}

