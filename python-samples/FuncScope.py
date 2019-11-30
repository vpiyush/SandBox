


print("1")
def my_func():
    x = 10
    print("11")
    print(f"value of x inside func {x}")
    return x

print("000")
print("****")
y = my_func();
print("111")
print(f"value of x outside func {x}")
print(f"value of x outside func {y}")

