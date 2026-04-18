#include <bits/stdc++.h>


using namespace std;


void mrep(pair<int,int>& p, int c){ 
	if(p.first > c){ 
		return;
	}else if(p.first < c){
		p.first = c;
		p.second =1;
		return;
	}else{ 
		p.second++;
	}
}

void solve(){
	int n, m;

	cin >> n >> m;

	int a[n][m];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> a[i][j];
		}
	}
	map<int,pair<int,int>> r, c; 
	int maxv = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			mrep(r[i], a[i][j]);
			mrep(c[j], a[i][j]);
			maxv = max(a[i][j], maxv);
		}
	}
	int rused=0, cused=0;
	for(int i =0;i<n;i++){
		if(maxv==r[i].first && r[i].second > 1){ 
			r[i].first = 0;
			for(int j=0;j<m;j++){
				a[i][j]--;
			}
			c.clear();
			r.clear();
			for(int k =0;k<n;k++){
				for(int t =0;t<m;t++){
				mrep(r[k], a[k][t]);
				mrep(c[k], a[k][t]);
			}
			}

			rused = 1;
		}
	}
	for(int i=0;i<m;i++){
		if(maxv==c[i].first  && c[i].second > 1){
			c[i].first = 0;
			for(int j=0;j<n;j++){
				a[j][i]--;
			}
			c.clear();
			r.clear();
			for(int k =0;k<n;k++){
				for(int t =0;t<m;t++){
				mrep(r[k], a[k][t]);
				mrep(c[k], a[k][t]);
			}
			}

			cused = 1;
		}
	}
	int rm =0;
	for(int i =0;i<n;i++){
		int t = 0;
		for(int j=0;j<m;j++){
			t = max(t, a[i][j]);
		}
		if(t == maxv && !rused){ 
			t =0;
			for(int j=0;j<m;j++){
				t = max(t, a[i][j]-1); 
			}
			
			c.clear();
			r.clear();
			for(int k =0;k<n;k++){
				for(int p =0;p<m;p++){
				mrep(r[k], a[k][p]);
				mrep(c[k], a[k][p]);
			}
			}
			rused = 1;
		}
		rm = max(t, rm);
	}
	int cm = 0;
	for(int i =0;i<m;i++){
		int t = 0;
		for(int j=0;j<n;j++){
			t = max(t, a[j][i]);
		}
		if(t == maxv && !cused){ 
			t =0;
			for(int j=0;j<n;j++){
				t = max(t, a[j][i]-1); 
			}
			cused = 1;
		}
		cm = max(t,cm);
	}
	cout << max(cm ,rm) << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
