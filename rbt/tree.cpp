#include"tree.h"
#include<assert.h>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef struct Node *PNode, *TREE;
PNode create_node(){
	PNode node = (PNode)malloc(sizeof(struct Node));
	if( NULL==node ){
		cout<<"Malloc failed."<<endl;
		exit(1);
	}
	node->left = NULL;
	node->right = NULL;
	node->color = BLACK;
	return node;
}
PNode create_tree(){
	PNode tree = NULL;
	
	return NULL;
}
PNode insert_node(TREE tree, int data ){
	//find correct pos
	PNode node = create_node();
	node->data = data;
	node->color = BLACK;
	if( NULL==tree ){
		tree = node;
		return tree;
	}
	PNode p = tree;
	PNode pre = p;
	while( NULL!=pre ){
		pre = p;
		if( data<=p->data ){
			p = p->left;
		}else{
			p = p->right;
		}
	}
	//insert
	if( data<=pre->data ){
		pre->left = node;
	}else{
		pre->right = node;
	}
	//fixup
	insert_fixup(tree, node);
	return tree;
}


PNode delete_node(TREE tree, PNode node){
	assert( NULL!=tree );//for ensurance
	PNode succ = get_successor(tree,  tree );//get successor
	if( succ==tree ){//no successor
		//delete tree
		free( succ );
		return NULL;
	}
	
	//take over successor's data and color
	node->data = succ->data;//data
	if( NULL!=succ->right ){//take over right children
		//delete succ
		succ->parent->left = succ->right;
		succ->right->parent = succ->parent;
		if( succ->color==BLACK ){
			delete_fixup( tree, succ );
		}
		free( succ );
	}
	return tree;
}
PNode search(TREE tree, int data ){
	return NULL;
}
void insert_fixup(TREE tree, PNode node){
	
}
void show_tree(TREE tree){
	int w = 128;//width of paint
	//bfs based
	queue<PNode> q1, q2;
	queue<PNode> *qCur, *qNext;
	if( NULL==tree ){
		cout<<"Empty tree."<<endl;
		return ;
	}
	qCur = &q1;
	qNext = &q2;
	qCur->push( tree );
	//get depth
	int nDepth = get_depth( tree );
	for( int iDep = 1; iDep<=nDepth; iDep++ ){
		while( !qCur->empty() ){
			PNode node = qCur->front();
			qCur->pop();
			if( NULL==node ){
				cout<<"NULL";
			}else{
				cout<<(node->data);
			}
			cout<<"	";
			
			qNext->push( node );
			if( NULL==node ){
				qNext->push( NULL );//for left
				qNext->push( NULL );//for right
			}else{
				qNext->push( node->left );//for left
				qNext->push( node->right );//for right
			}
		}
		cout<<endl;
		//switch qCur and qNext
		queue<PNode>* qTemp = qCur;
		qCur = qNext;
		qNext = qTemp;
		
	}
	
}
int get_depth( TREE tree ){
	if( NULL==tree){
		return 0;
	}
	int depth = 1;
	
	return depth;
}
/*
get successor of node
node: leftmost node of right subtree of "node"
*/
PNode get_successor(TREE tree, PNode node ){
	PNode p = node->right;
	PNode pre = p;
	while( NULL!=p ){
		pre = p;
		p = p->left;
	}
	return pre;
}
void delete_fixup(TREE tree, PNode node){
	
}
