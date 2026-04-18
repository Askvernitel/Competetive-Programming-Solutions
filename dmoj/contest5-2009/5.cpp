#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n, k;
	cin >>n >> k;
	int a[k];
	int arr[n+1];
	int mp[n+1];
	for(int i =0;i<n;i++){
		arr[i]=0;
		mp[i] =0;
	}
	for(int i=0;i<k;i++){
		cin >> a[i];
		arr[a[i]]++;
		mp[a[i]]++;
	}
	arr[0] = k;	
	for(int i = 1;i<n;i++){
		if(!mp[i]) continue;
		for(int j=i+i;j<n;j+=i){
			arr[j]+=mp[i];
		}
	}

	int pref[n+1];
	pref[0] = 0;
	for(int i =1;i<n+1;i++){
		pref[i] = pref[i-1] + arr[i-1];
	}
	int q;
	cin >> q;

	while(q--){
		int l,r;
		cin >> l >> r;

		cout << pref[r+1] - pref[l] << '\n';
	}
}
