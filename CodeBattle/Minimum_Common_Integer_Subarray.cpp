/*
https://leetcode.com/discuss/interview-question/4157292/TikTok-OA-or-Hard-question
ByteDance is developing a new algorithm to implement in an
upcoming software. The algorithm runs on a sequence of integers. Given an array data of size n, where the value of the ith integer is represented by the array data[i], the algorithm will run on data as:

. For every integer k, where 1 <= k < n. The algorithm will return the minimum common integer that occurs in all of the subarrays of the array data having length k.
• If there is no common integer occurring in any subarray of length k, then the algorithm will return -1.

given an integer n, and an array data, find the array that the algorithm will return after running on data

Example
Given, n = 5, data = [4, 3, 3, 4, 2]

subarrays | minimun comon integer
[4][3][3][4][2] | -1
[4,3][3,3][3,4][4,2] | -1
[4,3,3],[3,3,4],[3,4,2] | 3
[4,3,3,4][3,3,4,2] | 3
[4,3,3,4,2] | 2

Hence, the algorithm will return the array [-1, -1, 3, 3, 2] after
running on data

Function Description
Complete the function minimumCommoninteger in the editor
below
minimumCommoninteger has the following parameter;
int data[n]: an array of integers.

constraints
2 <= n <= 2 * 10^5
1 <= data[i] <= n

More examples
Example2
n = 3
data = [3,2,3,1]
sample output:
-1,
3,
2,
1

Exmaple3
n = 5
data = [2,4,2,3,5]
-1,-1,2,2,2
   */



/*

Follow the steps below to solve the problem:

Initialize an array, say indices[], to store the index where a particular number occurs corresponding to that index number.

Now, for every number which is present in the given array, find the minimum length so that it is present in every subarray of that length.

Minimum length can be found by finding the maximum interval at which that particular number repeats itself in the given array.
Similarly, find the same for other numbers of the array.

Initialize an answer[] array of size N+1 with -1 where answer[i] represents the answer for subarrays of length K.

Now, the indices[] array gives the number which was present in every subarray of length, say K,
then update answer[K] with the same number if answer[K] was -1.

After traversing, update answer[] array such that if a number is present in all the subarrays of length K,
then that particular number will also be present in all the subarrays of length greater than K.

After updating answer[] array, print all the elements present in that array as the answer for every subarray of length K.

*/

#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;


// Function to print the common
// elements for all subarray lengths
void printAnswer(int answer[], int N)
{
    for (int i = 1; i <= N; i++) {
        cout << answer[i] << " ";
    }
}

// Function to find and store the
// minimum element present in all
// subarrays of all lengths from 1 to n
void updateAnswerArray(int answer[], int N)
{
    int i = 0;

    // Skip lengths for which
    // answer[i] is -1
    while (answer[i] == -1)
        i++;

    // Initialize minimum as the first
    // element where answer[i] is not -1
    int minimum = answer[i];

    // Updating the answer array
    while (i <= N) {

        // If answer[i] is -1, then minimum
        // can be substituted in that place
        if (answer[i] == -1)
            answer[i] = minimum;

        // Find minimum answer
        else
            answer[i] = min(minimum, answer[i]);
        minimum = min(minimum, answer[i]);
        i++;
    }
}

// Function to find the minimum number
// corresponding to every subarray of
// length K, for every K from 1 to N
void lengthOfSubarray(vector<int> indices[],
                      set<int> st, int N)
{
    // Stores the minimum common
    // elements for all subarray lengths
    int answer[N + 1];

    // Initialize with -1.
    memset(answer, -1, sizeof(answer));

    // Find for every element, the minimum length
    // such that the number is present in every
    // subsequence of that particular length or more
    for (auto itr : st) {

        // To store first occurrence and
        // gaps between occurrences
        int start = -1;
        int gap = -1;

        // To cover the distance between last
        // occurrence and the end of the array
        indices[itr].push_back(N);

        // To find the distance
        // between any two occurrences
        for (int i = 0; i < indices[itr].size(); i++) {
            gap = max(gap, indices[itr][i] - start);
            start = indices[itr][i];
        }
        if (answer[gap] == -1)
            answer[gap] = itr;
    }

    // Update and store the answer
    updateAnswerArray(answer, N);

    // Print the required answer
    printAnswer(answer, N);
}

// Function to find the smallest
// element common in all subarrays for
// every possible subarray lengths
void smallestPresentNumber(int arr[], int N)
{
    // Initializing indices array
    vector<int> indices[N + 1];

    // Store the numbers present
    // in the array
    set<int> elements;

    // Push the index in the indices[A[i]] and
    // also store the numbers in set to get
    // the numbers present in input array
    for (int i = 0; i < N; i++) {
        indices[arr[i]].push_back(i);
        elements.insert(arr[i]);
    }

    // Function call to calculate length of
    // subarray for which a number is present
    // in every subarray of that length
    lengthOfSubarray(indices, elements, N);
}

// Driver Code
int main()
{
    // Given array
    int arr[] = {4, 3, 3, 4, 2};

    // Size of array
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    smallestPresentNumber(arr, N);

    return (0);
}
