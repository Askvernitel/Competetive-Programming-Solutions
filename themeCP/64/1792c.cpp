#include <bits/stdc++.h>


using namespace std;
int a[200001];

int n;
int f(int x){ 
	int prev = x-1;
	int can = 1;
	for(int i =0;i<n;i++){
		if(a[i] >= x && a[i] <= n-x+1){ 
			if(prev+1 == a[i]){ 
				prev++;
			}else{
				can =0;
				break;
			}
		}
	}
//	if(prev == n-x+1) return can;
//	else can = 0;
	return can;
}
void solve(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	map<int,int> m;
	for(int i =0;i<n;i++){
		m[a[i]]=i;
	}
	
	int l=-1, r=n+1;

	while(r-l>1){
		int mid = (l+r)/2;
		if(f(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
//	int p = n/2;
	cout << r-1 << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
