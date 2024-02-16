student={}
marks=[]
temp={}
result={}
no_of_students=int(input("Enter the number of students "))
for i in range(no_of_students):
    roll_no=input("Enter roll number ")
    name=input("Enter name ")
    student[roll_no]=name
print("Enter details for marks")
for i in range(2*no_of_students):
    roll_no=input("Enter roll_no ")
    subject=input("Enter subject ")
    score=int(input("Enter marks "))
    marks.append(tuple((roll_no,subject,score)))
print(student)
print(marks)
for std in marks:
    (roll_no,sub,score)=std
    if roll_no not in temp:
        temp[roll_no]=score
    else:
        temp[roll_no]+=score
for roll_no,marks in temp.items():
    if roll_no in student:
        result[student[roll_no]]=marks

print(result)