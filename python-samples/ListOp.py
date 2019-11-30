
even  = [2,4,6]
odd  = [1, 3,5]

# Iteration over list
for anything in even:
    print(anything)

#true if an item is present in list
print(2 in even)
if 2 in even:
    print("2 is present in even list")

# True is an item is not present in the list else True
print(2 not in even)
if 56 not in even:
    print("56 is not present in even list")

#concatenate 2 lists
numbers = even + odd
print(numbers)

#multiply
print(numbers * 2)

#acccessing an item in list
print(numbers[0])

#slicing the list
print(numbers[0:3])

#slicing the list, with step
print(numbers[0:3:2])

#length of the list
print(len(numbers))

#minimum of the list
print(min(numbers))

#max of the list
print(max(numbers))

#count the occurnece of an item in the list
print(numbers.count(4))


###################### Mutable Operation #####################

#replacing the item in ith index
numbers[2] = 78
print(numbers)

#replacing the item in specific range
numbers[2:4] = []
print(numbers)

#delete a range
del numbers[1:3]
print(numbers)

#append a number
numbers.append(56)
print(numbers)

#clear a list
numbers.clear()
print(numbers)

#insert an item in the list on ith index
numbers = odd + even
numbers.insert(2, 90)
print(numbers)

#remove an item
numbers.remove(90)
print(numbers)

#revers thee list
numbers.reverse()
print(numbers)

