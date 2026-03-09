flag = False

count = 0

for i in range(8):
    arr = input()
    flag = not flag
    for j in range(8):
        if flag and arr[j] == 'F':
            count += 1
        flag = not flag

print(count)