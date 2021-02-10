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
