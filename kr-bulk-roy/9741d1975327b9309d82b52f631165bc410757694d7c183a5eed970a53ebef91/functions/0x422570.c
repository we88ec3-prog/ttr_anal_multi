
undefined4 FUN_00422570(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar1 != 0) {
    *(uint *)(in_ECX + 0x5ee0) = (uint)*(ushort *)(iVar1 + 0x88);
    *(undefined4 *)(in_ECX + 0x5ed0) = 1;
    if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
      FUN_007a76b0(*(int *)(iVar1 + 0x15c));
    }
  }
  return 1;
}

