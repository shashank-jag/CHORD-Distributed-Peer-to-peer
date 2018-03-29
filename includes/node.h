#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define successor finger[0];

string my_ip, friend_ip;
int my_port, friend_port;

struct nodes{
	string ip;
	int port;
	int nodeID;
};

vector<nodes> finger;