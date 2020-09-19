class Solution {
public:
    static bool greater(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freqk;
        unordered_map<int,int> freq;
        for (int num: nums) {
            freq[num] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&greater)> cmpfreq(greater);
        for (auto& p: freq) {
            if (cmpfreq.size() < k) {
                cmpfreq.push(make_pair(p.first,p.second));
            }
            else {
                if (cmpfreq.top().second < p.second) {
                    cmpfreq.pop();
                    cmpfreq.push(make_pair(p.first,p.second));
                }
            }
            
        }

        for (int i = 0; i < k; i++) {
            freqk.push_back(cmpfreq.top().first);
            cmpfreq.pop();
        }
        return freqk;
    }
};
