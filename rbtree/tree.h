
enum rbtree_node_color { RED, BLACK };

typedef struct rbtree_node_t {
    void* key;
    void* value;
    struct rbtree_node_t* left;
    struct rbtree_node_t* right;
    struct rbtree_node_t* parent;
    enum rbtree_node_color color;
} *rbtree_node;

typedef struct rbtree_t {
    rbtree_node root;
} *rbtree;
typedef rbtree_node node;
typedef enum rbtree_node_color color;

node grandparent(node n) {
    assert (n != NULL);
    assert (n->parent != NULL); /* Not the root node */
    assert (n->parent->parent != NULL); /* Not child of root */
    return n->parent->parent;
}


node sibling(node n) {
    assert (n != NULL);
    assert (n->parent != NULL); /* Root node has no sibling */
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}


node uncle(node n) {
    assert (n != NULL);
    assert (n->parent != NULL); /* Root node has no uncle */
    assert (n->parent->parent != NULL); /* Children of root have no uncle */
    return sibling(n->parent);
}

void verify_properties(rbtree t) {
#ifdef VERIFY_RBTREE
    verify_property_1(t->root);
    verify_property_2(t->root);
    /* Property 3 is implicit */
    verify_property_4(t->root);
    verify_property_5(t->root);
#endif
}


void verify_property_1(node n) {
    assert(node_color(n) == RED || node_color(n) == BLACK);
    if (n == NULL) return;
    verify_property_1(n->left);
    verify_property_1(n->right);
}

void verify_property_2(node root) {
    assert(node_color(root) == BLACK);
}

color node_color(node n) {
    return n == NULL ? BLACK : n->color;
}

void verify_property_4(node n) {
    if (node_color(n) == RED) {
        assert (node_color(n->left)   == BLACK);
        assert (node_color(n->right)  == BLACK);
        assert (node_color(n->parent) == BLACK);
    }
    if (n == NULL) return;
    verify_property_4(n->left);
    verify_property_4(n->right);
}

void verify_property_5(node root) {
    int black_count_path = -1;
    verify_property_5_helper(root, 0, &black_count_path);
}

void verify_property_5_helper(node n, int black_count, int* path_black_count) {
    if (node_color(n) == BLACK) {
        black_count++;
    }
    if (n == NULL) {
        if (*path_black_count == -1) {
            *path_black_count = black_count;
        } else {
            assert (black_count == *path_black_count);
        }
        return;
    }
    verify_property_5_helper(n->left,  black_count, path_black_count);
    verify_property_5_helper(n->right, black_count, path_black_count);
}

rbtree rbtree_create() {
    rbtree t = malloc(sizeof(struct rbtree_t));
    t->root = NULL;
    verify_properties(t);
    return t;
}
node new_node(void* key, void* value, color node_color, node left, node right) {
    node result = malloc(sizeof(struct rbtree_node_t));
    result->key = key;
    result->value = value;
    result->color = node_color;
    result->left = left;
    result->right = right;
    if (left  != NULL)  left->parent = result;
    if (right != NULL) right->parent = result;
    result->parent = NULL;
    return result;
}

node lookup_node(rbtree t, void* key, compare_func compare) {
    node n = t->root;
    while (n != NULL) {
        int comp_result = compare(key, n->key);
        if (comp_result == 0) {
            return n;
        } else if (comp_result < 0) {
            n = n->left;
        } else {
            assert(comp_result > 0);
            n = n->right;
        }
    }
    return n;
}


