#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int changesLeft(int changeX, int changeY);
int sum = 0;
vector<string> canvas{};
int canvasSize, updates, newCanvasSize;

int main(){
    cin >> canvasSize >> updates;

    for (int i{}; i<canvasSize; i++){
        string line;
        cin >> line;
        canvas.push_back(line);
    }
    newCanvasSize = canvasSize-1;
    for (int i{}; i<canvasSize/2; i++){
        for(int j{}; j<canvasSize/2; j++){
            int same{};
            if(canvas[i][j]=='.'){
                same++;
            }
            if(canvas[newCanvasSize-i][j]=='.'){
                same++;
            }
            if(canvas[i][newCanvasSize-j]=='.'){
                same++;
            }
            if(canvas[newCanvasSize-i][newCanvasSize-j]=='.'){
                same++;
            }
            if (same==4){
                continue;
            }else if (same%2==1){
                sum++;
            }else{
                sum+=same;
            }
        }
    }
    
    cout<<sum<<'\n';

    for (int i{}; i<updates; i++){
        int changeX, changeY;
        cin >> changeX >> changeY;
        changeX--, changeY--;
        
        int in = changesLeft(changeX, changeY);

        if(canvas[changeX][changeY]=='#'){
            canvas[changeX][changeY]='.';
        }else{
            canvas[changeX][changeY]='#';
        }
        
        int out = changesLeft(changeX, changeY);
        sum = sum-in+out;
        cout<<sum<<'\n';
    }

}
int changesLeft(int k, int l){
    int same{};
    int i = min(newCanvasSize-k, k);
    int j = min(newCanvasSize-l, l);

    if(canvas[i][j]=='.'){
        same++;
    }
    if(canvas[newCanvasSize-i][j]=='.'){
        same++;
    }
    if(canvas[i][newCanvasSize-j]=='.'){
        same++;
    }
    if(canvas[newCanvasSize-i][newCanvasSize-j]=='.'){
        same++;
    }
    return min(abs(same-4), same);
}