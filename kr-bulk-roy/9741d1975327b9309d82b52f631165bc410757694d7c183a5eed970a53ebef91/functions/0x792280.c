
undefined4 FUN_00792280(int param_1,int *param_2,int *param_3,float *param_4)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *in_EDX;
  
  iVar1 = *in_EAX;
  iVar2 = FUN_007926f0(*in_EDX,0);
  if (iVar2 == iVar1) {
    return 0;
  }
  if (*(int *)(iVar2 + 8) == param_1) {
    *param_4 = 1.0;
    *param_2 = iVar2;
    *param_3 = iVar2;
    return 1;
  }
  *param_2 = iVar2 + -0x10;
  *param_3 = iVar2;
  *param_4 = (float)(param_1 - *(int *)(iVar2 + -8)) /
             (float)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + -8));
  return 1;
}

