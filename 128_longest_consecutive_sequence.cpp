class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> streakSizes; // key=number,value=streaksize at the time of discovery
        int result = 0;
        
        for(int num: nums){
            if(streakSizes[num]) continue;
            int streak = 1;
            
            // we heavily abuse the fact that hashmap in 
            // cpp returns 0 if the key is not found
            
            int upStreak = streakSizes[num+1]; // streak above me
            int downStreak = streakSizes[num-1]; // streak below me
            
            streak += (upStreak + downStreak); // final new streak size
            
            // redundant if downstreak is 0, but no harm
            streakSizes[num-downStreak] = streak; // lower endpoint should be updated
            // redundant if upstreak is 0, but no harm
            streakSizes[num+upStreak] = streak; // upper endpoint should be updated
            streakSizes[num] = streak; // self should be updated
            
            result = max(streak, result);
        }
        
        return result;
    }
};
