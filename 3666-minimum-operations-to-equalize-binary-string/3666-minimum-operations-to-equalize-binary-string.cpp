class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int start_z=0;
        for (char c:s) 
        {
            if (c=='0') start_z++;
        }
        if (start_z==0) return 0;
        if(k==1) return start_z;
        if(k%2==0&&start_z%2!=0) return -1;
        set<int> even, odd;
        for(int i=0;i<=n;i++)
        {
            if(i%2==0)
            even.insert(i);
            else odd.insert(i);
        }
        if(start_z%2==0)
        even.erase(start_z);
        else
        odd.erase(start_z);
        queue<pair<int, int>>q;
        q.push({start_z,0});
        vector<bool> visited(n+1,false);
        visited[start_z]=true;
        while(!q.empty()) 
        {
            auto [z,d]=q.front();
            q.pop();
            int min_i=max(0,k-(n-z));
            int max_i=min(k,z);
            int start_next=z+k-2*max_i;
            int end_next=z+k-2*min_i;
            if((z+k)%2==0)
            {
                auto it=even.lower_bound(start_next);
                while(it!=even.end()&&*it<=end_next)
                {
                    int next_z=*it;
                    it=even.erase(it);
                    if(next_z==0)
                    return d+1;
                    q.push({next_z,d+1});
                }
            }
            else
            {
                auto it=odd.lower_bound(start_next);
                while(it!=odd.end()&&*it<=end_next)
                {
                    int next_z=*it;
                    it=odd.erase(it);
                    if(next_z==0)
                    return d+1;
                    q.push({next_z,d+1});
                }
            }
        }
        return -1;
    }
};
                
            