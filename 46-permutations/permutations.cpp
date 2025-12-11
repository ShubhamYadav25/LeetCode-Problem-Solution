class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;      // rooms (arrangement), basically if size =0 then room A selected, size = 1 room b selected
    vector<bool> used;     // available items
    void permutation(vector<int>& nums){
        
        // if path size = 0, basically it mean it is Room A is processing
        // can say if path size == nums.size() => all rooms filled
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        // now task is too, try placing all the items in selected ROOM for now say ROOM A
        // can say try placing all items in the current room
        for(int i =0; i < nums.size(); i++){
            
            // what is it saying, it mean if item already used in some previous room, skip
            if(used[i]) continue;

            // if not used, place in current room
            used[i] = true;

            path.push_back((nums[i]));

            // now size of path is 1 so second room B selected and process this same process for B
            permutation(nums);

            // undo before trying next item in this room
            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        permutation(nums);
        return ans;
    }
};