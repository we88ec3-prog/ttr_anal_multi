
void FUN_0057d930(int param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092948a;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(local_14);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_54 = param_1;
  FUN_008438c0(&local_54);
  if (local_50 != DAT_00f8d91c) {
    psVar6 = *(short **)(local_50 + 0x10);
    if (psVar6 != (short *)0x0) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8 = 1;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_8 = 0xffffffff;
      }
      local_50 = *(int *)(psVar6 + 0x10);
      iVar3 = FUN_005c7190();
      if (iVar3 != 0) {
        FUN_0082ef00(&local_50);
        if ((local_54 != *(int *)(iVar3 + 0xc)) && (*(int *)(local_54 + 0x10) != 0)) {
          local_1c = 0xf;
          local_20 = 0;
          local_30 = local_30 & 0xffffff00;
          FUN_00402a70(&DAT_00c0dc30,4);
          local_8 = 2;
          uVar4 = FUN_00557de0();
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_005752e0(*(undefined4 *)(in_ECX + 4),uVar4);
          if (7 < local_38) {
            FUN_0089120c(local_4c);
          }
          local_8 = 0xffffffff;
          local_38 = 7;
          local_3c = 0;
          local_4c = local_4c & 0xffff0000;
          if (0xf < local_1c) {
            FUN_0089120c(local_30);
          }
          local_1c = 0xf;
          local_20 = 0;
          local_30 = local_30 & 0xffffff00;
        }
      }
      if (7 < *(uint *)(psVar6 + 10)) {
        psVar6 = *(short **)psVar6;
      }
      psVar5 = psVar6;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
      uVar2 = DAT_00fe2878 & 1;
      *(undefined4 *)(in_ECX + 0xc4) = param_2;
      if (uVar2 == 0) {
        DAT_00fe2878 = DAT_00fe2878 | 1;
        local_8 = 4;
        FUN_0052b6c0();
        _atexit((_func_4879 *)&LAB_00bcf300);
      }
      FUN_0052bcd0(*(undefined4 *)(in_ECX + 0xc0),param_1,param_2);
      FUN_0057d820();
      *(undefined4 *)(in_ECX + 0x94) = 1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

