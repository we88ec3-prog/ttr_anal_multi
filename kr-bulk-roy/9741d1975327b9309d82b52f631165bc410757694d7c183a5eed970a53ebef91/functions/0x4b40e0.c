
/* WARNING: Removing unreachable block (ram,0x004b4353) */

void FUN_004b40e0(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 ****ppppuVar6;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_00929f02;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 3) == '\x01') {
    if (*(char *)(param_1 + 2) == '\0') {
      if ((DAT_00fc0fc0 & 1) == 0) {
        DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
        local_8 = 6;
        FUN_006d8e50(local_14);
        _atexit((_func_4879 *)&LAB_00bcdbb0);
      }
      local_8._1_3_ = 0xffffff;
      local_8._0_1_ = 0xff;
      FUN_006d9680();
    }
    else {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_8 = 0;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
      local_8 = 0xffffffff;
      pcVar3 = (char *)FUN_004f6e80();
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
      pcVar5 = pcVar3;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
      local_8._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8._0_1_ = 2;
        local_8._1_3_ = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8._0_1_ = 3;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      if ((DAT_00fc0fc0 & 1) == 0) {
        DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
        local_8._0_1_ = 4;
        FUN_006d8e50();
        _atexit((_func_4879 *)&LAB_00bcdbb0);
      }
      ppppuVar6 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar6 = local_30;
      }
      if ((DAT_00fc0fc0 & 1) == 0) {
        DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
        local_8._0_1_ = 5;
        FUN_006d8e50();
        _atexit((_func_4879 *)&LAB_00bcdbb0);
      }
      local_8._0_1_ = 1;
      FUN_008fed10();
      FUN_006daa70();
      uVar2 = FUN_008fed10();
      FUN_006d9b30(&DAT_00fc0fc8,ppppuVar6,1,uVar2);
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
  else {
    pcVar5 = (char *)(param_1 + 4);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_0040b310((char *)(param_1 + 4));
    local_8._1_3_ = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 8;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_8._0_1_ = 7;
    piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

