class Solution {
public:

    vector<int> v = {-1, -1};

    void BSL(vector<int>& nums, int target){
        int i=0,  j = nums.size()-1;

        while(i <= j){
            int mid = i + (j -i) /2 ;

            if(nums[mid] == target){
                j = mid-1;
                v[0] = mid;
            }else if(nums[mid] < target){
                i = mid+1;
            }else {
                j = mid-1;
            }
        }

    }

    void BSR(vector<int>& nums, int target){
        int i=0,  j = nums.size()-1;

        while(i <= j){
            int mid = i + (j -i) /2 ;

            if(nums[mid] == target){
                v[1] = mid;
                i = mid+1;
            }else if(nums[mid] < target){
                i = mid+1;
            }else {
                j = mid-1;
            }
        }

    }


    vector<int> searchRange(vector<int>& nums, int target) {
        BSL(nums, target);
        BSR(nums, target);
        return v;
    }
};