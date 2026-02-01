// writen by mmd
#include <iostream>
using namespace std;

bool solve(string s3, string s1, string s2, int index, int i, int j) {
    if (index >= s3.size()) return true;

    if(i < s1.size() && s3[index] == s1[i] && solve(s3, s1, s2, index+1, i+1, j))
        return true;
    if(j < s2.size() && s3[index] == s2[j] && solve(s3, s1, s2, index+1, i, j+1))
        return true;
    
    return false;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if (s1.size() + s2.size() != s3.size()) {
        cout << "false";
        return 0;
    }

    cout << ((solve(s3, s1, s2, 0, 0, 0))? "true":"false");
    return 0;
}