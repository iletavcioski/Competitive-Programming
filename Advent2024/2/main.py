if __name__ == "__main__":
    cnt = 0
    with open('./input.txt', 'r') as file:
        input_lines = [line.strip() for line in file]
        for line in input_lines:
            numbers = [int(x) for x in line.split(" ")]
            for k in range(len(numbers)):
                new_numbers = numbers[:k] + numbers[k + 1:]
                if len(new_numbers) == 1:
                    continue
                inc = False
                diff = abs(new_numbers[0] - new_numbers[1])
                if new_numbers[0] < new_numbers[1]:
                    inc = True
                sol = True

                for j in range(len(new_numbers) - 1):
                    diff = abs(new_numbers[j] - new_numbers[j + 1])
                    if diff < 1 or diff > 3:
                        sol = False
                        break
                    inc2 = False
                    if new_numbers[j] < new_numbers[j + 1]:
                        inc2 = True
                    if inc != inc2:
                        sol = False
                        break
                if sol:
                    cnt += 1
                    break
    print(cnt)
            