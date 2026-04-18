#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c,d;

	cin >> a >> b >> c >> d;

	int k = max({a,b,c,d});

	if(a == k) k = max({b,c,d});
	else if(b == k) k = max({a,c,d});
	else if(c == k) k = max({a,b,d});
	else k = max({a,b,c});
	cout << min({a,b,c,d})*k;
}
