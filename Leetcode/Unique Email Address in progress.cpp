/**********************************************
Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.


Example 1:

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
Example 2:

Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3


Constraints:

1 <= emails.length <= 100
1 <= emails[i].length <= 100
emails[i] consist of lowercase English letters, '+', '.' and '@'.
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
Domain names end with the ".com" suffix.

***********************************************/
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails)
	{
		int validemails;
		int i = 0;
		int j = 0;
		int k = 0;
		int plus = 0;
		int at_hit = 0;
		char ** holding = new char*[10];//at max there is only 10 emails given


		//outerloop
		while (emails[i] != *emails.end())
		{
			//iner loop for first part of email
			for (std::string::iterator it = emails[j].begin();it != emails[j].end();it++) // ends for loop if we hit @ sign
			{
				if (*it == '@')
				{
					at_hit = 1;
					plus = 0;//resets + effects
				}
				if (*it == '+')//if there is a + remove till the @ sign
				{
					//remove all charaters after till the @
					plus = 1;
				}
				else if (plus = 1 || ((*it == '.') && (at_hit != 1)))
				{
					//do nothing just iterate
				}
				else
				{
					holding[i][j] = *it;//filling array
				}
				j++;
			}

			i++;
			at_hit = 0;
			plus = 0;
		}
		i = 0;
		//compare portion
		//the holding[k] to the emails[i] remove the ones that are the same
		while (holding[k] != nullptr)
		{
			while (emails[i] != *emails.end())///////change this to check for emails that are the same in the holding arrays
			{
				if (emails[i].compare(holding[k]) != 0)
				{
					validemails++;
				}
				i++;
			}
			k++;
		}
		delete[] holding;
		holding = nullptr;

		return validemails;
	}
};