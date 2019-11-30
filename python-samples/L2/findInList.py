mylist = [100, 200, 300, 200, 300, 400]
num1 = int(input("enter a number to find:"))
replaceValue = int(input("enter replace value:"))

index = 0
for anything in mylist:
    if num1 == anything:
        mylist[index] = replaceValue
    index = index +1
print(mylist)
