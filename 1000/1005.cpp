#include <iostream>
#include <math.h>

#define PI 3.14
using namespace std;

int main()
{
	int n;
	cin >> n;
	int pro = 0;
	while (n--)
	{
		pro++;
		float x = 0.0f, y = 0.0f;
		cin >> x >> y;
		float dist = sqrtf(x*x + y*y);
		int years = 0;
		float area = 0.0;
		while (true)
		{
			float radius = sqrtf(area / PI);
			if (radius >= dist)
				break;
			area += 100.0f;
			years++;
		}
		printf("Property %d: This property will begin eroding in year %d.\n", pro, years);
	}
	printf("END OF OUTPUT.\n");
	//system("pause");
	return 0;
}