import numpy as np
no_alloc = 0
inf = np.iinfo(np.int32).max

# taking input
r = int(input("Enter the number of rows:"))
c = int(input("\nEnter the number of columns:"))
print("\nEnter the entries in a single line (separated by space):\n")
entries = list(map(int, input().split()))
cm = np.array(entries).reshape(r, c)
print("\nCost Matrix")
print(cm)
print("\nRows, Columns: (", r, ",", c, ")")
print("\nEnter Supply values: ")
s = list(map(int, input().split()))
print("\nSupply Matrix: ")
print(s)
print("\nEnter Demand values: ")
d = list(map(int, input().split()))
print("\nDemand Matrix: ", sep = '')
print(d)
total_demand = np.sum(d)
total_supply = np.sum(s)
if total_demand == total_supply:
         print("\nBalanced Transportation Problem.")
else:
         print("\nUnbalanced Transportation Problem")

        # Add dummy row/column
        if total_demand < total_supply:
            cm = np.insert(cm, c-1, 0, axis = 1)
            cm[r-1][c-1] = total_supply - total_demand
            c += 1
        else:
            cm = np.insert(cm, [r-1], [[0], ], axis = 0)
            cm[r-1][c-1] = total_demand - total_supply
            r += 1
print()
i = 0
j = 0
A = np.zeros([r, c], dtype=int)
min_cost = np.amin(cm)

# IBFS Calculation
while min_cost != inf:
      
    indices = np.where(cm == min_cost)
    i = indices[0][0]
    j = indices[1][0]
    x = min(s[i], d[j])
    s[i] -= x
    d[j] -= x
    no_alloc += 1
    A[i][j] = x
    if s[i] < d[j]:
        j = 0
        while j < c:
            cm[i][j] = inf
            j += 1
    elif s[i] > d[j]:
        i = 0
        while i < r:
            cm[i][j] = inf
            i += 1
    else:
        k = 0
        while k < c:
            cm[i][k] = inf
            k += 1
        k = 0
        while k < r:
            cm[k][j] = inf
            k += 1
    min_cost = np.amin(cm)
print("\nNo of Allocation: ", no_alloc)
print("\nAllocation Matrix:\n")
print(A)
if (r + c - 41) == no_alloc and total_demand == total_supply:
         print("\nIt is not a Degenerate Solution")
else:
         print("\nDegenerate Solution")
