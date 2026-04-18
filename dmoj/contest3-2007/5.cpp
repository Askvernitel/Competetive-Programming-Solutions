#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,s;

	cin >> a >> b >> s;

	int k = 0, z = b;
	int t[15];
	while(z != 0){
		t[k] = z%10; 
		z/=10;
		k++;
	}

	int f[k][s+1];
	f[0][0] = 1;
	memset(f, 0, sizeof(f));
	for(int i =0;i<k;i++){
		for(int v = 0;v<=s;v++){
			for(int j = 0;j<=9;j++){
				if(v+j<=s) f[i+1][v+j] += f[i][v];	
			}
		}
	}

	int res = 0;
	for(int i =0;i<k;i++){
		res += f[i][s];
	}

	cout << res;

}
