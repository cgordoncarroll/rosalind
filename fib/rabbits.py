import sys

def breed(months, pairsPerLitter):
	youngPairs = 1
	maturePairs = 0

	for i in xrange(months-1):
		newbornPairs = maturePairs * pairsPerLitter
		maturePairs += youngPairs
		youngPairs = newbornPairs
	
	print str(youngPairs + maturePairs)

if __name__ == "__main__":
	months = int(sys.argv[1])
	pairsPerLitter = int(sys.argv[2])

	breed(months, pairsPerLitter)