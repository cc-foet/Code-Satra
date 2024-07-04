# This code Extract the last m elements of array that need sorting
# sort them and merge them back to the original array

def sort_last_m(nums, n, m):

    unsorted_part = nums[n:n+m]
    
    unsorted_part.sort()
    
    nums[n:n+m] = unsorted_part
    
    return nums


arr = [1, 3, 6, 19, 11, 16]
n = 3  
m = 3  

sorted_arr = sort_last_m(arr, n, m)

print(sorted_arr)

# Code by- Vikas Saroj
