#include <iostream>

using namespace std;

typedef long long ll;

pair <ll, ll> solve (ll k1, ll k2, ll p2, ll n2, ll m)
{
	ll number_on_langing, count_on_landing, p1 = -1, n1 = -1;

	if (n2 > m) return make_pair(-1, -1);
	if (m * (p2-1) + n2 == 1) return (k1 <= k2 ? make_pair(1, 1) : make_pair(0, 0));

	for (count_on_landing = 1; count_on_landing <= k2 + 1; count_on_landing++)
	{
		number_on_langing = k2 - count_on_landing * (m * (p2 - 1) + n2 - 1);

		if (number_on_langing >= 1 && number_on_langing <= count_on_landing)
		{
			ll new_p1 = (k1 - 1) / (count_on_landing * m) + 1,
			   new_n1 = (k1 - 1 - (new_p1 - 1) * m * count_on_landing) / count_on_landing + 1;

			p1 = (p1 != -1 && p1 != new_p1 ? 0 : new_p1),
			n1 = (n1 != -1 && n1 != new_n1 ? 0 : new_n1);
		}
	}

	if (k1 == k2) return make_pair(p2, n2);
	return make_pair(p1, n1);
}

ostream& operator << (ostream &s, const pair <ll, ll> &p)
{
	cout << p.first << ' ' << p.second;
	return s;
}

int main()
{
	ll k1, k2, p2, n2, m;

	cin >> k1 >> k2 >> p2 >> n2 >> m;
	cout << solve (k1, k2, p2, n2, m) << endl;
	
	system("pause");
	return 0;
}
