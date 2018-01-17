#include <iostream>
#include <string.h>
#include <list>
#include <string>
using namespace std;
//A, B, C -> 2
//D, E, F -> 3
//G, H, I -> 4
//J, K, L -> 5
//M, N, O -> 6
//P, R, S -> 7
//T, U, V -> 8
//W, X, Y -> 9

int main()
{
	char in[200]{ 0 };
	list<string> data;
	int n;
	cin >> n;
	if (n > 100000)
		return -1;
	while (n--)
	{
		string out;		
		cin >> in;
		for (int i = 0, j = 0; i < strlen(in); i++)
		{
			if (in[i] >= '0'&&in[i] <= '9')
			{
				out += in[i];
			}
			else
			{
				switch (in[i])
				{
				case 'A':
				case 'B':
				case 'C':
					out += '2';
					break;
				case 'D':
				case 'E':
				case 'F':
					out += '3';
					break;
				case 'G':
				case 'H':
				case 'I':
					out += '4';
					break;
				case 'J':
				case 'K':
				case 'L':
					out += '5';
					break;
				case 'M':
				case 'N':
				case 'O':
					out += '6';
					break;
				case 'P':
				case 'R':
				case 'S':
					out += '7';
					break;
				case 'T':
				case 'U':
				case 'V':
					out += '8';
					break;
				case 'W':
				case 'X':
				case 'Y':
					out += '9';
					break;
				default:
					break;
				}
			}
		}
		if (out.length() != 7)
			continue;
		data.push_back(out);
	}
	data.sort();
	int count = 0;
	string str = data.front();
	for (list<string>::iterator it = data.begin(); it != data.end(); it++)
	{
		if (str == *it)
			count++;
		else
		{			
			if (count >= 2)
			{
				str.insert(3, 1, '-');
				cout << str << " " << count << endl;
			}
			str = *it;
			count = 1;
		}
	}
	if (count >= 2)
	{
		str.insert(3, 1, '-');
		cout << str << " " << count << endl;
	}		
	int num = data.size();
	data.unique();
	//cout << num << " " << data.size() << endl;
	if (num == data.size())
		cout << "No duplicates." << endl;
	//system("pause");
	return 0;
}