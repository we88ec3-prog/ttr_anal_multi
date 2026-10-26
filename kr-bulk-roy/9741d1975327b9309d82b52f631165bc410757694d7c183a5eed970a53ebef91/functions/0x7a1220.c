
void FUN_007a1220(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EDI;
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907a01;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(int *)(unaff_EDI + 0xc) + *(int *)(unaff_EDI + 0x10) & 1U) == 0) &&
     (*(uint *)(unaff_EDI + 8) <= *(int *)(unaff_EDI + 0x10) + 2U >> 1)) {
    FUN_007a1930(unaff_EDI);
  }
  uVar5 = *(int *)(unaff_EDI + 0xc) + *(int *)(unaff_EDI + 0x10);
  uVar6 = uVar5 >> 1;
  if (*(uint *)(unaff_EDI + 8) <= uVar6) {
    uVar6 = uVar6 - *(uint *)(unaff_EDI + 8);
  }
  if (*(int *)(*(int *)(unaff_EDI + 4) + uVar6 * 4) == 0) {
    iVar4 = FUN_00891268(0x10,uVar3);
    if (iVar4 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_14);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *(int *)(*(int *)(unaff_EDI + 4) + uVar6 * 4) = iVar4;
  }
  local_18 = (char *)(*(int *)(*(int *)(unaff_EDI + 4) + uVar6 * 4) + (uVar5 & 1) * 8);
  local_8 = 0;
  if (local_18 != (char *)0x0) {
    local_18[0] = '\0';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
    iVar4 = param_1[1];
    uVar1 = *param_1;
    if (iVar4 != 0) {
      local_14 = local_18;
      cVar2 = FUN_0047c250();
      if (cVar2 != '\0') {
        FUN_007a31c0(uVar1,iVar4);
      }
    }
  }
  *(int *)(unaff_EDI + 0x10) = *(int *)(unaff_EDI + 0x10) + 1;
  ExceptionList = local_10;
  return;
}

