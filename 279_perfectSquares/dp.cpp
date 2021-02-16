// DP solution in which every element is least number of perfect square numbers which sum to that index
// if A = a^2 + b^2 + c^2 then A-a^2 = b^2 + c^2
// thus when we iterate over i, we again iterate over j such that j*j <= i

class Solution {
public:
  int numSquares(int n) {
    if(!n) return n;
    
    vector<int>count(n+1, INT_MAX);
    count[0] = 0;
    
    for(int i=1; i<=n;i++){
    // for each number i is sum of i-j*j and j*j
      for(int j=1; j*j <= i; j++){
        count[i] = min(count[i], count[i-j*j] + 1);
      }
    }
    return count.back();
  }
};
