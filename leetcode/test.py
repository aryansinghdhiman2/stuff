# from math import ceil
# def minimum_distances(N, A):
#     # Compute prefix sums
#     prefix_sum = [0] * (N + 1)
#     suffix_sum = [0] * (N + 1)
#     prefix_sum[0] = 0
#     for i in range(1, N+1):
#         prefix_sum[i] = prefix_sum[i - 1] + A[i-1]
    
#     # Compute suffix sums
#     suffix_sum[N - 1] = 0
#     for i in range(len(suffix_sum)-2,-1,-1):
#         suffix_sum[i] = suffix_sum[i + 1] + A[i]
    
#     result = [0] * N

#     low = 0
#     high = N - 2
#     for i in range(N):
#         if(i!=0 and i!=N-1):
#             if(A[high+1]-A[i] < A[i] - A[low]):
#                 high+=1
#                 low+=1
        
#         while(high < i):
#             low+1
#             high+1

#         leftSum = abs((suffix_sum[low] - suffix_sum[i]) - A[i]* (i - low))
#         rightSum = (prefix_sum[high+1] - prefix_sum[i+1]) - A[i]* (high - i)
#         result[i] = leftSum + rightSum
        
    
#     return result

# # Example usage
# N = 3
# A = [1,3,8]
# print(minimum_distances(N, A))

def min_distances(N, A):
    # Calculate the median
    median = A[N // 2] if N % 2 == 1 else (A[N // 2 - 1] + A[N // 2]) // 2

    # Calculate the sum of distances for each friend's house
    result = [0] * N
    for i in range(N):
        result[i] = abs(A[i] - median) * (N - 2)

    return result


