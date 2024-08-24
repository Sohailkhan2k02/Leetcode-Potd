class Solution {
public:

    vector<int> getNextPalin(vector<int> nums){
        int n=nums.size();
        int solved=0;
        for(int i=(n+1)/2;i<n;i++){
            if(nums[i]<nums[n-1-i]){
                solved=1;
                for(int j=i;j<n;j++){
                    nums[j]=nums[n-1-j];
                }
                break;
            }
            else if(nums[i]>nums[n-1-i]) break;
        }
        if(solved){
            return nums;
        }
        int carry=1;
        for(int i=(n-1)/2;i>=0;i--){
            nums[i]+=carry;
            carry=nums[i]/10;
            nums[i]%=10;
            if(carry==0) break;
        }
        vector<int> v;
        if(carry==1){
            v.push_back(1);
        }
        for(int i=0;i<n;i++) v.push_back(nums[i]);
        // for(auto it:v) cout<<it<<",";
        // cout<<endl;
        n=v.size();
        for(int i=0;i<n/2;i++) v[n-1-i]=v[i];
        return v;
    }

    vector<int> getPrevPalin(vector<int> nums){
        int n=nums.size();
        int solved=0;
        for(int i=(n+1)/2;i<n;i++){
            if(nums[i]>nums[n-1-i]){
                solved=1;
                for(int j=i;j<n;j++){
                    nums[j]=nums[n-1-j];
                }
                break;
            }
            else if(nums[i]<nums[n-1-i]) break;
        }
        if(solved){
            return nums;
        }
        int borrow=1;
        for(int i=(n-1)/2;i>=0;i--){
            if(nums[i]==0){
                nums[i]=9;
                borrow=1;
            }
            else{
                nums[i]--;
                borrow=0;
                break;
            }
        }
        vector<int> v;
        int i=0;
        if(nums[i]==0) i++;
        for(;i<n;i++) v.push_back(nums[i]);
        // for(auto it:v) cout<<it<<",";
        // cout<<endl;
        n=v.size();
        for(int i=0;i<n/2;i++) v[n-1-i]=v[i];
        if(nums[0]==0 && n%2==1) v[n/2]=9;
        return v;
    }

    long long getDiff(vector<int> v1,vector<int> v2){
        int n1=v1.size(), n2=v2.size();
        int ind1=n1-1, ind2=n2-1;
        int borrow=0;
        string ans="";
        while(ind1>=0){
            int val1=v1[ind1];
            int val2=0;
            if(ind2>=0) val2=v2[ind2];
            int val=0;
            val1-=borrow;
            if(val1>=val2){
                borrow=0;
            }
            else{
                val1+=10;
                borrow=1;
            }
            val=val1-val2;
            ans=to_string(val)+ans;
            ind1--;
            ind2--;
        }
        long long fin = stoi(ans);
        return fin;
    }

    string getString(vector<int> v){
        string ans="";
        for(auto it:v){
            ans=to_string(it)+ans;
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        if(n.size()==1){
            int val=n[0]-'0';
            char ch = ((val-1)+'0');
            string ans = "";
            ans+=ch;
            return ans;
        }
        vector<int> v;
        for(auto ch:n){
            v.push_back(ch-'0');
        }
        vector<int> next = getNextPalin(v);
        // for(auto it:next) cout<<it;
        // cout<<endl;
        vector<int> prev = getPrevPalin(v);
        // for(auto it:prev) cout<<it;
        // cout<<endl;
        long long diff1 = getDiff(v,prev);
        long long diff2 = getDiff(next,v);
        // cout<<diff1<<"==="<<diff2<<endl;
        if(diff1<=diff2){
            return getString(prev);
        }
        return getString(next);
    }
};
