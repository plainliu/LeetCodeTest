/*
 *3.27 2:00
 *PlainLiu
 *beat77.96%
 *The length of Palindromic Substring Odd or Even. Get the longest of them, and compare which one is longer.
 */
 class Solution {
public:
	string longestPalindrome(string s) {
		int l = s.length();
		int odd = 0, even = 0;//position
		int odd_num = 0, even_num = 0, num_tem = 0;//half num
		for (int odd_tem = 1; odd_tem<l - 1; odd_tem++){//0[1..l-2]l-1 odd
			num_tem = 1;
			while (s[odd_tem - num_tem] == s[odd_tem + num_tem]){
				num_tem++;
				if (odd_tem - num_tem<0 || odd_tem + num_tem>l - 1)
					break;
			}
			num_tem--;//2*n+1
			num_tem>odd_num ? odd_num = num_tem, odd = odd_tem : odd;
		}
		for (int even_tem = 0; even_tem<l - 1; even_tem++){//[0..l-2]l-1 even
			num_tem = 0;//odd
			if (s[even_tem] != s[even_tem + 1])continue;
			while (s[even_tem - num_tem] == s[even_tem + 1 + num_tem]){
				num_tem++;
				if (even_tem - num_tem<0 || even_tem + 1 + num_tem>l - 1)
					break;
			}
			num_tem>even_num ? even_num = num_tem, even = even_tem : even;//2n
		}
		if (2 * odd_num + 1>2 * even_num)
			return s.substr(odd - odd_num, 2 * odd_num + 1);
		else
			return s.substr(even - even_num + 1, 2 * even_num);
	}
};
