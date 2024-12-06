import re

if __name__ == "__main__":
    patterns = [r"mul\(\d{1},\d{1}\)", 
                r"mul\(\d{1},\d{2}\)",
                r"mul\(\d{1},\d{3}\)",
                r"mul\(\d{2},\d{1}\)",
                r"mul\(\d{2},\d{2}\)",
                r"mul\(\d{2},\d{3}\)",
                r"mul\(\d{3},\d{1}\)",
                r"mul\(\d{3},\d{2}\)",
                r"mul\(\d{3},\d{3}\)",]
    
    

    with open('./input.txt', 'r') as file:
        input_lines = [line.strip() for line in file]
        test_string = ""
        for line in input_lines:
            test_string += line
        

        print(test_string)
        result = 0
        for pattern in patterns:
            matches = re.finditer(pattern, test_string)
            for match in matches:
                start_pos = match.start()
                end_pos = match.end()
                max_do = -1
                max_dont = -1
                mnozi = True
                dos_matches = re.finditer(r"do\(\)", test_string)
                donts_matches = re.finditer(r"don't\(\)", test_string)
                for do_match in dos_matches:
                    if do_match.start() < start_pos:
                        max_do = do_match.start()
                    else:
                        break
                for dont_match in donts_matches:
                    if dont_match.start() < start_pos:
                        max_dont = dont_match.start()
                    else:
                        break
                if max_dont > max_do:
                    mnozi = False
                numbers = test_string[start_pos + 4 : end_pos - 1].split(",")
                if mnozi:
                    result += int(numbers[0]) * int(numbers[1])
    
    print(result)

