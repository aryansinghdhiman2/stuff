import numpy as np

marks = [int(i) for i in input("Enter marks (delimited by comma): ").split(',')]


pass_marks = int(input("Enter passing marks: "))

def meanAndMode(marks:list[int],pass_marks:int):
    new_marks = [ i for i in marks if i > pass_marks]
    new_marks = np.array(new_marks)

    return (np.mean(new_marks),np.median(new_marks))


mean_mode = meanAndMode(marks,pass_marks)
print(f"Mean and Mode of marks of passing students are: {mean_mode[0], mean_mode[1]}")
    