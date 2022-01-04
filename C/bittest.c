#include <stdio.h>
#include <memory.h>
#include <stdint.h>
#define TEST 29

int main () {

    printf ("test %d\n", TEST);

    char jbytes[20];
    uint16_t node = 65535;
    memcpy(jbytes, &node, 2);

    int c2 = jbytes[0] & 0xFF;
    int c1 = jbytes[1] & 0xFF;
    int nodeId = ((c1 << 8) + c2);
    printf ("nodeId %d\n", nodeId);

}
