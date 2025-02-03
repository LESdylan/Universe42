#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//the return array must be allocated
int *sortedSquares(int *nums, int numSize, int *returnSize)
{
    int *result = (int *)malloc(numSize * sizeof(int));
    if (result == NULL)
    {
        perror("Memory allocation failed");
        return NULL;
    }
    int left = 0;
    int right = numSize - 1;
    int pos = numSize -1;
    while(left <= right)
    {
        int power_left = pow(nums[left], 2);
        int power_right = pow(nums[right], 2);
        if(power_left > power_right)
        {
            result[pos] = power_left;
            left++;
        }
        else
        {
            result[pos]= power_right;
            right--;
        }            
        pos--;
    }
    *returnSize = numSize;
    return result;
}

int main(void)
{
    int nums[5] = {-4,-1,0,3,10};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = sortedSquares(nums, 5, &returnSize);
    if(result != NULL)
    {
        printf("Sorted Squares: ");
            for(int i = 0; i < returnSize; i++)
            {
                printf("%d, ", result[i]);
            }
            printf("\n");
            
            free(result);
        }
}