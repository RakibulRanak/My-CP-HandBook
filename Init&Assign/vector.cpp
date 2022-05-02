#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>vec1(5, 10);
    cout << vec1.size() << " " << vec1[1] << endl;
    //fill with a value after initialization
    fill(vec1.begin(), vec1.end(), 20);
    cout << vec1.size() << " " << vec1[1] << endl;



    vector<vector<int>>vec2(10, vector<int>(3, 9));
    cout << vec2.size() << " " << vec2[0].size() << " " << vec2[0][1] << endl;
    //fill with a value after initialization
    fill(vec2.begin(), vec2.end(), vector<int>(3, 18));
    cout << vec2.size() << " " << vec2[0].size() << " " << vec2[0][1] << endl;


}