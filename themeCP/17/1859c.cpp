#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	
	vector<int> v;
	for(int i =1;i<=n;i++){
		v.push_back(i);
	}
	vector<int> v1 = v;	
	int ans = 0;
	for(int i =0;i<v.size();i++){
		
		reverse(v1.begin()+i, v1.end());
		int sum =0;
		int maxv = 0;
		for(int j =0;j<v1.size();j++){
			sum += ((j+1)*v1[j]);
			maxv = max((j+1)*v1[j],maxv);
		}
		ans = max(ans,sum-maxv);
		v1=v;
	}
	cout << ans << '\n';

}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
