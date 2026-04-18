#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n;
	cin >> n;

	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int last = 0;
	int i = 0;
	while(a[i] == last){
		while(i<n && a[i] == last) i++;
	
		last++;
	}

	cout << last << '\n';
	

}
int main(){
	int tc;

	cin >> tc;

	while(tc--){
		solve();
	}
}
