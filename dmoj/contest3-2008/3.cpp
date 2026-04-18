#include <bits/stdc++.h>

using namespace std;

int const n =9;
int grid[n][n];
set<int> not_allowed[n][n];
set<int> not_allowed_boxes[3][3];
int check_and_add(int r, int c){  
	int startr = r*3, startc=c*3;
	for(int i = 1;i<=9;i++){
	
		int cnt = 0, p = 0, u =0;
		for(int k = startr;k<startr+3;k++){
			for(int v = startc;v<startc+3;v++){
				if(grid[k][v] == 0 && not_allowed[k][v].find(i) == not_allowed[k][v].end()){
					cnt++;
					p = k; u = v;
				}
			}
		}
		if(cnt == 1 && not_allowed_boxes[r][c].find(i) == not_allowed_boxes[r][c].end()){
			grid[p][u] = i;	
			not_allowed_boxes[r][c].insert(i);		
				for(int k = 0 ;k<n;k++){
					not_allowed[p][k].insert(grid[p][u]);
				}
				for(int k =0;k<n;k++){
					not_allowed[k][u].insert(grid[p][u]);
				}
		
		}
		if(cnt==0 && not_allowed_boxes[r][c].find(i) == not_allowed_boxes[r][c].end()){
			return -1;
		}
		
	
	}
	return 0;
}
int main(){

	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			char ch; cin >> ch;
			if(ch == '.') grid[i][j] = 0;
			else {
				grid[i][j] = ch - '0';
				for(int k = 0 ;k<n;k++){
					not_allowed[i][k].insert(grid[i][j]);
				}
				for(int k =0;k<n;k++){
					not_allowed[k][j].insert(grid[i][j]);
				}
				not_allowed_boxes[i/3][j/3].insert(grid[i][j]);
			}
		}
	}
	int pos = 1;
	for(int t = 0;t<9;t++){
	for(int i =0;i<3;i++){
		for(int j =0;j<3;j++){
			if(check_and_add(i,j) == -1) pos = 0;
		}
	}
	}
	if(!pos) cout << "ERROR";
	else{
		for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				if(grid[i][j] == 0){
					cout << ".";
				}else{
					cout << grid[i][j];
				}
				
			}
			cout << endl;
		}
	}


	



}
