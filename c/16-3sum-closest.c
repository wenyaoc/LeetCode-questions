int comp (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
} 


int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), comp);
    int a = 0, b = 0, c = 0;
    int ans = nums[a] + nums[a+1] + nums[a+2];
    while (a < numsSize - 2) {
        int total = nums[a] + nums[a+1] + nums[a+2];
        if (total >= target) {
            if (abs(ans - target) > abs(total - target)) return total;
            else return ans;
        }
        b = a + 1;
        c = numsSize - 1;
        while (b < c) {
            int total = nums[a] + nums[b] + nums[c];
            if (abs(ans - target) > abs(total - target)) ans = total;
            if (total == target) return target;
            else if (total > target) c--;
            else b++; 
        }
        a++;
    }
    return ans;
}
