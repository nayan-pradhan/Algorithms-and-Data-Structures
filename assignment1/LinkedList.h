/* 
    CH-231-A
    a1 p3 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
//struct node
template <class T>
struct node {
    T info; //for info
    node<T> *next; //for next
    node<T> *prev; //for prev
};
//class linked list
template <class T>
class linkedList {
    private:
        node<T> *head; //node head of type T
        int numOfElem; //number of element
    public: 
        linkedList() { //default constructor
            head = NULL;
            numOfElem = 0;
        }
        bool addToFront(T elem) { //add to front of list
            struct node<T> *newElem; //new element
            newElem = new struct node<T>; //dynamically allocating
            newElem -> info = elem;
            newElem -> prev = NULL;
            newElem -> next = NULL;
            if (head == NULL) { //corner case when list is empty
                std::cout << "Adding " << elem << " to the list!" << std::endl;
                head = newElem;
                numOfElem++;
                return true;
            }
            newElem -> next = head;
            head -> prev = newElem;
            head = newElem;
            numOfElem++;
            std::cout << "Adding " << elem << " to the front of the list!" << 
                std::endl;
            return true;
        }
        bool addToEnd(T elem) {
            struct node<T> *pointer, *newElem; //pointer and new element
            newElem = new struct node<T>; //dynamically allocating 
            newElem -> info = elem;
            newElem -> next = NULL;
            if (head == NULL) { //corner case when the list is empty
                std::cout << "Adding " << elem << " to the list!" << std::endl;
                head = newElem;
                numOfElem++;
                head -> prev = NULL;
                return true;
            }
            pointer = head; 
            while (pointer -> next != NULL) {
                pointer = pointer -> next; //points at last element of list
            }   
            pointer -> next = newElem;
            newElem -> prev = pointer;
            head -> prev = NULL;
            numOfElem++;
            std::cout << "Adding " << elem << " to the end of the list!" << 
                std::endl;
            return true;
        }
        bool lastElem() {
            struct node<T> *pointer; //pointer 
            if (head == NULL) { //if list is empty
                std::cout << "List is empty! Cannot determine last element"
                    << std::endl;
                return false;
            }
            pointer = head;
            while (pointer -> next != NULL) { 
                pointer = pointer -> next; //pointer at last element of list
            }
            std::cout << "Last element: " << pointer -> info << std::endl;
            return true;
        }
        bool firstElem() {
            struct node<T> *pointer; //pointer
            if (head == NULL) { //if list is empty
                std::cout << "List is empty! Cannot determine first element"
                    << std::endl;
                return false; 
            }
            pointer = head;
            std::cout << "First element: " << pointer -> info << std::endl;
            return true;
        }
        bool popFirst() {
            struct node<T> *pointer; //pointer
            if (head == NULL) { //if list is empty
                std::cout << "List is empty! Cannot Pop First element" << 
                    std::endl;
                return false;
            }    
            pointer = head;
            std::cout << "Popping first elem: "<< pointer -> info << std::endl;
            //if number of elements<=one, the head = head -> next does not work
            if (numOfElem <= 1) { //hence corner case
                head = NULL;
                numOfElem--;
                delete pointer;
                return true;
            }
            head = head -> next;
            delete pointer; //deleting from list
            numOfElem--;
            head -> prev = NULL;
            return true;
        }
        bool popLast() {
            struct node<T> *pointer; //pointer
            if (head == NULL) { //if list is empty
                std::cout << "List is empty! Cannot pop last element" <<
                    std::endl;
                return false;
            }
            pointer = head;
            while (pointer -> next != NULL) {
                pointer = pointer -> next; //pointer at end of list
            }
            std::cout << "Popping last elem: "<< pointer -> info << std::endl;
            //if number of elements<=one, the (pointer->prev) points to NULL
            if (numOfElem <= 1) { //hence corner case
                head = NULL;
                numOfElem--;
                delete pointer;
                return true;
            }
            //last element of list has to points to NULL
            (pointer -> prev) -> next = NULL;
            delete pointer; //deleting from list
            numOfElem--;
            return true;
        }
        void toPrint() { //printing
            struct node<T> *pointer;
            if (head == NULL) { //if list is empty
                std::cout << "The list you want to print is empty!" 
                    << std::endl;
            }
            else { //else print all element with a space in between
                pointer = head;
                while (pointer != NULL) { //till end of list
                    std::cout << pointer -> info << " ";
                    pointer = pointer -> next;
                }
                std::cout << std::endl; //new line after list is printed
            }

        }
        void numOfElements() { //for num of elements
            std::cout << "Number of elements in list: " << numOfElem << 
                std::endl;
        }
        ~linkedList () { //destructor
            struct node<T> *nextEl;
            while (head != NULL) {
                nextEl = head -> next;
                delete head;
                head = nextEl;
            }
            std::cout << "Destructor is succesfully called!" << std::endl;
        }
};