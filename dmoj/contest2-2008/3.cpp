#include <bits/stdc++.h>


using namespace std;

int main(){
	int n;
	cin >> n;
	
	pair<int,int> a[n];
	
	for(int i =0;i<n;i++) cin >> a[i].first >> a[i].second;
	int ans =INT_MAX;	
	for(int i =1;i < (1<<n);i++){
		int s = 1, b = 0;
		for(int j =0;j<n;j++){
			if((i >> j) & 1){
				s*=a[j].first;
				b+=a[j].second;
			}
		}
		ans = min(ans, abs(s-b));
	}
	cout << ans;
}
