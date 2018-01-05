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

#include "vk_lunarg_debug_marker.h"
#include "vktrace_trace_packet_utils.h"


typedef struct packet_vkCmdDbgMarkerBegin {
    vktrace_trace_packet_header* pHeader;
    VkCommandBuffer commandBuffer;
    const char* pMarker;
} packet_vkCmdDbgMarkerBegin;

static packet_vkCmdDbgMarkerBegin* interpret_body_as_vkCmdDbgMarkerBegin(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDbgMarkerBegin* pPacket = (packet_vkCmdDbgMarkerBegin*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pMarker = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pMarker);
    return pPacket;
}

typedef struct packet_vkCmdDbgMarkerEnd {
    vktrace_trace_packet_header* pHeader;
    VkCommandBuffer commandBuffer;
} packet_vkCmdDbgMarkerEnd;

static packet_vkCmdDbgMarkerEnd* interpret_body_as_vkCmdDbgMarkerEnd(vktrace_trace_packet_header* pHeader)
{
    packet_vkCmdDbgMarkerEnd* pPacket = (packet_vkCmdDbgMarkerEnd*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    return pPacket;
}

typedef struct packet_vkDbgSetObjectTag {
    vktrace_trace_packet_header* pHeader;
    VkDevice device;
    VkDebugReportObjectTypeEXT objType;
    uint64_t object;
    size_t tagSize;
    const void* pTag;
    VkResult result;
} packet_vkDbgSetObjectTag;

static packet_vkDbgSetObjectTag* interpret_body_as_vkDbgSetObjectTag(vktrace_trace_packet_header* pHeader)
{
    packet_vkDbgSetObjectTag* pPacket = (packet_vkDbgSetObjectTag*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pTag = (const void*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pTag);
    return pPacket;
}

typedef struct packet_vkDbgSetObjectName {
    vktrace_trace_packet_header* pHeader;
    VkDevice device;
    VkDebugReportObjectTypeEXT objType;
    uint64_t object;
    size_t nameSize;
    const char* pName;
    VkResult result;
} packet_vkDbgSetObjectName;

static packet_vkDbgSetObjectName* interpret_body_as_vkDbgSetObjectName(vktrace_trace_packet_header* pHeader)
{
    packet_vkDbgSetObjectName* pPacket = (packet_vkDbgSetObjectName*)pHeader->pBody;
    pPacket->pHeader = pHeader;
    pPacket->pName = (const char*)vktrace_trace_packet_interpret_buffer_pointer(pHeader, (intptr_t)pPacket->pName);
    return pPacket;
}

