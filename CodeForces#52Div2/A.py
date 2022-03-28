if __name__ == "__main__":
    n = int(input())
    res = 0
    lis = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
    for i in range(n):
        st = input()
        if st[0] >= '0' and st[0] <= '9':
            st = int(st)
            if st < 18:
                res += 1
        else:
            if st in lis:
                res += 1
    
    print(res)