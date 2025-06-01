class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for word in strs:
            sorted_words = ''.join(sorted(word))
            if sorted_words not in groups:
                groups[sorted_words] = []
            groups[sorted_words].append(word)

        return list(groups.values())
