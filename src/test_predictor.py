from sys import stdin
import csv
import predict
import numpy as np

dataset = []
labels = []

with open('LatencyTraining.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for (iter, value) in reader:
        if iter == '':
            continue
        value = float(value)
        dataset.append(value)
        if value < 0:
            labels.append(0)
        else:
            labels.append(1)


l = len(dataset)
ma_length = 3
preds = [0, 0, 0]
current_acc = 0
# Dataset has 1826 values. Do time series predictions on it:
for i in range(ma_length, l):
    data_subset = dataset[i-ma_length:i]
    preds.append(predict.predict(data_subset))
    # print(np.average(np.equal(preds[ma_length:], labels[ma_length:len(preds)])))

accuracy = np.average(np.equal(preds[ma_length:], labels[ma_length:]))
print(accuracy)

