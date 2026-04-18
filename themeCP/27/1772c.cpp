#include <bits/stdc++.h>

using namespace std;
void solve(){
	int k, n;
	cin >> k >> n;
	int p = n-k;
	int cur = 0;
	int cnt = 0;
	for(int i =1;cnt<k;i+=((p-cur >= 0)?cur+1:1)){
		cout << i << " ";
		if(p-cur >= 0){
			p-=cur;
			cur++;
		}
		cnt++;
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
