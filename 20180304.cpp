#include<iostream>
#include<vector>

struct point
{
    int x,
    int y
};

int count_XO(int x[3][3]){
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(x[i][j] == 1 || x[i][j] == 2)
                count++;
        }
    }
    return count;
}

vector<point> get_free(int x[3][3]){
    vector<point> result;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(x[i][j] == 0){
                point temp;
                temp.x = i;
                temp.y = j;
                result.push_back(temp);
            }
        }
    }
    return result;
}

void copy(int temp[3][3], int x[3][3]){
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp[i][j] = x[i][j];
        }
    }
}

bool X_win(int x[3][3]){//1 win
    if(x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 1){
        return true;
    }
    if(x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 1){
        return true;
    }
    if(x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 1){
        return true;
    }
    if(x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 1){
        return true;
    }
    if(x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 1){
        return true;
    }
    if(x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 1){
        return true;
    }
    if(x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 1){
        return true;
    }
    if(x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 1){
        return true;
    }
    return false;
}

bool O_win(int x[3][3]){//2 win
    if(x[0][0] == 2 && x[0][1] == 2 && x[0][2] == 2){
        return true;
    }
    if(x[1][0] == 2 && x[1][1] == 2 && x[1][2] == 2){
        return true;
    }
    if(x[2][0] == 2 && x[2][1] == 2 && x[2][2] == 2){
        return true;
    }
    if(x[0][0] == 2 && x[1][0] == 2 && x[2][0] == 2){
        return true;
    }
    if(x[0][1] == 2 && x[1][1] == 2 && x[2][1] == 2){
        return true;
    }
    if(x[0][2] == 2 && x[1][2] == 2 && x[2][2] == 2){
        return true;
    }
    if(x[0][0] == 2 && x[1][1] == 2 && x[2][2] == 2){
        return true;
    }
    if(x[0][2] == 2 && x[1][1] == 2 && x[2][0] == 2){
        return true;
    }
    return false;
}

int process(int x[3][3]){
    if(count(x) == 0)
        return 0;
    if(X_win(x))
        return 9-count_XO(x)+1;
    if(O_win(x))
        return -(9-count_XO(x)+1);
    int to_put = 0;
    if(count(x)%2 == 0)
        to_put = 1;
    else 
        to_put = 2;
    int max_reward = -4;
    point max_point;
    vector<point> free_points = get_free(x);
    for(int i=0; i<free_points.size(); i++){
        int temp[3][3];
        copy(temp, x);
        temp[free_points[i].x][free_points[i].y] = to_put;
        int next = process(temp);
        if(next > max_reward){
            max_reward = next;
            max_point = free_points[i];
        }
    }
    x[max_point.x][max_point.x] = to_put;
    return process(x);
}

int main(){
    int n;
    vector<int[3][3]> info;
    cin>>n;
    for(int i=0; i<n; i++){
        int x[3][3];
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                cin>>x[j][k];
        info.push_back(x);
    vector<int> res;
    }
    for(int i=0; i<n; i++){
        info.push_back(process(info[i]));
    }
    for(int i=0; i<n; i++){
        cout<<res[i]<<endl;
    }
    return 0;
}