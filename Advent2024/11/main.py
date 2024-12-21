cache: dict[tuple[int, int], int] = {}

def rec(x, depth):
    res = 0
    if depth == 75:
        res = 1
    elif (x, depth) in cache:
        res = cache[x, depth]
    else:
        if x == "0":
            res = rec("1", depth + 1)
        elif len(x) % 2 == 0:
            res = rec(x[:len(x)//2], depth +1) + rec(str(int(x[len(x)//2:])), depth + 1)
        else:
            res = rec(str(int(x) * 2024), depth + 1)
    cache[x, depth] = res
    return res

if __name__ == "__main__":
    with open("input.txt") as file:
        lines = [line.strip() for line in file]
        numbers = lines[0].split(" ")
        result = 0

        for num in numbers:
            result += rec(num, 0)
        print(result)
        