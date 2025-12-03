import random

n = 10**6      # Размер массива
q = 10**5          # Кол-во запросов
filename = "3.txt"
with open(filename, "w") as f:
    f.write(f"{n} {q}\n")
    a = [str(random.randint(1, 100)) for _ in range(n)]
    f.write(" ".join(a) + "\n")
    for _ in range(q):
        l = random.randint(0, n - 1)
        r = random.randint(0, n - 1)
        if l > r:
            l, r = r, l
        r += 1
        f.write(f"{l} {r}\n")
