class Platform:
    def __init__(self, y, x1, x2):
        self.y=y
        self.x1=x1
        self.x2=x2
pList = []
N=int(input())

def spusti(x, y):
    rez=0
    for i in range(N):
      if pList[i].y  < y and pList[i].x1 < x and pList[i].x2 > x and pList[i].y  > rez:
          rez = pList[i].y
    return rez

for i in range(N):
    line=input().split(' ')
    y, x1, x2 = line
    y=int(y)
    x1=int(x1)
    x2=int(x2)
    pList.append(Platform(y, x1, x2))

rez=0
for i in range(N):
    rez += pList[i].y - spusti(pList[i].x1 + 0.5, pList[i].y)
    rez += pList[i].y - spusti(pList[i].x2 - 0.5, pList[i].y)
print(rez)