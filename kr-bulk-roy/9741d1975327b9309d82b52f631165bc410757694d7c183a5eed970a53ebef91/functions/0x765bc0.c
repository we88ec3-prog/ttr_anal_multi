
void FUN_00765bc0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x110) + uVar2 * 4);
      FUN_00757c60(param_1,iVar1,0,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(param_1 + 0x10));
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2));
  }
  return;
}

