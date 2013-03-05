#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

static node grandparent(node n);

static node sibling(node n);

static node uncle(node n);
static void verify_properties(rbtree t);

static void verify_property_1(node root);
static void verify_property_2(node root);
static color node_color(node n);

static void verify_property_4(node root);

static void verify_property_5(node root);
static void verify_property_5_helper(node n, int black_count, int* black_count_path);

rbtree rbtree_create();
static node new_node(void* key, void* value, color node_color, node left, node right);
typedef int (*compare_func)(void* left, void* right);
static node lookup_node(rbtree t, void* key, compare_func compare);

ini main(void){

	cout<<"hello world"<<endl;
	return 0;
}
