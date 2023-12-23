#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LIS(const vector<int> &arr, vector<int> &path, int val, int idx, int n) {
    if (idx == n) {
        return path;
    }
    
    vector<int> maxPath = path; 
    
    for (int i = idx; i < n; i++) {
        if (arr[i] > val) {
            path.push_back(arr[i]);
            vector<int> result = LIS(arr, path, arr[i], i + 1, n);
            
            if (result.size() > maxPath.size()) {
                maxPath = result; 
            }
            path.pop_back();
        }
    }
    
    return maxPath;
}

int main() {
    vector<int> arr = {4, 1, 13, 7, 0, 2, 8, 11, 3}; 
    int n = arr.size();
    vector<int> path;
    path = LIS(arr, path, -1, 0, n);

    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }

    printf("\n");
    return 0;
}
