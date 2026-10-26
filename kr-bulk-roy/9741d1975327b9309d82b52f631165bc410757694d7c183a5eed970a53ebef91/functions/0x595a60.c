
undefined4 * FUN_00595a60(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912a27;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00760d60(param_1);
  local_8 = 0;
  *param_1 = FUI::CBasePage::vftable;
  param_1[0x2a] = 0;
  iVar2 = FUN_00891268(0x14,uVar1);
  if (iVar2 != 0) {
    param_1[0x29] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x29] + 4) = param_1[0x29];
    *(undefined4 *)(param_1[0x29] + 8) = param_1[0x29];
    *(undefined1 *)(param_1[0x29] + 0x10) = 1;
    *(undefined1 *)(param_1[0x29] + 0x11) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    *(undefined2 *)(param_1 + 0x2c) = 0;
    param_1[0x2d] = 0;
    *(undefined1 *)(param_1 + 0x2e) = 0;
    DVar3 = timeGetTime();
    param_1[0x2f] = DVar3;
    _eh_vector_constructor_iterator_(param_1 + 0x30,0x10,3,FUN_006d2c40,FUN_00595c10);
    param_1[0x3c] = 0;
    param_1[0x3d] = 0;
    param_1[0x3e] = 0;
    param_1[0x3f] = 0;
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined1 *)((int)param_1 + 0x102) = 0;
    *(undefined1 *)(param_1 + 0x41) = 0;
    param_1[0x42] = 0;
    param_1[0x43] = 0;
    *(undefined2 *)(param_1 + 0x44) = 0;
    *(undefined1 *)((int)param_1 + 0x112) = 0;
    *(undefined1 *)(param_1 + 0x45) = 0;
    param_1[0x46] = 0;
    param_1[0x47] = 0;
    *(undefined2 *)(param_1 + 0x48) = 0;
    *(undefined1 *)((int)param_1 + 0x122) = 0;
    *(undefined1 *)(param_1 + 0x49) = 0;
    param_1[0x4a] = 0;
    param_1[0x4b] = 0;
    param_1[0x4c] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

