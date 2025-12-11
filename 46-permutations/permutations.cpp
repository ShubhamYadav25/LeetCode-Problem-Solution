class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;  // rooms (arrangement), basically if size =0 then room A
                       // selected, size = 1 room b selected
    vector<bool> used; // available items
    void permutation(vector<int>& nums) {

        // if path size = 0, basically it mean it is Room A is processing
        // can say if path size == nums.size() => all rooms filled
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        // now task is too, try placing all the items in selected ROOM for now
        // say ROOM A can say try placing all items in the current room
        for (int i = 0; i < nums.size(); i++) {

            // what is it saying, it mean if item already used in some previous
            // room, skip
            if (used[i])
                continue;

            // if not used, place in current room
            used[i] = true;

            path.push_back((nums[i]));

            // now size of path is 1 so second room B selected and process this
            // same process for B
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

    /**
        CALL depth0: backtrack()           // path = [], used = [F,F,F]

        depth0 for i=0 -> try nums[0]=1
        used=[T,F,F]; path=[1]
        -> CALL depth1: backtrack()     // path=[1], used=[T,F,F]

        depth1 for i=0 -> skip used[0]=T
        depth1 for i=1 -> try nums[1]=2
            used=[T,T,F]; path=[1,2]
            -> CALL depth2: backtrack()   // path=[1,2], used=[T,T,F]

            depth2 for i=0 -> skip
            depth2 for i=1 -> skip
            depth2 for i=2 -> try nums[2]=3
            used=[T,T,T]; path=[1,2,3]
            -> CALL depth3: backtrack() // base: path.size()==3
            ans.push_back([1,2,3])     // print/save 123
            RETURN depth3 -> depth2

            // continue depth2 after recursive return
            depth2: path.pop_back() => path=[1,2]; used=[T,T,F]
            depth2 finishes for-loop (no more i)
            RETURN depth2 -> depth1

        // continue depth1 after return from depth2
        depth1: path.pop_back() => path=[1]; used=[T,F,F]
        depth1 for i=2 -> try nums[2]=3
            used=[T,F,T]; path=[1,3]
            -> CALL depth2 again: backtrack() // path=[1,3]

            depth2 for i=0 -> skip
            depth2 for i=1 -> try nums[1]=2
            used=[T,T,T]; path=[1,3,2]
            -> CALL depth3 -> base -> save [1,3,2]
            RETURN depth3 -> depth2

            depth2: pop => path=[1,3]; used=[T,F,T]
            depth2 finishes
            RETURN depth2 -> depth1

        depth1: pop => path=[1]; used=[T,F,F]
        depth1 finishes for-loop
        RETURN depth1 -> depth0

        // Now we are back in depth0 (Room A), exactly where we paused after calling
        backtrack depth0: path.pop_back() => path=[]; used=[F,F,F] depth0 for i=1 -> try
        nums[1]=2 used=[F,T,F]; path=[2]
        -> CALL depth1: backtrack()   // fill rooms after A=2
        ... (same pattern produces [2,1,3] then [2,3,1])
        RETURN depth1 -> depth0

        depth0: pop => path=[]; used=[F,F,F]
        depth0 for i=2 -> try nums[2]=3
        used=[F,F,T]; path=[3]
        -> CALL depth1 ...
        RETURN

        depth0 finishes for-loop
        RETURN (complete)
    */
};