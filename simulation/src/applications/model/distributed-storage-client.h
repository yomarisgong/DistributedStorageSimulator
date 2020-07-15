/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007,2008,2009 INRIA, UDCAST
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
 * Author: Amine Ismail <amine.ismail@sophia.inria.fr>
 *                      <amine.ismail@udcast.com>
 *
 */

/*
 * author:   Yixiao(Krayecho) Gao <532820040@qq.com>
 * date:     202000707
 */

#ifndef DISTRIBUTED_STORAGE_CLIENT_H
#define DISTRIBUTED_STORAGE_CLIENT_H

#include <ns3/rdma.h>

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/flowseg.h"
#include "ns3/ipv4-address.h"
#include "ns3/ptr.h"
#include "ns3/user-space-congestion-control.h"

namespace ns3 {

class Socket;
class Packet;

/**
 * \ingroup distributedStorage
 * \class DistributedStorageClient
 * \brief A distributed storage client.
 *
 */

class SendCompeltionReturnValue;
class RpcResponse;

class DistributedStorageClient : public RdmaClient {
   public:
    static TypeId GetTypeId(void);
    DistributedStorageClient();
    virtual ~DistributedStorageClient();

    // storage-specified level
    // maybe we need an abstraction here

    // RPC-level interface
    void SendRpc(uint32_t size);
    /**
     * \brief called by a QP when it recieves an response of RPC;
     * \param rpcResponse response;
     * \param qp the Rdma Queue Pair of received message;
     */
    void OnResponse(Ptr<RpcResponse> rpcResponse, Ptr<RdmaQueuePair> qp);

    // RDMA QP Callback
    /**
     * \brief called by a QP when it returns a completion;
     * \param completionReturn params returned by completion;
     */
    void OnSendCompletion(Ptr<SendCompeltionReturnValue> completionReturn);

    //

   protected:
    virtual void DoDispose(void);

   private:
    virtual void StartApplication(void);
    virtual void StopApplication(void);

    // need maintain a QP collection:
    // somthing like key-value storage <qp,ip>

    //
};

}  // namespace ns3

#endif /* DISTRIBUTED_STORAGE_CLIENT_H */