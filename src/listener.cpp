#include "../includes/listener.h"
#include "../includes/sha256.h"
#include "../includes/node.h"

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

void connect(string my_ip,int my_port, string friends_ip, int friends_port){

	//...............initialising finger table

	finger_table.resize(entries);

	for(int i=0;i<entries;i++){
		int from_key = (my_node_id + (int)pow(2,i))%mod;
		int to_key = (my_node_id + (int)pow(2+1,i) - 1)%mod;
		finger_table[i] = new ft_node();
		finger_table[i].interval = {from_key,to_key};
		finger_table[i].s_d = NULL;
	}

	//...............

	if(friends_ip == ""){
		successor = new node();
		successor->ip = my_ip;
		successor->port = my_port;
		successor->nodeID = my_node_id;

		predessor = new node();
		predessor->ip = my_ip;
		predessor->port = my_port;;
		predessor->nodeID = my_node_id;
	}

	else {
		node to;
		to.ip = friends_ip;
		to.port = friends_port;
		successor = getSuccessor(this_node,to,this_node.nodeID);
	}
}


void listenOnConnection(){
	int listenfd = 0;
	int connfd = 0;

	struct sockaddr_in serv_addr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	if (listenfd == -1){
		cout << "Please restart the client." << endl;
		exit(1);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET; // defines the family of socket, internet family used
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // which IP to listen on
	serv_addr.sin_port = htons(my_port); // port number to listen on

	// bind the socket now
	int res = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	// if the bind call fails
	if (res == -1)
	{
		exit(1);
	}

	listen(listenfd, 15);

	struct sockaddr client_addr;
	socklen_t client_len = sizeof(client_addr);

	while(1)
	{
	connfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_len);
	// thread t(&nodeClient::handleRequest, this, connfd);
	int pid = fork();
	if(pid == 0)
		handleRequest(connfd);
	}
}

void handleRequest(int connfd)
{
	char recvBuff[1024];
	bzero(recvBuff, sizeof(recvBuff));

	int bytes_read = recv(connfd, recvBuff, sizeof(recvBuff), 0);

	if (bytes_read == 0 || bytes_read == -1)
	{
		cout<<"Bad Conncetion --->"<<connfd<<endl;
		close(connfd);
	}

	string query_string(recvBuff);
	cout << query_string << endl;
	processQuery(query_string);
}
	


//.....dry run
/*
int main(){
  cout<<(getNodeID("shashank",007))<<endl;
  return 0;
}
*/