// whenever there is a rise, just record the difference
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int result = 0;
      for(int i=1; i<prices.size(); i++){
         // when there is a rise, just add up in our result
         if(prices[i] > prices[i-1]){
             result += prices[i] - prices[i-1];
         }
      }    
        return result;
    }
};
