if __name__ == "__main__":
    with open("input.txt") as file:
        lines = [line.strip() for line in file]
        words = lines[0].split(', ')
        res = 0
        for i in range(2, len(lines)):
            word = lines[i]
            dp = [0 for _ in range(len(word) + 1)]
            dp[0] = 1
            for j in range(len(word)):
                for pos_word in words:
                    if j + len(pos_word) <= len(word) and pos_word == word[j : j + len(pos_word)]:
                        dp[j + len(pos_word)] += dp[j]
                            

            res += dp[-1]
        print(res)
                        
    print("Advent of Code 19")