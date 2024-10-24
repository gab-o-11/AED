#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    void go(set<string>& so_far, string const& current, int index, int& result, string const& s) {
        if (index >= s.size()) {
            if (so_far.find(current) != so_far.end())
                return;
            result++;
            return;
        }

        // continuar la cadena actual
        string t = current;
        t.push_back(s[index]);
        go(so_far, t, index + 1, result, s);

        // empezar una nueva cadena
        if (so_far.find(current) != so_far.end())
            return;
        so_far.insert(current);
        go(so_far, "", index + 1, result, s);
        so_far.erase(current);
    }

    int maxUniqueSplit(string s) {
        set<string> so_far;
        int result = 0;
        go(so_far, "", 0, result, s);
        return result;
    }
};
