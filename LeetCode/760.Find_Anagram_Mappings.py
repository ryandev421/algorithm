class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        index_map = {}
        for index, item in enumerate(B):
            index_map[item] = index
        res = []
        for item in A:
            res.append(index_map[item])
            
        return res
        
