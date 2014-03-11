def permute(listOfNumbers, currentIndex = 0):
	if(currentIndex + 1 >= len(listOfNumbers)):
		yield listOfNumbers
	else:
		for p in permute(listOfNumbers, currentIndex + 1):
			yield p
		for i in range(currentIndex + 1, len(listOfNumbers)):
			#swap
			listOfNumbers[currentIndex], listOfNumbers[i] = listOfNumbers[i], listOfNumbers[currentIndex]
			for p in permute(listOfNumbers, currentIndex + 1):
				yield p
			#swap again
			listOfNumbers[currentIndex], listOfNumbers[i] = listOfNumbers[i], listOfNumbers[currentIndex]

def factorial(x):
	#This function returns the factorial of X
	if(x == 0):
		return 1
	else:
		return x * factorial(x - 1)

firstSet = list()
for i in xrange(1, 6):
	firstSet.append(i)
print str(factorial(5))
for p in permute(firstSet):
	print ' '.join(map(str, p))