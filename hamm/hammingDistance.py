import sys

def main(strand1, strand2):
	hammingDistance = 0
	for index, molecule in enumerate(strand1):
		if(molecule != strand2[index]):
			hammingDistance += 1
	print hammingDistance

if __name__ == "__main__":
	main(sys.argv[1], sys.argv[2])