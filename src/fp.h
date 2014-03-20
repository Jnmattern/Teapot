#define FRACBITS 8

#define fpAdd(a,b) ((a)+(b))
#define fpSub(a,b) ((a)-(b))
#define fpMul(a,b) (((a)*(b))>>FRACBITS)
#define fpDiv(a,b) (((a)<<FRACBITS)/(b))

#define fpAddInt(a,b) ((a)+((b)<<FRACBITS))
#define fpSubInt(a,b) ((a)-((b)<<FRACBITS))
#define fpMulInt(a,b) ((a)*(b))
#define fpDivInt(a,b) ((a)/(b))

#define fpMul2(a) ((a)<<1)
#define fpMul4(a) ((a)<<2)
#define fpDiv2(a) ((a)>>1)
#define fpDiv4(a) ((a)>>2)

/* convert to and from floating point */
#define numToFp(d) ((int)( (d)*(double)(1<<FRACBITS) ))
#define fpToFloat(a) ( (double)(a) / (double)(1<<FRACBITS) )
#define fpToInt(a) ((int)((a)>>FRACBITS))

typedef int32_t fp32_t;
