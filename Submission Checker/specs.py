print("specify the requirement file && code")

files = input().split(',')

f = [open(files[0], 'r'), open(files[1], 'r')]

compliant = False
for line in files[1] :
    parts = line.split()

    for str in parts : 
        if str in files[0].readlines():
            compliant = True
        else :
            compliant = False

if(compliant) :
    print("fits specs")

else :
    print("non compliant")

 


