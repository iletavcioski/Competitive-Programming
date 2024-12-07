if __name__ == "__main__":
    with open("./input.txt") as file:
        input_lines = [line.strip() for line in file]
        res = 0
        for line in input_lines:
            first_split = line.split(":")
            goal = int(first_split[0])
            rest = first_split[1]
            numbers = [int(x) for x in rest[1:].split(" ")]
            print(goal)
            print(numbers)
            length = len(numbers) - 1

            for i in range(int(pow(3, length))):
                start = numbers[0]
                for j in range(length):
                    mod = int(pow(3, j))
                    operator = (i // mod) % 3
                    if start > goal:
                        break
                    if operator == 1:
                        start *= numbers[j + 1]
                    elif operator == 0:
                        start += numbers[j + 1]
                    else:
                        a = str(start)
                        b = str(numbers[j + 1])
                        a = a + b
                        start = int(a)
                if start == goal:
                    res += goal
                    break
        print(res)
            