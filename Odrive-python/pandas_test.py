import pandas as pd

df = pd.DataFrame()

column1 = pd.Series([], dtype=str)
column2 = pd.Series([], dtype=int)
column3 = pd.Series([], dtype=float)

for i in range(15):
    column1[i] = "hola" + str(i)
    column2[i] = i
    column3[i] = i*3.3

df.insert(0, "String", column1)
df.insert(1, "Int", column2)
df.insert(2, "Float", column3)

print(df.head)

df.to_csv("prueba.csv", index=False)
