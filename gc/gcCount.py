import sys

def parseFile(fileName):
	fileObject = open(fileName, "r")
	dnaStrands = dict()
	currStrandID = ''
	fullStrand = ''
	for line in fileObject:
		if line[0] == ">":
			#new DNA Strand
			currStrandID = line[1::].rstrip()
			dnaStrands[currStrandID] = ''
		else:
			#add to existing index
			dnaStrands[currStrandID] += line.rstrip()
	return dnaStrands

def largestGCContent(dnaDict):
	largestID = ''
	largestContent = 0.0
	for strandID in dnaDict.keys():
		strandGCContent = gcContent(dnaDict[strandID])
		if strandGCContent > largestContent:
			largestID = strandID
			largestContent = strandGCContent
	print largestID
	print largestContent

def gcContent(dnaStrand):
	return round((float((dnaStrand.count("G") + dnaStrand.count("C"))) / len(dnaStrand)) * 100, 6)


if __name__ == "__main__":
	fileName = sys.argv[1]
	dnaDict = parseFile(fileName)
	largestGCContent(dnaDict)