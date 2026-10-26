
undefined4 * FUN_0073cf50(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  if (DAT_00fba820 == 1) {
    iVar3 = FUN_00891268(0x54,uVar1);
    local_8 = 0;
    if (iVar3 != 0) {
      puVar2 = (undefined4 *)FUN_0073c450(iVar3);
      *unaff_FS_OFFSET = local_10;
      return puVar2;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00891268(0x28,uVar1);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = CFontDriver_GDI::vftable;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      *unaff_FS_OFFSET = local_10;
      return puVar2;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return (undefined4 *)0x0;
}

