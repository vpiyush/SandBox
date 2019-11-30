class sample_class:
    i = 12345
    def __init__(self, name):
        self.name = name
        print(name)
    def f(self):
        return "Hello world"
    def cfoo():
        print("class method")

test1 = sample_class("test1")
print(test1.name)
print(test1.i)
print(test1.f())
sample_class.cfoo()
