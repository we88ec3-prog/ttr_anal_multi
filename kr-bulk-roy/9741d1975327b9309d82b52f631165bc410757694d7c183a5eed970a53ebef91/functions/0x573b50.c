
void FUN_00573b50(void)

{
  int iVar1;
  int in_ECX;
  int *unaff_EDI;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if (*unaff_EDI == 0) {
    local_14 = FUN_00891268(0x10,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (local_14 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00574160();
    }
    *unaff_EDI = iVar1;
  }
  local_8 = 0xffffffff;
  iVar1 = *unaff_EDI;
  FUN_007b7d40(*(undefined4 *)(*(int *)(iVar1 + 4) + 4));
  *(int *)(*(int *)(iVar1 + 4) + 4) = *(int *)(iVar1 + 4);
  *(undefined4 *)*(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 4);
  *(int *)(*(int *)(iVar1 + 4) + 8) = *(int *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 8) = 0;
  FUN_00574250(unaff_EDI + 1,&local_14,unaff_EDI[1],unaff_EDI[2]);
  unaff_EDI[0x11] = 0;
  ExceptionList = local_10;
  return;
}

