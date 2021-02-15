// two pointer approach 


class Solution {
public:
  int maxArea(vector<int>& height) {
    // result contains our max area
    // i and j a re start and end pointers
    int result = 0, i=0, j=height.size()-1, currArea;
    while(i<j){
      // record current area formed by filling i and j bars
      currArea = (j-i) * min(height[i], height[j]);
      result = max(result, currArea);
      
      // incrementing/decrementing start/end pointers respectively whichever is lesser
      if(height[i] < height[j]){
        i++;
      }
      else j--;
    }
    return result;
  }
};
