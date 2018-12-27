/*
 *using LeetCode Solution 2:Sliding Window
 *2018.12.27
 *Liu
 *all characters can be printed, not only abc
 *ascii32-126
 */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len=s.length();
        int lgstlen=0;
        char hash[95]={0};//HashSet,index=char-32(from 32 to 126)all can be print
        
		for (int i = 0, j = 0; i<len; i++){//get length of the longest substring starting i
			//memset(hash, '\0', sizeof(hash));//clear hash
            for (j = 0; j<95; ++j)//clear hash[95]
				hash[j] = 0;
            for (j = i; j<len; j++){//length=j-i,[i,j)
                if (s[j]==hash[s[j]-32])//if in HashSet
					break;
                else//add to HashSet
                    hash[s[j]-32]=s[j];
			}
            lgstlen=(j-i>lgstlen?j-i:lgstlen);//update lgstlen
            if(j==len)break;//the substring has been the tail
		}
        return lgstlen;
	}
};
