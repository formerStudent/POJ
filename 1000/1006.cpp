#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int cases = 0;
	int p = 0, e = 0, i = 0;
	int t = 0;
	while (true)
	{
		cases++;
		cin >> p >> e >> i >> t;
		p = p % 23;
		e = e % 28;
		i = i % 33;
		if (p == -1 && e == -1 && i == -1 && t == -1)
			break;
		if (p < 0 || p>365)
			continue;
		if (e < 0 || e>365)
			continue;
		if (i < 0 || i>365)
			continue;
		if (t < 0 || t>365)
			continue;
		int days = t;
		int pr = 0, er = 0, ir = 0;
		int next = 0;
		while (true)
		{
			if (i + next * 33 > days)
			{
				days = i + next * 33;
				break;
			}
			next++;
		}
		while (true)
		{
			pr = (days - p) % 23;
			er = (days - e) % 28;
			ir = (days - i) % 33;
			if (pr == 0 && er == 0 && ir == 0)
			{
				if (days != t)
					break;
			}
			days += 33;
		}
		if (days - t > 211252)
			continue;
		printf("Case %d: the next triple peak occurs in %d days.\n", cases, days-t);
	}
}