/*
给定一个字符串，找出其中不含有重复字符
的最长子串的长度
*/
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution{
    public:
    /*
    滑动窗口法，建立一个[i,j)的set当做窗，j开始与i相等，
    然后把窗口逐渐右移，并判断新的数是否在窗里，直到针对
    所有i进行这个操作。
    */
        int method2(string s){
            int i = 0, j = 0, cont = 0;
            int n = s.length();
            set<int> ss; 
            set<int>::iterator it;
            while(i<n && j<n){
                if(!ss.count(s[j])){
                    ss.insert(s[j++]);
                    cont = max(cont, j-i);
                }
                else{
                    ss.erase(s[i++]);
                }
            }
            return cont;
        }

        /*
        方法一，暴力搜索，先找出字符串s所有可能的子字符串，
        再逐一尝试这些子字符串是否满足条件
        时间复杂度O(n^3)
        */
        int method1(string s){
            int cont = 0;
            int n = s.length();
            for (int i = 0;i < n;i++){
                for(int j = i+1; j <= n; j++){
                    if(allUnique(s,i,j)) cont = max(cont, j-i);
                }
            }
            return cont;
        }

        bool allUnique(string s, int start, int end){
            set<int> ss;
            for(int i = 0;i < s.length(); i++){
                if(ss.count(s[i])) return false;
                ss.insert(s[i]);
            }
            return true;
        }


        /*
        对滑动窗口进行优化，如果s[j]在[i,j)范围内与j1重复，
        则不必把i逐渐右移，可直接把i跳至j1位置。
        */
        int method3(string s){
            map<char, int> hash;
            map<char, int>::iterator it;
            int cont = 0;
            for(int i=0, j=0; j<s.length(); j++){
                if(hash.find(s[j])!=hash.end()){
                    i = max(hash[s[j]], i);
                    hash.erase(hash.find(s[j]));
                }
                hash.insert(pair<char,int>(s[j], j+1)); //这里+1是为了针对输入是"“的情况
                cont = max(cont, j-i+1);               //因为答案在这种情况下给的结果是1
            }
            return cont;
        }
};

int main(){
    string s = "pwwkew";
    Solution ref;
    cout<<ref.method3(s);
}