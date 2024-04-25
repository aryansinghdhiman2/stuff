import pandas as pd

sd = pd.read_csv("student_data.csv")

sd['grade_mean'] = sd[['G1', 'G2', 'G3']].mean(axis=1)

features = sd.drop(columns=['G1', 'G2', 'G3', 'grade_mean'])

correlation_matrix = features.corrwith(sd['grade_mean'],numeric_only=True)

print("Correlation of Features with grade_mean: ")
print(correlation_matrix.abs().sort_values(ascending=False))

sd_by_sex = sd.groupby(by=['sex'])["grade_mean"].mean().sort_values(ascending=False)

print("Comparison of grades by Gender")
print(sd_by_sex)