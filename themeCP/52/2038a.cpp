#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int a[n], b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		cin >> b[i];
	}

	int t[n];

	for(int i=0;i<n;i++){
		t[i] = a[i]/b[i];
	}

	int d = 0;
	int suf[n+1];
	suf[n] =0;
	for(int i=n-1;i>=0;i--){
		suf[i] = suf[i+1]+t[i];	
	}
	int ans[n];
	memset(ans, 0, sizeof(ans));
	bool pos = 1;
	if(suf[0] < k) pos = 0;


	
	for(int i = 0;i<n;i++){
		if(!pos) break;
		if(suf[i+1] >= k){ 
		}else{ 
			ans[i] = k-suf[i+1];
			k-=ans[i];
		}
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << ' ';
	}
}
