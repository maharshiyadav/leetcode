// consider 5 6 7 8 9 1 2 3 as our array
// we have few cases to look after
// mid can be in left sorted part or right sorted part
// we use the fact that all elements belonging to left part are greater than right part
// so if mid lies in left part, we check if target is between left and mid then we for sure know that high should be mid - 1 (herein <= is for nums[left] <= target) as the high is going to be updated
// thus we know we have left - target - mid (sorted) so right = mid - 1
// if mid is in right part, we again check for target if it is greater than mid and less than right then we just update left = mid + 1

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int lo=0, hi=nums.size()-1, mid;

    while(lo <= hi){
      mid = (lo+hi)/2;

      if(nums[mid]==target) return true;
      
      if((nums[lo]==nums[mid]) && nums[hi]==nums[mid]) {lo++; hi--;} // herein if we have streak of same values we just update our pointers

      else if(nums[lo] <= nums[mid]){
        if(nums[lo] <= target && target < nums[mid]) hi = mid-1;
        else lo = mid + 1;
      }
      else{
        if(nums[mid] < target && target <= nums[hi]) lo = mid + 1;
        else hi = mid - 1;
      }
      
        
    }
    return false;
  }
};
