
void FUN_008b8140(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_3 = param_3 << 0x10;
  if ((param_1 != (int *)0x0) && (param_2 != (undefined4 *)0x0)) {
    iVar1 = FUN_008b7dc0(*param_1,param_2[2],param_3);
    iVar2 = FUN_008b7dc0(param_1[1],param_2[3],param_3);
    iVar3 = FUN_008b7dc0(param_1[1],param_2[1],param_3);
    iVar4 = FUN_008b7dc0(*param_1,*param_2,param_3);
    *param_1 = iVar3 + iVar4;
    param_1[1] = iVar1 + iVar2;
  }
  return;
}

