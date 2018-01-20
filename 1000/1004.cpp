#include <stdio.h>
#include <iostream>
//#include <fstream>

using namespace std;
int main()
{
	//fstream fs("1004.txt", std::fstream::in);
	float totalSalary = 0.00f;
	int n = 12;
	while (n--)
	{
		float salary = 0.00f;
		//fs >> salary;
		cin >> salary;
		if (salary<0.00f || salary>1000000.00f)
			break;
		totalSalary += salary;
	}
	printf("$%.2f\n", totalSalary / 12.00f);
	//system("pause");
}