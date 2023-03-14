#include <stdint.h>
#include <stdio.h>

uint32_t my_ntohl(uint32_t n) {
	return n << 24 | n >> 24 | (n & 0x0000ff00) << 8 | (n & 0x00ff0000) >> 8;
}

int main(int argc, char *argv[]){

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    uint32_t n1 = fread(fp1, 1, 4);
    uint32_t n2 = fread(fp2, 1, 4);
    
    n1 = my_ntohl(n1);
    n2 = my_ntohl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", n1, n1, n2, n2, n1+n2, n1+n2);
    return 0;
}