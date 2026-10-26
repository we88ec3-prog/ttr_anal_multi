
void FUN_008fd520(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = FUN_00572120();
  uVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)uVar1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)uVar1 * 4));
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  uVar1 = 0;
  iVar3 = FUN_00572120();
  if (iVar3 != 0) {
    do {
      iVar3 = FUN_00891268(0x20);
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_00571ec0();
      }
      *(undefined4 *)(*(int *)(param_1 + 0x14) + uVar1 * 4) = uVar2;
      FUN_00572140();
      FUN_008fd450();
      uVar1 = uVar1 + 1;
      uVar4 = FUN_00572120();
    } while (uVar1 < uVar4);
  }
  return;
}

