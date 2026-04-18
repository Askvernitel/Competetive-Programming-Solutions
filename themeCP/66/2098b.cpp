#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int l =n/2,r=n/2;
	if(!(n%2)) l--;
	int cnt = n;
	while(k > 0){
		if(l == r){
			r++;
			l--;
			k--;
		}else{
			if(k >= 2){
				r++;
				l--;
				k-=2;
				continue;
			}else{
				k--;
				continue;
			}
		}
	}

	cout << a[r]-a[l]+1 << '\n';
		
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
