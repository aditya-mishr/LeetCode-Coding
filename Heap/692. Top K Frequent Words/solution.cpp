bool compare(pair<string,int> p1,pair<string,int> p2)
{
    if(p1.second>p2.second)
        return true;
    else if(p1.second==p2.second)
        return p1.first<p2.first;
    else 
        return false;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> dic;
        map<string,int>::iterator it;
        vector<pair<string,int>> vec;
        vector<string> result;
        for(int i=0;i<words.size();i++)
        {
            if(dic.find(words[i])!=dic.end())
            {
                dic[words[i]]+=1;
            }
            else
            {
                dic.insert(make_pair(words[i],1));
            }
        }
        for(it=dic.begin();it!=dic.end();it++)
        {
            vec.push_back(*it);
        }
        sort(vec.begin(),vec.end(),compare);
        int i=0; 
        while(k>0)
        {
            result.push_back(vec[i].first);
            i++;
            k--;
        }
        return result;
    }
};