# include <iostream>
# include <vector>
using namespace std;

void merge(vector<int>&nums,int low,int mid,int high,int &c)
    {
        int i=low;
        int j=mid+1;
        
        vector<int>temp(high-low+1);
        
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*1ll*nums[j])
            {
                c+=(mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
        i=low;
        j=mid+1;
        int k=0;
        while(i<=mid and j<=high)
        {
            if(nums[i]<nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid)
            temp[k++]=nums[i++];
        while(j<=high)
            temp[k++]=nums[j++];
        
        for(i=low;i<=high;i++)
            nums[i]=temp[i-low];
        //sort(nums.begin()+low,nums.begin()+high+1);
    }

void mergeSort(vector<int>&nums,int low,int high,int &c)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid,c);
            mergeSort(nums,mid+1,high,c);
            
            merge(nums,low,mid,high,c);
        }
    }

int main(){

    vector<int> nums={1,3,2,3,1};
    int n=nums.size();
    int c=0;
    mergeSort(nums,0,n-1,c);
    cout<<c;

    return 0;
}