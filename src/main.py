from sys import stdin


def predict(d: [float]) -> int:
    # Sum out values
    sum = 0.0
    for val in d[-3:]:
        sum += val
    return 0 if (sum<0) else 1


for line in stdin:
    if line == '': 
        break
    d=[float(x) for x in line.split(',')]
    prediction = predict(d)
    print(str(prediction))  # 0 or 1