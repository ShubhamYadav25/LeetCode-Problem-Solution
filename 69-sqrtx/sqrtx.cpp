class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0 ) {
            return 0;
        }
        
        if(x ==1){
            return 1;
        }
        
        long  left = 0;
        
        long  right = x;
        
        while(left < right){
            
            long  mid = left + (right -left) /2;
            
            if( (long ) mid * mid > (long) x) {
                right = mid;
            }else {
                left = mid+1;
            }
        }
        return left-1;
    }
};