#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int,int> m;
	for(int i =0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	int l = 0;	
	int ans =0 ;

	int left=-1,right=-1;
	for(int r=0;r<n;r++){
		if(m[a[r]] > 1){ 
			l = r+1;
			continue;
		}
		if(ans <= r-l){ 
			ans = r-l;
			left=l;
			right=r;
		}
	}
	if(left == -1){ 
		cout << 0 << '\n';
		return;
	}
	cout << left+1 << " " << right+1 << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
