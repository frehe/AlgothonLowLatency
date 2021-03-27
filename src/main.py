import cython
import predict
from sys import stdin


for line in stdin:
    if line == '': 
        break
    d=[float(x) for x in line.split(',')]
    prediction = predict.predict(d)
    print(str(prediction)))  # 0 or 1