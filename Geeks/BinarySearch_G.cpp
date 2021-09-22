#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define TEST1

using namespace std;

class Solution {
public:
	// Function to find element in sorted array
	// arr : input array
	// N : size of array
	// K : element to be search
	int searchInSorted(int arr[], int N, int K) {
		int l = 0;
		int r = N;

		while (l <= r) {
			int m = l + (r - l) / 2;

			if (arr[m] == K) { return 1; }

			if (arr[m] < K) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		return -1;
	}
};

int main(void)
{
#ifdef TEST1
	int n = 5;
	int k = 6;
	int ar[5] = { 1, 2, 3, 4, 6 };
#else
	int n = 5;
	int k = 2;
	int ar[] = { 1, 3, 4, 5, 6 };
#endif

	Solution sol;
	int result = sol.searchInSorted(ar, n, k);

	cout << "Result : " << result << endl;

	return 0;
}