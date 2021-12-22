string = "Hello World"

arr = bytes(string, "utf-8")
arr_1 = bytes(string, "ascii")

for i in arr:
    print(i)

for i in arr_1:
    print(i)
