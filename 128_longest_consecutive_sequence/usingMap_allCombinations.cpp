// While adding vector elements to Map, we then and there itself update values of relevant keys in Map. 
// e.g. 1(3) 2(3) 3(3) 7(3) 8(3) 9(3) is the current Map and we have to add 4 
// (here the representation is key(value) as 1,2,3 are a sequence their values will be 3 ideally ) 
// but we do not need values of keys which are NOT at endpoints of a sequence. So while adding 4 we will update Map such that 
// 1(4) 2(3) 3(3) 4(4) 7(3) 8(3) 9(3)
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
