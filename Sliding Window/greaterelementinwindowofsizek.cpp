//Greater element in each window of size k
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> solution(int *arr,int n,int k){
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push({arr[i],i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<n;i++){
        pq.push({arr[i],i});
        while(i-pq.top().second>=k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}
void print(int *arr,int n){
    cout<<"Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
    vector<int> ans=solution(arr,n,2);
    cout<<"Solution : "<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}