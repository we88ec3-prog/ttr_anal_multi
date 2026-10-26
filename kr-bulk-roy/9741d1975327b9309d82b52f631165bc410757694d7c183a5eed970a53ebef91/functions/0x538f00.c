
void FUN_00538f00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *unaff_EDI;
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = param_1;
  FUN_008438c0(&param_1);
  if ((local_8 != *(int *)(iVar1 + 0x14)) && (iVar2 = *(int *)(local_8 + 0x10), iVar2 != 0)) {
    FUN_008438c0(local_c);
    if ((param_1 != *(int *)(iVar2 + 0x30)) && (iVar2 = *(int *)(param_1 + 0x10), iVar2 != 0)) {
      FUN_00539110(&param_1);
      iVar1 = *(int *)(iVar1 + 4);
      *(undefined4 *)(unaff_EDI + 10) = 7;
      *(undefined4 *)(unaff_EDI + 8) = 0;
      if (param_1 != iVar1) {
        *unaff_EDI = 0;
        FUN_004026e0(param_1 + 0x28,0,0xffffffff);
        return;
      }
      *unaff_EDI = 0;
      FUN_004026e0(iVar2,0,0xffffffff);
      return;
    }
  }
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  return;
}

