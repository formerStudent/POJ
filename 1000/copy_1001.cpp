#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

string Add(string s1, string s2)  //两个整数大数相加，以字符串的形式
{
	int len1 = s1.size();
	int len2 = s2.size();
	string maxStr;
	string minStr;
	int minLen;
	int maxLen;
	if (len1 <= len2)
	{
		maxStr = s2;
		minStr = s1;
		minLen = len1;
		maxLen = len2;
	}
	else
	{
		maxStr = s1;
		minStr = s2;
		minLen = len2;
		maxLen = len1;
	}
	string str(maxLen + 1, '0');
	int i, j, temp;
	for (i = minLen - 1, j = maxLen - 1; i >= 0; i--, j--)
	{
		temp = (minStr[i] - '0') + (maxStr[j] - '0') + (str[j + 1] - '0');
		str[j + 1] = temp % 10 + '0';
		str[j] += temp / 10;
	}
	for (i = maxLen - minLen - 1; i >= 0; i--)
	{
		temp = (maxStr[i] - '0') + (str[i + 1] - '0');
		str[i] += temp / 10;
		str[i + 1] = temp % 10 + '0';
	}
	if (str[0] == '0')
	{
		return str.substr(1);
	}
	else
		return str;

}

string Mul(string s1, string s2)  //一个整数大数与一个整数的乘积
{
	vector<string> vec;
	vec.clear();
	long num = atoi(s1.c_str());
	int k = 0;
	for (int i = s2.size() - 1; i >= 0; i--)
	{
		long j = (s2[i] - 48);
		long t = j*num;
		string c;
		ostringstream oss;
		oss << t;
		c = oss.str();
		c.append(k, '0');
		vec.push_back(c);
		k++;
	}
	string s;
	if (vec.size() >= 2)
	{
		s = Add(vec[0], vec[1]);
		for (k = 2; k<vec.size(); k++)
			s = Add(s, vec[k]);
	}
	else
		s = vec[0];
	return s;
}

string StringPow(string s, int n)  //一个整数大数的n次幂
{
	string str = s;
	while (--n)
	{
		str = Mul(s, str);
	}
	return str;
}



int main()
{
	string s;
	int n;
	//ifstream fin("e:\\data.txt");
	//while (fin>>s>>n)
	while (cin >> s >> n)
	{
		string str;
		int count = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '0' || s[i] == '.')
			{
				count++;
			}
		}
		if (count == s.size())
		{
			str = "0";      //对于输入的s形如  000000,0.0000，.00000等形式的处理
		}
		else  //输入的s是正数
		{
			int pos = s.find('.');
			int num;
			if (pos != s.npos)   //输入的s是小数
			{
				int exp = s.size() - (pos + 1);
				s.erase(pos, 1); //去除小数点，比如1.01变为101(小数变整数)
				int num = exp*n;  //最后结果移动的小数点位(比如1.01的立方=101*101*101向左移动2*3位(此时n=3，num=3)
				int i;
				for (i = 0; i<s.size(); i++)
				{
					if (s[i] != '0')
					{
						s = s.substr(i);  //去除整型大数前面的0，比如0101变为101
						break;
					}
				}
				str = StringPow(s, n);  //str保存s的n次幂值
				int p = str.size() - num;
				if (p<0)  //处理一种特殊情况，向左进的位大于结果的位数
				{
					str.insert((size_t)0, -p, '0');
					str.insert((size_t)0, 1, '.');
				}
				else
					str.insert(p, 1, '.');  //移动小数点位，得到正确的结果
			}
			else //输入的s是整数
			{
				for (int i = 0; i<s.size(); i++)
					if (s[i] != '0')
					{
						s = s.substr(i);    //去除整型大数前面的0，比如0101变为101
					}
				str = StringPow(s, n);
			}

			pos = str.find('.');
			if (pos != s.npos)
			{
				for (int i = str.size() - 1; i >= pos; i--)
				{
					if (str[i] == '0')
					{
						str.erase((size_t)i, 1);     //去除小数点后面表示精度的0，比如1.2000变为1.2
					}
					else
						break;
				}
			}

			int len = str.size();
			if (str[len - 1] == '.')
			{
				str.erase((size_t)(len - 1), 1);   //处理一种特殊情况，比如10.变为10
			}
		}

		cout << str << endl;
	}
	return 0;
}