// यो न हृष्यति न द्वेष्टि न शोचति न काङ्‍क्षति। शुभाशुभपरित्यागी भक्तिमान्यः स मे प्रियः॥
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<bitset>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
#include<iomanip>
#define f               first
#define s              second
#define int               long long
#define ll               long long
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define mii              unordered_map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue< int,vi,greater<int> >
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e10
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr,n,type)   type *arr=new type[n];
#define w(x)             int x; cin>>x; while(x--)
#define me(i,start,end)  for(int i=start;i<end;i++)
#define he(i,end,start) for(int i=end-1;i>=start;i--)
#define all(v)         v.begin(),v.end()

using namespace std;
ll pf[10000001];

// Tanya Rajhans
class Solution {
public:
    
    struct Node{
        Node* arr[2];
        int val;
    };
    
    Node* root=new Node();
    
    void insert(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            bool bitVal=n & (1<<i);
            if(temp->arr[bitVal]==NULL){
               Node* newNode = new Node();
               temp->arr[bitVal]=newNode; 
            }
            temp=temp->arr[bitVal];
        }
        temp->val=n;
    }
    
    int findMaxXor(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            bool bitVal=n & (1<<i);
            if(temp->arr[!bitVal]!=NULL)
                temp=temp->arr[!bitVal]; 
            else if(temp->arr[bitVal]!=NULL)
                temp=temp->arr[bitVal];
            else
                return INT_MIN;
        }
        return n^temp->val;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Node* temp=root;
        int maxXor=INT_MIN;
        int n=nums.size();
        if(n<2)
            return 0;
        insert(nums[0]);
        for(int i=1;i<n;i++){
            maxXor=max(maxXor, findMaxXor(nums[i]));
            insert(nums[i]);
        }
        return maxXor;
    }
};
