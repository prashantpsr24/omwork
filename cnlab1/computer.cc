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

#include "computer.h"

Define_Module(Computer);

void Computer::initialize()
{
       id = par ("address");
       S = par ("src");
       D = par ("dest");
       in = gate ("in");
       out = gate ("out");

           counter = 1;

           if (id == S)
           {
               cMessage* event = new cMessage ();
               scheduleAt (0.0, event);
           }
    // TODO - Generated method body
}

void Node::handleMessage(cMessage *msg)
{
    counter++;
    if (msg->isSelfMessage())
    {
        Pkt* p = new Pkt ();
        p->setId (counter);
        p->setSrc (S);
        p->setDest (D);
        p->setType (DATA);
        EV << "Sending DATA is self with id = " << p->getId () << ".\n";
        send (p, "out");
    }
    else
    {
        if (counter > 10)
        {
            EV << "All messages sent!\n";
            delete (msg);
        }
        Pkt* p1 = new Pkt ();
        p1 = check_and_cast<Pkt*> (msg);
        if (p1->getType() == DATA)
        {

            Pkt* ack = new Pkt ();
            ack->setId (counter);
            ack->setType (ACK);
            EV << "Sending ACK with id = " << ack->getId () << ".\n";
            send (ack, "out");
            if (counter >= 10)
                delete (ack);
            finish();
         }

        else
        {
            Pkt* newData = new Pkt ();
            newData->setId (counter);
            EV << "Sending DATA with id = " << newData->getId () << ".\n";
            newData->setType (DATA);
            send (newData, "out");
            if (counter > 10)
              /*  newData->drop(msg); */
                delete (newData);
        }
    }
}
