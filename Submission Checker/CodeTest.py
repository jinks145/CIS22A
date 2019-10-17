lines = [line for line in open('result.txt')]
numbers = [int(n) for n in lines]

min, max = 1, 15  

print(numbers)

for i in range(5) :
    if numbers[i] not in range(min , max + 1) :
        print('error!')
        break
    min += 15
    max += 15 
