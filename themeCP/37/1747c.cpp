#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	if(a[0] == 1){ 
		cout << "Bob\n";
		return;
	}
	for(int i =1;i<n;i++){
		if(a[i] == 1){
			cout << "Alice\n";
			return;
		}
	}
	int minv = a[0];
	for(int i =1;i<n;i++){
		minv = min(a[i], minv);
	}

	if(minv == a[0]){
		cout << "Bob\n";
	}else{
		cout << "Alice\n";
	}
}
int main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
