// constraint is that every ')' occurs after '(' and number of '(' <= n and number of ')' <= number of '('
// record result when #'('+ #')' = 2n

class Solution {
public:
  vector<string> result;
  vector<string> generateParenthesis(int n) {
    backTrack(n, "", 0, 0);
    
    return result;
  }
  
  void backTrack(int n, string s, int open, int close){
    if(2*n == open + close){
      result.push_back(s); // record result
      return;
    }
    else{
      if(open < n) backTrack(n, s + "(", open + 1, close); // constraint 1
      
      if(close < open) backTrack(n, s + ")", open, close + 1);// constraint 2
    }
    return;
  }
  
};
