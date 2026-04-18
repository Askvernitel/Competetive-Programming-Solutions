#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[(n*(n-1))/2];
	map<int,int> m;
	for(int i =0;i<(n*(n-1))/2;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	map<int,vector<int>> mc;
	int cur = n-1;	
	for(auto &[x,y]:m){ 
		mc[y].push_back(x);
		while(cur > 0 && y-cur >= 0){ 
			cout << x << " ";
			y-=cur;
			cur--;
		}
	}
	cout << (int)1e9<< '\n';

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
