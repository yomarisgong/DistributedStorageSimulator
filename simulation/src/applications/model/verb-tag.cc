/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//
/*
 * Copyright (c) 2006 Georgia Tech Research Corporation
 *               2007 INRIA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: yomarisgong<1054087539@qq.com>
 */

#include "verb-tag.h"

#include <iomanip>
#include <iostream>

#include "ns3/log.h"
#include "ns3/tag.h"

NS_LOG_COMPONENT_DEFINE("VerbTag");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED(ChunkSizeTag);

ChunkSizeTag::ChunkSizeTag() { NS_LOG_FUNCTION(this); }

void ChunkSizeTag::SetChunkSize(uint32_t chunkSize) { m_chunkSize = chunkSize; }

uint32_t ChunkSizeTag::GetChunkSize(void) const { return m_chunkSize; }

TypeId ChunkSizeTag::GetTypeId(void) {
    static TypeId tid = TypeId("ns3::ChunkSizeTag").SetParent<Tag>().AddConstructor<ChunkSizeTag>();
    return tid;
}

TypeId ChunkSizeTag::GetInstanceTypeId(void) const { return GetTypeId(); }

uint32_t ChunkSizeTag::GetSerializedSize(void) const { return sizeof(uint32_t); }

void ChunkSizeTag::Serialize(TagBuffer i) const { i.WriteU32(m_chunkSize); }

void ChunkSizeTag::Deserialize(TagBuffer i) { m_chunkSize = i.ReadU32(); }

void ChunkSizeTag::Print(std::ostream &os) const { os << "ChunkSizeTag.chunkSize(dec)=" << std::dec << m_chunkSize; }

NS_OBJECT_ENSURE_REGISTERED(RPCTag);

RPCTag::RPCTag() { NS_LOG_FUNCTION(this); }

void RPCTag::SetRequestSize(uint32_t requestSize) { m_requestSize = requestSize; }
void RPCTag::SetResponseSize(uint32_t responseSize) { m_responseSize = responseSize; }

void RPCTag::SetRPCReqResType(RPCType type) { m_type = type; }

void RPCTag::SetRPCReqResId(uint64_t reqres_id) { m_reqres_id = reqres_id; }

uint32_t RPCTag::GetRequestSize(void) const { return m_requestSize; }
uint32_t RPCTag::GetResponseSize(void) const { return m_responseSize; }

RPCType RPCTag::GetRPCReqResType(void) const { return m_type; }

uint64_t RPCTag::GetRPCReqResId(void) const { return m_reqres_id; }

TypeId RPCTag::GetTypeId(void) {
    static TypeId tid = TypeId("ns3::RPCTag").SetParent<Tag>().AddConstructor<RPCTag>();
    return tid;
}

TypeId RPCTag::GetInstanceTypeId(void) const { return GetTypeId(); }

uint32_t RPCTag::GetSerializedSize(void) const { return sizeof(uint32_t) + sizeof(uint8_t) + sizeof(uint64_t); }

void RPCTag::Serialize(TagBuffer i) const {
    i.WriteU32(m_requestSize);
    i.WriteU32(m_responseSize);
    i.WriteU8(static_cast<uint8_t>(m_type));
    i.WriteU64(m_reqres_id);
}

void RPCTag::Deserialize(TagBuffer i) {
    m_requestSize = i.ReadU32();
    m_responseSize = i.ReadU32();
    m_type = static_cast<RPCType>(i.ReadU8());
    m_reqres_id = i.ReadU64();
}

void RPCTag::Print(std::ostream &os) const {
    os << "RPCTag.m_requestSize(dec)=" << std::dec << m_requestSize << "\n"
       << "RPCTag.m_responseSize(dec)=" << std::dec << m_responseSize << "\n"
       << "RPCTag.m_reqres_id(dec)=" << std::dec << m_reqres_id << "\n"
       << " RPCTag.m_type(dec)=" << std::dec << static_cast<uint8_t>(m_type);
}

NS_OBJECT_ENSURE_REGISTERED(RPCTotalOffsetTag);

RPCTotalOffsetTag::RPCTotalOffsetTag() { NS_LOG_FUNCTION(this); }

void RPCTotalOffsetTag::SetRPCTotalOffset(uint16_t rpcTotalOffest) { m_rpcTotalOffest = rpcTotalOffest; }

uint16_t RPCTotalOffsetTag::GetRPCTotalOffset(void) const { return m_rpcTotalOffest; }

TypeId RPCTotalOffsetTag::GetTypeId(void) {
    static TypeId tid = TypeId("ns3::RPCTotalOffsetTag").SetParent<Tag>().AddConstructor<RPCTotalOffsetTag>();
    return tid;
}

TypeId RPCTotalOffsetTag::GetInstanceTypeId(void) const { return GetTypeId(); }

uint32_t RPCTotalOffsetTag::GetSerializedSize(void) const { return sizeof(uint16_t); }

void RPCTotalOffsetTag::Serialize(TagBuffer i) const { i.WriteU16(m_rpcTotalOffest); }

void RPCTotalOffsetTag::Deserialize(TagBuffer i) { m_rpcTotalOffest = i.ReadU16(); }

void RPCTotalOffsetTag::Print(std::ostream &os) const { os << "RPCTotalOffsetTag.m_rpcTotalOffest(dec)=" << std::dec << m_rpcTotalOffest; }

NS_OBJECT_ENSURE_REGISTERED(WRidTag);

WRidTag::WRidTag() { NS_LOG_FUNCTION(this); }

void WRidTag::SetWRid(uint64_t wrid) { m_wrid = wrid; }

uint64_t WRidTag::GetWRid(void) const { return m_wrid; }

TypeId WRidTag::GetTypeId(void) {
    static TypeId tid = TypeId("ns3::WRidTag").SetParent<Tag>().AddConstructor<WRidTag>();
    return tid;
}

TypeId WRidTag::GetInstanceTypeId(void) const { return GetTypeId(); }

uint32_t WRidTag::GetSerializedSize(void) const { return sizeof(uint64_t); }

void WRidTag::Serialize(TagBuffer i) const { i.WriteU64(m_wrid); }

void WRidTag::Deserialize(TagBuffer i) { m_wrid = i.ReadU64(); }

void WRidTag::Print(std::ostream &os) const { os << "WRidTag.chunkSize(dec)=" << std::dec << m_wrid; }

}  // namespace ns3

// TO DO GYY: implement this
