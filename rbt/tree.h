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
PNode insert_fixup(TREE tree, PNode node);
bool show_tree(TREE tree);
int get_depth( TREE tree );
PNode get_successor( TREE tree, PNode node );
PNode  delete_fixup(TREE tree, PNode node);
PNode  left_rotate( TREE tree, PNode node );
PNode right_rotate( TREE tree, PNode node );
PNode get_minimum( PNode node);
int get_count( int depth );
bool check_parent( TREE tree );
void check_p( PNode tree );

#endif
