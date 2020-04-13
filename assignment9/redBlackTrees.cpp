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
        void rbTransplant(RedBlackTree T, Node *u, Node *v);
    public:
        RedBlackTree();
        void printTree (struct Node *root);
        void insert (RedBlackTree myTree, int newElem);
        void insertFixup(RedBlackTree myTree, struct Node* newElem);
        void deleteNode (RedBlackTree myTree, Node *&elem);
        void deleteFixUp (RedBlackTree myTree, Node *&elem);
        Node *predecessor(const Node *&x);
        Node *successor(const Node *&x);
        Node *getMinimum(Node *x);
        Node *getMaximum(Node *x);
        Node *search(RedBlackTree myTree, int elem);
};

RedBlackTree::RedBlackTree() {
    root = NULL;
}

void RedBlackTree::printTree (struct Node *root) {
    if (root != NULL) {
        printTree (root -> left);
        std::cout << root -> data << " ";
        printTree (root -> right);
    }
    std::cout << std::endl;
}

void RedBlackTree::rotateLeft(Node *&x) {
    Node *y = NULL;
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
    Node *y = NULL;
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

void RedBlackTree::insert(RedBlackTree myTree ,int elem) {
    struct Node *newElem = NULL, *x = NULL, *y = NULL;
    newElem -> data = elem;
    x = myTree.root;
    y = NULL;
    while(x != NULL) {
        y = x;
        if ((newElem -> data) < (x -> data)) {
            x = x -> left;
        }
        else {
            x = x -> right;
        }
    }
    newElem -> parent = y;
    if (y == NULL) {
        myTree.root = newElem;
    }
    else if ((newElem -> data) < (y -> data)) {
        y -> left = newElem;
    }
    else {
        y -> right = root;
    }
    newElem -> left = NULL;
    newElem -> right = NULL;
    newElem -> color = RED;
    insertFixup (myTree, newElem);
}

void RedBlackTree::insertFixup(RedBlackTree myTree, struct Node *newElem) {
    while (newElem -> parent -> color == RED) {
        if (newElem -> parent == newElem -> parent -> parent -> left) {
            struct Node *y = newElem -> parent -> parent -> right;
            if (y -> color == RED) {
                newElem -> parent -> color = BLACK;
                y -> color = BLACK;
                newElem -> parent -> parent -> color = RED;
                //to check effect of the above code in rest of tree 
                newElem = newElem -> parent -> parent; 
            }
            else if (newElem == newElem -> parent -> right) {
                newElem = newElem -> parent;
                rotateLeft(newElem);
            }
            newElem -> parent -> color = BLACK;
            newElem -> parent -> parent -> color = RED;
            rotateRight (newElem -> parent -> parent);
        }
        else {
            struct Node *y = newElem -> parent -> parent -> left; //left uncle
            if (y -> color == RED) {
                newElem -> parent -> color = BLACK;
                y -> color = BLACK;
                newElem -> parent -> parent -> color = RED;
                //to check effect of the above code in rest of tree
                newElem = newElem -> parent -> parent;
            }
            else if (newElem == newElem -> parent -> right) {
                newElem = newElem -> parent;
                rotateLeft(newElem);
            }
            newElem -> parent -> color = BLACK;
            newElem -> parent -> parent -> color = RED;
            rotateRight (newElem -> parent -> parent);
        }
    }
}

void RedBlackTree::deleteNode(RedBlackTree myTree, Node *&z) {
    struct Node *y = z;
    struct Node *x = NULL;
    Color ogYcolor = y -> color;
    if (z -> left == NULL) {
        x = z -> right;
        rbTransplant(myTree, z, z -> right);
    }
    else if (z -> right == NULL) {
        x = z -> left;
        rbTransplant(myTree, z, z -> left);
    }
    else {
        y = getMinimum(z -> right);
        ogYcolor = y -> color;
        x = y -> right;
        if (y -> parent == z) {
            x -> parent = y;
        }
        else {
            rbTransplant(myTree, y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }
        rbTransplant(myTree, z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
        y -> color = z -> color;
    }
    if (ogYcolor == BLACK) {
        deleteFixUp (myTree, x);
    }
}

void RedBlackTree::deleteFixUp(RedBlackTree myTree, Node *&x) {
    while (x != myTree.root && x->color == BLACK) {
        if (x == x -> parent -> left) {
            struct Node *w = x -> parent -> right;
            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                rotateLeft(x -> parent); 
                w = x -> parent -> right;
            }
            if (w -> left -> color == BLACK && w -> right -> color == BLACK) {
                w -> color = RED;
                x = x -> parent;
            }
            else if (w -> right -> color == BLACK) {
                w -> left -> color = BLACK;
                w -> color = RED;
                rotateRight (w);
                w = x -> parent -> right;
            }
            w -> color = x -> parent -> color;
            x -> parent -> color = BLACK;
            w -> right -> color = BLACK;
            rotateLeft(x -> parent);
        }
        else {
            struct Node *w = x-> parent -> left;
            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                rotateRight(x -> parent);
                w = x -> parent -> right;
            }
            if (w -> left -> color == BLACK && w -> right -> color == BLACK) {
                w -> color = RED;
                x = x -> parent;
            }
            else if (w -> left -> color == BLACK) {
                w -> right -> color = BLACK;
                w -> color = RED;
                rotateLeft (w);
                w = x -> parent -> right;
            }
            w -> color = x -> parent -> color;
            x -> parent -> color = BLACK;
            w -> left -> color = BLACK;
            rotateRight(x -> parent);
        }
    }
    x -> color = BLACK;
}

void RedBlackTree::rbTransplant(RedBlackTree myTree, Node *u, Node *v) {
    if (u -> parent == NULL) {
        myTree.root = u;
    }
    else if (u == (u -> parent -> left)) {
        u -> parent -> left = v;
    }
    else {
        u -> parent -> right = v;
    }
    v -> parent = u -> parent;
}

Node* RedBlackTree::predecessor(const Node *&x) {
    if (x -> left != NULL) {
        return (getMaximum(x -> left));
    }
    else {
        return NULL;
    }
}

Node* RedBlackTree::successor(const Node *&x) {
    if (x -> right != NULL) {
        return (getMinimum(x -> right));
    }
    else {
        return NULL;
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

Node* RedBlackTree::search(RedBlackTree myTree, int elem) {
    struct Node *pointer;
    pointer = myTree.root;
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

int main() {
    RedBlackTree myTree;
    std::cout << "Helllo" << std::endl;
    myTree.insert(myTree, 1);
}