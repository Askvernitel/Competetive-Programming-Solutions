#include <bits/stdc++.h>


using namespace std;
const int MX = 1073741823;
void solve(){
	
	int n;
	cin >> n;
	int M[n][n];	
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin >> M[i][j];
		}
	}
	int a[n];
	for(int i =0;i<n;i++){
		int d = MX;
		for(int j =0;j<n;j++){
			if(j == i) continue;
			d = d&M[i][j];
		}
		a[i] = d;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i) continue;
			if((a[i]|a[j]) != M[i][j]){ 
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	for(int i =0;i<n;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
