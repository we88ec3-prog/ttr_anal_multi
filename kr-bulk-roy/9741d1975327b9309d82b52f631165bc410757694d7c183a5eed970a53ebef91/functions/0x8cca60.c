
void FUN_008cca60(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int in_EDX;
  uint uVar3;
  int unaff_EDI;
  int local_8;
  
  uVar2 = *(int *)(unaff_EDI + 4) + 7U >> 3;
  uVar3 = in_EDX + 7U >> 3;
  local_8 = 0;
  if (uVar2 < uVar3) {
    uVar3 = uVar3 + 7 & 0xfffffff8;
    uVar1 = FUN_008bc7d0(param_1,1,uVar2,uVar3,*(undefined4 *)(unaff_EDI + 8),&local_8);
    *(undefined4 *)(unaff_EDI + 8) = uVar1;
    if (local_8 == 0) {
      *(uint *)(unaff_EDI + 4) = uVar3 * 8;
    }
  }
  return;
}

