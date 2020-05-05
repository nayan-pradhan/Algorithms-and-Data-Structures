using namespace std;
#include <iostream>

enum Color {RED, BLACK};
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};
class RedBlackTree
{
    private:
        Node * root;
    protected:
        void rotateLeft(Node * &x){
            if(x == NULL){
                //cout << "impossible to rotate, empty node!" << endl;
                return;
            }
            if(x -> right == NULL){
                //cout << "impossible to rotate, no right child!" << endl;
                return;
            }
            Node * x1 = new Node;
            x1 = x;
            Node * y = new Node;
            y = x1 -> right;
            x1 -> right = y -> left;
            if(y -> left != NULL)
                y -> left -> parent = x1;
            y -> parent = x1 -> parent;
            if(x1 -> parent == NULL)
                root = y;
            else if(x1 == x1 -> parent -> left)
                x1 -> parent -> left = y;
            else
                x1 -> parent -> right = y;
            y -> left = x1;
            x1 -> parent = y;
            return;
        }
        void rotateRight(Node * &x){
            if(x == NULL){
                //cout << "impossible to rotate, empty node!" << endl;
                return;
            }
            if(x -> left == NULL){
                //cout << "impossible to rotate, no left child!" << endl;
                return;
            }
            Node * x1 = new Node;
            x1 = x;
            Node * y = new Node;
            y = (x1 -> left);
            Node * b = new Node;
            b = (y -> right);
            (x1 -> left) = b;
            if(b != NULL)
                (b -> parent) = x1;
            (y -> parent) = x1;
            (y -> parent) = (x1 -> parent);
            if((x1 -> parent) == NULL)
                root = y;
            else if(x1 == ((x1 -> parent) -> right))
                ((x1 -> parent) -> right) = y;
            else
                ((x1 -> parent) -> left) = y;
            (y -> right) = x1;
            (x1 -> parent) = y;
            return;
        }
        void transplant(Node* &u, Node* &v){
            Node * u1 = new Node;
            u1 = u;
            Node * v1 = new Node;
            v1 = v;
            if(u1 == NULL){
                cout << "Impossible, node u not defined!" << endl;
                return;
            }
            if(u1 -> parent == NULL)
                root = v1;
            else if(u1 == u1 -> parent -> left)
                u1 -> parent -> left = v1;
            else
                u1 -> parent -> right = v1;
            if(v1 != NULL)
                v1 -> parent = u1 -> parent;
        }
    public:
        RedBlackTree(){
            root = NULL;
        }
        Node * getRoot(){
            return root;
        }
        void print_tree(Node* top, int level = 0){
            if(root == NULL){
                cout << "tree is empty" << endl;
                return;
            }
            if(top == NULL){
                cout << "on the level " << level << " NULL Node" << endl;
                return;
            }
            cout << "on the level " << level << " element with value " << top -> data << " of color " << top -> color << endl;
            Node * top1 = new Node;
            top1 = top -> left;
            Node * top2 = new Node;
            top2 = top -> right;
            level++;
            print_tree(top1, level);
            print_tree(top2, level);
        }
        void insert(int num){
            Node * y = new Node;
            y = NULL;
            Node * x = new Node;
            x = root;
            while(x != NULL){
                y = x;
                if(num < (x -> data))
                    x = (x -> left);
                else
                    x = (x -> right);
            }
            Node * z = new Node;
            z -> data = num;
            z -> parent = y;
            if(y == NULL)
                root = z;
            else if((z -> data) < (y -> data))
                (y -> left) = z;
            else
                (y -> right) = z;
            z -> right = NULL;
            z -> left = NULL;
            z -> color = RED;
            cout << num << " successfully inserted!" << endl;
            //color fixup
            if(z == root){
                z -> color = BLACK;
                return;
            }
            Node * y1 = new Node;
            while(z -> parent -> color == RED){
                if(z -> parent == root){
                    z -> parent -> color = BLACK;
                }
                else{
                    if(z -> parent == z -> parent -> parent -> left){
                        y1 = z -> parent -> parent -> right;
                        if(y1 == NULL){
                            if(z == z -> parent -> right){
                                z = z -> parent;
                                rotateLeft(z);
                            }
                            z -> parent -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            rotateRight(z -> parent -> parent);
                        }
                        else if(y1 -> color == BLACK){
                            if(z == z -> parent -> right){
                                z = z -> parent;
                                rotateLeft(z);
                            }
                            z -> parent -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            rotateRight(z -> parent -> parent);
                        }
                        else{ // y1 -> color == RED
                            z -> parent -> color = BLACK;
                            y1 -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            z = z -> parent -> parent;
                            if(z == root){
                                z -> color = BLACK;
                                return;
                            }
                        }
                    }
                    else{ //if(z -> parent == z -> parent -> parent -> right)
                        y1 = z -> parent -> parent -> left;
                        if(y1 == NULL){
                            if(z == z -> parent -> left){
                                z = z -> parent;
                                rotateRight(z);
                            }
                            z -> parent -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            rotateLeft(z -> parent -> parent);
                        }
                        else if(y1 -> color == BLACK){
                            if(z == z -> parent -> left){
                                z = z -> parent;
                                rotateLeft(z);
                            }
                            z -> parent -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            rotateRight(z -> parent -> parent);
                        }
                        else{ // y1 -> color == RED
                            z -> parent -> color = BLACK;
                            y1 -> color = BLACK;
                            z -> parent -> parent -> color = RED;
                            z = z -> parent -> parent;
                            if(z == root){
                                z -> color = BLACK;
                                return;
                            }
                        }
                    }
                }
            }
            root -> color = BLACK;
            return;
        }
        void delete_el(Node *& z){
            if(z == NULL){
                cout << "Invalid input, z is NULL" << endl;
                return;
            }
            Node * z1 = new Node;
            z1 = z;
            Node * y = new Node;
            y = z1;
            Color y_original = y -> color;
            Node * x = new Node;
            if(z1 -> left == NULL){
                x = z1 -> right;
                transplant(z1, z1 -> right);
            }
            else if(z -> right == NULL){
                x = z1 -> left;
                transplant(z1, z1 -> left);
            }
            else{
                y = getMinimum(z1 -> right);
                y_original = y -> color;
                x = y -> right;
                if(y -> parent == z1)
                    x -> parent = y;
                else{
                    transplant(y, y -> right);
                    y -> right = z1 -> right;
                    if(y -> right != NULL)
                        y -> right -> parent = y;
                }
                transplant(z1, y);
                y -> left = z1 -> left;
                if(y -> left != NULL)
                    y -> left -> parent = y;
                y -> color = z1 -> color;
            }
            if(y_original == BLACK){
                if((x == root)&&(x == NULL))
                    return;
                if(x == root){
                    return;
                }
                Node * w = new Node;
                while((x != root)&&(x -> color == BLACK)){
                    if(x == x -> parent -> left){
                        w = x -> parent -> right;
                        // w cannot be NULL because otherwise tree would be invalid
                        if(w -> color == RED){ // case 1
                            w -> color = BLACK;
                            x -> parent -> color = RED;
                            rotateLeft(x -> parent);
                            w = x -> parent -> right;
                        }
                        if((w -> left -> color == BLACK)&&(w -> right -> color == BLACK)){
                            // w -> left or w -> right are not NULL due to construction
                            w -> color = RED;
                            if(x -> parent -> color == RED){
                                x -> parent -> color = BLACK;
                                return;
                            }
                            x = x -> parent;
                        }
                        else{
                            if(w -> right -> color == BLACK){
                                w -> left -> color = BLACK;
                                w -> color = RED;
                                rotateRight(w);
                                w = x -> parent -> right;
                            }
                            w -> color = x -> parent -> color;
                            x -> parent -> color = BLACK;
                            w -> right -> color = BLACK;
                            rotateLeft(x -> parent);
                        }
                    }
                    else{ //if(x == x -> parent -> right)
                        w = x -> parent -> left;
                        // w cannot be NULL because otherwise tree would be invalid
                        if(w -> color == RED){ // case 1
                            w -> color = BLACK;
                            x -> parent -> color = RED;
                            rotateRight(x -> parent);
                            w = x -> parent -> left;
                        }
                        if((w -> right -> color == BLACK)&&(w -> left -> color == BLACK)){
                            // w -> left or w -> right are not NULL due to construction
                            w -> color = RED;
                            if(x -> parent -> color == RED){
                                x -> parent -> color = BLACK;
                                return;
                            }
                            x = x -> parent;
                        }
                        else{
                            if(w -> left -> color == BLACK){
                                w -> right -> color = BLACK;
                                w -> color = RED;
                                rotateLeft(w);
                                w = x -> parent -> left;
                            }
                            w -> color = x -> parent -> color;
                            x -> parent -> color = BLACK;
                            w -> left -> color = BLACK;
                            rotateRight(x -> parent);
                        }
                    }
                }
                x -> color = BLACK;
            }
            return;
        }
        Node * predecessor(Node *&x){
            if(x == NULL){
                cout << "Invalid tree, empty" << endl;
                return NULL;
            }
            Node * x1 = new Node;
            x1 -> data = x -> data;
            x1 -> color = x -> color;
            x1 -> parent = x -> parent;
            x1 -> right = x -> right;
            x1 -> left = x -> left;
            if(x1 -> left != NULL)
                return getMaximum(x1 -> left);
            Node * y = new Node;
            y = x1 -> parent;
            while((y != NULL)&&(x1 == y -> left)){
                x1 = y;
                y = y -> parent;
            }
            return y;
        } 
        Node * successor(Node *& x){
            if(x == NULL){
                cout << "Invalid tree, empty" << endl;
                return NULL;
            }
            Node * x1 = new Node;
            x1 -> data = x -> data;
            x1 -> color = x -> color;
            x1 -> parent = x -> parent;
            x1 -> right = x -> right;
            x1 -> left = x -> left;
            if(x1 -> right != NULL)
                return getMinimum(x1 -> right);
            Node * y = new Node;
            y = x1 -> parent;
            while((y != NULL)&&(x1 == y -> right)){
                x1 = y;
                y = y -> parent;
            }
            return y;
        }
        Node * getMinimum(Node * top){
            if(top == NULL){
                cout << "tree is empty, operation is impossible" << endl;
                return NULL;
            }
            Node * y = top;
            while(y -> left != NULL)
                y = y -> left;
            return y;
        }
        Node * getMaximum(Node * top){
            if(top == NULL){
                cout << "tree is empty, operation is impossible" << endl;
                return NULL;
            }
            Node * y = top;
            while(y -> right != NULL)
                y = y -> right;
            return y;
        }
        Node * search(int num){
            if(root == NULL){
                cout << "tree is empty, operation is impossible" << endl;
                return NULL;
            }
            Node * y = root;
            while(y != NULL){
                if(y -> data == num){
                    cout << num << " is found, search finished" << endl;
                    return y;
                }
                else if(((y -> data) > num)&&(y -> left != NULL))
                    y = y -> left;
                else if(((y -> data) < num)&&(y -> right != NULL))
                    y = y -> right;
                else{
                    cout << num << " is not in the tree, search finished" << endl;
                    return NULL;
                }
            }
            return NULL; //not needed, but otherwise produces the warning
        }
};
int main(){
    RedBlackTree x = RedBlackTree();
    cout << "Enter X to exit, I to insert, D to delete, P to print tree, S for search, A for successor, B for predesessor, E for maximum, F for minimum, R for root. The tree is empty right now." << endl;
    cout << "Use root, search, Max, Min, successor, and predesessor functions to point to the needed element. By default pointer is pointing to the root." << endl;
    char sw;
    cin >> sw;
    Node * ptr = new Node;
    ptr = x.getRoot();
    while(sw != 'X'){
        switch(sw){
            case 'X':
                break;
            case 'I':
                int num;
                cout << "Enter integer to be inserted: ";
                cin >> num;
                x.insert(num);
                break;
            case 'D':
                x.delete_el(ptr);
                cout << "Element deleted!" << endl;
                ptr = x.getRoot();
                break;
            case 'P':
                cout << "The tree is printed from top to bottom; all elements within the same level are printed from left to right." << endl;
                x.print_tree(x.getRoot());
                break;
            case 'S':
                int number;
                cout << "Enter integer to be searched: ";
                cin >> number;
                ptr = x.search(number);
                break;
            case 'A':
                ptr = x.successor(ptr);
                if(ptr != NULL){
                    cout << "Successor has value " << ptr -> data << " and color " << ptr -> color << endl;;
                }
                else{
                    cout << "Successor is NULL" << endl;
                }
                break;
            case 'B':
                ptr = x.predecessor(ptr);
                if(ptr != NULL){
                    cout << "Predesessor has value " << ptr -> data << " and color " << ptr -> color << endl;;
                }
                else{
                    cout << "Predesessor is NULL" << endl;
                }
                break;
            case 'E':
                ptr = x.getMaximum(x.getRoot());
                if(ptr != NULL){
                    cout << "Maximum has value " << ptr -> data << " and color " << ptr -> color << endl;;
                }
                break;
            case 'F':
                ptr = x.getMinimum(x.getRoot());
                if(ptr != NULL){
                    cout << "Minimum has value " << ptr -> data << " and color " << ptr -> color << endl;;
                }
                break;
            case 'R':
                ptr = x.getRoot();
                if(ptr != NULL){
                    cout << "Root has value " << ptr -> data << " and color " << ptr -> color << endl;;
                }
                else{
                    cout << "Root is NULL" << endl;
                }
                break;
            case 'Z':
                cout << "X - exit, \nI - insert, D - delete, P - print, \nS - search, A - successor, B - predesessor, \nE - Max, F - Min, R - root. \nThe tree is empty right now." << endl;
                cout << "Use R, S, A, B, E, and F functions to point to the needed element. \nBy default pointer is pointing to the root." << endl;
                break;
            default:
                cout << "This input doesn't correspond to any action" << endl;
                break;
        }
        if(ptr == NULL)
            ptr = x.getRoot();
        cout << "Choose next action (Z - list of possible actions)" << endl;
        cin >> sw;
    }
}