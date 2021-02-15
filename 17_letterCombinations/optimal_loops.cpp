// We follow a simple approach but yet tricky
// we create a temp vector<string>  and iterate over all elements of result and also on all elements of digit (which is element of digits) and create a temp result
// e.g. result = {"a", "b", "c"} and digit = "def" then we iterate over "def" and for each e.g. 'd' we append 'a', then 'b' then for each 'e' we append',' then 'b' ....
// now we need result for the next inclusion of digit so we simply swap result and temp

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    // digits : "234"
    vector<string> dialPad {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // we access digits numbers by index in dialPad
    vector<string>result;
    if(!digits.size()) return result; // handling empty cases
    
    result.push_back(""); // e.g. we have {"a", "b", "c"}
    
    for(char d : digits){
      string newString = dialPad[d-'0']; // newString = "def"
      vector<string> temp;
      for(char c : newString){ // c = 'a'
        for(string s : result){ // s = "d"
          temp.push_back(s + c); // s+c = "ad"
        }
      } // now we got expanded version in temp which includes abc and def
      swap(result, temp); // we swap result and temp so that in next iteration in line 20, we use this new expanded version
    }
    return result;
  }
};
