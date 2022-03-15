#include <iostream>

int binary_search(int arr[], int start_index, int end_index, int x)
{
    if (end_index >= start_index) {
        int mid = start_index + (end_index - start_index) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binary_search(arr, start_index, mid - 1, x);
 
        return binary_search(arr, mid + 1, end_index, x);
    }
 
    return -1;
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int key = 6;
	int size = sizeof(arr) / sizeof(arr[0]);

	int result = binary_search(arr, 0, size-1, key);
	std::cout << result << std::endl;
}