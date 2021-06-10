#include<stdio.h>
int main()
{
	int x = 0x12345678;
	int y = 0x65666768;
	void *p = &x;
	void *p1 = &x;
/*warning: invalid application of ‘sizeof’ to a void type [-Wpointer-arith]*/
//printf("%ld\n",sizeof(void));
//printf("%x\n",*p); // we cannot derefrence 
//printf("%x\n",(int*)*p);// associate problem we cannot derefrence
printf("%x\n",*(int*)p);
//printf("%x\n",*(unsigned char*)p);
//printf("%x\n",*(char*)(p + 1));
//printf("%x\n",*(short*)(p + 1));
//printf("%x\n",*(int*)(p + 1));
printf("%x\n",*(char*)((short*)p + 1));
printf("%x\n",*(int*)((short*)p1 + 1));

}
