#include <bits/stdc++.h>
#include <cstring>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];

	int arr[31]{};

	for(int i =0;i<n;i++){
		int p = a[i];
		int cur = 0;
		while(p != 0){
			if(p & 1){ 
				arr[cur]++;
			}
			cur++;
			p = (p >> 1);
		}
	}
	int ans = 0;
	for(int k =0;k<n;k++){
		int tmp[31];
		memcpy(tmp, arr, sizeof(arr));
		int p = a[k];
		int cur = 0;
		while(p!=0){
			if(p & 1){ 
				tmp[cur]=n-tmp[cur];
			}
			cur++;
			p=(p>>1);
		}
		int sum = 0;
		for(int i =0;i<31;i++){
			if(tmp[i]){ 
				sum+=((1<<i)*tmp[i]);
			}
		}
		ans = max(ans,sum);
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
