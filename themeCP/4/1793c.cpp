#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	set<int> s;
	for(int i =0;i<n;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	int l=0, r=n-1;

	while(l<r){
		if(a[l] == *s.begin() || a[l] == *prev(s.end())){
			s.erase(a[l]);
			l++;
		}else if(a[r] == *s.begin() || a[r] == *prev(s.end())){
			s.erase(a[r]);
			r--;
		}else{
			break;
		}
	}
	l++;r++;
	if(l ==r) {cout << - 1 << '\n'; return;}
	cout << l << " "<< r << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
