#include <stdio.h>
#include <string.h>

struct dict{
    char key;
    char value;
};

int main(){
    struct dict rna_codons[64];

    FILE * fp;

    fp = fopen("rna_codons.txt", "r+");

    char * line = NULL;
    size_t len = 0;
    int k = 0;
    while(getline(&line, &len, fp))
    {
        rna_codons[k].key = * strtok(line, " ");
        rna_codons[k].value = * strtok(line, " ");
        k++;
    }
    fclose(fp);

    for(int i = 0; i < 64; i++){
        printf("Key: %c Value: %c\n", rna_codons[i].key, rna_codons[i].value);
    }
}
