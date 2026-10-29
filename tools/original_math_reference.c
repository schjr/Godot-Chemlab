/* x87 instruction reference for the original CRT's finite positive path.
 * Build for x86_64 and execute with Rosetta on the ARM host. This isolates
 * FYL2X/F2XM1 from Unicorn's software implementations; it is not the app.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
static long double fyl2x(double x,int decimal){
    long double out;
    if(decimal) __asm__ volatile("fldlg2; fldl %1; fyl2x; fstpt %0":"=m"(out):"m"(x):"st");
    else __asm__ volatile("fldln2; fldl %1; fyl2x; fstpt %0":"=m"(out):"m"(x):"st");
    return out;
}
static long double f2xm1(long double x){
    long double out;
    __asm__ volatile("fldt %1; f2xm1; fstpt %0":"=m"(out):"m"(x):"st");
    return out;
}
static long double native_exp(long double x){
    long double l2e;
    __asm__ volatile("fldl2e; fstpt %0":"=m"(l2e)::"st");
    long double z=x*l2e;
    int negative=z<0;if(negative)z=-z;
    long double out;
    if(z<=1)out=f2xm1(z)+1;
    else {
        int k=(int)(z*2);
        out=f2xm1(z-(long double)k*.5L)+1;
        static const unsigned char sqrt2bytes[16]={0x85,0x64,0xde,0xf9,0x33,0xf3,0x04,0xb5,0xff,0x3f};
        long double sqrt2;memcpy(&sqrt2,sqrt2bytes,16);
        if(k&1)out*=sqrt2;
        long double shift=(long double)(k>>1);
        __asm__ volatile("fldt %1; fldt %2; fscale; fstp %%st(1); fstpt %0":"=m"(out):"m"(shift),"m"(out):"st");
    }
    return negative?1/out:out;
}
int main(int argc,char**argv){
    unsigned short control=0x037f;
    __asm__ volatile("fldcw %0"::"m"(control));
    if(argc<3)return 1;
    double x=strtod(argv[2],0);long double out;
    if(!strcmp(argv[1],"sqrt")) __asm__ volatile("fldl %1; fsqrt; fstpt %0":"=m"(out):"m"(x):"st");
    else if(!strcmp(argv[1],"sin")) __asm__ volatile("fldl %1; fsin; fstpt %0":"=m"(out):"m"(x):"st");
    else if(!strcmp(argv[1],"cos")) __asm__ volatile("fldl %1; fcos; fstpt %0":"=m"(out):"m"(x):"st");
    else if(!strcmp(argv[1],"tan")) __asm__ volatile("fldl %1; fptan; fstp %%st(0); fstpt %0":"=m"(out):"m"(x):"st");
    else if(!strcmp(argv[1],"log10"))out=fyl2x(x,1);
    else {if(argc<4)return 1;double exponent=strtod(argv[3],0);out=native_exp(fyl2x(x,0)*exponent);}
    double stored=(double)out;
    for(int i=0;i<8;i++)printf("%02x",((unsigned char*)&stored)[i]);
    putchar(' ');
    for(int i=0;i<10;i++)printf("%02x",((unsigned char*)&out)[i]);
    putchar('\n');return 0;
}
