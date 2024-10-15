#define _CRT_SECURE_NO_WARNINGS 1
#include"Hash.h"

using namespace open_address;

//int main()
//{
//	HashTable<int, int> ht;
//	int a[] = { 19,30,5,36,13,20,21,12 };
//	for (auto e : a) 	ht.Insert({ e,e });
//	ht.Print();
//
//	cout << endl;
//
//	if (ht.Find(9)) cout << "True" << endl;
//	else cout << "False" << endl;
//
//	if(ht.Erase(19) ) cout << "True" << endl;
//	else cout << "False" << endl;
//
//	//string s[]{ "abc", "aaa", "bbb", "ccc", "ddd" };
//	//HashTable<string, string> hts;
//	//for (auto e : s)
//	//{
//	//	cout << e << " ";
//	//}
//	////hts.Print();
//
//	//cout << endl;
//
//	/*if (ht.Find("aaa")) cout << "True" << endl;
//	else cout << "False" << endl;
//
//	if (ht.Erase(19)) cout << "True" << endl;
//	else cout << "False" << endl;*/
//
//
//	return 0;
//}


vector<int> missingTwo(vector<int>& nums) {
    int tmp = 0;
    for (int i = 1; i <= nums.size() + 2; ++i)
        tmp ^= i;
    for (auto v : nums) tmp ^= v;

    int diff = 0;
    while (1) {
        if (((tmp >> diff) & 1) == 1) break;
        else ++diff;
    }
    int a = 0, b = 0;
    for (int i = 1; i <= nums.size() + 2; ++i) {
        if (((i >> diff) & 1) == 1) a ^= i;
        else b ^= i;
    }
    for (auto v : nums) {
        if (((v >> diff) & 1) == 1) a ^= v;
        else b ^= v;
    }
    return { a,b };
}

int main() {
    vector<int> nums{ 2 };
    vector<int> ret = missingTwo(nums);
    for (auto e : ret) cout << e << " ";
    return 0;
}