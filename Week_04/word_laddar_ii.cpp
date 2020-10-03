class Solution {
public:
    vector<string> wordsidx;
    vector<vector<int>> edges;
    vector<vector<string>> allpath;
    bool oneDiff(const string& w1, const string& w2) {
        int numDiff = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                numDiff ++;
            }
            if (numDiff > 1) {
                return false;
            }
        }
        if (numDiff == 0) {
            return false;
        }
        return true;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> words;
        for (int i = 0; i < wordList.size(); i++) {
            if (words.find(wordList[i]) == words.end()) {
                words[wordList[i]] = i;
                wordsidx.push_back(wordList[i]);
            }
        }
        if (words.find(endWord) == words.end()) {
            return allpath;
        }

        if (words.find(beginWord) == words.end()) {
            words[beginWord] = wordList.size();
            wordsidx.push_back(beginWord);
        }

        vector<int> depth;
        edges.resize(wordsidx.size());
        for (int i = 0; i < wordsidx.size(); i++) {
            for (int j = i + 1; j < wordsidx.size(); j++) {
                if (oneDiff(wordsidx[i], wordsidx[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
            depth.push_back(wordsidx.size());
        }
        queue<vector<int>> q;
        q.push(vector<int>{words[beginWord]});
        depth[words[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int idx = curr.back();
            if (idx == words[endWord]) {
                vector<string> path;
                for (int index : curr) {
                    path.push_back(wordsidx[index]);
                }
                allpath.push_back(path);
            } 
            else {
                for (int i = 0; i < edges[idx].size(); i++) {
                    int next_idx = edges[idx][i];
                    if (depth[idx] + 1 <= depth[next_idx]) {
                        depth[next_idx] = depth[idx] + 1;
                        vector<int> children = curr;
                        children.push_back(next_idx);
                        q.push(children);
                    }
                }
            }
        }
        return allpath;
    }
};
