class Solution {
public:
    vector<int>getNSL(vector<int>&height){
        int n=height.size();
        stack<int>st; // TO STORE INDICES
        vector<int>left(n);
        left[0]=-1;
        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            else if(st.empty()){
                left[i]=-1; // WHICH IS THE OUT OF BOUND INDEX
            }
            st.push(i);
        }
        return left;
    }

    vector<int>getNSR(vector<int>&height){
        int n=height.size();
        stack<int>st; // TO STORE INDICES
        vector<int>right(n);
        right[n-1]=n;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            else if(st.empty()){
                right[i]=n; // WHICH IS THE OUT OF BOUND INDEX
            }
            st.push(i);
        }
        return right;
    }
    int findMaxArea(vector<int>&height){
        int n=height.size();
        // FOR AREA WE NEED WIDTH AND HEIGHT
        // WE HAVE ALREADY CALCULATED HEIGHT
        // NOW WE NEED ONLY WIDTH WHICH CAN BE CALCULATED
        // BY NSR AND NSL WHICH ARE STACK IMPLEMENTATION
        // WIDTH[I]=NSR[I]-NSL[I]-1;
        // SO WE WILL MAKE VECTORS WHICH STORES INDEXES 
        vector<int>NSR=getNSR(height);
        vector<int>NSL=getNSL(height);

        vector<int>width(n);

        for(int i=0; i<n; i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int maxi=0;
        for(int i=0; i<n; i++){
            int area=width[i]*height[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<int>height(m,0);

        // AND 2D MATRIX IS DIFFICULT SO WE MAKE IT 1D
        //BY ADDING HEIGHT IN 1ST ROW ONLY
        //NOW FOR THE REST OF THE ROW WE ADD THE HEIGHT AND FIND THE MAXAREA

        // WHY I=1 BECAUSE WE HAVE ALREADY TAKEN 1ST ROW NOW WE ARE JUST ADDING
        // HEIGHTS IN 1ST ROW MAKING IT 1D 
        /*
        [1, 0, 1, 0, 0]
        [1, 0, 1, 1, 1] =>  [2, 0, 2, 1, 1]
        [1, 1, 1, 1, 1] =>  [3, 1, 3, 2, 2]
        [1, 0, 0, 1, 0] ->  [3, 0, 0, 3, 0]
        */
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }
            maxi=max(maxi,findMaxArea(height));
        }
        return maxi;
    }
};
