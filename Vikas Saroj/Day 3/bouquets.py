# this code prints the min. no. of days required to make 
# m bouquets with k adjacent flower
# and return -1 if not possible to make the bouquets
# it uses binary search and greedy algorithm.

def minDays(bloomDay, m, k):
    if len(bloomDay) < m * k:
        return -1
    
    #greedy algorithm
    def possibility(days):
        bouquets, flowers = 0, 0
        for bloom in bloomDay:
            if bloom > days:
                flowers = 0
            else:
                flowers += 1
                if flowers == k:
                    bouquets += 1
                    flowers = 0
        return bouquets >= m
    
    #binary search
    left, right = 1, max(bloomDay)
    while left < right:
        mid = left + (right - left) // 2
        if possibility(mid):
            right = mid
        else:
            left = mid + 1
    return left



M=2
K=3
bloomDay=[5, 5, 5, 5, 10, 5, 5]

result = minDays(bloomDay, M, K)

print(result)


# Code by- Vikas Saroj