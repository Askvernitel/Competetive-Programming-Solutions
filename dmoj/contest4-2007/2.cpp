#include <bits/stdc++.h>

using namespace std;
int a[8];
int main(){
	int n;
	cin >> n;
	int k = n, c = n;

	int t =0;
	while(c!=0){
		c/=10;
		t++;
	}
	int u = t-1;
	while(k != 0){
		a[u] = k%10;
		k/=10;
		u--;
	}
	int pos=0, x = -1;
	for(int i =t-2;i>=0;i--){
		int cur = 10, p = 0, k = -1;
		for(int j = t-1;j>=i+1;j--){
			if(a[i] < a[j]){
				p = 1;
				k=j;
				break;
			}
		}
		if(p){
			x = i+1;
			pos = 1;
			swap(a[i], a[k]);
			break;
		}
	}
	if(!pos){cout << 0; return 0;}
	sort(a+x, a+t);
	for(int i = 0;i<t;i++){
		cout << a[i];
	}
}
