#include "../includes/node.h"
#include "../includes/listener.h"

int main(int argc,const char *argv[]){
  //..........................PHASE I............................
  if(argc<3){
    cout<<"Arguments required  -->">>argv[0]>>" my_ip my_port [friends_ip] [friends_port] ">>endl;
    return 0;
  }
  my_ip = argv[1];
  my_port = argv[2];

  if(argc == 5) 
    friends_ip = argv[3] , 
    friends_port = argv[4] ;

  else   
    friends_ip = "" , 
    friends_port = 0 ;

  connect(my_ip,my_port,friends_ip,friends_port);

  listen();

  //..........................PHASE II...........................

  string input;
  while(getline(cin,input)){

  }


  return 0;
}