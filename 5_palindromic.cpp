#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    暴力搜索法，先找出所有可能子串，再逐一判断是否为回文字符串。
    时间复杂度为O(n^3),空间复杂度为O(1)。
    */
    string longestPalindrome(string s) {
        int n = s.length();
        string maxStr = "";
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<= n; j++) {
                string subs = s.substr(i, j-i);
                if(palindromic(subs)) {
                    maxStr = (maxStr.length()>subs.length()) ? maxStr:subs;
                }
            }
        }
        return maxStr;
    }

    bool palindromic(string s) {
        int low = 0, high = s.length() - 1;
        while(low<high) {
            if(s[low] != s[high])
                return false;
            else {
                low++;
                high--;
            }
        }
        return true;
    }

    /*
    分而治之。空和长度为1的字符串一定是回文，直接返回
    验证所有长度为2的字符串，然后验证长度为3的，以此类推
    bool dp[i][j]的状态表示索引i到索引j的子串是否是回文，
    对于j-i>1，dp[i][j] = (str[i]==str[j])&&dp[i-1][j+1]
    时间复杂度O(n^2),空间复杂度O(n^2)
    */

   string method2(string s) {
       int n = s.length(), maxlen = 1;
       vector<vector<bool>> dp(n, vector<bool>(n, false));
       int start = 0;
       for(int j = 0;j < n;j++) {
           for(int i = 0; i <= j; i++) {
               if(j-i<2) {
                   dp[i][j] = (s[i]==s[j]);
               }
               else {
                   dp[i][j] = (s[i]==s[j])&&dp[i+1][j-1];

               }
               if(dp[i][j] && maxlen < j-i+1) {
                   start = i;
                   maxlen = j-i+1;
               }
           }
       }
       return s.substr(start, maxlen);
   }

   string method3(string s) {
       /*
       中心扩展法，回文中心的两侧互为镜像，因此回文可以从
       中心展开，并且只有2n-1个这样的中心(一个元素为中心的
       情况有n种，两个元素为中心的情况有n-1中)
       时间复杂度为O(n^2)，空间复杂度为O(1)。
       */
      int n = s.length(), maxlen = 1, start = 0, end = 0;
      if(n<1) return "";
      for(int i = 0; i < n; i++) {
          int len1 = ispalindromic(s, i, i);
          int len2 = ispalindromic(s, i, i+1);
          maxlen = max(maxlen, max(len1, len2));
          if(maxlen > end - start + 1) {
              start = i - (maxlen - 1) / 2;
              end = i + maxlen / 2;
          }
      }
      return s.substr(start, end-start+1);
   }

   int ispalindromic(string s, int low, int high) {
       while(low >= 0 && high<=s.length() && s[low] == s[high]) {
           low--;
           high++;
       }
       return high - low - 1;
   }
};

int main() {
    string str = "bab";
    Solution s;
    cout<<s.longestPalindrome(str)<<endl;
    cout<<s.method3(str);
}