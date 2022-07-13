#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stock_span(vector<int> v){
    vector<int> result;
    stack<int> s;
    s.push(0);
    result.push_back(1);

    for(int i=1;i<v.size();i++){
        int currentPrice = v[i];

        while(!s.empty() and v[s.top()] <=currentPrice){
            s.pop();
        }

        if(!s.empty()){
            result.push_back(i-s.top());
        }
        if(s.empty()){
            result.push_back(i+1);
        }
        s.push(i);
    }
    return result;
}

int main(){
    vector<int> arr {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stock_span(arr);
    for(int i:result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}