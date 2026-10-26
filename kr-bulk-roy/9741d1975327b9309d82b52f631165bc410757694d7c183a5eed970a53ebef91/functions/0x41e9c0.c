
void FUN_0041e9c0(int param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  int in_ECX;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  short *psVar8;
  undefined4 ****ppppuVar9;
  int local_34;
  undefined4 ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009398f9;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    piVar5 = (int *)(in_ECX + 0xec);
    local_34 = 0;
    do {
      if (*(int *)(param_1 + 8) == *(int *)(*piVar5 + 0x20)) {
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffff0000);
        local_8._1_3_ = 0;
        if ((DAT_00fb72e8 & 1) == 0) {
          DAT_00fb72e8 = DAT_00fb72e8 | 1;
          DAT_00fb72ec = 0;
          DAT_00fb72f0 = 0;
          DAT_00fb72f4 = 0;
          local_8._0_1_ = 2;
          local_8._1_3_ = 0;
          FUN_0049ef70(uVar2);
          _atexit(FUN_00bccff0);
        }
        local_8._0_1_ = 0;
        uVar6 = DAT_00fb72f0 - DAT_00fb72ec >> 6;
        uVar3 = 0;
        if (uVar6 != 0) {
          piVar7 = (int *)(DAT_00fb72ec + 0x3c);
          do {
            if (local_34 + 1 == *piVar7) {
              psVar8 = (short *)(uVar3 * 0x40 + DAT_00fb72ec);
              if (7 < *(uint *)(psVar8 + 10)) {
                psVar8 = *(short **)psVar8;
              }
              goto LAB_0041eaa3;
            }
            uVar3 = uVar3 + 1;
            piVar7 = piVar7 + 0x10;
          } while (uVar3 < uVar6);
        }
        psVar8 = &DAT_00bed1fc;
LAB_0041eaa3:
        psVar4 = psVar8;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00402160(psVar8,(int)psVar4 - (int)(psVar8 + 1) >> 1);
        if (local_20 != 0) {
          ppppuVar9 = (undefined4 ****)local_30[0];
          if (local_1c < 8) {
            ppppuVar9 = local_30;
          }
          if ((DAT_00fb11e0 & 1) == 0) {
            DAT_00fb11e0 = DAT_00fb11e0 | 1;
            local_8._0_1_ = 3;
            FUN_004d4d10();
            _atexit((_func_4879 *)&LAB_00bccef0);
            local_8._0_1_ = 0;
          }
          FUN_004d5ae0(&DAT_00fb11e8,0,ppppuVar9);
        }
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      local_34 = local_34 + 1;
      piVar5 = piVar5 + 1;
    } while (local_34 < 0x12);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

