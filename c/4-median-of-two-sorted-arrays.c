double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double ans = 0;
    int i = 0, j = 0, k = 0;
    int totalLen = nums1Size + nums2Size;
    int * totalNums = malloc(totalLen * sizeof(int));

    while (k < totalLen) {
        if (i >= nums1Size) {
            totalNums[k] = nums2[j];
            j++;
        } else if (j >= nums2Size) {
            totalNums[k] = nums1[i];
            i++;
        } else if(nums1[i] < nums2[j]) {
            totalNums[k] = nums1[i];
            i++;
        } else {
            totalNums[k] = nums2[j];
            j++;
        }
        k++;
    }

    if (totalLen == 1) ans = totalNums[0];
    else if(totalLen%2 == 0) {
        ans = totalNums[totalLen/2 - 1] + totalNums[totalLen/2];
        ans = (double)ans / 2;
    } else {
        ans = totalNums[totalLen/2];
    }
    return ans;
}
