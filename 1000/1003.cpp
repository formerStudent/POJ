#include <iostream>	
using namespace std;

int main()
{
	float c = 0.0f;
	while (true)
	{
		cin >> c;
		if (c == 0.0f)
			break;
		if (c<0.01f || c>5.20f)
			continue;
		float totalLength = 0.0f;
		float increNum = 2.0f;
		int count = 0;
		while (totalLength < c)
		{
			totalLength += 1.0f / increNum;
			increNum += 1.0f;
			count++;
		}
		printf("%d card(s)\n", count);
	}
	//system("pause");
}