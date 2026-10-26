
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00862d10(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009069d6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe3488;
  DAT_00fe34a0 = 0;
  DAT_00fe34a4 = 0;
  _DAT_00fe34a8 = 0;
  local_8 = 0;
  DAT_00fe34b0 = (undefined4 *)0x0;
  puVar2 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe34b0 = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  *DAT_00fe34b0 = &DAT_00fe34b0;
  _DAT_00fe34b4 = 0;
  _DAT_00fe34b8 = 0;
  _DAT_00fe34bc = 0;
  _DAT_00fe34c0 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  _DAT_00fe34d0 = 0;
  iVar3 = FUN_00891268(0x18,uVar1);
  if (iVar3 != 0) {
    DAT_00fe34cc = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(DAT_00fe34cc + 4) = DAT_00fe34cc;
    *(int *)(DAT_00fe34cc + 8) = DAT_00fe34cc;
    *(undefined1 *)(DAT_00fe34cc + 0x14) = 1;
    *(undefined1 *)(DAT_00fe34cc + 0x15) = 1;
    ExceptionList = local_10;
    return &DAT_00fe3488;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

