// writen by mmd
#include <iostream>
#include <sstream>
using namespace std;

// #define ll long long

long long indexOf(long long *arr, long long n, long long value, long long start, long long end, long long current_index) {
    if (current_index > end) return -1;
    if (arr[current_index] == value) return current_index;

    return indexOf(arr, n, value, start, end, current_index+1);
}

void rightShift(long long *arr, long long n, long long count, long long start, long long end, long long current_index) {
    long long len = end - start + 1;
    if (len <= 0) return;
    count = min(count, len);
    if (count == 0) return;

    if (current_index < start) return;

    if (current_index < start + count)
        arr[current_index] = 0;
    else
        arr[current_index] = arr[current_index - count];

    rightShift(arr, n, count, start, end, current_index-1);
}

void leftShift(long long *arr, long long n, long long count, long long start, long long end, long long current_index) {
    long long len = end - start + 1;
    if (len <= 0) return;
    count = min(count, len);
    if (count == 0) return;

    if (current_index > end) return;

    if (current_index > end - count)
        arr[current_index] = 0;
    else
        arr[current_index] = arr[current_index + count];

    leftShift(arr, n, count, start, end, current_index+1);
}

void leftRotate(long long *arr, long long n, long long count, long long start, long long end) {
    long long len = end - start + 1;
    if (len <= 0) return;
    count %= len;
    if (count == 0) return;

    long long firsts[count];
    for (long long i = 0; i < count; i++)
        firsts[i] = arr[start+i];

    for (long long i = start; i <= end - count; i++)
        arr[i] = arr[i + count];

    for (long long i = 0; i < count; i++)
        arr[end - count + 1 + i] = firsts[i];
}

void rightRotate(long long *arr, long long n, long long count, long long start, long long end) {
    long long len = end - start + 1;
    if (len <= 0) return;
    count %= len;
    if (count == 0) return;

    long long lasts[count];
    for (long long i = 0; i < count; i++)
        lasts[i] = arr[end - count + 1 + i];

    for (long long i = end; i >= start + count; i--)
        arr[i] = arr[i - count];

    for (long long i = 0; i < count; i++)
        arr[start + i] = lasts[i];
}

void merge(long long *arr, long long l, long long mid, long long r, int mode) {
    long long n1 = mid - l + 1;
    long long n2 = r - mid;

    long long L[n1];
    long long R[n2];

    for (long long i = 0; i < n1; i++) L[i] = arr[l + i];
    for (long long i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    long long i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (mode == 1) { // ascending
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        } else { // descending
            if (L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(long long *arr, long long l, long long r, int mode) {
    if (l >= r) return;
    long long mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, mode);
    mergeSort(arr, mid + 1, r, mode);
    merge(arr, l, mid, r, mode);
}

void sortRange(long long *arr, long long n, int mode, long long start, long long end) {
    if (start < 0) start = 0;
    if (end >= n) end = n - 1;
    if (start >= end) return;

    mergeSort(arr, start, end, mode);
}

void input(long long *arr, long long size) {
    for (long long i = 0; i < size; i++)
        cin >> arr[i];
}

void print(long long *arr, long long size) {
    for (long long i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    long long n; 
    cin >> n;
    long long arr[n];
    input(arr, n);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "indexOf") {
            long long value, start = 0, end = n-1; 
            ss >> value;
            if (ss >> start) ss >> end;

            cout << indexOf(arr, n, value, start, end, start) << endl;
        }
        else if (cmd == "leftShift") {
            long long count, start = 0, end = n-1; 
            ss >> count;
            if (ss >> start) ss >> end;

            leftShift(arr, n, count, start, end, start);
            print(arr, n);
        }
        else if (cmd == "rightShift") {
            long long count, start = 0, end = n-1; 
            ss >> count;
            if (ss >> start) ss >> end;

            rightShift(arr, n, count, start, end, end);
            print(arr, n);
        }
        else if (cmd == "leftRotate") {
            long long count, start = 0, end = n-1; 
            ss >> count;
            if (ss >> start) ss >> end;

            leftRotate(arr, n, count, start, end);
            print(arr, n);
        }
        else if (cmd == "rightRotate") {
            long long count, start = 0, end = n-1; 
            ss >> count;
            if (ss >> start) ss >> end;

            rightRotate(arr, n, count, start, end);
            print(arr, n);
        }
        else if (cmd == "sort") {
            long long mode, start = 0, end = n-1; 
            ss >> mode;
            if (ss >> start) ss >> end;

            sortRange(arr, n, mode, start, end);
            print(arr, n);
        }
        else if (cmd == "exit") return 0;
    }

    return 0;
}
