// We have to maintain two numbers as there can be maximum 2 numbers which satisfy the condition
// Keep track of 2 numbers and keep track of count which when 0 then corresponding number will be the new one
// Let us take example of 1,1,1,3,3,2,2,2 and go through algo  // these numbers below are the locations of code which will get executed
// num1 = -1, num2 = -1, count1 = 0, count2 = 0
// i=0 nums[i] = 1  num1 = 1  count1 = 1 num2 = -1  count2 = 0    // 3
// i=1 nums[i] = 1  num1 = 1  count1 = 2 num2 = -1  count2 = 0    // 1
// i=2 nums[i] = 1  num1 = 1  count1 = 3 num2 = -1  count2 = 0    // 1
// i=3 nums[i] = 3  num1 = 1  count1 = 3 num2 = 3  count2 = 1     // 4
// i=3 nums[i] = 3  num1 = 1  count1 = 3 num2 = 3  count2 = 2     // 2
// i=4 nums[i] = 2  num1 = 1  count1 = 2 num2 = 3  count2 = 1     // 5
// i=5 nums[i] = 2  num1 = 1  count1 = 1 num2 = 3  count2 = 0     // 5
// i=6 nums[i] = 2  num1 = 1  count1 = 1 num2 = 2  count2 = 1     // 4

// We got num1 and num2 which might be the numbers we are looking for but count1 and count2 are not their frequencies
// So we iterate over nums and calculate frequencies of num1 and num2 whichever exceeds n/3 gets recorded in result

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0; // initialization
    vector<int> result;
    
    for(int i=0; i<nums.size(); i++){
      if(nums[i] == num1) count1++;      // 1
      else if(nums[i] == num2) count2++; // 2
      else if(count1 == 0){              // 3
        num1 = nums[i];
        count1++;
      }
      else if(count2 == 0){              // 4
        num2 = nums[i];
        count2++;
      }
      else{                              // 5
        count1--;
        count2--;
      }
    }
    // cout<<num1<<" "<<num2<<" "<<count1<<" "<<count2<<endl;
    count1=0;
    count2=0;
    for(int a : nums){
      if(a==num1) {count1++; continue;}
      if(a==num2) {count2++; continue;}
    }
    if(count1 > nums.size()/3) result.push_back(num1);
    if(count2 > nums.size()/3) result.push_back(num2);
    
    return result;
  }
};
