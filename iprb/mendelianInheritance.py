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

		probMK = (m / totalPop) * (k / (totalPop-1))
		probMN = (m / totalPop) * (n / (totalPop-1))
		probMM = (m / totalPop) * ((m - 1) / (totalPop-1))

		probNK = (n / totalPop) * (k / (totalPop-1))
		probNM = (n / totalPop) * (m / (totalPop-1))
		probNN = (n / totalPop) * ((n - 1) / (totalPop-1))

		self.assertEqual(1, round(probKK + probKM + probKN + probMK + probMN + probMM + probNK + probNM + probNN))


def generation(k, m, n):
	totalPop = k+m+n

	probKK = (k / totalPop) * ((k - 1) / (totalPop-1)) #100%
	probKM = (k / totalPop) * (m / (totalPop-1)) #100%
	probKN = (k / totalPop) * (n / (totalPop-1)) #100%

	probMK = (m / totalPop) * (k / (totalPop-1)) #100%
	probMN = (m / totalPop) * (n / (totalPop-1)) #50
	probMM = (m / totalPop) * ((m - 1) / (totalPop-1)) #75%

	probNK = (n / totalPop) * (k / (totalPop-1)) #100%
	probNM = (n / totalPop) * (m / (totalPop-1)) #50%
	probNN = (n / totalPop) * ((n - 1) / (totalPop-1)) #0%

	print str(probKK + probKM + probKN + probMK + (probMN * .5) + (probMM * .75) + probNK + (probNM * .5))

if __name__ == "__main__":
	k = float(30)
	m = float(23)
	n = float(29)
	generation(k, m, n)