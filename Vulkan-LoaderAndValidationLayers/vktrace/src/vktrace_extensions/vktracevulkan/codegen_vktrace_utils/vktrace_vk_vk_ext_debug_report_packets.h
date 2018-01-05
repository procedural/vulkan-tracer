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

#include "vk_ext_debug_report.h"
#include "vktrace_trace_packet_utils.h"


typedef struct packet_vkCreateDebugReportCallbackEXT {
    vktrace_trace_packet_header* pHeader;
    VkInstance instance;
    const VkDebugReportCallbackCreateInfoEXT* pCreateInfo;
    const VkAllocationCallbacks* pAllocator;
    VkDebugReportCallbackEXT* pCallback;
    VkResult result;
} packet_vkCreateDebugReportCallbackEXT;

static packet_vkCreateDebugReportCallbackEXT* interpret_body_as_vkCreateDebugReportCallbackEXT(vktrace_trace_packet_header* pHeader)
{
    packet_vkCreateDebugReportCallbackEXT* pPacket = (packet_vkCreateDebugReportCallbackEXT*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pCreateInfo = (const VkDebugReportCallbackCreateInfoEXT*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCreateInfo);
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    pPacket->pCallback = (VkDebugReportCallbackEXT*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pCallback);
    return pPacket;
}

typedef struct packet_vkDestroyDebugReportCallbackEXT {
    vktrace_trace_packet_header* pHeader;
    VkInstance instance;
    VkDebugReportCallbackEXT callback;
    const VkAllocationCallbacks* pAllocator;
} packet_vkDestroyDebugReportCallbackEXT;

static packet_vkDestroyDebugReportCallbackEXT* interpret_body_as_vkDestroyDebugReportCallbackEXT(vktrace_trace_packet_header* pHeader)
{
    packet_vkDestroyDebugReportCallbackEXT* pPacket = (packet_vkDestroyDebugReportCallbackEXT*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pAllocator = (const VkAllocationCallbacks*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pAllocator);
    return pPacket;
}

typedef struct packet_vkDebugReportMessageEXT {
    vktrace_trace_packet_header* pHeader;
    VkInstance instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objType;
    uint64_t object;
    size_t location;
    int32_t msgCode;
    const char * pLayerPrefix;
    const char * pMsg;
} packet_vkDebugReportMessageEXT;

static packet_vkDebugReportMessageEXT* interpret_body_as_vkDebugReportMessageEXT(vktrace_trace_packet_header* pHeader)
{
    packet_vkDebugReportMessageEXT* pPacket = (packet_vkDebugReportMessageEXT*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pLayerPrefix = (const char *)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pLayerPrefix);
    pPacket->pMsg = (const char *)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMsg);
    return pPacket;
}

