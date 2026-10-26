
undefined4 * FUN_00626590(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a3f7;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00629e40(param_1);
  local_8 = 0;
  *param_1 = FUI::CJoyStickOptionDefWnd::vftable;
  param_1[0x49] = 0;
  iVar2 = FUN_00891268(0x8c,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x48] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0x48] + 4) = param_1[0x48];
  *(undefined4 *)(param_1[0x48] + 8) = param_1[0x48];
  *(undefined1 *)(param_1[0x48] + 0x88) = 1;
  *(undefined1 *)(param_1[0x48] + 0x89) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[0x4d] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0x4c] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x4c] + 4) = param_1[0x4c];
    *(undefined4 *)(param_1[0x4c] + 8) = param_1[0x4c];
    *(undefined1 *)(param_1[0x4c] + 0x14) = 1;
    *(undefined1 *)(param_1[0x4c] + 0x15) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

