#include "../includes/listener.h"
#include "../includes/sha256.h"

int val(char c){
  if(c >= 'a' and c <= 'f')return (c-'A');
  return (c-'0');
}

int hextodec(string hash){
  reverse(hash.begin(),hash.end());
  long long multi=1;
  int ret = 0;
  for(auto x : hash){
    ret += val(x) * multi;
    multi *= 16;
    if(!(multi%m))return ret;
  }
  return ret;
}

int getNodeID(string ip, int port){
  string input = ip + to_string(port);
  string hex = sha256(input);
  // cout<<hex<<endl;
  int nodeID = hextodec(hex);
  return nodeID;
}

int main(){
  cout<<(getNodeID("shashank",007))<<endl;
  return 0;
}