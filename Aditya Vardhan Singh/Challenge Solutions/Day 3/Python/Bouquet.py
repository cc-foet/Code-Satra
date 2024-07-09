import sys

def getSum(bloomDay, i, n):
    sum = 0
    for idx in range(i, n):
        sum += bloomDay[idx]
    return sum

def getMax(bloomDay, i, n):
    max = bloomDay[i]
    for idx in range(i, n):
        if bloomDay[idx] > max:
            max = bloomDay[idx]
    return max

def bouquet(bloomDay, M, K):
    adj_flowers = M * K;

    if adj_flowers > len(bloomDay):
        return -1

    min_idx = 0
    min_sum = sys.maxsize
    for i in range(len(bloomDay) - adj_flowers):
        sum = getSum(bloomDay, i, i+adj_flowers)
        if sum < min_sum:
            min_sum = sum
            min_idx = i
    
    return getMax(bloomDay, min_idx, min_idx + adj_flowers)

M = 2
K = 3
bloomDay = [5, 5, 5, 5, 10, 5, 5]

print(bouquet(bloomDay, M, K))