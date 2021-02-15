// record every elements frequency using map
// iterate over map and check if frequency is > n/3
// one catch is there can be at most 2 numbers which can satisfy the condition but is of no use in this approach

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int,int> Map;
    vector<int> result;
    for(auto a : nums) Map[a]++;
    for(auto a : Map) if(a.second > nums.size()/3) result.push_back(a.first);
    return result;
  }
};
