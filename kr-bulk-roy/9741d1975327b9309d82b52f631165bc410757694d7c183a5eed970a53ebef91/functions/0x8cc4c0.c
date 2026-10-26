
int * FUN_008cc4c0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2;
  *param_2 = 0;
  iVar2 = FUN_008baee0(param_1,0x18,&param_2);
  if (param_2 == (int *)0x0) {
    *(undefined4 *)(iVar2 + 8) = param_1;
    *piVar1 = iVar2;
    return (int *)0x0;
  }
  return param_2;
}

