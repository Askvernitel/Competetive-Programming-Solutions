#include <bits/stdc++.h>

using namespace std;

int timee[5003];
int main(){
	int t, n;
	cin >> t >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];

	sort(a, a+n, greater<int>());
	vector<int> ans;
	int p = 0, cur = 0;
	while(p<t && cur < n){
		ans.push_back(p);
		ans.push_back(p+1);
		p += a[cur];
		cur+=2;
	}

	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
}	
