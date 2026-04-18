#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int c[n];

	for(int i =0;i<n;i++){
		cin >> c[i];
	}
	
	sort(c, c+n);

	bool pos = 1;
	if(c[0] != 1)pos=0;
	
	for(int i =1;i<n;i++){
		int cur = c[i];
		for(int j=i-1;j>=0;j--){
			if(c[j] <= cur) cur-=c[j];
		}
		if(cur != 0){
			pos = 0;
			break;
		}

	}

	
	if(pos){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
