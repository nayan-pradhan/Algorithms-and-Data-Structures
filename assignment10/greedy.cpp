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
        Activity greedySolution();
        ListOfActivity returnListSolution();
        int size(){return activityList.size();}
        Activity elemAt(int i) {return activityList[i];}
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

// I was just practicing here, sorting is NOT implemented anywhere else
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

// returns the latest start time
Activity ListOfActivity::greedySolution() {
    Activity latestStartTime;
    latestStartTime.setStart(0);
    latestStartTime.setFinish(0);
    for (int i = 0; i < activityList.size(); i++) {    
        if (activityList[i].getStart() > latestStartTime.getStart()) {
            latestStartTime.setStart(activityList[i].getStart());
            latestStartTime.setFinish(activityList[i].getFinish());
        }
    }
    return latestStartTime;
}

// returns final solution
ListOfActivity ListOfActivity::returnListSolution() {
    ListOfActivity Solution; // creating a list of activity called solution
    while (!activityList.empty()) { // while activity list is not empty
        Activity latestStartTime; // creating a temp activity
        // the start and finish time of latestStartTime is initialzied to 0 
        latestStartTime.setStart(0); 
        latestStartTime.setFinish(0);
        int pointer = 0; // just an index
        // finding the latest start time
        for (int i = 0; i < activityList.size(); i++) {
            if (activityList[i].getStart() > latestStartTime.getStart()) {
                latestStartTime.setStart(activityList[i].getStart());
                latestStartTime.setFinish(activityList[i].getFinish());
                pointer = i; // pointer used later
            }
        }
        
        // if the latest is the temp activity, stop
        if (latestStartTime.getStart() == 0 && 
                latestStartTime.getFinish() == 0) {
            break;
        }

        /* 
            bool to check if the latestStartTime activity overlaps with other 
            activities in the final solution 
        */
        bool overlapCheck = false;
        for (int i = 0; i < Solution.size(); i++) { // goes through activities in sol
            if (latestStartTime.getFinish() > Solution.elemAt(i).getStart()) {
                overlapCheck = true; // if overlap occurs
            }
        }
         
        // if overlap does not occur, add activity to solution list
        if (overlapCheck == false) {
            Solution.addActivity(latestStartTime);
        }

        // now erase the latestStartTime activity from the list of activities
        activityList.erase(activityList.begin()+pointer);
    }

    /*
        The above returns the solution in reversed order. 
        To print in proper order, I just copied the activities from back
        to front in a new ListOfActivity. 
    */
    ListOfActivity InCorrectOrderSolution;
    for (int i = Solution.size()-1; i >= 0; i--) {
        InCorrectOrderSolution.addActivity(Solution.elemAt(i));
    }
    return InCorrectOrderSolution;
}

// main
int main() {
    ListOfActivity activityList; // making a list of activity
    // activities (according to Professor's slide but not in order)
    Activity a1(1,4), a2(0, 6), a3(3, 5), a4(3, 8), a5(12, 14), a6(2, 13),
        a7(8, 11), a8(8, 12), a9(6, 10), a10(5, 7), a11(5, 9);

    // a1.printActivity();
    // std::cout << std::endl;

    // adding the activities
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

    // printing the unsorted list
    std::cout << "Unsorted List: ";
    activityList.printList();
    std::cout << std::endl;

    // implemented sort to practice (not used in program)
    // activityList.sort();

    // std::cout << "Descending Order List: ";
    // activityList.printList();

    // printing activity with latest starting time
    std::cout << "Activity With Latest Starting Time: ";
    activityList.greedySolution().printActivity();
    std::cout << std::endl;

    // printing activity list after greedy solution
    std::cout << std::endl;
    std::cout << "Greedy Solution:";
    activityList.returnListSolution().printList();
    std::cout << std::endl;
}