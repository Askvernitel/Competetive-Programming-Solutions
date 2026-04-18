#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	
	int f,s, d;
	cin >> f >> s >> d;
	if(f > s){ 
		swap(f, s);
	}

	if(f <= d && s >= d){ 
		cout << max(1,(s-f)/2) << '\n';
		return;
	}

	if(s < d){ 
		cout << n-s << '\n';
		return;
	}
	if(f > d){ 
		cout << f-1 << '\n';
		return;
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
