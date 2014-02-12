#/usr/bin/python

import sys
def main(argv):
	strand = argv[0]
	strand = ''.join(reversed(strand))
	outStrand = ''
	for index, molecule in enumerate(strand):
		if molecule == "A":
			outStrand += "T"
		elif molecule == "C":
			outStrand += "G"
		elif molecule == "G":
			outStrand += "C"
		elif molecule == "T":
			outStrand += "A"
	print outStrand

if __name__ == "__main__":
	main(sys.argv[1:])