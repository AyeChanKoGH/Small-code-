#finding prime number from 0 to num:
'''
Algorithm one
#A number is prime number when it can't divisible by smaller prime number 
#A number is prime number when it can't divisible by a prime number that is smaller than the square root of that number
'''
num =1000000
prime=[2,3]
for i in range (5,num,2):
    for j in prime:
        if (i%j==0):
            break
        if(j*j>i):
            prime.append(i)
            break
print(prime)
