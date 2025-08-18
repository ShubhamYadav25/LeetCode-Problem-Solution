class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int lightest = 0;                
        int heaviest = people.size() - 1; 
        int boats = 0;                  

        while (lightest <= heaviest) {
            // pairing lightest + heaviest
            if (people[lightest] + people[heaviest] <= limit) {
                lightest++;
                heaviest--;
            } else {
                heaviest--;
            }
            boats++;
        }

        return boats;
    }
};