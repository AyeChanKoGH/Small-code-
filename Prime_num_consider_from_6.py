num=1000000
prime=[2,3]
def test(i):
	for j in prime:
		if(i%j==0):
			break
		if(j*j>i):
			prime.append(i)
			break
	return 0
for i in range (6,num,6):
	i=i-1
	test(i)
	i=i+2
	test(i)
	i=i-1	
print(prime)
