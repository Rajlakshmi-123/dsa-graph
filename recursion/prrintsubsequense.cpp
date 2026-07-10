#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(int i, vector<int>& arr, vector<int>& temp) {

    // Base case
    if (i == arr.size()) {

        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j] << " ";
        }

        cout << endl;
        return;
    }

    // Take current element
    temp.push_back(arr[i]);

    printSubsequence(i + 1, arr, temp);

    // Remove current element
    temp.pop_back();

    // Not take current element
    printSubsequence(i + 1, arr, temp);
}

int main() {

    vector<int> arr = {1, 2, 3};

    vector<int> temp;

    printSubsequence(0, arr, temp);

    return 0;
}