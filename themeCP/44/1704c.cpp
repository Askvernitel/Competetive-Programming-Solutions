#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int a[m];
	for(int i =0;i<m;i++){
		cin >> a[i];
	}

	sort(a, a+m);

	int dist[m];

	dist[0] = n-a[m-1] + (a[0]-1);
	for(int i = 0;i<m-1;i++){
		dist[i+1] = a[i+1]-a[i]-1;
	}
	sort(dist, dist+m, greater<int>());

	int t = 2;
	int s = 0;
	int idx = -1;
	for(int i = 0;i<m;i++){
		if(dist[i] - (t-1)*2 + 1 <=0) {idx=i;break;}
		s+=dist[i] -(t-1)*2+1;
		t+=2;
	}
	if(idx!=-1 && dist[idx] - (t-2)*2> 0){ 
		s+=dist[idx] - (t-2)*2 ;
	}
	cout << n - s << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
