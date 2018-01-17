#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char r[6] = { 0 };
	int n;
	while (cin >> r >> n)
	{
		int m = n;
		int output[200];
		int mul[6];
		memset(mul, -1, 6 * sizeof(int));
		memset(output, -1, 200 * sizeof(int));
		int point = 5;
		double a = strtod(r, NULL);
		if (n > 25 || n < 0)
			continue;
		for (int i = 5,j = 5; i >= 0; i--)
		{
			if (r[i] == '.')
			{
				point = i;
				continue;
			}			
			if (r[i] <= '9'&&r[i] >= '0')
				mul[j--] = r[i] - '0';
		}

		for (int i = 0; i <= 5; i++)
		{
			if (mul[i] == 0)
				mul[i] = -1;
			else if (mul[i] != -1)
				break;
		}
		int isZero = 0;
		int isNine = 0;
		for (int i = 0; i < 6; i++)
		{
			if (mul[i] == -1 || mul[i] == 0)
				isZero++;
			if (mul[i] == 9)
				isNine++;
		}
		if (isNine == 5 && point >= 2)
			continue;
		if (isZero == 6)
		{
			for (int i = 0; i < 5; i++)
				mul[i] = -1;
			mul[5] = 0;
			point = 5;
		}
		for (int i = 5, j = 199; i >= 0; i--, j--)
			output[j] = mul[i];
		if (n == 0)
		{
			memset(output, -1, 200 * sizeof(int));
			if (isZero == 6)
				output[199] = 0;
			else
				output[199] = 1;
		}
		while (--n > 0)
		{
			int temp[200];
			memset(temp, -1, 200 * sizeof(int));
			for (int i = 5; i >= 0; i--)
			{
				if (mul[i] == -1)
					continue;
				int en = 0;
				int j;
				for (j = 199; j >= 0; j--)
				{
					if (output[j] == -1)
						break;					
					int tmp = mul[i] * output[j] + en;
					en = tmp / 10;
					tmp = tmp % 10;					
					if (temp[j - 5 + i] == -1)
					{
						temp[j - 5 + i] = tmp;
					}
					else
						temp[j - 5 + i] += tmp;
					en += temp[j - 5 + i] / 10;
					temp[j - 5 + i] = temp[j - 5 + i] % 10;
				}
				while (en != 0)
				{
					if (temp[j - 5 + i] == -1)
						temp[j - 5 + i] = en;
					else
						temp[j - 5 + i] += en;
					en = temp[j - 5 + i] / 10;
					temp[j - 5 + i] = temp[j - 5 + i] % 10;
					j--;
				}
			}
			memcpy(output, temp, 200 * sizeof(int));
		}
		int pos_point = (5 - point)*m;
		for (int i = 0; i < 199; i++)
		{
			if (output[i] == 0)
			{
				output[i] = -1;
			}
			else if (output[i] > 0)
				break;
		}

		if (point != 5)
		{
			for (int i = 0; i < 200; i++)
			{
				if (output[i] > 0)
					break;
				if (200 - i > pos_point)
				{
					if (output[i] == 0)
						output[i] = -1;
				}
				else if (output[i] == -1)
					output[i] = 0;
				if (output[i] == -1)
					continue;
			}
			for (int j = 199; j >= 0; j--)
			{
				if (output[j] > 0)
					break;
				if (output[j] == -1)
					continue;
				if (output[j] == 0 && (200 - j) <= pos_point)
					output[j] = -1;
			}
		}
		for (int i = 0; i < 200; i++)
		{
			if (output[i] == -1)
				continue;
			if (200 - i == pos_point)
				cout << '.';
			cout << output[i];
		}
		cout << endl;
	}
}
