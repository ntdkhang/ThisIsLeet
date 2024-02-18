class MyClass:
    def __init__(notSelf, x, y):
        notSelf.x = x 
        notSelf.y = y

    def foo(self, t):
        print("HEllo" + str(t))

    def __str__(self):
        return "yo" + str(self.x)

newClass = MyClass(3, 4)
# print(newClass.x) 
# newClass.foo("SLAKDJ")
# print(newClass)
# MyClass.foo(newClass, "YOOO")
print(type(newClass))
print(MyClass)
print(type(MyClass))
print(type(type(MyClass)))
