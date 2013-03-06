

#ifndef _TREE_H_
#define _TREE_H_

enum Color{
	RED, BLACK
};

struct Node{
	struct Node* parent;
	struct Node* left;
	struct Node* right;
	int data;
	Color color;
	
};

typedef struct Node *PNode, *TREE;
PNode create_node();
PNode create_tree();
PNode insert_node(TREE tree, int data );
PNode delete_node(TREE tree, PNode node);
PNode search(TREE tree, int data );
void insert_fixup(TREE tree, PNode node);
void show_tree(TREE tree);
int get_depth( TREE tree );
PNode get_successor( TREE tree, PNode node );
void delete_fixup(TREE tree, PNode node);



#endif
