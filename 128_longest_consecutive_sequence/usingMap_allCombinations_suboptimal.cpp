// While adding elements of vector in map, we then and there only update values of the keys.
// We cover all possibilities like while inserting a new number 'a' we check if 'a-1' and 'a+1' already exist and 
// thus proceed ahead with updating values of the upStreak and downStreak
// We have covered 2 conditions in one by using bool x and y. Though this is suboptimal, lesser the ifs better the performance

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, int> Map;
      int result = 0;
      for(int a : nums){
        if(!Map.count(a)){
          // n-1 and n+1 are not present
          bool x = Map.count(a-1);
          bool y = Map.count(a+1);
          bool z = Map.count(a);

          if(x ^ y){
            Map[a] = Map[a + (y?1:-1)] + 1;
            Map[a + (y?-1:1)*(1 - Map[a])] = Map[a];
            result = max(result, Map[a]);
          }
          else if(!x && !y){
            Map[a] = 1;
            result = max(result, Map[a]);
          }

          else{
            int newVal = Map[a-1] + Map[a+1] + 1;
            Map[a - Map[a-1]] = newVal;
            Map[a + Map[a+1]] = newVal;
            Map[a] = newVal;
            result = max(result, Map[a]);
          }
        }
      }
      return result;
    }
};
