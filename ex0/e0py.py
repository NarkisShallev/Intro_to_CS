#Read string as input from the user
name=raw_input()
print ("Hi "+name+"!")
#Read number as input from the user
number=input()
#If the number is negative, change its sign
if number < 0:
    number=number*-1
#print the numbers from 1 to the number
for i in range (1,number+1):
    print i

