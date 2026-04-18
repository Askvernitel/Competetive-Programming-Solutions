#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
    

#define MAX_N  10000
#define MAX_M  10000

int n, m;
char grid[MAX_N][MAX_M];
vector<pair<pair<int,int>, pair<int,int>>> connectAllPoints(vector<pair<int,int>>& points){
   vector<pair<pair<int,int>,pair<int,int>>> lines;
    for(int i =0;i<points.size(); i++){
        pair<int,int> curPoint = points[i];
        for(int j = 0;j<points.size();j++){
            if(i == j) continue;
            if(curPoint.X != points[j].X && curPoint.Y != points[j].Y) continue;
            
            lines.push_back({curPoint,points[j]});

        }
    }
    return lines;
}

void draw(int from, int to, int col, int row){ 
    if(row == -1){
        for(int i = from+1; i <=to-1;i++){
            if(grid[i][col]=='x') continue;
            grid[i][col] = '-';
        }
    }else if(col == -1){
        for(int i = from+1; i <=to-1;i++){
            if(grid[row][i]=='x') continue;
            grid[row][i] = '-';
        }
    }
}

void drawLines(vector<pair<pair<int,int>, pair<int,int>>>& lines){
    //x means first // y means second
    for(pair<pair<int,int>,pair<int,int>> line:lines){
        if(line.first.X == line.second.X){ 
            draw(line.first.Y, line.second.Y, -1, line.first.X);
        }else if(line.first.Y == line.second.Y){ 
            draw(line.first.X, line.second.X, line.first.Y, -1);
        }
    }
}
void printGrid(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
int main(){
    cin >> n >> m;
    vector<pair<int,int>> points;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'x'){
                points.push_back({i,j});
            }
        }
    }

    auto lines = connectAllPoints(points);
    drawLines(lines);
    printGrid();
    

}
