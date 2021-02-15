// we reduce the target by considering one candidate and then backtrack for solution
// when candidate is greater than target we do not have solution
// we first sort the candidates as we iterate from 0 to size-1 and decrement target 
// if target is 0, then we have our solution

class Solution {
public:
  vector<vector<int>> result;
  // set<vector<int>> answer; // Used when we also record duplicates 
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    // 1, 1, 2, 5, 6, 7, 10
    vector<int> temp; // stores one solution
    
    backTrack(candidates, target, temp, 0);
    // for(auto& a : answer) result.push_back(a); // for removing duplicate records ()
    return result;
  }
  
  void backTrack(vector<int>& candidates, int target, vector<int>&temp, int index){
    if(!target){
      // answer.insert(temp);
      result.push_back(temp);
      return;
    }
    // as we want all possible solutions we have to loop from the current index till the end
    // this ensures all outcomes are recorded
    for(int i = index; i<candidates.size(); i++){ 
      if(candidates[i] > target) return; // as the sum exceeds target
      if(i && candidates[i]==candidates[i-1] && i > index) continue; // skippipng duplicate records
      
      temp.push_back(candidates[i]); // add candidate which is considered to temp
      
      // back track to next index and reduce the next loop's target
      backTrack(candidates, target - candidates[i], temp, i+1); 
      
      temp.pop_back(); // remove the candidate after work is done
    }
    return;
  }
};
