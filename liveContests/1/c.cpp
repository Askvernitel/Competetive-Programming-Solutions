#include <bits/stdc++.h>


#define RANGE(a, r, b) ((a) >= (r)) ? (0) : (b[a])
using namespace std;
void solve(){
	int n;
	cin >> n;
	

	vector<int> a;

	int s = 0;
	int x = n;
	int p = 0;
	while(x != 0){ 
		a.push_back(x%2);
		s++;
		x/=2;
		p++;
	}

	bool pos = 1;
	for(int i =0;i<p;i++){
		int l = 0, r=p-1+i;
		pos = 1;
		while(l <= r){
			if(l == r && a[l] == 1){ 
				cout << "NO\n";
				return;
			}
			int p1=RANGE(l, p, a);
			int p2=RANGE(r, p, a);
//			cout << p1 << " " << p2 << '\n';
			if(p1 != p2){
				pos = 0;
				break;
			}
			l++;
			r--;
		}
		if(pos) break;
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
