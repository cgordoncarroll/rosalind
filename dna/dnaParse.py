#/usr/bin/python

import sys
def main(argv):
	strand = str(argv[0])
	aCount = 0
	cCount = 0
	gCount = 0
	tCount = 0

	#Parsing DNA strand
	for molecule in strand:
		if molecule == "A":
			aCount += 1
		elif molecule == "C":
			cCount += 1
		elif molecule == "G":
			gCount += 1
		elif molecule == "T":
			tCount += 1
	
	print aCount, cCount, gCount, tCount

if __name__ == "__main__":
	main(sys.argv[1:])