public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        
        var pq = new PriorityQueue<int, int>(
            Comparer<int>.Create((x, y) => y.CompareTo(x))
        );

        foreach (int num in nums)
        {
            pq.Enqueue(num,num);
        }

        while(k > 1){
            pq.Dequeue();
            k--;
        }

        return pq.Peek();
    }
}