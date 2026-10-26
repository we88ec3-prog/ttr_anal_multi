
void FUN_00538e60(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined2 *unaff_EDI;
  int local_c;
  undefined1 local_8 [4];
  
  local_c = 0;
  FUN_008438c0(local_8);
  if ((local_c != *(int *)(in_ECX + 0x14)) && (iVar2 = *(int *)(local_c + 0x10), iVar2 != 0)) {
    FUN_00539110(&local_c);
    iVar1 = *(int *)(in_ECX + 4);
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    if (local_c != iVar1) {
      *unaff_EDI = 0;
      FUN_004026e0(local_c + 0x28,0,0xffffffff);
      return;
    }
    *unaff_EDI = 0;
    FUN_004026e0(iVar2,0,0xffffffff);
    return;
  }
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  return;
}

