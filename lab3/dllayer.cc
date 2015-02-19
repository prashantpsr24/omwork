//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "dllayer.h"

Define_Module(Dllayer);

void Dllayer::initialize()
{
                in0 = gate ("in0");
              out0 = gate ("out0");
              in1 = gate ("in1");
               out1 = gate ("out1");
              id=par("id");
    // TODO - Generated method body
}

void Dllayer::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn("in0"))
    {
        apdu* pkt=new apdu();
        pkt = check_and_cast<apdu*> (msg);
        Dpdu *frame=new Dpdu();
        frame->setSrc(pkt->getSrc());
        frame->setDest(pkt->getDest());
        frame->setType(pkt->getType());
        frame->setId((pkt->getId())%2);
        send (frame, "out1");
    }
    else if(msg->arrivedOn("in1"))
    {
        Dpdu* frame=new Dpdu();
        frame = check_and_cast<Dpdu*> (msg);
        apdu *pkt=new apdu();
        pkt->setSrc(frame->getSrc());
        pkt->setDest(frame->getDest());
        pkt->setType(frame->getType());
        send (pkt, "out0");

    }
    // TODO - Generated method body
}
