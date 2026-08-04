public class Solution {
/**
Instead of asking "What's the best partition?", flip it:
"If I give you a ship capacity of C, can you ship everything in D days?"
Think about this carefully. If the answer is YES for capacity C, what about capacity C+1?
Also YES! (If it fits in a smaller truck, it fits in a bigger one.)
If the answer is NO for capacity C, what about C-1?
Also NO! (If it doesn't fit in a big truck, it won't fit in a smaller one.)

*/

    public int ShipWithinDays(int[] weights, int days) {
        int left = 0, right = 0;
        
        // Set up search space
        foreach (int w in weights) {
            left = Math.Max(left, w);   // At least the heaviest package
            right += w;                 // At most the sum of all
        }
        
        // Binary search for minimum valid capacity
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (CanShip(weights, days, mid)) {
                right = mid;      // mid works, try smaller
            } else {
                left = mid + 1;   // mid too small, need bigger
            }
        }
        
        return left;
    }
    
    private bool CanShip(int[] weights, int days, int capacity) {
        int requiredDays = 1;
        int currentLoad = 0;
        
        foreach (int w in weights) {
            if (currentLoad + w > capacity) {
                requiredDays++;
                currentLoad = w;
                if (requiredDays > days) return false;
            } else {
                currentLoad += w;
            }
        }
        
        return true;
    }
}