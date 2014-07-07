#include <stdio.h>
#include <string.h>

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

struct dict{
    char key[4];
    char value[2];
};

void lookup_codon(struct dict dictionary[], char *searchTerm, char *result){
    for(int i = 0; i < NELEMS(dictionary); i++)
    {
        if(dictionary[i].key == searchTerm)
        {
            strcpy(result, dictionary[i].value);
        }
    }
}

int main(){
    struct dict rna_codons[64];

    FILE * fp;

    fp = fopen("rna_codons.txt", "r+");

    char * line = NULL;
    size_t len = 0;
    int k = 0;

    while(getline(&line, &len, fp) != -1)
    {
        char line_array[6];
        strcpy(line_array, line);

        char value[2];
        memcpy(value, &line_array[4], 1);
        value[1] = '\0';
        strcpy(rna_codons[k].value, value); 

        char key[4];
        memcpy( key, &line_array[0], 3);
        key[3] = '\0';
        strcpy(rna_codons[k].key, key);
        k++;
    }
    free(line);
    fclose(fp);
    // Make sure we read everything in right
    int i;
    for(i = 0; i < 64; i++){
        printf("Key: %s Value: %s\n", rna_codons[i].key, rna_codons[i].value);
    }
    printf("%d lines read in for codon table. Input DNA Strand:", k+1);
}
