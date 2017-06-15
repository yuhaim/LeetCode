#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target)
{
    int *pNumsArray = (int *)calloc(2, sizeof(int));

    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {   
                pNumsArray[0] = i;
                pNumsArray[1] = j;
                return pNumsArray;
            }
        }
    }
	return NULL;
}

int main(int argc, char *argv[])
{
	const int numsSize = 3;
	int nums[3] = {3, 2, 4};
	int target = 6;
	int *pNumsArray = twoSum(nums, numsSize, target);
	printf("%d,%d\n", pNumsArray[0],pNumsArray[1]);	
	free(pNumsArray);
}
