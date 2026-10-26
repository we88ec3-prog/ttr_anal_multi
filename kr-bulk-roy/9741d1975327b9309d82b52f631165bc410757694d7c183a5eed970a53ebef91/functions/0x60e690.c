
void FUN_0060e690(undefined4 param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092de2e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = 0;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  uStack_7 = 0;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x180) + 0x154) = 0xffffffff;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 1;
    uStack_7 = 0;
    FUN_0052f7e0(local_14);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0;
  iVar5 = 0;
  local_50 = 0;
  if (param_2 != 0) {
    iVar6 = FUN_00530530(&DAT_00fc1098);
    iVar5 = FUN_005305c0(&DAT_00fc1098);
    local_50 = FUN_00530650(&DAT_00fc1098);
  }
  local_50 = local_50 + *(short *)(unaff_EDI + 0x19c);
  sVar1 = *(short *)(unaff_EDI + 0x19e);
  iVar6 = iVar6 + *(short *)(unaff_EDI + 0x198);
  iVar5 = iVar5 + *(short *)(unaff_EDI + 0x19a);
  sVar2 = *(short *)(unaff_EDI + 0x1a0);
  sVar3 = *(short *)(unaff_EDI + 0x1a2);
  if ((((*(short *)(unaff_EDI + 0x198) != 0) || (*(short *)(unaff_EDI + 0x19e) != 0)) ||
      (*(short *)(unaff_EDI + 0x19a) != 0)) ||
     (((*(short *)(unaff_EDI + 0x1a0) != 0 || (*(short *)(unaff_EDI + 0x19c) != 0)) ||
      (*(short *)(unaff_EDI + 0x1a2) != 0)))) {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x180) + 0x154) = 0xff5aff78;
  }
  if (iVar6 + (sVar1 * iVar6) / 100 != 0) {
    uVar4 = FUN_004068f0();
    local_8 = 2;
    FUN_004041f0(uVar4,0,0xffffffff);
    local_8 = 0;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  if (iVar5 + (sVar2 * iVar5) / 100 != 0) {
    uVar4 = FUN_004068f0();
    local_8 = 3;
    FUN_004041f0(uVar4,0,0xffffffff);
    local_8 = 0;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  if (local_50 + (sVar3 * local_50) / 100 != 0) {
    uVar4 = FUN_004068f0();
    local_8 = 4;
    FUN_004041f0(uVar4,0,0xffffffff);
    local_8 = 0;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  FUN_00757800(local_30);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

