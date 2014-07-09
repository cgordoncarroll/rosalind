#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define CODON_DICT_SIZE 64

struct dict{
    char key[4];
    char value[2];
};

char lookup_codon(struct dict dictionary[CODON_DICT_SIZE], char * search_term)
{
    int i;
    char result;
    for(i = 0; i < CODON_DICT_SIZE; i++)
   {
        if(strcmp(dictionary[i].key, search_term)==0)
       {
            result = *dictionary[i].value;
           break;
       }
    }
    return result;
}
int main(){
    struct dict rna_codons[CODON_DICT_SIZE];

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
    for(i = 0; i < CODON_DICT_SIZE; i++){
        printf("Key: %s Value: %s\n", rna_codons[i].key, rna_codons[i].value);
    }
    printf("%d lines read in for codon table. Input DNA Strand:", k+1);

    char strand [MAX_SIZE];
    fgets(strand, MAX_SIZE-1, stdin);
    printf("Parsing DNA Strand: %s", strand);
    int n;
    for(n = 0; n < strlen(strand)-3; n=n+3)
    {
        char search_term[4];
        memcpy(search_term, &strand[n], 3);
        search_term[3] = '\0';
        char result;
        result = lookup_codon(rna_codons, search_term);
        if(strcmp(result, "Z") == 0){
            break;
        }
        printf("%c", result);
   }
    printf("\n");
    return 1;
}
