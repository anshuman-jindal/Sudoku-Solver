#include <bits/stdc++.h>
using namespace std;

int grid[9][9]={{0}};
#define N 9
#define M 3

class Solution{
public:
    bool row[N][N+1]={{0}};
    bool col[N][N+1]={{0}};
    bool sq[M][M][N+1]={{{0}}};
    vector<pair<int, int>>zero;
    bool b=0;
    bool SolveSudoku(){
        cout<<"Initial Sudoku: \n";
        printGrid();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int x=grid[i][j];
                if(row[i][x]||col[j][x]||sq[i/M][j/M][x]){
                    cout<<"This Sudoku is not solvable\n";
                    return 0;
                }
                if(x!=0)row[i][x]=col[j][x]=sq[i/M][j/M][x]=1;
                else zero.push_back({i, j});
            }
        }
        if(zero.size()==0)return 1;
        solve(grid, 0);
        if(!b)cout<<"This Sudoku is not solvable\n";
        else{
            cout<<"Solution:\n";
            printGrid();
        }
        return b;
    }
    void solve(int grid[N][N], int ind){
        if(b)return;
        if(ind==zero.size()){
            b=1;
            return;
        }
        int x=zero[ind].first, y=zero[ind].second;
        for(int i=1; i<=N; i++){
            if(!row[x][i] && !col[y][i] && !sq[x/M][y/M][i]){
                grid[x][y]=i;
                row[x][i]=col[y][i]=sq[x/M][y/M][i]=1;
                solve(grid, ind+1);
                row[x][i]=col[y][i]=sq[x/M][y/M][i]=0;
                if(b)return;
            }
        }
    }
    void printGrid () {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    cout<<"Enter Sudoku. For empty squares, enter 0\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            string s;
            cin>>s;
            for(int i=0; i<s.size(); i++){
                if(s[i]<'0'||s[i]>'9'){
                    cout<<"Enter a valid number\n";
                    j--;
                    continue;
                }
            }
            if(stoi(s)>=0 && stoi(s)<=N)grid[i][j]=stoi(s);
            else{
                cout<<"Enter a valid number\n";
                j--;
                continue;
            }
        }
    }
    Solution S;
    S.SolveSudoku();
}