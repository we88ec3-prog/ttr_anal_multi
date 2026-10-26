
undefined4 FUN_00537d90(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  undefined1 local_8 [4];
  
  FUN_008438c0(local_8);
  if ((local_c != *(int *)(in_ECX + 0x14)) && (iVar1 = *(int *)(local_c + 0x10), iVar1 != 0)) {
    FUN_008438c0(&stack0x00000004);
    if (local_c != *(int *)(iVar1 + 0x30)) {
      return *(undefined4 *)(local_c + 0x10);
    }
  }
  return 0;
}

