#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size() - 1;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (letters[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (letters[right] <= target) return letters[0];
    else return letters[right];
}
int main()
{
    vector<char> letters { 'c','f','j'};
    char ch = nextGreatestLetter(letters, 'c');
    cout << ch << endl;
    return 0;
}