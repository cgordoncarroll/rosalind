#include <stdio.h>

float generation(int k, int m, int n)
{
    float totalPopulation = k + m + n;
    float probK = k / totalPopulation;
    float probM = m / totalPopulation;
    float probN = n / totalPopulation;

    float probKK = probK * ((k - 1) / (totalPopulation-1));
    float probKM = probK * (m / (totalPopulation-1));
    float probKN = probK * (n / (totalPopulation-1));
    float probMK = probM * (k / (totalPopulation-1));
    float probMM = probM * ((m-1) / (totalPopulation-1));
    float probMN = probM * (n / (totalPopulation-1));
    float probNK = probN * (k / (totalPopulation-1));
    float probNM = probN * (m / (totalPopulation-1));
    float probNN = probN * ((n-1) / (totalPopulation-1));

    return probKK + probKM + probKN + probMK + (probMN * .5) + (probMM * .75) + probNK + (probNM * .5);
}

int main()
{
    int k = 0;
    int m = 0;
    int n = 0;
    printf("Enter # of Homozygous dominant: ");
    fscanf(stdin, "%d", &k);
    printf("Enter # of Heterozygous: ");
    fscanf(stdin, "%d", &m);
    printf("Enter # of Homozygous recessive: ");
    fscanf(stdin, "%d", &n);

    float probability = generation(k,m,n);
    printf("Probabily of displaying dominant phenotype: %f", probability);
}
