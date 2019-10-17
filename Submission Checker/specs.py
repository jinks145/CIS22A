import sys
print("specify the requirement file && code")

files = input().split(' ')

f = [open(files[0], 'r'), open(files[1], 'r')]

occurence =  {}

for spec in f[0].readlines() :
    occurence.update(spec, 0)

compliant = False

for line in f[1].readlines() :
      for token in line.split():
        if token in occurence.keys() :
            occurence[token] += 1

if 0 in occurence.values() :
    sys.exit()



 


