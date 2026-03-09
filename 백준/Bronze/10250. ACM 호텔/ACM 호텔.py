# 2         테스트 케이스 개수
# 6 12 10   층수 방수 몇 번째 손님인지?
# 30 50 72

testnum = int(input())

result = []

for _ in range(testnum):
    arr = []
    arr = list(map(int,input().split()))
    num = arr[2]
    count = 0
    for i in range(1,arr[1] + 1): # 방
        for j in range(1, arr[0] + 1): # 층
            count += 1
            if count == num:
                result.append(j * 100 + i)
                print(j * 100 + i)
                break
