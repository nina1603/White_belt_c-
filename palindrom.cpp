int Factorial(int n) {
    if (n < 0) {
        return 1;
    }
    else {
        int res = 1;
        while (n > 1) {
            res *= n;
            n--;
        }
        return res;
    }
}

bool IsPalindrom(string s) {
    int i = 0;
    bool res = 1;
    for (i = 0; i <= s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            res = 0;
        }
    }
    return res;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    size_t i = 0;
    vector<string> res;
    for (i = 0; i < words.size(); i++) {
        if ((words[i].size() >= minLength) && (IsPalindrom(words[i]) == 1)) {
            res.push_back(words[i]);
        }
    }
    return res;
}

