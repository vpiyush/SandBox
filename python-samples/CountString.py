

string = input("Enter a string")
char = input("Entr the char")


def xy(l, n):
    count = 0
    for i in l:
        if i == n:
           count = count + 1
    return count

result = xy(string, char)

print(result)
