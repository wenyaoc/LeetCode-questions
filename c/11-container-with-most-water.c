//执行用时: 24 ms
//内存消耗: 7.1 MB

int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize-1;
    int area = 0;
    while (i < j) {
        area = fmax(area, fmin(height[i], height[j]) * (j - i));
        if (height[i] < height[j]) i++;
        else j--;
    }
    return area;
}




/*
//执行用时: 1868 ms
//内存消耗: 6.8 MB

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

int maxArea(int* height, int heightSize){
    int i, j;
    int area = 0;
    for (i = 0; i < heightSize-1; i++) {
        for (j = heightSize-1; j > i; j--) {
            area = MAX(area, MIN(height[i], height[j]) * (j - i));
        }
    }
    return area;
}
*/
