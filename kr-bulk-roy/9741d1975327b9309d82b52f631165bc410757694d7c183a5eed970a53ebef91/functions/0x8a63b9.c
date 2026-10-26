
/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Library: Visual Studio 2010 Release */

int * __updatetlocinfoEx_nolock(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_2 == (int *)0x0) || (param_1 == (undefined4 *)0x0)) {
    param_2 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*param_1;
    if (piVar1 != param_2) {
      *param_1 = param_2;
      ___addlocaleref(param_2);
      if (((piVar1 != (int *)0x0) && (___removelocaleref(piVar1), *piVar1 == 0)) &&
         (piVar1 != (int *)&DAT_00d627a0)) {
        ___freetlocinfo(piVar1);
      }
    }
  }
  return param_2;
}

