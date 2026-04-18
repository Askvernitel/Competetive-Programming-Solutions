#include <bits/stdc++.h>


using namespace std;
int main(){
	int n ,k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int cnt =0;
	for(int i = 0;i<n;i++){
		set<int> npos={};
		for(int j=max(0,i-2);j<=min(n-1,i+2);j++){
			if(j == i) continue;
			npos.insert(a[j]);
		}
		npos.erase(0);
		if(npos.size() >= k || (npos.find(a[i]) != npos.end())){ 
			cout << "NO\n";
			return 0; 
		}
		if(a[i] == 0){
			int r = i;
			for(int t = i; t<n;t+=2){
				if(a[t] != 0){ 
					break;
				}
				r = t;
			}
			bool filled = 1;
			for(int v=i;v<=r;v+=2){
				set<int> npos1={};
				for(int j=max(0,v-2);j<=min(n-1,v+2);j++){
					if(j == v) continue;
					npos1.insert(a[j]);
				}
				int found = 0;
				for(int j =1;j<=k;j++){
				  if(npos1.find(j) == npos1.end()){
				    a[v] = j;
				    found =1;
				    break;
				  }
				}
				if(!found){
				  filled = 0;
				  break;
				}
			}
			if(!filled){ 
				for(int t = i; t<=r;t+=2){ 
					a[t] = 0;
				}
				for(int v=r;v>=i;v-=2){
					set<int> npos1={};
					for(int j=max(0,v-2);j<=min(n-1,v+2);j++){
						if(j == v) continue;
						npos1.insert(a[j]);
					}
					int found = 0;
					for(int j =1;j<=k;j++){
					  if(npos1.find(j) == npos1.end()){
					    a[v] = j;
					    found =1;
					    break;
					  }
					}
					if(!found){
					  cout << "NO\n";
					  return 0;
					}
				}
			}
		}
	}

	cout << "YES\n";
	for(int i =0;i<n;i++){
		cout << a[i] << " ";
	}

}
