#include <iostream>
#include <vector>
#include <algorithm>

// activity type
class Activity {
    private:
        int start;
        int finish;
    public:
        int getStart() {return start;}
        int getFinish() {return finish;}
        void setStart(int start) {this->start = start;}
        void setFinish(int finish) {this->finish = finish;}
        Activity(int start = 0, int finish = 0);
        void printActivity();
};

// constructor
Activity::Activity(int start, int finish) {
    this -> start = start;
    this -> finish = finish;
}

// print for Activity
void Activity::printActivity() {
    std::cout << "{" << start << " ," << finish << "}";
}

// list of activities
class ListOfActivity {
    public:
        ListOfActivity();
        std::vector<Activity> activityList;
        void addActivity(Activity a);
        void printList();
        void sort();
};

// constructor
ListOfActivity::ListOfActivity() {
    // Activity a0; 
}

// adds activity to vector of activities
void ListOfActivity::addActivity(Activity a) {
    activityList.push_back(a);
}

// prints list
void ListOfActivity::printList() {
    std::cout << "{ ";
    for (int i = 0; i < activityList.size(); i++) {
        activityList[i].printActivity(); 
        if (i != activityList.size()-1) {
            std::cout << ", ";
        }
        else {
            std::cout << " }";
        }
    }
    std::cout << std::endl;
}

// I use insertion sort here because it is fast and easy to write
void ListOfActivity::sort() {
    for (int j = 1; j < activityList.size(); j++) {
        int key[2];
        key[0] = activityList[j].getStart();
        key[1] = activityList[j].getFinish();
        int i = j - 1;
        while (i >= 0 && key[1] > activityList[i].getFinish()) {
            activityList[i+1].setStart(activityList[i].getStart());
            activityList[i+1].setFinish(activityList[i].getFinish());
            i = i - 1;
        }
        activityList[i+1].setStart(key[0]);
        activityList[i+1].setFinish(key[1]);
    }
}

int main() {
    ListOfActivity activityList;
    Activity a1(1,4), a2(0, 6), a3(3, 5), a4(3, 8), a5(12, 14), a6(2, 13),
        a7(8, 11), a8(8, 12), a9(6, 10), a10(5, 7), a11(5, 9);

    // a1.printActivity();
    // std::cout << std::endl;

    activityList.addActivity(a1);
    activityList.addActivity(a2);
    activityList.addActivity(a3);
    activityList.addActivity(a4);
    activityList.addActivity(a5);
    activityList.addActivity(a6);
    activityList.addActivity(a7);
    activityList.addActivity(a8);
    activityList.addActivity(a9);
    activityList.addActivity(a10);
    activityList.addActivity(a11);

    std::cout << "Unsorted List: ";
    activityList.printList();

    activityList.sort();

    std::cout << "Descending Order List: ";
    activityList.printList();

}