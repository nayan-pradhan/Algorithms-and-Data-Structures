#include <iostream>

enum Color {RED, BLACK};
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree {
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
    public:
        RedBlackTree();
        void insert (int newElem);
        void insertFixup(RedBlackTree myTree, int newElem);
        void deleteNode (Node *&);
        Node *predecessor(const Node *&x);
        Node *successor(const Node *&x);
        Node *getMinimum(Node *x);
        Node *getMaximum(Node *x);
        Node *search(int elem);
};

RedBlackTree::RedBlackTree() {
    RedBlackTree myTree;
    root = NULL;
    root -> color = BLACK;
    root -> left = NULL;
    root -> right = NULL;
    root -> right = NULL;
}

void RedBlackTree::rotateLeft(Node *&x) {
    Node *y;
    y = x -> right;
    x -> right = y -> left;
    if (y -> left != NULL) {
        y -> left -> parent = x;
    } 
    y -> parent = x -> parent;
    if (x -> parent == NULL) {
        root = y;
    }
    else if (x == x -> parent -> left) {
        x -> parent -> left = y;
    }
    else {
        x -> parent -> right = y;
    }
    y -> left = x;
    x -> parent = y;
}

void RedBlackTree::rotateRight(Node *&x) {
    Node *y;
    x = y -> left;
    y -> left = x -> right;
    if (x -> left != NULL) {
        x -> left -> parent = x;
    }
    if (y -> parent == NULL) {
        root = x;
    }
    else if (y == y -> parent -> left) {
        y -> parent -> left = x;
    }
    else {
        y -> parent -> right = x;
    }
    x -> right = y;
    y -> parent = x;
}

void RedBlackTree::insert (RedBlackTree myTree ,int elem) {
    struct Node *newElem, *x, *y;
    newElem -> data = elem;
    x = root;
    y = NULL;
    while(x != NULL) {
        y = x;
        if (newElem -> data < x -> data) {
            x = x -> left;
        }
        else {
            x = x -> right;
        }
    }
    newElem -> parent = y;
    if (y -> data == NULL) {
        root = newElem;
    }
    else if (newElem -> data > y -> data) {
        y -> left - newElem;
    }
    else {
        y -> right = root;
    }
    newElem -> left = NULL;
    newElem -> right = NULL;
    newElem -> color = RED;
    insertFixup (myTree, elem);
}

void RedBlackTree::deleteNode (Node *&) {

}

Node* RedBlackTree::predecessor(const Node *&x) {
    if (x -> left != NULL) {
        return (getMaximum(x -> left));
    }
}

Node* RedBlackTree::successor(const Node *&x) {
    if (x -> right != NULL) {
        return (getMinimum(x -> right));
    }
}

Node* RedBlackTree::getMaximum(Node *x) {
    struct Node *y = x;
    while (y -> right != NULL) {
        y = y -> right;
    }
    return y;
}

Node* RedBlackTree::getMinimum(Node *x) {
    struct Node *y = x;
    while (y -> left != NULL) {
        y = y -> left;
    }
    return y;
}

Node* RedBlackTree::search(int elem) {
    struct Node *pointer;
    pointer = root;
    while ((pointer != NULL) && (elem != pointer -> data)) {
        if (elem > pointer -> data) {
            pointer = pointer -> left;
        }
        else {
            pointer = pointer -> right;
        }
    }
    return pointer;
}