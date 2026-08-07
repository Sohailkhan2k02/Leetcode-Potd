class Solution {
public:
    // Prime contribution of each digit
    vector<int> two  = {0,0,1,0,2,0,1,0,3,0};
    vector<int> three= {0,0,0,1,0,0,1,0,0,2};
    vector<int> five = {0,0,0,0,0,1,0,0,0,0};
    vector<int> seven= {0,0,0,0,0,0,0,1,0,0};

    // Minimum digits required
    int minLen(long long a,long long b,long long c,long long d){
        a=max(0LL,a);
        b=max(0LL,b);
        c=max(0LL,c);
        d=max(0LL,d);

        int ans=d+c;

        ans+=a/3;
        a%=3;

        ans+=b/2;
        b%=2;

        if(a==2 && b==1) ans+=2;
        else if(a>0 || b>0) ans++;

        return ans;
    }

    bool possible(long long a,long long b,long long c,long long d,int rem){
        return minLen(a,b,c,d)<=rem;
    }

    string makeSuffix(long long a,long long b,long long c,long long d,int len){

        a=max(0LL,a);
        b=max(0LL,b);
        c=max(0LL,c);
        d=max(0LL,d);

        string s;

        while(d--){
            s+='7';
        }

        while(c--){
            s+='5';
        }

        int eight=a/3;
        a%=3;

        int nine=b/2;
        b%=2;

        if(a==2 && b==1){
            s+="26";
            a=0;
            b=0;
        }
        else if(a==1 && b==1){
            s+='6';
            a=0;
            b=0;
        }
        else if(a==2){
            s+='4';
            a=0;
        }
        else if(a==1){
            s+='2';
            a=0;
        }
        else if(b==1){
            s+='3';
            b=0;
        }

        while(nine--){
            s+='9';
        }

        while(eight--){
            s+='8';
        }

        while((int)s.size()<len){
            s+='1';
        }

        sort(s.begin(),s.end());
        return s;
    }

    string smallestNumber(string num, long long t) {

        long long need2=0,need3=0,need5=0,need7=0;

        while(t%2==0){
            need2++;
            t/=2;
        }

        while(t%3==0){
            need3++;
            t/=3;
        }

        while(t%5==0){
            need5++;
            t/=5;
        }

        while(t%7==0){
            need7++;
            t/=7;
        }

        if(t>1) return "-1";

        int n=num.size();

        vector<long long> p2(n+1,need2);
        vector<long long> p3(n+1,need3);
        vector<long long> p5(n+1,need5);
        vector<long long> p7(n+1,need7);

        int zeroPos=-1;

        for(int i=0;i<n;i++){

            int d=num[i]-'0';

            if(d==0){
                zeroPos=i;
                break;
            }

            p2[i+1]=p2[i]-two[d];
            p3[i+1]=p3[i]-three[d];
            p5[i+1]=p5[i]-five[d];
            p7[i+1]=p7[i]-seven[d];
        }

        if(zeroPos==-1 && possible(p2[n],p3[n],p5[n],p7[n],0))
            return num;

        int last=(zeroPos==-1)?n-1:zeroPos;

        for(int i=last;i>=0;i--){

            for(int d=num[i]-'0'+1;d<=9;d++){

                long long a=p2[i]-two[d];
                long long b=p3[i]-three[d];
                long long c=p5[i]-five[d];
                long long e=p7[i]-seven[d];

                if(possible(a,b,c,e,n-1-i)){

                    return num.substr(0,i)
                           + char('0'+d)
                           + makeSuffix(a,b,c,e,n-1-i);
                }
            }
        }

        int len=max(n+1,minLen(need2,need3,need5,need7));

        return makeSuffix(need2,need3,need5,need7,len);
    }
};
