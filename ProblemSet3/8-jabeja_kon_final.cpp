// writen by mmd
#include <iostream>
using namespace std;

#define ll long long

int count_bin_one(ll n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void mergeSort(string &s, int left, int right);

bool prev_permutation(string &s) {
    int n = s.size();

    int i = n - 2;
    while (i >= 0 && s[i] <= s[i + 1]) i--;
    if (i < 0) return false;

    int j = n - 1;
    while (s[j] >= s[i]) j--;

    swap(s[i], s[j]);

    // reverse
    int l = i + 1, r = n - 1;
    while (l < r) swap(s[l++], s[r--]);
    return true;
}

int main()
{
    ll n; cin >> n;
    string num = to_string(n);
    mergeSort(num, 0, num.size() - 1);

    int count = 0;
    do {
        if(isPrime(count_bin_one(stoll(num)))) {
            cout << num << endl;
            count++;
        }
    } while(prev_permutation(num));

    if(count == 0) cout << "Not Found!" << endl;
    return 0;
}


void merge(string &s, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L = "", R = "";
    for(int i=0; i<n1; i++) L += s[left + i];
    for(int i=0; i<n2; i++) R += s[mid + 1 + i];

    int i=0, j=0, k=left;

    while(i < n1 && j < n2) {
        if(L[i] >= R[j]) s[k++] = L[i++];
        else s[k++] = R[j++];
    }
    while(i < n1) s[k++] = L[i++];
    while(j < n2) s[k++] = R[j++];
}

void mergeSort(string &s, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(s, left, mid);
        mergeSort(s, mid+1, right);
        merge(s, left, mid, right);
    }
}
