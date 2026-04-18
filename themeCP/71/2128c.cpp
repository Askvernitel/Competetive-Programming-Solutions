#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int b[n];
	for(int i=0;i<n;i++){
		cin >> b[i];
	}

	int minv=1e9;	
	bool pos = 1;
	for(int i=0;i<n;i++){
		if(minv*2 <= b[i]){
			pos=0;
			break;
		}
		minv = min(b[i], minv);
	}
	cout << ((pos)?"YES":"NO") << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
