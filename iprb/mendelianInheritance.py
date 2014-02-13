import sys
import unittest

#Given: Three positive integers k, m, and n, representing a population containing k+m+n organisms: 
# k individuals are homozygous dominant for a factor, m are heterozygous, and n are homozygous recessive.

class probTest(unittest.TestCase):
	def test_probabilities(self):
		k = float(10)
		m = float(10)
		n = float(10)
		totalPop = k+m+n

		probKK = (k / totalPop) * ((k - 1) / (totalPop-1))
		probKM = (k / totalPop) * (m / (totalPop-1))
		probKN = (k / totalPop) * (n / (totalPop-1))
		probMN = (m / totalPop) * (n / (totalPop-1))
		probMM = (m / totalPop) * ((m - 1) / (totalPop-1))
		probNN = (n / totalPop) * ((n - 1) / (totalPop-1))

		self.assertEqual(1, probKK + probKM + probKN + probMN + probMM + probNN)


def generation(k, m, n):
	totalPop = k+m+n

	probKK = (k / totalPop) * ((k - 1) / (totalPop-1))
	probKM = (k / totalPop) * (m / (totalPop-1))
	probKN = (k / totalPop) * (n / (totalPop-1))
	probMN = (m / totalPop) * (n / (totalPop-1))
	probMM = (m / totalPop) * ((m - 1) / (totalPop-1))
	probNN = (n / totalPop) * ((n - 1) / (totalPop-1))

	print str(probKK + probMM + probKM + probKN + probMN)

if __name__ == "__main__":
	#unittest.main()
	input = sys.argv
	k = float(input[1])
	m = float(input[2])
	n = float(input[3])
	generation(k, m, n)