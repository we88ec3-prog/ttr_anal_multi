
undefined4 FUN_008f3cb0(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_2 == 0) {
    return 0x24;
  }
  if (iVar1 == 0) {
    return 6;
  }
  if ((*(uint *)(iVar1 + 0x10) <= param_3) && (*(int *)(*(int *)(iVar1 + 0x80) + 0x30) == 0)) {
    return 6;
  }
  if ((param_4 & 2) != 0) {
    if ((*(uint *)(iVar1 + 8) & 0x2000) != 0) {
      param_4 = param_4 & 0xfffffffd;
    }
    if ((param_4 & 0x8000) != 0) {
      param_4 = param_4 | 2;
    }
  }
  uVar2 = param_4;
  if (((param_4 & 0x401) != 0) && (uVar2 = param_4 | 9, (*(uint *)(iVar1 + 8) & 0x2000) == 0)) {
    uVar2 = param_4 | 0xb;
  }
  uVar3 = FUN_008f3a50(param_3,uVar2);
  return uVar3;
}

