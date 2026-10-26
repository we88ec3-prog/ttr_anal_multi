
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0081e5f0(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092b774;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  DAT_00fb75c8 = 0;
  DAT_00fb75cc = 0;
  _DAT_00fb75d0 = 0;
  DAT_00fb75d8 = 0;
  DAT_00fb75dc = 0;
  _DAT_00fb75e0 = 0;
  DAT_00fb75e8 = 0;
  DAT_00fb75ec = 0;
  _DAT_00fb75f0 = 0;
  DAT_00fb75f8 = 0;
  DAT_00fb75fc = 0;
  _DAT_00fb7600 = 0;
  local_8 = 3;
  uStack_7 = 0;
  DAT_00fb7608 = (int *)0x0;
  FUN_0081ea10(uVar1);
  iVar2 = FUN_00891268(0x14);
  local_8 = 0xb;
  if (iVar2 == 0) {
    DAT_00fb7608 = (int *)0x0;
  }
  else {
    DAT_00fb7608 = (int *)FUN_0081ecf0();
  }
  _local_8 = CONCAT31(uStack_7,3);
  (**(code **)(*DAT_00fb7608 + 4))();
  *unaff_FS_OFFSET = local_10;
  return &DAT_00fb75c8;
}

