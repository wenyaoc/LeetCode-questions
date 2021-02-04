/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int *sort(int *nums, int numsSize) {
    int i, j ,temp;
    for (i = 0; i < numsSize-1; i++) {
        for (j = 0; j < numsSize-1-i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    returnColumnSizes = NULL;
    if (numsSize < 3) {
        return NULL;
    }
    nums = sort(nums, numsSize);
    int ** ans = NULL;
    int a = 0, b = 1, c = 3;
    while (a < numsSize - 2) {
        printf("%d\n", a);
        b = a + 1;
        if (nums[a] + nums[a+1] + nums[a+2] > 0) break;
        while (b < numsSize - 1) {
            if (nums[a] + nums[b]> 0) break;
            c = b + 1;
            while (c < numsSize) {
                int total = nums[a] + nums[b] + nums[c];
                if (total == 0) {
                    returnColumnSizes = realloc(returnColumnSizes, ((*returnSize)+1) * sizeof(int*));
                    returnColumnSizes[*returnSize] = malloc(sizeof(int));
                    ans = realloc(ans, (*returnSize+1) * sizeof(int*));
                    ans[*returnSize] = malloc(3 * sizeof(int));
                    ans[*returnSize][0] = nums[a];
                    ans[*returnSize][1] = nums[b];
                    ans[*returnSize][2] = nums[c];
                    returnColumnSizes[*returnSize][0] = 0;
                    *returnSize++;
                    break;
                } else if (total > 0) break;
                while (c+1 < numsSize && nums[c] == nums[c+1]) c++;
                c++;
            }
            while (b+1 < numsSize-1 && nums[b] == nums[b+1]) b++;
            b++;
        }
        while (a+1 < numsSize-2 && nums[a] == nums[a+1]) a++;
        a++;
    }
    printf("hello");
    return ans;
}
