#include <stdio.h>
#include <stdlib.h>

int findLength(int *nums, int k)
{
    int left = 0;
    int curr = 0; // curr is the current sum of the window;
    int ans = 0;

    for(int right = 0; right < sizeof(nums)/sizeof(nums[0]); right++ )
    {
        curr += nums[right];
        while (curr >k)
        {
            curr -= nums[left];
            left++;
        }
        ans = max(ans, right -left +1);
    }
    return ans;
}

int main(void)
{
    nums = []
    for (int right = 0; right < )
}