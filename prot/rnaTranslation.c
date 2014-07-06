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
        char line_array[6];
        strcpy(line_array, line);
        printf("%s", line_array[3]);
        /*char key[3];
        strcat(key, line_array[0]);
        strcat(key, line_array[1]);
        strcat(key, line_array[2]);
        printf("%s", line_array[4]);
        rna_codons[k].key = key;
        rna_codons[k].value = line_array[4]; 
        k++;*/
    }
    fclose(fp);
    
    int i;
    for(i = 0; i < 64; i++){
        printf("Key: %c Value: %c\n", rna_codons[i].key, rna_codons[i].value);
    }
}
