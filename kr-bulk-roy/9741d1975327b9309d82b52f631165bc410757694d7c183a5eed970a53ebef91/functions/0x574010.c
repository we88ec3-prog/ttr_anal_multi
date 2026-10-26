
void FUN_00574010(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int unaff_ESI;
  uint uVar3;
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913421;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(unaff_ESI + 8) <= *(int *)(unaff_ESI + 0x10) + 1U) {
    FUN_00574340(unaff_ESI);
  }
  uVar3 = *(int *)(unaff_ESI + 0xc) + *(int *)(unaff_ESI + 0x10);
  if (*(uint *)(unaff_ESI + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(unaff_ESI + 8);
  }
  if (*(int *)(*(int *)(unaff_ESI + 4) + uVar3 * 4) == 0) {
    iVar2 = FUN_00891268(0x1c,uVar1);
    if (iVar2 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_14);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *(int *)(*(int *)(unaff_ESI + 4) + uVar3 * 4) = iVar2;
  }
  local_18 = *(char **)(*(int *)(unaff_ESI + 4) + uVar3 * 4);
  local_8 = 0;
  if (local_18 != (char *)0x0) {
    local_18[0x14] = '\x0f';
    local_18[0x15] = '\0';
    local_18[0x16] = '\0';
    local_18[0x17] = '\0';
    local_18[0x10] = '\0';
    local_18[0x11] = '\0';
    local_18[0x12] = '\0';
    local_18[0x13] = '\0';
    *local_18 = '\0';
    local_14 = local_18;
    FUN_0040b0b0(param_1,0);
  }
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 1;
  ExceptionList = local_10;
  return;
}

