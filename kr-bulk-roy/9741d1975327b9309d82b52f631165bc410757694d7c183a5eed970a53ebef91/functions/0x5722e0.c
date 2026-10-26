
void FUN_005722e0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  
  uVar1 = thunk_FUN_005723e0();
  if (uVar1 < param_1) {
    FUN_005723b0();
  }
  uVar1 = FUN_00572350();
  if (uVar1 < param_1) {
    iVar2 = thunk_FUN_007d01e0();
    FUN_005724c0(*unaff_ESI);
    iVar3 = FUN_00572120();
    if (*unaff_ESI != 0) {
      FUN_005723c0();
    }
    *unaff_ESI = iVar2;
    unaff_ESI[2] = iVar2 + param_1 * 4;
    unaff_ESI[1] = iVar2 + iVar3 * 4;
  }
  return;
}

