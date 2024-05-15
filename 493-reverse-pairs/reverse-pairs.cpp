
class Solution {
    void merge(vector<int>&v,int start,int mid ,int end){
        int count=0;
        int left = start;
        int right = mid+1;
        vector<int>temp;

        while(left<=mid && right <= end){
            if(v[left]<=v[right]){
                temp.push_back(v[left]);
                left++;
            }
            else{
                temp.push_back(v[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(v[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(v[right]);
            right++;
        }

        for(int i =start;i<=end;i++){
            v[i] = temp[i-start];
        }
    }

    int count1(vector<int>&v,int start,int mid ,int end){
        long long int count=0;
        int right = mid+1;
        for(int i = start;i<=mid;i++){
            while(right<=end && v[i]>2*(long long)v[right]){
                right++;
            }
            count+=(right-(mid+1));
        }
        return count;
    }

    int mergesort(vector<int>&v,int start, int end){
        long long int count=0;
        if(start>=end) return count;
        int mid = start + (end - start)/2;
        count+=mergesort(v,start,mid);
        count+=mergesort(v,mid+1,end);
        count+=count1(v,start,mid,end);
        merge(v,start,mid,end);
        return count;
    }


public:
    int reversePairs(vector<int>& v) {
        long long int count = mergesort(v,0,v.size()-1);
        return count;
    }
};