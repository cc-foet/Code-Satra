import heapq
from collections import Counter

def rearrange(s):
    freq = Counter(s)
    max_heap = [(-count, char) for char, count in freq.items()]
    heapq.heapify(max_heap)

    prev_char, prev_count = None, 0
    result = []

    while max_heap:
        count, char = heapq.heappop(max_heap)
        result.append(char)

        if prev_count < 0:
            heapq.heappush(max_heap, (prev_count, prev_char))
        
        prev_char, prev_count = char, count + 1
    
    result = ''.join(result)
    return result if len(result) == len(s) else ''

str = 'caaabbbaacdddd'
print(rearrange(str))