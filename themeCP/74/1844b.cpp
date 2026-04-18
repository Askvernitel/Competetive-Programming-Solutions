#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n ;
	cin >> n;
	int a[n];
	set<int> tt;
	for(int i =1;i<=n;i++){
		tt.insert(i);
	}


	int ans[n];
	int p = n/2;
	ans[p] = 1;

	tt.erase(1);
	if(p!=0){ 
		ans[0] = 2;
		tt.erase(2);
	}
	if(p != n-1){ 
		ans[n-1] = 3;
		tt.erase(3);
	}

	for(int i =1;i<p;i++){
		auto it = tt.begin();
		ans[i]=*it;
		tt.erase(it);
	}

	for(int i =p+1;i<n-1;i++){
		auto it = tt.begin();
		ans[i]=*it;
		tt.erase(it);
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
