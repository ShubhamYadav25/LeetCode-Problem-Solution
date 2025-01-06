class Solution {
public:
    int countGoodSubstrings(string s) {
        
        // freq
        unordered_map<char, int> m;

        int i =0, j=0;
        int n = s.length();
        int sum =0;

        while(j < n){
            m[s[j]]++;
            cout<<s[j]<< " "<<m[s[j]]<<"\n";
           if(j-i+1 == 3){
                cout<<"-----------"<<m.size()<<"\n";
                            for(auto [a,b]: m)
{
    cout<<"In map "<<a<<" "<<b<<"\n";
} 
                if(m.size() == 3){
                    sum++;
                }
                
                    m[s[i]]--;
                    std::erase_if(m, [](const auto& pair) { return pair.second == 0; });
                    i++;
                
            }
            j++;
        }

    return sum;
    }
};