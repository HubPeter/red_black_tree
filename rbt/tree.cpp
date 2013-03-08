#include"tree.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
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
	node->color = RED;
	if( NULL==tree ){
		tree = node;
		return tree;
	}
	PNode p = tree;
	PNode pre = p;
	while( NULL!=p ){
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
	node->parent = pre;
	//fixup
	insert_fixup(tree, node);
	return tree;
}

PNode delete_node(TREE tree, PNode node){
	PNode succ;
	if( NULL==node->left || NULL==node->right ){
		succ = node;
	}else{
		succ = get_successor( tree, node );
	}
	//now succ has only one child
	//get child
	PNode child;
	if( succ->left!=NULL ){
		child = succ->left;
	}else{
		child = succ->right;
	}
	//link new child
	if( child!=NULL ){
		child->parent = succ->parent;
		if( NULL==succ->parent ){//root to be delete
			tree = child;
		}else{
			if( succ == succ->parent->left ){
				child->parent->left = child;
			}else{
				child->parent->right = child;
			}
		}
	}else{
		if( succ == succ->parent->left ){
			succ->parent->left = NULL;
		}else{
			succ->parent->right = NULL;
		}
	}
	//think only tree one node, we do not need toswitch data
	if( succ!=node ){
		node->data = succ->data;
	}
	//this case will break p:5(black path)
	if( BLACK==succ->color ){
		delete_fixup( tree, child );
	}
	free( succ );//free node
	return tree;
}
PNode search(TREE tree, int data ){
	PNode node = tree;
	while( node!=NULL &&node->data!=data ){
		if( data<node->data ){
			node = node->left;
		}else{
			node = node->right;
		}
	}
	return node;
}
void insert_fixup(TREE tree, PNode node){
	if( node->data==205 ){
		cout<<endl;
	}
	while(  node->parent!=NULL && \
			node->parent->parent!=NULL && \
			node->parent->color==RED ){
 		    //in this case, grandpa exists
		//goal is floating the red
		if( node->parent==node->parent->parent->left ){
			//parent is left child of grandpa
			PNode uncle = node->parent->parent->right;
				//get uncle node
			//sink black and float red
			if( uncle!=NULL && uncle->color==RED ){
				//after this still be case 1, need judge
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			//node->parent and uncle is black
			//node is red
			//this case prepare for right rotate
			}else{
				if( node==node->parent->right ){
					//node is right child of parent
					node = node->parent;
					left_rotate( tree, node );
				}
			    //right rotate and ensure balck path length
			    node->parent->color = BLACK;
				node->parent->parent->color = RED;
			    right_rotate( tree, node->parent->parent );
			}
		}else{
 		    //in this case, grandpa exists
			//goal is floating the red
			//parent is left child of grandpa
			PNode uncle = node->parent->parent->left;
			//get uncle node
			//sink black and float red
			if( uncle!=NULL && uncle->color==RED ){
				//after this still be case 1, need judge
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
				//node->parent and uncle is black
				//node is red
				//this case prepare for right rotate
			}else{
				if( node==node->parent->left ){
					//node is right child of parent
					node = node->parent;
					right_rotate( tree, node );
				}
				//right rotate and ensure balck path length
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				left_rotate( tree, node->parent->parent );
			}
		}
	}
	//until here we can change red to black and p:5 will
	//not be violated
	tree->color = BLACK;
}
void show_tree(TREE tree){
	//bfs based
	queue<PNode> q1, q2;
	queue<PNode> *qCur, *qNext;
	if( NULL==tree ){
		cout<<"Empty tree."<<endl;
		return;
	}
	qCur = &q1;
	qNext = &q2;
	qCur->push( tree );
	//get depth
	int nDepth = get_depth( tree );
	int nRowHigh = 2;//height of row
	int W = 32;//width of canvas

	for( int iDep = 1; iDep<=nDepth; iDep++ ){
		int nCurCount ;//current count of node of level iDep
		nCurCount = get_count( iDep );//get count
		int nCurNode = 0;//index of current node:1 based
		int nCurOffset = 0;//current offset of x-ray
		
		int nColWidth;//current column width
		nColWidth = W/nCurCount;
		while( !qCur->empty() ){
			nCurNode ++;//1 based
			PNode node = qCur->front();
			qCur->pop();
			//before data
			for( int i=0; i<nColWidth-2; i++ ){
				printf(" ");
			}
			if( NULL==node ){
				printf("----");
			}else{
				if( node->color==BLACK ){
				    printf("%4d", node->data);
				}else{
					printf("%4d", node->data);
				}
			}
			//after data
			for( int i=0; i<nColWidth-2; i++ ){
				printf(" ");
			}
			
			if( NULL==node ){
				qNext->push( NULL );//for left
				qNext->push( NULL );//for right
			}else{
				qNext->push( node->left );//for left
				qNext->push( node->right );//for right
			}
		}
		//show row height
		for( int i=0; i<nRowHigh; i++ ){
			printf("\n");
		}
		//switch qCur and qNext
		queue<PNode>* qTemp = qCur;
		qCur = qNext;
		qNext = qTemp;
		
	}

}
int get_depth( TREE tree ){
	
	if( NULL==tree ){
		return 0;
	}
 	int ldepth = get_depth( tree->left );
 	int rdepth = get_depth( tree->right );
	return ((ldepth>rdepth)?ldepth:rdepth) + 1;
}
//get minimum of subtree root by node
PNode get_minimum( PNode node){
	PNode p = node;
	PNode pre = p;
	while( NULL!=p ){
		pre = p;
		p = p->left;
	}
	return pre;
}
/*
get successor of node
node: leftmost node of right subtree of "node"
*/
PNode get_successor(TREE tree, PNode node ){
	PNode succ = NULL;
	if( node->right!=NULL ){
		succ = get_minimum( node->right );
		return succ;
	}
	succ = node->parent;
	while( succ!=NULL && node==succ->right ){
		node = succ;
		succ = succ->parent;
	}
	return succ;
}
void delete_fixup(TREE tree, PNode node){
	while( node!=tree && BLACK==node->color ){
		if( node==node->parent->left ){
			PNode brother = node->parent->right;
			//here we can get a red pos
			if( brother->color==RED ){
				brother->color = BLACK;
				node->parent->color = RED;
				left_rotate( tree, node->parent );
				brother = node->parent->right;
			}
			//
			if( brother->left->color==BLACK &&\
				brother->right->color==BLACK){
				brother->color = RED;
				node = node->parent;
			}else {
				if( brother->right->color==BLACK ){
					brother->left->color = BLACK;
					brother->color = RED;
					right_rotate( tree, brother );
					brother = node->parent->right;
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->right->color = BLACK;
				left_rotate( tree, node->parent );
				node = tree;
			}
		}else{
			
		}
		node->color = BLACK;
	}


}
void left_rotate( TREE tree, PNode node ){
	if( node->data==205 ){
		cout<<endl;
	}
	assert( node!=NULL );//prevent illegal call
	//get related subtree
	PNode left = node->left;
	PNode right = node->right;
	PNode right_left = NULL;
	PNode right_right = NULL;
	if( right!=NULL ){
		right_left = right->left;
		right_right = right->right;
	}
	//rotate: we take over all related pointer, and be careful
	//try typing first line code, and you find the order
	right->parent = node->parent;
	if( node==node->parent->left ){
		node->parent->left = right;
	}else{
		node->parent->right = right;
	}
	node->parent = right;
	node->right = right_left;
	right->left = node;
}
void right_rotate( TREE tree, PNode node ){
	if( node->data==205 ){
		cout<<endl;
	}
	assert( node!=NULL );//prevent illegal call
	//get related subtree
	PNode left = node->left;
	PNode right = node->right;
	PNode left_left = NULL;
	PNode left_right = NULL;
	if( NULL!=left ){
		left_left = left->left;
		left_right = left->right;
	}
	//until now we take over all need pointer
	//we can change the child or parent field
	left->parent = node->parent;
	if( node==node->parent->left ){
		node->parent->left = left;
	}else{
		node->parent->right = left;
	}
	node->parent = left;
	left->right = node;
	node->left = left_right;
}
//get node count of depth
int get_count( int depth ){
	assert( depth>0 );
	int count = 0;
	count = pow( 2, depth-1 );
	return count;
}
