
undefined4 FUN_00549980(int param_1,uint param_2,byte param_3,int param_4)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int local_34;
  int local_30;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fd7c;
  local_14 = ExceptionList;
  if (*(int *)(param_1 + 0x50) == 0) {
    return 0;
  }
  uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0x50) + 0x88);
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((((uVar8 < 10) &&
       (iVar7 = uVar8 * 0x210 + DAT_00f94304, *(int *)(uVar8 * 0x210 + 0x5c + DAT_00f94304) != 0))
      && (iVar7 != 0)) && (iVar3 = iVar7 + 500, iVar3 != 0)) {
    uVar1 = *(undefined1 *)((uint)(*(char *)(iVar7 + 0x1f6) != '\0') + iVar3);
    if ((DAT_00fab278 & 1) == 0) {
      DAT_00fab278 = DAT_00fab278 | 1;
      local_c = 1;
      FUN_00817da0();
      _atexit((_func_4879 *)&LAB_00bcced0);
    }
    local_c = 0xffffffff;
    iVar4 = FUN_00819220(uVar8,uVar1);
    if (iVar4 != 0) {
      if (3 < (byte)param_2) {
        ExceptionList = local_14;
        return 0;
      }
      if (10 < param_3) {
        ExceptionList = local_14;
        return 0;
      }
      sVar2 = *(short *)(iVar4 + 4 + ((param_2 & 0xff) * 0xb + (uint)param_3) * 2);
      if (sVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      FUN_00404ba0();
      iVar5 = FUN_00825f70(sVar2);
      if (iVar5 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      uVar6 = FUN_00484eb0();
      local_34 = FUN_00530530(uVar6);
      uVar6 = FUN_00484eb0();
      iVar5 = FUN_005305c0(uVar6);
      uVar6 = FUN_00484eb0();
      local_30 = FUN_00530650(uVar6);
      if (((param_2 == 1) && (*(int *)(*(int *)(param_1 + 0x50) + 1000) != 1)) &&
         (iVar4 = FUN_00825f70(*(undefined2 *)(iVar4 + 0x12)), iVar4 != 0)) {
        uVar6 = FUN_00484eb0();
        iVar4 = FUN_00530530(uVar6);
        local_34 = local_34 + iVar4;
        uVar6 = FUN_00484eb0();
        iVar4 = FUN_005305c0(uVar6);
        iVar5 = iVar5 + iVar4;
        uVar6 = FUN_00484eb0();
        iVar4 = FUN_00530650(uVar6);
        local_30 = local_30 + iVar4;
      }
      iVar4 = *(int *)(param_1 + 0x50);
      if (*(int *)(iVar4 + 0x3c8) + local_34 < 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (*(int *)(iVar4 + 0x3cc) + iVar5 < 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (*(int *)(iVar4 + 0x3d0) + local_30 < 0) {
        ExceptionList = local_14;
        return 0;
      }
      local_1c = CONCAT31((int3)((uint)iVar3 >> 8),
                          *(undefined1 *)((uint)(*(char *)(iVar7 + 0x1f6) != '\0') + iVar3));
      FUN_00548d20();
      iVar7 = FUN_0054f270(local_1c,param_2);
      if (iVar7 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (param_4 == 0) {
        ExceptionList = local_14;
        return 1;
      }
      if (*(uint *)(*(int *)(param_1 + 0x50) + 1000) == param_2) {
        ExceptionList = local_14;
        return 1;
      }
      ExceptionList = local_14;
      return 0;
    }
  }
  ExceptionList = local_14;
  return 0;
}

