class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, int> Map;
      int result = 0;
      for(int a : nums){
        if(!Map.count(a)){
          // n-1 and n+1 are not present
          if(!Map.count(a-1) && !Map.count(a+1)){
            Map[a] = 1;
            result = max(result, 1);
          }
          else if(!Map.count(a-1) && Map.count(a+1)){
            Map[a] = Map[a+1] + 1;
            Map[a + Map[a] - 1] = Map[a];
            result = max(result, Map[a]);
          }
          else if(Map.count(a-1) && !Map.count(a+1)){
            Map[a] = Map[a-1] + 1;
            Map[a - Map[a] + 1] = Map[a];
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
