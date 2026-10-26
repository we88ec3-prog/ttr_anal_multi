
int FUN_008bd240(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *param_1;
  iVar2 = FUN_008bc6b0(uVar1,param_3,".AppleDouble/");
  if (iVar2 == 0) {
    return 0x40;
  }
  iVar3 = FUN_008bc650(param_5);
  if (iVar3 == 0) {
    *param_4 = iVar2;
    return 0;
  }
  FUN_008b9f80(uVar1,iVar2);
  return iVar3;
}

