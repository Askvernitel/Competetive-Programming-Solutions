#include <bits/stdc++.h>

using namespace std;
int nextsqr(int x){ 
	
	int p = sqrt(x) + 1;
	return p*p;
}
int prevsqr(int x){ 
	
	int p = sqrt(x) -1;
	return p*p;
}


void solve(){
	int n;
	cin >> n;
	int arr[n], occ[n];
	memset(occ, 0,sizeof(occ));
	int pos = 1;	
	map<int, int> m;	
	for(int j =1;j<=n;j++){
		for(int i =0;i<n;i++){
			int cnt = 0;
			int k;
			if(sqrt(i) == (int)sqrt(i)) k = i;
			else k = nextsqr(i);
			while(k-i < n){ 
				cnt++;
				k=nextsqr(k);
			}
			if(cnt == j){
				int found = 0;
				if(sqrt(i) == (int)sqrt(i)) k = i;
				else k = nextsqr(i);
				while(k-i < n){ 
					if(!occ[k-i]){
						found = 1;
						arr[k-i] = i;
						occ[k-i] = 1;
						break;
					}
					k=nextsqr(k);
				}
				if(!found){cout << i << " " << k << '\n'; pos =0;}
			}
//			if(cnt == 0) {cout <<"HERE";pos = 0;}
			
		}
		if(!pos) break;
	}	
	for(int i =0;i<n;i++){
		cout << arr[i] << " ";
	}
	if(!pos){

		cout << -1 << '\n';
		return;
	}

	for(int i =0;i<n;i++){
		cout << arr[i] << " ";
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
