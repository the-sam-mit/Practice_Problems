
def binary_search(input_array, value):
    lo = 0
    hi = len(input_array) - 1
   # mid = (lo + hi)/2
    while lo<=hi:
        mid = (lo + hi)/2
        #print(input_array[mid])
        if input_array[mid] == value:
            return mid
        elif input_array[mid] < value:
            lo = mid + 1
        else: 
            hi = mid - 1
    return -1

test_list = [1,3,9,11,15,19,29]
test_val1 = 25
test_val2 = 15
print binary_search(test_list, test_val1)
print binary_search(test_list, test_val2)
