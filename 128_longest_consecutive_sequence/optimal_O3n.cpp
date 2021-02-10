// We insert all elements of nums in Set
// for all numbers whose num-1 is not present we fetch num+1 in Set and increment currentStreak by 1 then updating maxStreak
// Thus if 1 2 3 4 6 7 8 9 is present in Set then we already know that for 1 we have fetched until 4 so 
// while searching from 2, we already have 1 so 2 is already covered so we do not search from 2
// But this is O(3n) as first n comes from creating Set, for each num we check if n-1 is present 
// and the last n comes from the while loop

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> Map;
      if(!nums.size()) return 0;
      // insert in Map
      for(int a : nums) Map.insert(a);
      
      int result = 1, currentNum, currentStreak;
      
      for(int num : Map){
        if(!Map.count(num-1)){ // if n-1 is present in set then n will always be considered !!!
          currentNum = num;
          currentStreak = 1;
          while(Map.count(currentNum + 1)){
            currentStreak++;
            currentNum++;
          }
          result = max(result, currentStreak);
        }
      }
      return result;
    }
};
