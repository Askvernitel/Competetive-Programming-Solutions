#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	
	int first = 0, second = 0;
	int asc = 0, desc = 0;
	int last_asc = 0;
	int change = 0;
	int pos =1;
	for(int i = 0;i<n-1;i++){
		if(a[i] < a[i+1]){
			if(last_asc ==2 && change >= 2){ 
				pos = 0;
				break;
			}
			if(last_asc != 1) change++;
			last_asc = 1;

		}
		if(a[i] > a[i+1]){ 
			if(last_asc == 1){ 
				pos = 0;
				break;	
			}
			if(last_asc != 2) change++;
			last_asc = 2;
		}
	}
	if(change >=3) pos = 0;
	cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
