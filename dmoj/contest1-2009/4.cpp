#include <bits/stdc++.h>

using namespace std;
int ca[101], cb[101];
int main(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i =0;i<n;i++){
		cin >> a[i] >> b[i];	
	}
	for(int i= 0;i<n;i++){
		ca[a[i]]++; cb[b[i]]++;
		int lca[101], lcb[101];
		int ans = INT_MIN;
		int real_ans = INT_MAX;
		for(int k = 0;k<101;k++){
			lca[k]=ca[k];
		}
		for(int k = 0;k<101;k++){
			lcb[k]=cb[k];
		}
		int l=1, r = 100;
		while(l<101){
			while(lca[l] == 0 && l < 101) l++;
			if(l >= 101) break;
			while(r>=0){ 
				while(lcb[r] == 0 && r>=0) r--;
				if(r < 0) break;	
				ans = max(l + r, ans);
				if(lcb[r] > lca[l]){ 
					lcb[r]-=lca[l];	
					l++;
				}
				else if(lcb[r] < lca[l]){ 
					lca[l]-=lcb[r];
					r--;
				}else{ 
					l++;
					r--;
				}
				
			}
		}
		cout << ans << '\n';
	}
		
}
