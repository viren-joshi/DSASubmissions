import heapq
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        heap = []
        counter = {}
        for word in words:
            counter[word] = counter.get(word,0) + 1
        for key, val in counter.items():
            heapq.heappush(heap, (-val, key))
        ans = []
        while len(ans) < k:
            ans.append(heapq.heappop(heap)[1])
        return ans
