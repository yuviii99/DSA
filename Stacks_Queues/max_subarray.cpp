#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSubArrayK(vector<int> a, int k){
    deque<int> Q(k);
    int i=0;
    // for first k elements
    for(int i=0;i<k;i++){
        while(!Q.empty() and a[i] >= a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    // for rest of the elements
    for(i=k;i<a.size();i++){
        cout << a[Q.front()] << " ";

        while(!Q.empty() and Q.front() <= i-k){
            Q.pop_front();
        }
        while(!Q.empty() and a[i] >= a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
}

int main(){
    vector<int> arr = {1,2,3,1,4,5,2,3,5};
    int k=3;

    maxSubArrayK(arr,k);
    return 0;
}