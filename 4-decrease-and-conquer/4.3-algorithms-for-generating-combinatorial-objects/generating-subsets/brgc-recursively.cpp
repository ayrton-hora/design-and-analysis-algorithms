#include <bits/stdc++.h>

using namespace std;

vector<string> binaryReflectedGrayCode(int n);

int main() {
    int n = 0;
    cout << "Binary Reflected Gray Code Alghorithm to get all subsets in bit strings" << endl << endl; 
    while (n <= 0) {
        cout << "Please insert a non-zero positive integer value: ";
        scanf("%d", &n);
    }
    cout << endl;

    vector<string> subsets = binaryReflectedGrayCode(n);

    cout << "Subsets in bit string representation:" << endl;
    for (int i = 0; i < subsets.size(); i++) cout << subsets[i] << endl;

    cout << endl << "Total: " << pow(2, n) << endl;

    return 0;
}

vector<string> binaryReflectedGrayCode(int n) {
    // Base list
    if (n == 1) return {"0", "1"};

    else {
        vector<string> l1, l2, l;

        // Generate list L1 of bit string of size n - 1 with recursively
        l1 = binaryReflectedGrayCode(n - 1);

        // Copy list L1 to L2 in reversed order
        l2 = l1;
        reverse(l2.begin(), l2.end());

        // Add bit 0 in front of each bit string in list L1
        for (int i = 0; i < l1.size(); i++) l1[i] = "0" + l1[i];

        // Add bit 1 in front of each bit string in list L2
        for (int i = 0; i < l2.size(); i++) l2[i] = "1" + l2[i];

        // Append L2 to L1 to get final list L
        l.insert(l.end(), l1.begin(), l1.end());
        l.insert(l.end(), l2.begin(), l2.end());

        return l;
    }
}
