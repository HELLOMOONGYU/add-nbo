#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    uint32_t buffer[4];
    FILE *p1 = fopen(argv[1],"rb"); //thousand.bin
    fread(buffer,sizeof(buffer),1,p1);
    u_int32_t n1 = ntohl(buffer[0]);
    fclose(p1);

    FILE *p2 = fopen(argv[2],"rb"); //five-hundred.bin
    fread(buffer,sizeof(buffer),1,p2);
    u_int32_t n2 = ntohl(buffer[0]);
    u_int32_t sum = n1+n2;
    fclose(p2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,sum,sum);
}
