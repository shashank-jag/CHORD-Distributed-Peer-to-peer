#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int mod = 1024 , entries = 10;

int val(char);
int hextodec(string);
int getNodeID(string , int);
void connect(string ,int , string , int);
void listenOnConnection();
void handleRequest(int connfd);
