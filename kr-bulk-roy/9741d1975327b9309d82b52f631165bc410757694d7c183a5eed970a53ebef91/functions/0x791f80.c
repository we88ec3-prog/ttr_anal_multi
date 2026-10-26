
undefined4 FUN_00791f80(undefined4 param_1,int param_2,int *param_3,int *param_4,float *param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int *in_EAX;
  int iVar4;
  
  pfVar3 = param_5;
  iVar2 = param_2;
  iVar1 = *in_EAX;
  iVar4 = FUN_00792590(&param_2,0);
  if (iVar4 == iVar1) {
    return 0;
  }
  if (*(int *)(iVar4 + 8) == iVar2) {
    *pfVar3 = 1.0;
    *param_3 = iVar4;
    *param_4 = iVar4;
    return 1;
  }
  *param_3 = iVar4 + -0x2c;
  *param_4 = iVar4;
  *pfVar3 = (float)(iVar2 - *(int *)(iVar4 + -0x24)) /
            (float)(*(int *)(iVar4 + 8) - *(int *)(iVar4 + -0x24));
  return 1;
}

