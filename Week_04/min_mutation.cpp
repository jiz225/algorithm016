class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int num = -1;
        unordered_set<string> genes;
        genes.insert(bank.begin(), bank.end());
        if (genes.find(end) == genes.end()) {
            return num;
        }
        // level-order: use double end hashset
        num ++;
        vector<char> ncs{'A','C','G','T'};
        unordered_set<string> head, tail, *headptr, *tailptr;
        head.insert(start);
        tail.insert(end);

        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                tailptr = &head;
                headptr = &tail;
            }
            else {
                headptr = &head;
                tailptr = &tail;
            }
            unordered_set<string> candidates;
            num ++;
            for (auto it = headptr->begin(); it != headptr->end(); ++it) {
                string child = *it;
                for (int i = 0; i < child.length(); i++) {
                    char nci = child[i];
                    for (char nc: ncs) {
                        if (nc != nci) {
                            child[i] = nc;
                        }
                        if (tailptr->find(child) != tailptr->end()) {
                            return num;
                        }
                        if (genes.find(child) != genes.end()) {
                            candidates.insert(child);
                            genes.erase(child);
                        }
                    }
                    child[i] = nci;
                }
            }
            headptr->swap(candidates);
        }
        return -1;
    }
};
