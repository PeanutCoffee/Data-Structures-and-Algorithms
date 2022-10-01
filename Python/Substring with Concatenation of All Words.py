class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        words.sort()
        output=[]
        concatenated_len=len(words)*len(words[0])
        for i in range(len(s)+1-concatenated_len):
            temp=[]
            for j in range(i,i+concatenated_len,len(words[0])):
                temp.append(s[j:j+len(words[0])])
            temp.sort()
            if(temp==words):
                output.append(i)
        return output
    