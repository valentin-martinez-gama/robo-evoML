from numpy import loadtxt
from keras.models import Sequential
from keras.layers import Dense
import numpy as np
import pandas as pd

temp = 0
error = 0

#Load dataset as numpy array
dataset = loadtxt('TrainingSet.csv', delimiter=',', usecols=range(23))
X = dataset[:, 0:20]
y = dataset[:, 20:23]

#Convert dataset to Pandas DataFrame in case data manipulation is needed
df = pd.DataFrame(dataset)

#Escalar variables de salida
for i in range(len(y)):
    y[i,1] = y[i,1] * 10
    y[i, 2] = y[i, 2] * 10

#Define Keras Model
model = Sequential()
model.add(Dense(30, input_dim=20, activation='relu'))
model.add(Dense(45, activation='relu'))
model.add(Dense(30, activation='relu'))
model.add(Dense(15, activation='relu'))
model.add(Dense(3, activation='relu'))

model.compile(loss='mean_squared_error', optimizer='adam')

model.fit(X, y, epochs=100, batch_size=50)

print('Training Succesfull')

#Test model on trained dataset
print('Testing on known dataset...')
predictions = model.predict(X)

y_np = np.array(y)
predictions_np = np.array(predictions)

for i in range(15):
    print('Output for example# %d => %s => Expected %s)' % (i, predictions[i].tolist(), y[i].tolist()))
    error = error + (abs((y_np[i] - predictions_np[i]))/y_np[i]) * 100
    temp += 1
error_acum = error/temp
print(error_acum)


#Test model on untrained dataset
print('Testing on unknown Dataset...')
validation = loadtxt('TestSet.csv', delimiter=',', usecols=range(23))

X_val = validation[:, 0:20]
y_val = validation[:, 20:23]

#Escalar variables de salida
for i in range(len(y_val)):
    y_val[i, 1] = y_val[i, 1] * 10
    y_val[i, 2] = y_val[i, 2] * 10

results = model.predict(X_val)

y_val_np = np.array(y_val)
results_np = np.array(results)

temp = 0
error = 0
for i in range(45):
    print('Output for example# %d => %s => Expected %s)' % (i, results[i].tolist(), y_val[i].tolist()))
    error = error + (abs((y_val_np[i] - results_np[i])) / y_val_np[i]) * 100
    temp += 1
error_acum = error / temp
print(error_acum)
