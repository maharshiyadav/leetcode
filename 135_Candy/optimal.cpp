// Assign one Candy to every person (initializing vector with all values being 1)
// While doing a left swipe we just consider uni directional condition matching that higher valued person gets more candy
// Now doing the same while right swipe we just ensure that what right swipe result, consider left swipe result and take max of those
// out final result is sum of all elements of array

class Solution {
public:
    int candy(vector<int>& ratings) {
      vector<int> candies(ratings.size(), 1);
      int result = 0;
      
      //Left swipe
      for(int i=1; i<ratings.size(); i++){
        if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
      }
      //Right swipe ensure we have max of left sum and right sum
      for(int i=ratings.size()-1; i>0; i--){
        if(ratings[i-1] > ratings[i]){
          candies[i-1] = max(candies[i-1], candies[i] + 1);
        }
      }
      
      for(int i : candies) result += i;
      
      return result;
    }
};
