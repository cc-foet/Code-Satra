import heapq
from collections import Counter

def rearrange_chars(s):
    # Count frequency of each character in the string
    chars_freq = Counter(s)

    # Create a max_heap with neg freq
    heap = [(-freq, char) for char, freq in chars_freq.items()]
    heapq.heapify(heap)

    # To store previous frequency and character
    prev_count, prev_char = 0, ''
    ans_arr = []

    while heap:
        count, char = heapq.heappop(heap)
        ans_arr.append(char)

        if prev_count < 0: # character left to be used
            heapq.heappush(heap, (prev_count, prev_char))
        
        prev_count, prev_char = count + 1, char
    
    ans = ''.join(ans_arr)

    return ans if len(ans_arr) == len(s) else ''


s = "aaabbc"
print(rearrange_chars(s))
