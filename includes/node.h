#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define successor finger[0];

string my_ip, friend_ip;
int my_port, friend_port, my_node_id;

struct nodes{
	string ip;
	int port;
	int nodeID;
};

struct ft_node{
	pair<int,int> interval;
	int successor;
	nodes * s_d;
};

node *successor , *predessor
node this_node;

vector<ft_nodes> finger_table;