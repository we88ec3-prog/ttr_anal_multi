
undefined4 FUN_00537df0(int param_1)

{
  int iVar1;
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = param_1;
  FUN_008438c0(&param_1);
  if ((local_8 != *(int *)(iVar1 + 0x14)) && (iVar1 = *(int *)(local_8 + 0x10), iVar1 != 0)) {
    FUN_008438c0(local_c);
    if ((param_1 != *(int *)(iVar1 + 0x30)) && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0)) {
      FUN_008438c0(&stack0x00000008);
      if (param_1 != *(int *)(iVar1 + 0x30)) {
        return *(undefined4 *)(param_1 + 0x10);
      }
    }
  }
  return 0;
}

