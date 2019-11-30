myset = {1,2,3}
for i in myset:
    print(i)

mylist = [1,2,3,4,3,2,1]

print(f"mylist before removing duplicates {mylist}")
myset1 = set(mylist)

mylist = list(myset1)

print(f"mylist after removing duplicates {mylist}")
