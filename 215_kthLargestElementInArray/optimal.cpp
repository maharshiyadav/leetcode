// Using property of min heap which always provides the least number amongst the points added
// We use a min heap to keep track of the kth largest element.
// Iterate over nums and push into heap and if the size is greater than k then pop
// time complexity is O(nlogk)

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min heap (priority queue)
    for(int i=0; i<nums.size(); i++){
      pq.push(nums[i]);
      if(pq.size() > k) pq.pop(); // ensures size of heap is k
    }
    return pq.top();
  }
};
