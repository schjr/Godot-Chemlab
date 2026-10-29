/* Persistent original x87 intrinsic host. Built as x86_64 on macOS; Rosetta
 * executes the same FSIN/FCOS/FSQRT/FPTAN instructions used by the original CRT.
 * Binary protocol: one operation byte, eight IEEE input bytes; ten output bytes.
 * No target process, file, network, input, or application state access. */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(void) {
    unsigned short control = 0x037f;
    __asm__ volatile("fldcw %0"::"m"(control));
    setvbuf(stdout, NULL, _IONBF, 0);
    unsigned char request[9];
    while (fread(request,1,9,stdin)==9) {
        if (request[0]==0) break;
        double input; long double output;
        memcpy(&input,request+1,8);
        switch(request[0]) {
        case 1: __asm__ volatile("fldl %1; fsin; fstpt %0":"=m"(output):"m"(input):"st"); break;
        case 2: __asm__ volatile("fldl %1; fcos; fstpt %0":"=m"(output):"m"(input):"st"); break;
        case 3: __asm__ volatile("fldl %1; fsqrt; fstpt %0":"=m"(output):"m"(input):"st"); break;
        case 4: __asm__ volatile("fldl %1; fptan; fstp %%st(0); fstpt %0":"=m"(output):"m"(input):"st"); break;
        default: return 2;
        }
        if(fwrite(&output,1,10,stdout)!=10) return 3;
    }
    return ferror(stdin)?4:0;
}
