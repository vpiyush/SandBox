
mylist = [10, 20, 30, 40, 50]



def maxinList(l, n):
    for i in l:
        if i == n:
            return True

    return False

    #find whehter num is present or not
    # return True  => if present
    # Fals  => it not present

num = int(input("Enter a num"))
result = maxinList(mylist, num)
print(result)
