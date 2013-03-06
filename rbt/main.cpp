

#include<iostream>
#include"tree.h"
#include"tree.cpp"

#define SIZE 5

using namespace std;


int main(void){
	//create an empty tree
	PNode tree = create_tree();
	//insert one node
	int data = 101;
	tree = insert_node(tree, data);	
	show_tree( tree );
	//delete root for first delete case
	PNode node = search(tree, data);
	tree = delete_node(tree, node);
	show_tree( tree );
	return 0;
}
