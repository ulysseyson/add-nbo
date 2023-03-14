#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    uint32_t n1 , n2;
    fread(&n1, 4, 1, fp1);
    fread(&n2, 4, 1, fp2);
    
    uint32_t nn1 = ntohl(n1);
    uint32_t nn2 = ntohl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", nn1, nn1, nn2, nn2, nn1+nn2, nn1+nn2);
    return 0;
}