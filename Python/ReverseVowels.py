Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Solution 1: Using Stack
Approach: Define a list of vowels, and a temp string res.
Run a for loop and store the vowels in stack in first pass, and in second pass if we encounter a vowel, pop the element and add it to string res, else add that element in res.

class Solution:
    def reverseVowels(self, s: str) -> str:
        stack=[]
        res=""
        vowel=['a','e','i','o','u','A','E','I','O','U']
        for char in s:
            if char in vowel:
                stack.append(char)          # put the vowel in stack
        for char in s:
            if char in vowel:               # if we encounter a vowel
                res+=stack.pop()            # add the last vowel in stack to string
            else:
                res+=char                   # else simply add that element to string
        return res
Time Complexity: O(n)

Solution 2: Using 2 Pointers
Approach: Define a list of vowels. Have two pointers for left(i) and right(j). This means i=0(starting) and j=len(s)-1(ending).
Run a while loop on condition i<j. If s[i] and s[j] are in vowel, then swap the elements of ith and jth position. Update the pointers. If either of them is not in vowels update the respective pointer.

class Solution:
    def reverseVowels(self, s: str) -> str:
        i=0                                  # starting pointer
        j=len(s)-1                           # ending pointer
        vowels=['a','e','i','o','u','A','E','I','O','U']
        s=list(s)                            # convert to list to make swap operation easier
        while i<j:
            if s[i] in vowels and s[j] in vowels:
                s[i],s[j]=s[j],s[i]          # swap the characters
                i+=1                         # update the pointers
                j-=1
            elif s[i] not in vowels:         # we have to increament our start pointer
                i+=1
            elif s[j] not in vowels:         # we have to decreament our end pointer
                j-=1
        return ''.join(s)
Time Complexity: O(n)