#include <bits/stdc++.h>

using namespace std;
int cnt[5];
char grid[55][55];
int n,m;
void check_park(int r, int c){
	bool pos = 1;	
	int car = 0;
	for(int i=r;i<r+2;i++){
		for(int j=c;j<c+2;j++){
			if(grid[i][j] == '#') pos = 0;
			if(grid[i][j] == 'X') car++;
		}
	}
	if(pos){
		cnt[car]++;
	}

}
int main(){
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<m-1;j++){
			check_park(i, j);
		}
	}
	for(int i = 0;i<5;i++){
		cout << cnt[i] << '\n';
	}
}
