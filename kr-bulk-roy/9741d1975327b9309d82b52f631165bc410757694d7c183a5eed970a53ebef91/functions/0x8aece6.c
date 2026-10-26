
/* Library Function - Single Match
    __handle_qnan2
   
   Library: Visual Studio 2010 Release */

float10 __handle_qnan2(undefined4 param_1,double param_2,double param_3,undefined4 param_4)

{
  int *piVar1;
  float10 fVar2;
  
  if (DAT_00d62cb0 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,param_3,param_2 + param_3,param_4);
    return fVar2;
  }
  piVar1 = __errno();
  *piVar1 = 0x21;
  __ctrlfp();
  return (float10)(param_2 + param_3);
}

