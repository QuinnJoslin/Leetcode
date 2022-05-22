#include <string>
using std::string;

class Solution {
public:
	int romanToInt(string s)
	{
		int output = 0;
		for (int i = 0; i < s.length(); i++)
		{
			//IV / IX
			if (i != 0 && (s[i - 1] == 'I' && s[i] == 'V' || s[i - 1] == 'I' && s[i] == 'X'))
			{
				output = output - 2; //subtracting the last addition 2x
			}
			//XL / XC
			if (i != 0 && (s[i - 1] == 'X' && s[i] == 'L' || s[i - 1] == 'X' && s[i] == 'C'))
			{
				output = output - 20; //subtracting the last addition 2x
			}

			//CD / CM
			if (i != 0 && (s[i - 1] == 'C' && s[i] == 'D' || s[i - 1] == 'C' && s[i] == 'M'))
			{
				output = output - 200; //subtracting the last addition 2x
			}


			if (s[i] == 'I')
			{
				output += 1;
			}
			else if (s[i] == 'V')
			{
				output += 5;
			}
			else if (s[i] == 'X')
			{
				output += 10;
			}
			else if (s[i] == 'L')
			{
				output += 50;
			}
			else if (s[i] == 'C')
			{
				output += 100;
			}
			else if (s[i] == 'D')
			{
				output += 500;
			}
			else if (s[i] == 'M')
			{
				output += 1000;
			}
		}

		return output;
	}
};
