#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	bool has = 0, pos = 1;
	bool hasnorm = 0;
	int prev = -1;
	for(int i = 0;i<n;i++){
		int v= a[i]%10;
		if(has && prev%10 == 0 && a[i] != prev && v!=5){
			pos = 0;
			break;
		}else if(has && prev%10 == 0 && v==5 && a[i]+v != prev){
			pos = 0;
			break;
		}else if(has && prev%10 == 5 && a[i] != prev && a[i]+v != prev +5 && a[i] != prev + 5){
			pos = 0;
			break;
		}
		if(v== 5 || v==0){
			if(hasnorm) pos = 0;
			has =1;
			prev=a[i];
		}else if(v%2){
			if(has) pos=0;
			hasnorm = 1;
			a[i]+=v;
		}else{
			hasnorm =1;
		}
	}
	if(!pos){ 
		cout << "NO\n";
		return;
	}
	if(has && pos){ 
		cout << "YES\n";
		return;
	}
	int maxv = 0;
	for(int i =0;i<n;i++){
		maxv = max(maxv,a[i]);
	}

	for(int i=0;i<n;i++){
		int v=maxv-a[i];
		int c=a[i];	
		int s = 0;
		int found = 0;
		int x = 0;
		while(x < 5){
			if(s == v || (v-s)%20 == 0){
				found = 1;
				break;
			}
			s+=c%10;
			c+=c%10;
			x++;
		}
		if((v-s)%20 == 0){ 
			found = 1;
		}
		if(found) continue;

		pos = 0;
		break;
	}
	if(pos){
		cout << "YES";
	}else{
		cout << "NO";
	}

	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

