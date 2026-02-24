import math

def calculate_merge_sort_time_1(N = 100_000):
    logN = math.log2(N)
    return  N * logN

def calculate_merge_sort_time_2(N = 100_000):
    logN = math.log2(N)
    return  N * logN -N + 1
    print(f"Merge 1: {merge_sort_time:.2f}")
    return merge_sort_time

N = 100_000
sort_1 =calculate_merge_sort_time_1(N)
sort_2 = calculate_merge_sort_time_2(N)

# print value
for i in range(1, 20):
    N = 10 ** i
    sort_1 = calculate_merge_sort_time_1(N)
    sort_2 = calculate_merge_sort_time_2(N)
    print(f"N: {N}")
    print(f"Merge 1: {sort_1:.2f}")
    print(f"Merge 2: {sort_2:.2f}")
    print(f"Difference ratio: {sort_1 / sort_2:.2f}")
    print("-" * 30)
