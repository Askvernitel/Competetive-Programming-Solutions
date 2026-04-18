#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> m;
	for(int i =0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	int ones = 0, other = 0;
	for(auto &x:m){ 
		if(x.second == 1) ones++;
		else other++;
	}
	cout << other + ((ones+1)/2)*2 << '\n';


}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
