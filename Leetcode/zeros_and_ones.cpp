/****************************************
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y. //////////this is probbly where i am getting confused

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
***************************************/
// note i dont understand the output my code works for most test casses except the one above


#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		int str_that_fit = 0;
		int zeros = 0;
		int ones = 0;
		int i = 0;
		while (i != strs.size())
		{
			for (int j = 0; j < strs[i].length(); j++)
			{
				if (strs[i][j] == '0')
				{
					zeros++;
				}
				else if (strs[i][j] == '1')
				{
					ones++;
				}
			}
			if (ones <= n && zeros <= m)
			{
				str_that_fit++;
			}
			ones = 0;
			zeros = 0;
			i++;
		}

		return str_that_fit;
	}
};