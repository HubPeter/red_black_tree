#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node{
	int data;
	char key;
}*PNode;
int main(void){
	//PNode node = (struct Node*)malloc(sizeof(struct Node));
	PNode node = new struct Node;
	node->data = 20;
	node->key = 97;
	cout<<node->data<<endl;
	cout<<node->key<<endl;
	return 0;
}
