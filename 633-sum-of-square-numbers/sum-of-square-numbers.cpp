class Solution {
public:
    int floorSqrt(int n) {
        return static_cast<int>(sqrt(n));
    }

    bool judgeSquareSum(int c) {
        int i =0, j = floorSqrt(c);

        while(i <= j){
            
            long long mul = (1LL * i * i) + (1LL * j * j);

            if( mul == c){
                return true;
            }else if (mul > c){
                j--;
            }else {
                i++;
            }
        }

        return false;
    }
};