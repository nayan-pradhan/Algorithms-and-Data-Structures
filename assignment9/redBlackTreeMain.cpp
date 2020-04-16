/* 
    CH-231-A
    9b cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include "redBlackTrees.cpp"

int main() {
    RedBlackTree myTree;
    myTree.insert(1);
    myTree.insert(2);
    std::cout << "root->"<< myTree.getRoot() -> data;
    myTree.printTree(myTree.getRoot());
    myTree.insert(5);
    myTree.printTree(myTree.getRoot());
    myTree.insert(3);
    myTree.printTree(myTree.getRoot());
}