[TOC]

# Recursive

### Longest Substring with At Least K Repeating Characters(395) ***

Q:Find the length of the longest substring **T** of a given string (consists of lowercase letters only) such that every character in **T** appears no less than *k* times.

Idea:

1. We count the frequency of all characters in the string and store it in a list **count**.
2. Traverse all characters in the string, if the frequency of a character in the list is inferior than k, which means that this character are not supposes to exist in the final string.
3. Split the string by this character, do the same thing to the left side and right side of the string , then return the biggest result of each side. 
4. We should also check that the length of right side and left side are superior than 0.

```java
class Solution {
    
    public int longestSubstring(String s, int k) {
        int[] count = new int[26];
        char[] chars = s.toCharArray();
        for (char c : chars) count[c - 'a']++;

        boolean found = false;
        for (int i = 0; i < chars.length; i++) {
            if (count[chars[i] - 'a'] < k) {
                chars[i] = '#';
                found = true;
            }
        }
        if (!found) return s.length();

        String[] split = new String(chars).split("#");
        int ans = 0;
        for (String ss : split) {
            if (ss.length() > 0)
                ans = Math.max(longestSubstring(ss, k), ans);
        }

        return ans;
    }
}
```

# Optimize complexity

###  4Sum II(454) **

Q: Given four lists A, B, C, D of integer values and have same longer, compute how many tuples `(i, j, k, l)` there are such that `A[i] + B[j] + C[k] + D[l]` is zero.

idea: divide four degree four loop to two degree for loop with a HashMap of frequency of sum a and b.

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int a : A) {
            for (int b : B) {
                map.put(a + b, map.getOrDefault(a + b, 0) + 1);
            }
        }
        int res = 0;
        for (int c : C) {
            for (int d : D) {
                res += map.getOrDefault(-(c + d), 0);
            }
        }
        return res;
    }
}
```

