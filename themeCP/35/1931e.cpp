#include <bits/stdc++.h>
#define int long long
using namespace std;
int dig_count(int x){ 

	int res=0;
	while(x>0){ 
		res++;
		x/=10;
	}
	return res;
}
int zero_count(int x){
	int res = 0;
	int cur = x%10;
	while(x > 0 && cur == 0){ 
		res++;
		x/=10;
		cur = x%10;
	}
	return res;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int digs=0;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	vector<int> v;
	for(int i =0;i<n;i++){
		int p = a[i];
		digs+=dig_count(p);
		if(zero_count(p)){
			v.push_back(zero_count(p));
		}
	}
	if(digs < m+1){ 
		cout << "Anna\n";
		return;
	}
	sort(v.begin(),v.end(), greater<int>());
	int d = 0;
	for(int i =0;i<v.size();i+=2){
		d+=v[i];	
	}
	if(digs-d < m+1) { 
		cout << "Anna\n";
		return;
	}
	cout << "Sasha\n";
}
signed main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
