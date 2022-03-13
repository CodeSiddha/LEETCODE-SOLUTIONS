class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  int n = s.size();
  unordered_map<char, int> mpp;
  int maxlen = 0;
  int len = 0;
  int l = 0;
  for (int r = 0 ; r < n ; r++) {
    mpp[s[r]]++;
    if (mpp[s[r]] > 1) {
      while (1) {
        if (s[l] == s[r]) {
          mpp[s[l]]--;
          l++;
          break;
        } else {
          mpp[s[l]]--;
          l++;
        }
      }
    }
    maxlen = max(maxlen , r - l + 1);

  }
  return maxlen;
    }
};