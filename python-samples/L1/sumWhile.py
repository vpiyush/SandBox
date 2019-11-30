# n = int(input("Enter n: "))
n = 10

# initialize sum and counter
sum = 0
i = 1

while i <= n:
    i = i+1    # update counter
    if i == 10:
        continue
    sum = sum + i

# print the sum
#print("The sum is {0} n is {1} i is {2}".format(sum, n, i))
print(f"The sum is {sum} n is {n} i is {i}")
