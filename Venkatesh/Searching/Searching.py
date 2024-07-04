def days_to_bouquet(bloom_array, no_of_bouquets, flowers_in_bouquet):
    def can_make(days):
        bouquets = 0
        flowers = 0
        for day in bloom_array:
            if day <= days:
                flowers += 1
                if flowers == flowers_in_bouquet:
                    bouquets += 1
                    flowers = 0
            else:
                flowers = 0
        return bouquets >= no_of_bouquets
    
    if len(bloom_array) < no_of_bouquets * flowers_in_bouquet:
        return -1
    
    left, right = min(bloom_array), max(bloom_array)
    while left < right:
        mid = (left + right) // 2
        if can_make(mid):
            right = mid
        else:
            left = mid + 1
    return left if can_make(left) else -1

bloom_day = [1, 10, 3, 10, 2]
k = 1
m = 3

print(days_to_bouquet(bloom_day, m, k))