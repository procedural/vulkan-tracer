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

#include "vktrace_vk_packet_id.h"
#include "vktrace_platform.h"
#include "vktrace_common.h"
#include "vktrace_vk_vk_ext_debug_report.h"
#include "vktrace_vk_vk_ext_debug_report_packets.h"
#include "vk_struct_size_helper.h"
#include "vk_ext_debug_report_struct_size_helper.h"
#include "vktrace_lib_helpers.h"

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL __HOOKED_vkCreateDebugReportCallbackEXT(
    VkInstance instance,
    const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugReportCallbackEXT* pCallback)
{
    vktrace_trace_packet_header* pHeader;
    VkResult result;
    packet_vkCreateDebugReportCallbackEXT* pPacket = NULL;
    CREATE_TRACE_PACKET(vkCreateDebugReportCallbackEXT, sizeof(VkDebugReportCallbackCreateInfoEXT) + sizeof(VkAllocationCallbacks) + sizeof(VkDebugReportCallbackEXT));
    result = mid(instance)->instTable.CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkCreateDebugReportCallbackEXT(pHeader);
    pPacket->instance = instance;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCreateInfo), sizeof(VkDebugReportCallbackCreateInfoEXT), pCreateInfo);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pCallback), sizeof(VkDebugReportCallbackEXT), pCallback);
    pPacket->result = result;
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCreateInfo));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pCallback));
    FINISH_TRACE_PACKET();
    return result;
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDestroyDebugReportCallbackEXT(
    VkInstance instance,
    VkDebugReportCallbackEXT callback,
    const VkAllocationCallbacks* pAllocator)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDestroyDebugReportCallbackEXT* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDestroyDebugReportCallbackEXT, sizeof(VkAllocationCallbacks));
    mid(instance)->instTable.DestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDestroyDebugReportCallbackEXT(pHeader);
    pPacket->instance = instance;
    pPacket->callback = callback;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pAllocator), sizeof(VkAllocationCallbacks), NULL);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pAllocator));
    FINISH_TRACE_PACKET();
}

// CODEGEN : file /home/constantine/Vulkan-LoaderAndValidationLayers/vktrace/vktrace_generate.py line #418
VKTRACER_EXPORT VKAPI_ATTR void VKAPI_CALL __HOOKED_vkDebugReportMessageEXT(
    VkInstance instance,
    VkDebugReportFlagsEXT flags,
    VkDebugReportObjectTypeEXT objType,
    uint64_t object,
    size_t location,
    int32_t msgCode,
    const char * pLayerPrefix,
    const char * pMsg)
{
    vktrace_trace_packet_header* pHeader;
    packet_vkDebugReportMessageEXT* pPacket = NULL;
    CREATE_TRACE_PACKET(vkDebugReportMessageEXT, ((pLayerPrefix != NULL) ? strlen(pLayerPrefix) + 1 : 0) + ((pMsg != NULL) ? strlen(pMsg) + 1 : 0));
    mid(instance)->instTable.DebugReportMessageEXT(instance, flags, objType, object, location, msgCode, pLayerPrefix, pMsg);
    vktrace_set_packet_entrypoint_end_time(pHeader);
    pPacket = interpret_body_as_vkDebugReportMessageEXT(pHeader);
    pPacket->instance = instance;
    pPacket->flags = flags;
    pPacket->objType = objType;
    pPacket->object = object;
    pPacket->location = location;
    pPacket->msgCode = msgCode;
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pLayerPrefix), sizeof(char ), pLayerPrefix);
    vktrace_add_buffer_to_trace_packet(pHeader, (void**)&(pPacket->pMsg), sizeof(char ), pMsg);
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pLayerPrefix));
    vktrace_finalize_buffer_address(pHeader, (void**)&(pPacket->pMsg));
    FINISH_TRACE_PACKET();
}

