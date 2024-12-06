if __name__ == "__main__":
    with open("./input.txt", "r") as file:
        input_lines = [line.strip() for line in file]
        pairs = {}
        arrays = []
        cc = False
        for line in input_lines:
            if len(line) > 0 and not cc:
                pairs[(int(line.split("|")[0]), int(line.split("|")[1]))] = 1
            elif len(line) == 0:
                cc=True
            elif cc:
                nums = [int(x) for x in line.split(",")]
                arrays.append(nums)
        print(pairs)
        print(arrays)
        cnt = 0
        for nums in arrays:
            sol = True
            for i in range(len(nums)):
                for j in range(i + 1, len(nums)):
                    if (nums[j], nums[i]) in pairs.keys():
                        temp = nums[i]
                        nums[i] = nums[j]
                        nums[j] = temp
                        sol = False
                        
                    
                
            if not sol:
                leng = len(nums)
                if leng % 2 == 0:
                    print("ALOOO")
                cnt += nums[leng // 2]
        print(cnt)


