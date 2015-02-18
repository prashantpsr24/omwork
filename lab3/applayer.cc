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

#include "applayer.h"

Define_Module(Applayer);

void Applayer::initialize()
{
          in0 = gate ("in0");
          out0 = gate ("out0");
         id=par("id");

          if(id==0)
          {
              apdu* pkt=new apdu();
              pkt->setSrc(0);
              pkt->setDest(1);
              pkt->setType(DATA);
              send (pkt, "out0");
              //send
          }

    // TODO - Generated method body
}

void Applayer::handleMessage(cMessage *msg)
{

    apdu* pkt=new apdu();
    pkt = check_and_cast<apdu*> (msg);
    if(pkt->getType() == DATA)
    {
        apdu* ackpkt=new apdu();
        ackpkt->setSrc(pkt->getDest());
        ackpkt->setDest(pkt->getSrc());
        ackpkt->setType(ACK);
        send (ackpkt, "out0");
    }
    // TODO - Generated method body
}
