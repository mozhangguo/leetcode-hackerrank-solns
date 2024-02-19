#include <algorithm> // For std::sort
#include <vector>

int findSmallestMissingPositive(std::vector<int>& A) {
    // Step 1: Sort the array
    std::sort(A.begin(), A.end());
    
    // Step 2: Initialize the smallest positive integer not yet seen
    int smallestMissingPositive = 1;
    
    // Step 3: Iterate through the sorted array
    for (int num : A) {
        // If the current element is the smallest missing positive, update it
        if (num == smallestMissingPositive) {
            smallestMissingPositive++;
        }
    }
    
    // Return the smallest missing positive integer
    return smallestMissingPositive;
}
