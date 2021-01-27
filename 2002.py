N = int(input())
car_in = []
car_out = []
ans = 0

for n in range(N):
    car = input()
    car_in.append(car)

for n in range(N):
    car = input()
    car_out.append(car)


for n in car_out:
    if car_out.index(n) < car_in.index(n):
        ans+=1
print(ans)