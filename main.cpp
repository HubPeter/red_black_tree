#include<iostream>
#include"tree.h"
#include"tree.cpp"

 //debug with little number and show in good
//#define SIZE 12
#define SIZE 1024*8*4//big number to test

using namespace std;

int main(void){
    //create an empty tree
    //PNode tree = create_tree();
	PNode tree = NULL;
    for(int i=0; i<SIZE; i++){
        //int data = rand()%1024;//[0:32767]
		int data = rand()%16383;//[0:32767]
		
		//cout<<i+1<<"--"<<data<<endl;//required when debug
		tree = insert_node(tree, data);
		//show_tree( tree );//required wehn debug
		check_p(tree);
	}
	//delete root for first delete case
	int data = 1;
	cout<<"searching..."<<endl;
	PNode node = search(tree, data);
	if( node!=NULL ){
		cout<<node<<"-->"<<node->data<<endl;
	}
	//tree = delete_node(tree, node);
	//show_tree( tree );
	return 0;
}
