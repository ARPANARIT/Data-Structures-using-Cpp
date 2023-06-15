#include <iostream>
// arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n].
class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n)
    {

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            { // even places should have number less than their right adjacent arr[0] < arr[1]
                if (arr[i] > arr[i + 1])
                {//if not swap
                    swap(arr[i], arr[i + 1]);
                }
            }
            else
            { // odd places should be greater than their right adjacent  arr[1]  > arr[2]
                if (arr[i] < arr[i + 1])
                {// if not swap
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
};