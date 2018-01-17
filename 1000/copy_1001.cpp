#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

string Add(string s1, string s2)  //��������������ӣ����ַ�������ʽ
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

string Mul(string s1, string s2)  //һ������������һ�������ĳ˻�
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

string StringPow(string s, int n)  //һ������������n����
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
			str = "0";      //���������s����  000000,0.0000��.00000����ʽ�Ĵ���
		}
		else  //�����s������
		{
			int pos = s.find('.');
			int num;
			if (pos != s.npos)   //�����s��С��
			{
				int exp = s.size() - (pos + 1);
				s.erase(pos, 1); //ȥ��С���㣬����1.01��Ϊ101(С��������)
				int num = exp*n;  //������ƶ���С����λ(����1.01������=101*101*101�����ƶ�2*3λ(��ʱn=3��num=3)
				int i;
				for (i = 0; i<s.size(); i++)
				{
					if (s[i] != '0')
					{
						s = s.substr(i);  //ȥ�����ʹ���ǰ���0������0101��Ϊ101
						break;
					}
				}
				str = StringPow(s, n);  //str����s��n����ֵ
				int p = str.size() - num;
				if (p<0)  //����һ������������������λ���ڽ����λ��
				{
					str.insert((size_t)0, -p, '0');
					str.insert((size_t)0, 1, '.');
				}
				else
					str.insert(p, 1, '.');  //�ƶ�С����λ���õ���ȷ�Ľ��
			}
			else //�����s������
			{
				for (int i = 0; i<s.size(); i++)
					if (s[i] != '0')
					{
						s = s.substr(i);    //ȥ�����ʹ���ǰ���0������0101��Ϊ101
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
						str.erase((size_t)i, 1);     //ȥ��С��������ʾ���ȵ�0������1.2000��Ϊ1.2
					}
					else
						break;
				}
			}

			int len = str.size();
			if (str[len - 1] == '.')
			{
				str.erase((size_t)(len - 1), 1);   //����һ���������������10.��Ϊ10
			}
		}

		cout << str << endl;
	}
	return 0;
}