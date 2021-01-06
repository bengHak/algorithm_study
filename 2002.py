수 = int(input())
들어가는차 = {}
나가는차 = {}
추월 = 0

for ㄱ in range(수):
    차 = input()
    들어가는차[차] = ㄱ

for ㄱ in range(수):
    차 = input()
    나가는차[차] = ㄱ


for ㄱ in 나가는차.keys():
    if 나가는차[ㄱ] < 들어가는차[ㄱ]:
        추월+=1

print(추월)