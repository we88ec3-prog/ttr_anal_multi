
int FUN_008bb1d0(int param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1;
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 100);
  if ((*(byte *)(*(int *)(param_1 + 0x9c) + 4) & 1) == 0) {
    puVar1 = (uint *)(*(int *)(param_1 + 0x9c) + 4);
    *puVar1 = *puVar1 | 1;
  }
  else {
    FUN_008b9f80(uVar3,*(undefined4 *)(param_1 + 0x58));
    *(undefined4 *)(iVar2 + 0x58) = 0;
  }
  uVar3 = FUN_008baee0(uVar3,param_2,&param_1);
  *(undefined4 *)(iVar2 + 0x58) = uVar3;
  return param_1;
}

