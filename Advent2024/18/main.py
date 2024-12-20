from collections import deque

if __name__ == "__main__":
    with open("input.txt") as file:
        lines = [line.strip() for line in file]
        n = 71
        mapa = [['.' for _ in range(n)] for x in range(n)]
        
        for i in range(len(lines)):
            line = [int(x) for x in lines[i].split(',')]
            
            mapa[line[1]][line[0]] = '#'
        
            dx = [0, 0, 1, -1]
            dy = [1, -1, 0, 0]
            qx = deque()
            qy = deque()
            qs = deque()
            mapa[0][0] = 'O'
            qx.append(0)
            qy.append(0)
            qs.append(0)
            ok = False
            while qx:
                topx = qx.popleft()
                topy = qy.popleft()
                tops = qs.popleft()
                if topx == n - 1 and topy == n - 1:
                    ok = True
                    break
                for x, y in zip(dx, dy):
                    if topx + x >= 0 and topx + x < n and topy + y >= 0 and topy + y < n and mapa[topx + x][topy + y] == '.':
                        mapa[topx + x][topy + y] = 'O'
                        qx.append(topx + x)
                        qy.append(topy + y)
                        qs.append(tops + 1)
            for ii in range(n):
                for jj in range(n):
                    if mapa[ii][jj] == 'O':
                        mapa[ii][jj] = '.'
            if not ok:
                print(line)
                break
      
        
