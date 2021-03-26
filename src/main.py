from sys import stdin

WINDOWSIZE=500 # windowsize input 

for line in stdin:
    if line == '': 
        break
    d=[float(x) for x in line.split(',')]
    print('0')  # 0 or 1