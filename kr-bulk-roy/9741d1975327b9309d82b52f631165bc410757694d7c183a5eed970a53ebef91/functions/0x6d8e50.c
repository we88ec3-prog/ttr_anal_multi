
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d8e50(void)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined **local_5c [3];
  char *local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091603d;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fc0fdc = 0xf;
  _DAT_00fc0fd8 = 0;
  _DAT_00fc0fc8 = (undefined1 *)((uint)_DAT_00fc0fc8 & 0xffffff00);
  local_8 = 0;
  DAT_00fc0fe4 = 0;
  _DAT_00fc0fe8 = 0;
  _DAT_00fc0fec = 0;
  _DAT_00fc0ff4 = 0;
  iVar3 = FUN_00891268(0x40,local_14);
  if (iVar3 != 0) {
    DAT_00fc0ff0 = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(DAT_00fc0ff0 + 4) = DAT_00fc0ff0;
    local_8._0_1_ = 1;
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    FUN_00402a70(&DAT_00bf2375,0);
    local_8._0_1_ = 2;
    DAT_00fc0ffc = 0;
    DAT_00fc1014 = 0xf;
    _DAT_00fc1010 = 0;
    DAT_00fc1000._0_1_ = 0;
    FUN_00403040(local_30,0,0xffffffff);
    _DAT_00fc1028 = 0x3f800000;
    _DAT_00fc102c = 0x40400000;
    _DAT_00fc101c = 1;
    _DAT_00fc1020 = 10000;
    _DAT_00fc1024 = 0;
    _DAT_00fc1030 = 0;
    local_8._0_1_ = 4;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    FUN_00402a70(&DAT_00bf2375,0);
    local_8 = CONCAT31(local_8._1_3_,5);
    DAT_00fc1034 = 0;
    DAT_00fc104c = 0xf;
    _DAT_00fc1048 = 0;
    DAT_00fc1038._0_1_ = 0;
    FUN_00403040(local_4c,0,0xffffffff);
    _DAT_00fc1060 = 0x3f800000;
    _DAT_00fc1064 = 0x40400000;
    _DAT_00fc1054 = 1;
    _DAT_00fc1058 = 10000;
    _DAT_00fc105c = 0;
    _DAT_00fc1068 = 0;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    _DAT_00fc106c = 0;
    _DAT_00fc1070 = 0;
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fc107c,4000);
    local_8._0_1_ = 8;
    local_50 = (char *)FUN_00891268(0x18);
    local_8._0_1_ = 9;
    if (local_50 == (char *)0x0) {
      DAT_00fc1074 = 0;
    }
    else {
      puVar4 = (undefined4 *)FUN_00891268(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        DAT_00fc1074 = FUN_006d8d20();
      }
      else {
        *puVar4 = FunctorArg0Inst<void,CMusicPlayer>::vftable;
        puVar4[1] = &DAT_00fc0fc8;
        puVar4[2] = FUN_006d9870;
        DAT_00fc1074 = FUN_006d8d20();
      }
    }
    puVar5 = _DAT_00fc0fc8;
    if (DAT_00fc0fdc < 0x10) {
      puVar5 = &DAT_00fc0fc8;
    }
    uVar1 = DAT_00fb8828 & 1;
    *puVar5 = 0;
    if (uVar1 == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8._0_1_ = 10;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    sVar2 = DAT_00fb90ea;
    local_8._0_1_ = 8;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8._0_1_ = 0xb;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_50 = (char *)(int)sVar2;
    FUN_008fed10();
    FUN_006daa70();
    _DAT_00fc106c = FUN_008fed10();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_50 = (char *)0x0;
  std::exception::exception((exception *)local_5c,&local_50);
  local_5c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_5c,&DAT_00c857a8);
}

