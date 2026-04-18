#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n;

	cin >> n;
	map<int, int> x, y;
	pair<int, int> cords[n];
	for(int	i =0;i<n;i++){
		int a, b;
		cin >> a >> b;

		x[a]++;
		y[b]++;
		cords[i].first = a;
		cords[i].second = b;
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		int f = cords[i].first, s = cords[i].second;

		ans += ((x[f]-1)*(y[s]-1));

	}
	cout << ans;


}
