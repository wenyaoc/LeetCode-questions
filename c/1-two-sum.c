/*
#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(){
    int nums[3] = {3, 2, 4};
    int target = 6;
    int * returnSize = malloc(sizeof(int));
    int * ans = twoSum(nums, sizeof(nums) / sizeof(int), target, returnSize);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * ans = malloc(2 * sizeof(int));
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            int total = nums[i] + nums[j];
            if (total == target) {
                ans[0] = j;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            } 
        }
    }
    *returnSize = 0;
    return ans;
}