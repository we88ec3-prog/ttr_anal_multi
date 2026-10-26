
void FUN_007997a0(void)

{
  int iVar1;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x470,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00839940();
  }
  local_8 = 0xffffffff;
  *unaff_ESI = iVar1;
  if (unaff_ESI[0x29] == 0) {
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  else {
    *(uint *)(iVar1 + 0xd0) = (uint)(unaff_ESI[0x29] == 3);
  }
  FUN_00799840();
  ExceptionList = local_10;
  return;
}

