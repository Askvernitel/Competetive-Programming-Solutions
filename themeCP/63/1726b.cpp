#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;

	if(!(m%n)){ 
		cout << "YES\n";
		for(int i =0;i<n;i++){
			cout << m/n<< " ";
		}
		cout << '\n';
		return;
	}

	if((m%2 && !(n%2)) || n > m){ 
		cout << "NO" <<'\n';
		return;
	}

	cout << "YES\n";
	int p = m-n+1;
	if(n%2){
		cout << p << " ";
		for(int i =0;i<n-1;i++){
			cout << 1 << " ";
		}
	}else{ 
		int k = (p+1)/2;
		cout << k << " " << k << " ";

		for(int i =0;i<n-2;i++){
			cout << 1 << " ";
		}
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
