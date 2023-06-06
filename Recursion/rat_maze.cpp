#include<iostream>
#include<vector>
using namespace std;

bool isSafetoMove(int x,int y,int maze[3][3],int visited[3][3]){
    if((x>=0&&x<3)&&(y>=0&&y<3)&&maze[x][y]==1&&visited[x][y]==0){
        return true;
    }
    else{
        return false;
    }
}
void solve(int maze[3][3],vector<string> &ans,int x,int y,int visited[3][3],string path){
    //base 
    if(x==2 && y==2){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    // Down Left Right Up
    //FOR DOWN MOVE
    int newx=x+1;
    int newy=y;
    if(isSafetoMove(newx,newy,maze,visited)){
        path.push_back('D');
        solve(maze,ans,newx,newy,visited,path);
        path.pop_back();
    }

     //FOR left MOVE
    newx=x;
    newy=y-1;
    if(isSafetoMove(newx,newy,maze,visited)){
        path.push_back('L');
        solve(maze,ans,newx,newy,visited,path);
        path.pop_back();
    }

     //FOR right MOVE
     newx=x;
     newy=y+1;
    if(isSafetoMove(newx,newy,maze,visited)){
        path.push_back('R');
        solve(maze,ans,newx,newy,visited,path);
        path.pop_back();
    }

     //FOR Up MOVE
     newx=x-1;
     newy=y;
    if(isSafetoMove(newx,newy,maze,visited)){
        path.push_back('U');
        solve(maze,ans,newx,newy,visited,path);
        path.pop_back();
    }
    visited[x][y]=0;
}

int main(){
    int maze[3][3];
    maze[0][0]=1;
    maze[0][1]=0;
    maze[0][2]=0;
    maze[1][0]=1;;
    maze[1][1]=0;
    maze[1][2]=0;
    maze[2][0]=1;
    maze[2][1]=1;
    maze[2][2]=1;
    //maze matrix
     for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<maze[i][j]<<" ";
    }
    cout<<endl;
   }
    //create a visited matrix
   int visited[3][3];
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        visited[i][j]=0;
    }
   }
    vector<string> ans;
    int srcx=0;
    int srcy=0;
    string path="";
    solve(maze,ans,srcx,srcy,visited,path);
    for(const string &s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}