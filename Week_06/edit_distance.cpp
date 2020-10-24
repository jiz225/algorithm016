class Solution {
public:
    // i != j D[i][j] = min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]) + 1
    // i == j D[i][j] = min(D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1][j - 1])
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<int> chars(l2 + 1);
        for (int j = 1; j <= l2; j++) {
            chars[j] = j;
        }
        vector<int> chars_i(l2 + 1);
        for (int i = 1; i <= l1; i++) {
            chars_i[0] = i;
            for (int j = 1; j <= l2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    chars_i[j] = min(chars[j-1], min(chars_i[j-1]+1, chars[j]+1));
                }
                else {
                    chars_i[j] = min(chars[j-1], min(chars_i[j-1], chars[j])) + 1;
                }
            }
            chars = chars_i;
        }
        return chars[l2];
    }
};
