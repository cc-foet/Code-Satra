def minTime(arr, n, k):
  def checkTime(arr, n, k, max_time):
    total_time = 0
    painters = 1

    for i in range(n):
      total_time += arr[i]
      if total_time > max_time:
        total_time = arr[i]
        painters += 1
        if painters > k:
          return False
    return True

  low = max(arr) # min time
  high = sum(arr) # max time

  while low < high:
    mid = (low + high) // 2

    if checkTime(arr, n, k, mid):
      high = mid
    else:
      low = mid + 1
  
  return low

arr = [10, 20, 30, 40]
n = 4
k = 2

min_time = minTime(arr, n, k)
print(min_time)