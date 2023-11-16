// // C++ program for the above approach 
// #include <bits/stdc++.h>
// using namespace std;

// // Function to assign rank to 
// // array elements 
// void changeArr(int input[], int N, int k) 
// { 
	
// 	// Copy input array into newArray 
// 	int newArray[N];
// 	copy(input, input + N, newArray);

// 	// Sort newArray[] in ascending order 
// 	sort(newArray, newArray + N); 
// 	int i; 
	
// 	// Map to store the rank of 
// 	// the array element 
// 	map<int, int> ranks;

// 	int rank = 1; 

// 	for(int index = 0; index < N; index++)
// 	{ 

// 		int element = newArray[index]; 

// 		// Update rank of element 
// 		if (ranks[element] == 0) 
// 		{ 
// 			ranks[element] = rank; 
// 			rank++; 
// 		} 
// 	} 

// 	// Assign ranks to elements 
// 	for(int index = 0; index < N; index++) 
// 	{ 
// 		int element = input[index]; 
// 		input[index] = ranks[input[index]]; 
// 	} 
// } 

// // Driver code 
// int main()
// {
	
// 	// Given array arr[] 
// 	int arr[] = { 100, 2, 70, 2 }; 

// 	int N = sizeof(arr) / sizeof(arr[0]);
	
// 	// Function call 
// 	changeArr(arr, N); 

// 	// Print the array elements 
// 	cout << "[";
// 	for(int i = 0; i < N - 1; i++)
// 	{
// 		cout << arr[i] << ", ";
// 	}
// 	cout << arr[N - 1] << "]";
// 	return 0;
// }

#include <iostream>
#include <algorithm>

const int MAX_SIZE = 100; // Set the maximum size of the array

int findRank(int arr[], int size, int target) {
    int sortedArr[MAX_SIZE];
    std::copy(arr, arr + size, sortedArr); // Create a copy of the original array
    std::sort(sortedArr, sortedArr + size); // Sort the array

    int* it = std::find(sortedArr, sortedArr + size, target);

    if (it != sortedArr + size) {
        int rank = 1;
        for (int* i = sortedArr; i != it; ++i) {
            if (*i == *it) {
                // Elements are the same, share the same rank
                rank++;
            }
        }
        return rank;
    } else {
        // Element not found in the array
        return -1;
    }
}

int main() {
    int myArray[] = {4, 2, 8, 1, 6, 3, 7, 5, 6};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]); // Calculate the size of the array
    int elementToFind = 6;

    int elementRank = findRank(myArray, arraySize, elementToFind);

    if (elementRank != -1) {
        std::cout << "The rank of " << elementToFind << " in the array is: " << elementRank << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
