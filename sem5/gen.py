from random import randrange, random

MAX = 10
print(MAX)
print(MAX)
num = []
# gera números na range 1..1e9
for i in range (0, MAX):
    num.append(randrange(1000000000))
    print(num[i])

queries = []
pos = 1
qt = MAX
for i in range (0, MAX):
    r = random()
    # mover
    if(r >= 0 and r <= 0.33):
        sign = random()
        # decide o sinal, acho que tem q arrumar tb
        if(sign <= 0.5 and pos > 1):
            m = randrange(1, pos - 1, 1)  
            m = m*-1
            print("m", m)
            queries.append(["m", m])
        else:
            m = randrange(1, qt - pos - 1, 1)  
            print("m", m)
            queries.append(["m", m])
    # deletar
    elif(r > 0.33 and r <= 0.66):
        print("d")
        queries.append(["d"])
        qt -= 1
    # printar
    else:
        print("q")
        queries.append(["q"])

pos = 0
qt = MAX
# resolutor pra comparar, acho que ta quebrado
with open('expected.out', 'w') as writer:
    for q in queries:
        if(q[0] == "m"):
            pos = pos + int(q[1])
        elif(q[0] == "d"):
            num.pop(pos)
            if(pos == qt-1): pos = pos - 1
            else: pos = pos + 1
            qt = qt - 1
        else:
            writer.write(str(num[pos]))
            writer.write('\n')