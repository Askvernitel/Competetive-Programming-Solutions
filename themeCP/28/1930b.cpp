#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int mv=0;
	int cur1 = 1;
	int cur2 = n;
	for(int i =n;i>=1;i--){
		if(!(mv%2)){
			cout << cur2 << ' ';
			cur2--;
		}else {
			cout << cur1<<' ';
			cur1++;
		}
		mv++;
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
