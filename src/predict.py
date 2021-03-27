
def predict(d: [float]) -> int:
    # Sum out values
    sum = 0.0
    for val in d[-3:]:
        sum += val
    return 0 if (sum<0) else 1
