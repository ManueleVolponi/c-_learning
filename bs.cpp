#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>

int binary_search(vector<T>& data, T& target) {
    clock_t start = clock();

    sort(data.begin(), data.end());
    int l = 0, r = data.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (data[mid] == target) {
            clock_t end = clock();

            cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
            return mid + 1;
        } else if (data[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    clock_t end = clock();

    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";

    return - 1;
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " {data1,data2} ... target\n";
        return 1;
    }
    

    vector<string> data;

    for (int i = 1; i < argc - 1; i++) {
        data.push_back(argv[i]);
    }
    
    string target = argv[argc - 1];

    cout << "Searching for " << target << " in { ";
    for (auto n : data) cout << n << " ";
    cout << "}\n";

    int result = binary_search(data, target);

    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << "Not found\n";

    return 0;
}
