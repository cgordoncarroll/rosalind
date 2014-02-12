#/usr/bin/python

import sys
def main(argv):
	dnaStrand = argv[0]
	rnaStrand = dnaStrand.replace("T","U")
	print rnaStrand
	
if __name__ == "__main__":
	main(sys.argv[1:])