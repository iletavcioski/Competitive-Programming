class FreshTires:
  def projectedOvertake(self, interval, sectors, sectorTimesChaser, sectorTimesDefender):
    
    lap = 0
    prev_interval = interval
    sector = 0
    while True:
        print(interval)
        for i in range(sectors):
            sector = i + 1
            print(lap)
            print(sector)
            
            interval -= (sectorTimesDefender[i] - sectorTimesChaser[i])
            print(interval)
            if interval < 0:
                return str(str(lap) + ";" + str(sector))
                
        if interval >= prev_interval:
            return "Impossible"
        prev_interval = interval
        lap += 1

    return "Impossible"
if __name__ == "__main__":
    f = FreshTires()
    f.projectedOvertake(45, 6, [53,90,50,36,77,97], [62,94,58,44,83,94])