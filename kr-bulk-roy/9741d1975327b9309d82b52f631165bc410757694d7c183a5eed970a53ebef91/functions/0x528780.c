
undefined4 * FUN_00528780(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d193;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fc0e34 = param_1;
  param_1[1] = IDataTable::vftable;
  local_8 = 1;
  *param_1 = COptionGrantTable::vftable;
  param_1[1] = COptionGrantTable::vftable;
  param_1[4] = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    param_1[3] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[3] + 4) = param_1[3];
    *(undefined4 *)(param_1[3] + 8) = param_1[3];
    *(undefined1 *)(param_1[3] + 0x2c) = 1;
    *(undefined1 *)(param_1[3] + 0x2d) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

