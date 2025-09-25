class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)    //We need atleast 3 bars to be able to trap water
            return 0;
        
        vector<int> left(n),right(n);
        left[0] = 0;
        int leftMax = height[0];
        for(int i=1;i<n;++i) {  //Store the leftMax for each bar
            left[i] = leftMax;
            leftMax = max(leftMax,height[i]);
        }
        
        right[n-1] = 0;
        int rightMax = height[n-1];
        for(int i=n-2;i>=0;--i) {   //Store rightMax at each bar
            right[i] = rightMax;
            rightMax = max(rightMax,height[i]);
        }
        
        //Now parse the array to find the water
        int trappedWater = 0;
        for(int i=1;i<n-1;++i) {    //Find trappedWater
            if(height[i]<left[i] and height[i]<right[i])
                trappedWater += min(left[i],right[i]) - height[i];
        }
        return trappedWater;
    }
};