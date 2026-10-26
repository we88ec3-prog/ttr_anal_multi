
int FUN_008bb230(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1;
  if ((param_1 == 0) || (iVar3 = *(int *)(param_1 + 0x60), iVar3 == 0)) {
    return 6;
  }
  uVar1 = *(undefined4 *)(iVar3 + 8);
  iVar3 = FUN_008baee0(uVar1,*(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x2c),&param_1);
  if (param_1 == 0) {
    *(int *)(iVar3 + 4) = iVar2;
    iVar4 = FUN_008bb160();
    if (iVar4 != 0) {
      FUN_008ba3f0();
      FUN_008b9f80(uVar1,iVar3);
      return iVar4;
    }
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar2 + 0x54);
    *(int *)(iVar2 + 0x54) = iVar3;
    param_1 = 0;
    if (param_2 != (int *)0x0) {
      *param_2 = iVar3;
      return 0;
    }
  }
  else if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  return param_1;
}

