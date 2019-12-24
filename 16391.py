N=int(input())
arr=[]
for i in range(N):
    _input = input()
    arr.append(_input)
i=0
cnt=0
while True:
    i=N-1
    while i>=0:
        if arr[i] == 'O':
            arr[i]='Z'
            i+=1
            break
        i-=1
    if i<0:
        break
    if i<N:
        while i<N:
            if arr[i] == 'Z':
                arr[i] = 'O'
            i += 1
    cnt += 1
print(cnt)
