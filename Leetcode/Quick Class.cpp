/********
	this file is just a preinterview brushup this is a pointless class,
	takes a user defined string and tells u how many capital T's there are and where in the string they are. 
*********/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string; 

class mydata
{
public:
	mydata();
	mydata(string data);
	char methodsearch();
	string m_data;
};

mydata::mydata()
{
	m_data = nullptr; 
}

mydata::mydata(string data) : m_data(data)
{

}
char mydata::methodsearch()
{
	char found; 
	for (int i = 0 ;i < m_data.length(); i++)
	{
		if (m_data[i] == 'T')
		{
			found = m_data[i];
			cout << "T found at : " << i << endl;
		}
	}
	cout << "testing";
	return found;
}

int main()
{
	string datatestset;
	cout << "input your string : ";
	cin >> datatestset;
	mydata myData(datatestset);
	myData.methodsearch();

	return 0; 
}