#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	bool ok = 1;
	int ans =0;
	vector<int> v;
	bool p = 0, t = 0;
	sort(a, a+n);
	while(ok){ 
		int diff = 0;
		int p1 = -1, p2 =-1;
		diff = a[n-1]-a[0];
		for(int i =0;i<n;i++){
			if(p1 == -1){
				p1=a[i];
			}
			if(p1 != a[i] && p1 != -1 && p2 == -1){
				p2=a[i];
			}
		}
		if(diff == 0) break;
		int t1= min(p1,p2), t2=max(p1,p2);
		if(((t1%2) )){
			v.push_back(1);
		}else{
			v.push_back(0);
		}
		for(int i =0;i<n;i++){
			a[i] = (a[i]+v.back())/2;
		}
	}
	cout << v.size() << '\n';
	if((int)v.size() <= n){
		for(int i =0;i<v.size();i++){
			cout << v[i] << " ";
		}
		cout << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
