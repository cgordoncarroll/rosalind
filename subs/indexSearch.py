import sys

def findIndicies(dnaString, searchString, listIndicies, offset):
	if(dnaString.find(searchString, offset) == -1):
		return listIndicies
	else:
		listIndicies.append(dnaString.index(searchString, offset))
		offset = dnaString.index(searchString, offset) + 1
		return findIndicies(dnaString, searchString, listIndicies, offset)

if __name__ == "__main__":
	dnaString = sys.argv[1]
	searchString = sys.argv[2]
	print ' '.join(str(val+1) for val in (findIndicies(dnaString, searchString, [], 0)))