double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double ans = 0;
    int i = 0, j = 0, k = 0;
    int totalLen = nums1Size + nums2Size;
    int * midNums = malloc(2 * sizeof(int));

    while (k < totalLen/2+1) {
        int nextNum;
        if (i >= nums1Size) {
            nextNum = nums2[j];
            j++;
        } else if (j >= nums2Size) {
            nextNum = nums1[i];
            i++;
        } else if(nums1[i] < nums2[j]) {
            nextNum = nums1[i];
            i++;
        } else {
            nextNum = nums2[j];
            j++;
        }
        if (totalLen == 1) midNums[0] = nextNum;
        else if(k == totalLen/2 - 1) {
            midNums[0] = nextNum;
        } else if(k == totalLen/2) {
            midNums[1] = nextNum;
        }
        k++;
    }
    if (totalLen == 1) ans = midNums[0];
    else if(totalLen%2 == 0) {
        ans = midNums[0] + midNums[1];
        ans = (double)ans / 2;
    } else {
        ans = midNums[1];
    }
    return ans;
}
