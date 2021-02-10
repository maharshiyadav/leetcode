// We simplify the solution by sorting the nums vector this sorting makes O(nlogn)
// Thus we simply have to look at previous number and update streak accordingly !

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size()==0) return 0;
      // Using SORTING
      sort(nums.begin(), nums.end());
      
      int curr=1, result=1;
      
      for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]) continue;
        
        if(nums[i] == nums[i-1] + 1){
          curr++;
        }
        else{
          result = max(result, curr);
          curr = 1;
        }
        
      }
      return max(result, curr);
    }
};
