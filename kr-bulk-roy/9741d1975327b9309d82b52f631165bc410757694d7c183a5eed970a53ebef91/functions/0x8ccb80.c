
void FUN_008ccb80(undefined4 param_1)

{
  undefined4 uVar1;
  uint in_EDX;
  uint uVar2;
  int unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (*(uint *)(unaff_EDI + 4) < in_EDX) {
    uVar2 = in_EDX + 7 & 0xfffffff8;
    uVar1 = FUN_008bc7d0(param_1,0x10,*(uint *)(unaff_EDI + 4),uVar2,*(undefined4 *)(unaff_EDI + 8),
                         &local_8);
    *(undefined4 *)(unaff_EDI + 8) = uVar1;
    if (local_8 == 0) {
      *(uint *)(unaff_EDI + 4) = uVar2;
    }
  }
  return;
}

