
void FUN_005201b0(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *unaff_EDI;
  int local_24 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d1f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (1 < (in_ECX - (int)unaff_EDI) / 0x14) {
    iVar2 = in_ECX + -0x10;
    local_14 = 0x10 - (int)unaff_EDI;
    do {
      FUN_004fcd00(local_24,iVar2);
      local_8 = 0;
      *(undefined4 *)(iVar2 + -4) = *unaff_EDI;
      FUN_004fcdc0(unaff_EDI + 1);
      FUN_005203e0();
      local_8 = 0xffffffff;
      if (local_24[0] != 0) {
        FUN_0089120c(local_24[0],uVar1);
      }
      iVar2 = iVar2 + -0x14;
    } while (1 < (local_14 + iVar2) / 0x14);
  }
  ExceptionList = local_10;
  return;
}

