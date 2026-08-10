class Solution {
public:
    array<array<long long,4>,10> mp;

    Solution(){
        mp[1]={0,0,0,0}; mp[2]={1,0,0,0}; mp[3]={0,1,0,0};
        mp[4]={2,0,0,0}; mp[5]={0,0,1,0}; mp[6]={1,1,0,0};
        mp[7]={0,0,0,1}; mp[8]={3,0,0,0}; mp[9]={0,2,0,0};
        mp[0]={0,0,0,0};
    }

    bool factorize(long long t, array<long long,4>& need){
        int primes[4]={2,3,5,7};
        for(int i=0;i<4;i++)
            while(t % primes[i]==0){ need[i]++; t/=primes[i]; }
        return t==1;
    }
    vector<int> coverDigits(array<long long,4> need){
        vector<int> digits;
        while(need[0]>=3){ digits.push_back(8); need[0]-=3; }
        while(need[1]>=2){ digits.push_back(9); need[1]-=2; }
        while(need[2]>0){ digits.push_back(5); need[2]--; }
        while(need[3]>0){ digits.push_back(7); need[3]--; }
        if(need[1]==1 && need[0]>=1){ digits.push_back(6); need[0]--; need[1]--; }
        if(need[1]==1){ digits.push_back(3); need[1]--; }
        if(need[0]==2){ digits.push_back(4); need[0]=0; }
        else if(need[0]==1){ digits.push_back(2); need[0]=0; }
        return digits;
    }

    long long minDigits(array<long long,4> need){ return (long long)coverDigits(need).size(); }

    string buildSuffix(array<long long,4> need, long long length){
        vector<int> digits = coverDigits(need);
        while((long long)digits.size() < length) digits.push_back(1);
        sort(digits.begin(), digits.end());
        string s; s.reserve(digits.size());
        for(int d: digits) s.push_back(char('0'+d));
        return s;
    }

    string smallestNumber(string num, long long t) {
        array<long long,4> req = {0,0,0,0};
        if(!factorize(t, req)) return "-1";
        int n = (int)num.size();

        if (num.find('0') == string::npos) {
            array<long long,4> have = {0,0,0,0};
            for (char c : num) { auto &v = mp[c-'0']; for (int k=0;k<4;k++) have[k]+=v[k]; }
            bool ok = true;
            for (int k=0;k<4;k++) if (have[k] < req[k]) { ok=false; break; }
            if (ok) return num;
        }

        int z = n;
        for (int i=0;i<n;i++) if (num[i]=='0') { z=i; break; }

        vector<array<long long,4>> pref(z+1);
        pref[0] = {0,0,0,0};
        for (int i=0;i<z;i++){
            pref[i+1]=pref[i];
            auto &v = mp[num[i]-'0'];
            for (int k=0;k<4;k++) pref[i+1][k]+=v[k];
        }

        int maxPivot = min(z, n-1);
        for (int p = maxPivot; p >= 0; p--) {
            int curDigit = num[p]-'0';
            for (int nd = curDigit+1; nd <= 9; nd++) {
                array<long long,4> have = pref[p];
                auto &v = mp[nd];
                for (int k=0;k<4;k++) have[k]+=v[k];
                array<long long,4> need;
                for (int k=0;k<4;k++) need[k] = max(0LL, req[k]-have[k]);
                long long rem = n - p - 1;
                if (minDigits(need) > rem) continue;

                string ans = num.substr(0, p);
                ans.push_back(char('0'+nd));
                ans += buildSuffix(need, rem);
                return ans;
            }
        }

        long long L = max((long long)n + 1, minDigits(req));
        return buildSuffix(req, L);
    }
};