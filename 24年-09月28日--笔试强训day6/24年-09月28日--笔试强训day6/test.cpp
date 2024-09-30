#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<List>

using namespace std;


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算两个数之和
//     * @param s string字符串 表示第一个整数
//     * @param t string字符串 表示第二个整数
//     * @return string字符串
//     */
//    string solve(string s, string t) {
//        // write code here
//        int l1 = s.size();
//        int l2 = t.size();
//        string ret;
//        int flag = 0;
//        while (l1 > 0 || l2 > 0)
//        {
//            int num1 = (--l1 >= 0) ? s[l1] - '0' : 0;
//            int num2 = (--l2 >= 0) ? t[l2] - '0' : 0;
//            int sum = num1 + num2 + flag;
//            flag = sum / 10;
//            sum %= 10;
//            ret.insert(0, 1, sum + '0');
//       }
//        if (flag == 1)
//            ret.insert(0, 1, '1');
//        return ret;
//    }
//};
//
//int main()
//{
//    string s;
//    s.insert(0, 1, '0');
//    s.insert(0, 1, '1');
//    s.insert(0, 1, '1');
//    s.push_back('9');
//    reverse(s.begin(), s.end());
//    cout << s << endl;
//
//
//    string str = "1";
//    string ret;
//    string t("99");
//    Solution sol;
//    string  s1 =  sol.solve(str, t);
//    cout << s1;
//	return 0;
//   
//    
//}



//struct ListNode {
//	int val;
//	struct ListNode* next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
// 
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param head1 ListNode类
//     * @param head2 ListNode类
//     * @return ListNode类
//     */
//
//
//    ListNode* reverse(ListNode* list) {
//        ListNode* prev(nullptr);
//        while (list->next) {
//            ListNode* next = list->next;
//            list->next = prev;
//            prev = list;
//            list = next;
//        }
//        list->next = prev;
//        return list;
//    }
//    ListNode* addInList(ListNode* head1, ListNode* head2) {
//        // write code here
//        ListNode* l1 = reverse(head1);
//        ListNode* l2 = reverse(head2);
//        ListNode* tmp = new ListNode(0);
//        ListNode* prev = tmp;
//        int flag = 0;
//
//        while (l1 || l2) {
//            int n1 = 0, n2 = 0;
//            if (l1)
//            {
//                n1 = l1->val;
//                l1 = l1->next;
//            }
//            if (l2)
//            {
//                n2 = l2->val;
//                l2 = l2->next;
//            }
//            
//            int sum = n1 + n2 + flag;
//            flag = sum / 10;
//            sum %= 10;
//            ListNode* cur = new ListNode(sum);
//            prev->next = cur;
//            prev = cur;
//          
//        }
//        if (flag == 1)
//        {
//            ListNode* cur = new ListNode(1);
//            prev->next = cur;
//        }
//        ListNode* ret = tmp->next;
//        delete tmp;
//        ret = reverse(ret);
//        return ret;
//    }
//};
//
//int main()
//{
//    ListNode* l1 = new ListNode(9);
//    ListNode* l2 = new ListNode(3);
//    ListNode* l3 = new ListNode(7);
//    l1->next = l2;
//    l2->next = l3;
//
//    ListNode* s1 = new ListNode(6);
//    ListNode* s2 = new ListNode(3);
//    s1->next = s2;
//    Solution s;
//    ListNode* s.addInList(l1, s1);
//
//    return 0;
//}


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        if (s == "0" || t == "0")
            return "0";
        int l1 = s.size();
        int l2 = t.size();
        if (l1 < l2)
        {
            swap(s, t);
            swap(l1, l2);
        }
        vector<int> v(l1+l1, 0);
        for (int j = 0; j < l2; j++)
        {
            int flag = 0;
            for (int i = 0; i < l1; i++)
            {
                int n1 = s[i] - '0';
                int n2 = t[j] - '0';
                int sum = n1 * n2 + flag + v[i + j];
                flag = sum / 10;
                sum %= 10;
                v[i + j] = sum;
            }
            if (flag != 0)
                v[j + l1] = flag;
              
        }
        string ret;
        if (v[l1 + l2] == 0)
            l1 - 1;
        for (int i = 0; i < l1+l2; i++)
        {
            ret.insert(0, 1, v[i] + '0');
        }
        return ret;
    }
};

int main()
{
    string s("1");
    string t("0");
    Solution sol;
    string s1 = sol.solve(s, t);
    cout << s1;

	return 0;
}






















