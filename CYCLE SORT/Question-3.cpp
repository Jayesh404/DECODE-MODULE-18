# include <iostream>
# include <vector>
using namespace std;

bool contains(vector<int>& v,int k){
    for(int i=0;i<v.size();i++ ){
        if(v[i]==k) return false;
    }
    return true;
}

int main(){

    vector<int> nums={4,3,2,7,8,2,3,1};
    int n=nums.size();
    vector<int> ans;
    int i=0;
    while(i<n){
        int correctIdx=nums[i]-1;
        if(i==correctIdx) i++;
        else if(i!=correctIdx && nums[i]==nums[correctIdx]){
            if(ans.empty()) ans.push_back(nums[i]);
            if(contains(ans,nums[i])) ans.push_back(nums[i]);
            i++;
        }
        else swap(nums[i],nums[correctIdx]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}