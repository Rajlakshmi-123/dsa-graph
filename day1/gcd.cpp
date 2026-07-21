#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maxDiffSubArrays(vector<int>& arr) {

    int n = arr.size();

    vector<int> leftBig(n), leftSmall(n), rightBig(n), rightSmall(n);

    int maxSum = arr[0];
    int minSum = arr[0];

    leftBig[0] = arr[0];
    leftSmall[0] = arr[0];

    for (int i = 1; i < n; i++) {

        maxSum = max(arr[i], maxSum + arr[i]);
        leftBig[i] = max(leftBig[i - 1], maxSum);

        minSum = min(arr[i], minSum + arr[i]);
        leftSmall[i] = min(leftSmall[i - 1], minSum);
    }

    maxSum = arr[n - 1];
    minSum = arr[n - 1];

    rightBig[n - 1] = arr[n - 1];
    rightSmall[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {

        maxSum = max(arr[i], maxSum + arr[i]);
        rightBig[i] = max(rightBig[i + 1], maxSum);

        minSum = min(arr[i], minSum + arr[i]);
        rightSmall[i] = min(rightSmall[i + 1], minSum);
    }

    int answer = 0;

    for (int i = 0; i < n - 1; i++) {

        answer = max(answer, abs(leftBig[i] - rightSmall[i + 1]));
        answer = max(answer, abs(leftSmall[i] - rightBig[i + 1]));
    }

    return answer;
}

int main() {

    int n;
    cout <<" ans is " ;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Absolute Difference = " << maxDiffSubArrays(arr) << endl;

    return 0;
}