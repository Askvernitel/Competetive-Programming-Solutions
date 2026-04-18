#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;

	pair<int,int> a[n];
	for(int i =0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);	
	int ans = 0;
	int p = a[0].second;


	for(int i =1;i<n;i++){
		if(a[i].second <p){ 
			ans+=p-a[i].second;
		}else{
		}

		p=a[i].second;
	}
	ans+=p;
	cout << ans << '\n';
}
