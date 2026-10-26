
void FUN_005a5330(int param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  int *piVar5;
  short *psVar6;
  undefined4 ****ppppuVar7;
  undefined4 ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00939b69;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffff0000);
  uStack_7 = 0;
  if ((DAT_00fb72e8 & 1) == 0) {
    DAT_00fb72e8 = DAT_00fb72e8 | 1;
    DAT_00fb72ec = 0;
    DAT_00fb72f0 = 0;
    DAT_00fb72f4 = 0;
    local_8 = 2;
    uStack_7 = 0;
    FUN_0049ef70(local_14);
    _atexit(FUN_00bccff0);
  }
  local_8 = 0;
  uVar4 = DAT_00fb72f0 - DAT_00fb72ec >> 6;
  uVar2 = 0;
  if (uVar4 != 0) {
    piVar5 = (int *)(DAT_00fb72ec + 0x3c);
    do {
      if (param_1 + 1 == *piVar5) {
        psVar6 = (short *)(uVar2 * 0x40 + DAT_00fb72ec);
        if (7 < *(uint *)(psVar6 + 10)) {
          psVar6 = *(short **)psVar6;
        }
        goto LAB_005a53ea;
      }
      uVar2 = uVar2 + 1;
      piVar5 = piVar5 + 0x10;
    } while (uVar2 < uVar4);
  }
  psVar6 = &DAT_00bed1fc;
LAB_005a53ea:
  psVar3 = psVar6;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar6,(int)psVar3 - (int)(psVar6 + 1) >> 1);
  if (local_20 != 0) {
    ppppuVar7 = (undefined4 ****)local_30[0];
    if (local_1c < 8) {
      ppppuVar7 = local_30;
    }
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 3;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = 0;
    }
    FUN_004d5ae0(&DAT_00fb11e8,0,ppppuVar7);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

