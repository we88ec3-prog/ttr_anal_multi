
undefined4 * FUN_005245b0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0091b4e0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fe1bd0 = param_1;
  param_1[1] = IDataTable::vftable;
  local_8 = 1;
  uStack_7 = 0;
  *param_1 = CNPCTable::vftable;
  param_1[1] = CNPCTable::vftable;
  param_1[4] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[3] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[3] + 4) = param_1[3];
  *(undefined4 *)(param_1[3] + 8) = param_1[3];
  *(undefined1 *)(param_1[3] + 0x14) = 1;
  *(undefined1 *)(param_1[3] + 0x15) = 1;
  _local_8 = CONCAT31(uStack_7,2);
  param_1[8] = 0;
  iVar2 = FUN_00891268(0x74,uVar1);
  if (iVar2 != 0) {
    param_1[7] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[7] + 4) = param_1[7];
    *(undefined4 *)(param_1[7] + 8) = param_1[7];
    *(undefined1 *)(param_1[7] + 0x70) = 1;
    *(undefined1 *)(param_1[7] + 0x71) = 1;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

