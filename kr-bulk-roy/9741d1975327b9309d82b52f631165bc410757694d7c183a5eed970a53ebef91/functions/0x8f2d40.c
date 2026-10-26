
int FUN_008f2d40(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = FUN_008b8fc0(*(undefined4 *)(*(int *)(param_2 + 0x60) + 4),&DAT_00bd7d94);
  if (iVar3 == 0) {
    return 0xb;
  }
  iVar4 = FUN_008b97e0(param_1,0);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = (**(code **)(iVar3 + 4))(param_1,param_2,param_3,param_4,param_5);
  uVar1 = *(undefined4 *)(param_2 + 0x68);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = *(int *)(param_2 + 0x94);
  if (((iVar4 != 0x10000) && (iVar4 != 0x20000)) && (iVar4 != 0x74727565)) {
    return 2;
  }
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x800;
  if (param_3 < 0) {
    return 0;
  }
  iVar3 = (**(code **)(iVar3 + 8))(uVar1,param_2,param_3,param_4,param_5);
  if (iVar3 == 0) {
    cVar2 = FUN_008eba80();
    if (cVar2 != '\0') {
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x2000;
    }
    iVar3 = FUN_008eaa10(param_2,uVar1);
    if (iVar3 == 0) {
      iVar3 = 0;
      if ((*(byte *)(param_2 + 8) & 1) != 0) {
        if (((*(int *)(*(int *)(param_2 + 0x80) + 0x30) != 0) ||
            (iVar3 = FUN_008ea700(uVar1), iVar3 == 0)) &&
           ((iVar3 = FUN_008f1a40(), iVar3 == 0 && (iVar3 = FUN_008ea950(), iVar3 == 0)))) {
          iVar3 = FUN_008ea9b0();
        }
        if (((*(int *)(*(int *)(param_2 + 0x80) + 0x30) == 0) && (*(int *)(param_2 + 0x1c) != 0)) &&
           ((*(int *)(param_2 + 700) != 0 && (cVar2 = FUN_008ebab0(), cVar2 != '\0')))) {
          *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffe;
        }
      }
      FUN_008f1f00();
      return iVar3;
    }
    return iVar3;
  }
  return iVar3;
}

