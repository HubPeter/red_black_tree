#include<iostream>
#include"tree.h"
#include"tree.cpp"

#define SIZE 5

using namespace std;

int main(void){
    //create an empty tree
    //PNode tree = create_tree();
	PNode tree = NULL;
    for(int i=0; i<SIZE; i++){
        int data = rand()%1024;//[0:32767]
		cout<<"inserting "<<data<<endl;
        tree = insert_node(tree, data);
	}
	show_tree( tree );
	//delete root for first delete case
	int data = 105;
	PNode node = search(tree, data);
	tree = delete_node(tree, node);
	show_tree( tree );
	return 0;
}
