class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram=defaultdict(list)

        for word in strs:
            sorted_str=''.join(sorted(word))
            anagram[sorted_str].append(word)

        print(anagram.values())
        print(list(anagram.values())[0])  # Print the first list of anagrams
        return list(anagram.values())
            