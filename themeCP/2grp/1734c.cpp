#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int arr[n+1]; 
	memset(arr, 1, sizeof(arr));
	string t;
	cin >> t;
	
	int m = t.size();
	long long ans= 0;
	for(int i =0;i<m;i++){
		int c = i+1;
		if(t[i] == '1'){ 
			for(int j = 1;j*j<=c;j++){
				if(c%j == 0){ 
					arr[j] = 0;
					arr[c/j] = 0;
				}
			}
			continue;
		}
		int minv = c;
		for(int j =1;j*j<=c;j++){
			if(c%j == 0){ 
				if(t[j-1] =='0'	&& arr[j]){ 
					minv = min((int)j, minv);
				}
				if(t[c/j -1] == '0' && arr[c/j]){ 
					minv = min((int)c/(int)j, minv);
				}
			}
		}
		ans += minv;

	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
