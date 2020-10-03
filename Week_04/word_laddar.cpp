class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int num = 0;
        unordered_set<string> words (wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return num;
        }
        num ++;
        unordered_set<string> head, tail, *headptr, *tailptr;
        head.insert(beginWord);
        tail.insert(endWord);

        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                headptr = &tail;
                tailptr = &head;
            }
            else {
                headptr = &head;
                tailptr = &tail;
            }
            unordered_set<string> candidates;
            num ++;
            for (auto it = headptr->begin(); it != headptr->end(); it++) {
                string word = *it;
                for (int i = 0; i < word.length(); i++) {
                    char ci = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (tailptr->find(word) != tailptr->end()) {
                            return num;
                        }
                        if (words.find(word) != words.end()) {
                            candidates.insert(word);
                            words.erase(word);
                        }
                    }
                    word[i] = ci;
                }
            }
            headptr->swap(candidates);
        }
        return 0;
    }
};
