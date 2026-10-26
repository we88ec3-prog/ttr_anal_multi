
undefined4 FUN_00831e00(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  undefined4 local_10;
  int local_c;
  undefined1 local_8 [4];
  
  iVar1 = unaff_EDI[3];
  FUN_00835c70(local_8);
  iVar2 = local_c;
  if (local_c != *(int *)(iVar1 + 4)) {
    FUN_00835c70(&local_10);
    if ((local_c != *(int *)(iVar2 + 0x14)) && ((undefined4 *)(local_c + 0x10) != (undefined4 *)0x0)
       ) {
      local_10 = *(undefined4 *)(local_c + 0x10);
      iVar1 = *unaff_EDI;
      FUN_0052ced0(&local_10);
      if (local_c != *(int *)(iVar1 + 4)) {
        return *(undefined4 *)(local_c + 0x20);
      }
    }
  }
  return 0;
}

