"""
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex1.py
"""
# A function that converts an input to a number in the base we received
def convert (number,base):
    result =[]
    i=1
    # A loop that performs the conversion according to the n algorithm
    while i!=0:
        result.append(number%base)
        i=number/base
        number = i
    result.reverse()
    return result
print ("please enter the mission number:")
missionum = int (input())
# Converts string numbers from base 2-9 to decimal base
if missionum == 1:
    print ("please enter a number:")
    number = raw_input ()
    print ("please enter a base (2-9):")
    base = int (input())
    numbers=[]
    # Create an int list from the number we received
    for i in range(len(number)):
        numbers.append (int (number [i]))
    numbers.reverse()
    result=0
    # Converts input to a decimal base
    for i in range (len(numbers)):
        result += numbers[i]*base**i
    print (result)
# Converts a number from base 8 or 16 to binary
elif missionum == 2:
    base16={'0':"0000",'1':"0001",'2':"0010",'3':"0011",'4':"0100",'5':"0101",'6':"0110",'7':"0111",
        '8':"1000",'9':"1001",'A':"1010",'B':"1011",'C':"1100",'D':"1101",'E':"1110",'F':"1111"}
    base8={'0':"000",'1':"001",'2':"010",'3':"011",'4':"100",'5':"101",'6':"110",'7':"111"}
    print ("please enter a number:")
    number = raw_input()
    print ("please enter a base (16 or 8):")
    base = int (input())
    # Converts a number from base 16 to binary
    if base == 16:
        result=''
        numbers = list (number)
        # A loop that performs the conversion
        for i in range(len (numbers)):
            numbers[i]=base16.get(numbers[i])
            result += str(numbers[i])
        print (result)
    # Converts a number from base 8 to binary
    else:
        result=''
        numbers = list (number)
        # A loop that performs the conversion
        for i in range(len (numbers)):
            numbers[i]=base8.get(numbers[i])
            result += str(numbers[i])
        print (result)
# Converts a number from base 10 to a number in the base we received
elif missionum == 3:
    print ("please enter a number:")
    number = input()
    print ("please enter a base (16,8,4 or 2):")
    base = int (input())
    result = convert(number,base)
    newResult=''
    # Converts the numbers 10-15 to the letters A-F at the base 16
    for i in range(len (result)):
        if base == 16:
            if result[i]==10:
                result[i]='A'
            elif result[i]==11:
                result[i]='B'
            elif result[i]==12:
                result[i]='C'
            elif result[i]==13:
                result[i]='D'
            elif result[i]==14:
                result[i]='E'
            elif result[i]==15:
                result[i]='F'
    # Make the list a string
    for i in range(len (result)):
        newResult += str(result[i])
    print (newResult)
# Convert a binary number to a number at a decimal base (signed and unsigned)
elif missionum == 4:
    print ("please enter an 8-bit binary number")
    number = raw_input()
    uNumbers = []
    # Create an int list from the number we received
    for i in range(len(number)):
        uNumbers.append (int(number [i]))
    uNumbers.reverse()
    uResult=0
    # A loop that performs the conversion (unsigned)
    for i in range (len(uNumbers)):
        uResult += uNumbers[i]*2**i
    print 'unsigned: '+ str(uResult)
    numbers =[]
    # Create an int list from the number we received
    for i in range(len(number)):
        numbers.append (int(number [i]))
    # Treatment of a negative number according to the "supplementary to 2" method
    if numbers[0]==1:
        for i in range(len(numbers)):
            i=int(i)
            if numbers[i]==0:
                numbers [i]=1
            elif numbers [i]==1:
                numbers [i]=0
        numbers.reverse()
        result=0
        # A loop that performs the conversion (signed)
        for i in range (len(numbers)):
            result += numbers[i]*2**i
        result +=1
        print 'signed: -' + str(result)
    # Treatment of a positive number
    if numbers[0]==0:
        print 'signed: ' + str(uResult)
# Error message for input that is not 1-4
else:
    print ("Error")
