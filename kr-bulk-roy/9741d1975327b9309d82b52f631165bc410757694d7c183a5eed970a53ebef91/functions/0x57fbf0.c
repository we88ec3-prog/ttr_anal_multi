
undefined4 * FUN_0057fbf0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916b06;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Synopsis::CBookNode::vftable;
  param_1[1] = 0;
  local_14 = param_2 + 1;
  param_1[8] = 0xf;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar3 - (int)local_14);
  local_8 = 0;
  param_1[0xc] = 0;
  iVar4 = FUN_00891268(0x30,uVar2);
  if (iVar4 != 0) {
    param_1[0xb] = iVar4;
    *(int *)iVar4 = iVar4;
    *(undefined4 *)(param_1[0xb] + 4) = param_1[0xb];
    *(undefined4 *)(param_1[0xb] + 8) = param_1[0xb];
    *(undefined1 *)(param_1[0xb] + 0x2c) = 1;
    *(undefined1 *)(param_1[0xb] + 0x2d) = 1;
    uVar2 = DAT_00fe1e1c & 1;
    param_1[2] = 0;
    if (uVar2 == 0) {
      DAT_00fe1e1c = DAT_00fe1e1c | 1;
      local_8._0_1_ = 2;
      FUN_007c30c0();
      _atexit(FUN_00bcf1b0);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_007c2880();
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

