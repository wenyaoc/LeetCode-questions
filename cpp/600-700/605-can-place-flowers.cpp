class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = 0;

        for (int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] != 1) && (i+1==flowerbed.size() || flowerbed[i+1] != 1)) {
                num++;
                i++;
            }
            if (num >= n) break;
        }

        return num >= n;
    }
};
