class Solution {
public:
    int mod=1e9+7;
    vector<int> seg;
    vector<int> seieve(){
        int n=1e5;
        vector<int> v(n+1,1);
        v[0]=0;v[1]=0;
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]==0)continue;
            for(int j=i*i;j<=(n);j+=i){
                v[j]=0;
            }   
        }
        return v;
    }
    void build(vector<int>& b, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = b[low];
            return;
        }
        int mid = (low + high)/ 2;
        build(b,2*idx+1,low,mid);
        build(b,2*idx+2,mid+1,high);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int tr(int idx, int low, int high, int qlow, int qhigh, int threshold) {
    if (low > qhigh || high < qlow || seg[idx]<threshold)return INT_MIN;
    if (low == high){
        return low;
        }
        
    int mid = (low + high) / 2;
    
  
    int leftResult = INT_MIN;
    if (mid+1 <= qhigh && seg[2*idx+2]>=threshold) { 
        leftResult = tr(2*idx+2, mid+1, high, qlow, qhigh, threshold);
    }
    
    if (leftResult != INT_MIN)
        return leftResult;
    
    return tr(2*idx+1, low, mid, qlow, qhigh, threshold);
    }
   
    int tr1(int idx, int low, int high, int qlow, int qhigh, int threshold) {
    if (low > qhigh || high < qlow || seg[idx] <threshold)
        return INT_MIN;
        
    if (low == high)
        return low;
        
    int mid = (low + high) / 2;
    
    int leftResult = INT_MIN;
    if (mid >= qlow && seg[2*idx+1]>=threshold) { 
        leftResult = tr1(2*idx+1, low, mid, qlow, qhigh, threshold);
    }
 
    if (leftResult != INT_MIN)
        return leftResult;

        return tr1(2*idx+2, mid+1, high, qlow, qhigh, threshold);
 
    }

    long long bin(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b&1){
                res=((res%mod)*(a%mod))%mod;
            }
            a=((a%mod)*(a%mod))%mod;
            b>>=1;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
       
        vector<int> v=seieve();

        seg.resize(4*n,INT_MAX);
        vector<int> yh;

        for(int i=0;i<n;i++){
            int gh=nums[i],kl=0;
            for(int j=1;j<=sqrt(gh);j++){
                if(gh%j!=0)continue;
                
                if(j==(gh/j)){
                    if(v[j]==1)kl++;
                }else{
                    if(v[j]==1)kl++;
                     if(v[gh/j]==1)kl++;
                }

            }
            yh.push_back(kl);
        }
       
        build(yh, 0, 0, n - 1);

        vector<vector<int>> vl;

        for(int i=0;i<nums.size();i++){ 
            int gh1=tr(0,0,n-1,0,i-1,yh[i]);
            gh1= (gh1==INT_MIN ) ? -1 : gh1;
          
            int gh=tr1(0,0,n-1,i,n-1,yh[i]+1);
            gh= (gh==INT_MIN) ? n : gh;

             vl.push_back({nums[i],i,gh1,gh});
        }
        sort(vl.rbegin(),vl.rend());

        long long ans=1;
        k*=1ll;
        for(int i=0;i<vl.size();i++){
            long long val=vl[i][0];
            long long idx=vl[i][1];
            
            long long tot=((idx-vl[i][2])*1ll)*((vl[i][3]-idx));
            if(tot<=k){
                ans=((ans%mod)*(bin(val,tot)%mod))%mod;
                k-=tot;
            }else{
                ans=((ans%mod)*(bin(val,k)%mod))%mod;
                k=0;
                break;
            }
        }
        return ans;
    }
};
