










def ArrayChallenge(arr):
    sum = 0
    for num in arr:
        sum += num

    arr.sort()

    largest_product = max(arr[-2] * arr[-1], arr[0] * arr[1])



    if largest_product > sum * 2:
        return True
    else:
        return False

# arr = [2, 2, 2, 2, 4, 1]
# arr = [1, 1, 2, 10, 3, 12]
# arr = [2,5,6,-6,16,2,3,6,5,3]
arr = [2, 2, -4, -8,2, 2, 2, 2,2,2,2,2,2,2, 1]

print(ArrayChallenge(arr))


