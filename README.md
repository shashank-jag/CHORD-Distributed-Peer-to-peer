# CHORD-Distributed-Peer-to-peer
A fundamental problem that confronts peer-to-peer applications is to efficiently locate the node that stores a particular data item. This paper presents Chord, a distributed lookup protocol that addresses this problem. Chord provides support for just one operation: given a key, it maps the key onto a node. Data location can be easily implemented on top of Chord by associating a key with each data item, and storing the key/data item pair at the node to which the key maps. Chord adapts efficiently as nodes join and leave the system, and can answer queries even if the system is continuously changing. Results from theoretical analysis, simulations, and ex- periments show that Chord is scalable, with communication cost and the state maintained by each node scaling logarithmically with the number of Chord nodes.


# PHASE_1
Focusing on addition of a node according to the algorithm we have develop two modules node and listener.
Their respective functionalities are:

## Node
This module will take care of functionalities of creating and modifying our nodes finger table and other entries.

## Listener
This module will take care of updating the finger tables of existing nodes nad stabelising them.
