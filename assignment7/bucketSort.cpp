#include <iostream>
#include <vector>

void bucketSort (std::vector<float>*arr);
void print (std::vector<float>arr);
void insertionSort (std::vector<float>bucket);

int main() {
    std::vector<float>arr = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1}; //my array

    std::cout << "Unsorted array: ";
    print (arr); //prints unsorted array

    bucketSort (&arr); //bucketSort implementation

    std::cout << "Sorted array: ";
    print (arr);
}

//just prints
void print (std::vector<float>arr) {
    std::vector<float>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
}

//bucketSort implementation
void bucketSort (std::vector<float> *arr) {
    std::vector<float>bucket[(*arr).size()]; //bucket for ranges
    //as we use vector, no need to initialize all elem individually to 0
    std::vector<float>::iterator itr1; //an iterator
    for (itr1 = (*arr).begin(); itr1 != (*arr).end(); itr1++) { //going to list
        int temp = (*itr1) * (*arr).size(); //which range
        bucket[temp].push_back(*itr1); //places elements in range
    }
    //sorting elements of each range
    for (int i = 0; i < (*arr).size(); i++) {
        insertionSort(bucket[i]); //using insertionSort
    }
    int position = 0; //position of element
    for (int i = 0; i < (*arr).size(); i++) { //going through buckets
        for (int j = 0; j < bucket[i].size(); j++) {
            //going through each element of bucket[i]
            (*arr)[position] = (bucket[i])[j]; 
            //jth elem of bucket[i] in arr[position]
            position++; //next position
        }
    }
}

//insertionSort implementation for bucketSort
void insertionSort (std::vector<float>bucket) {
    float key;
    for (int i = 1; i < bucket.size(); i++) {
        key = bucket[i];
        int ref = i - 1;
        while (ref >= 0 && bucket[ref] > key) {
            bucket[ref+1] = bucket[ref];
            ref--;
        }
        bucket[ref+1] = key;
    }
}
