#include<iostream>
#include"tree.h"
#include"tree.cpp"

//debug with little number and show in good
#define SIZE 1024
//#define SIZE 1024*8*4//big number to test

using namespace std;

int main(void){
    //create an empty tree
    //PNode tree = create_tree();
	PNode tree = NULL;
    for(int i=0; i<SIZE; i++){
        int data = rand()%1024;//[0:32767]//little
		    //num and good format
		//int data = rand()%16383;//[0:32767]
		
		cout<<i+1<<"--"<<data<<endl;//required when debug
		tree = insert_node(tree, data);
		//show_tree( tree );//required wehn debug
		check_p(tree);
	}
	//delete root for first delete case
	cout<<"searching..."<<endl;
	while( tree!=NULL ){
		show_tree(tree);
		cout<<"deleting "<<tree->data<<endl;

		tree = delete_node( tree, tree );
	}
	//show_tree( tree );
	check_rbt( tree );
	return 0;
}
