//
//  main.cpp
//  inversioncounting
//
//  Created by Devansh Dhar Dwivedi on 10/19/25.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;

// A Function to merge the two halves and then count number of inversions
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (leftArr.size() - i);  // all remaining in leftArr are the greater ones
        }
    }

    // Copy remaining elements
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];

    return inversions;
}

// Recursive function to count number of inversions
long long countInversions(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}
//A function that computes number of inversion using a naive brute force algorithm.
long long countInversionsBruteForce(const vector<int>& arr, int arrsize) {
    long long inversions = 0;
    int n = arrsize;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                inversions++;
        }
    }
    return inversions;
}
//random integer array generator, for our experiments
vector<int> randomintarray(int randsize, int randmax) {
    int n;
    n=randsize;
    int maxVal= randmax;
    int minVal=1;
        // Seed the random number generator using current time
        std::srand(static_cast<unsigned int>(std::time(0)));

        std::vector<int> arr(n);

        // Generate random integers in [minVal, maxVal]
        for (int i = 0; i < n; ++i) {
            arr[i] = minVal + std::rand() % (maxVal - minVal + 1);
        }
        return arr;
    }


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long result = countInversions(arr, 0, n - 1);
    cout << "Number of inversions: " << result << endl;
    vector<int> randarr=randomintarray(10, 1000);
    for(int i=0;i<10;i++)
    {cout<< randarr[i] << endl;}
    return 0;
    
    
}



// insert code here...
    
    

