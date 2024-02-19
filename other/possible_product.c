/*
 * Given an array of N positive integers. Remove one elements from array and compute the product of all the remaining array elements. 
 * If there is only one elements remaining in the array, the product is equal to that element. We want to return the number of different products that
 * can be obtained by removing exactly one element from A. 
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *A, const void* B) {
	return (*(int*)A - *(int*)B); 
}


void uniqueProductCnt(int* A, int N) {
		qsort(A, sizeof(int), compare);
	

		int uniqueCnt = 0;
		for (int i = 1; i < N; i++) {
				if (A[i] != A[i-1]) uniqueCnt++;
		}

		return uniqueCnt;
}

int main() {
		
		int A[] = {1, 2, 3, 4};

		int N = sizeof(A) / sizeof(int);
		uniqueProductCnt(A, N);
		return 0;
}
