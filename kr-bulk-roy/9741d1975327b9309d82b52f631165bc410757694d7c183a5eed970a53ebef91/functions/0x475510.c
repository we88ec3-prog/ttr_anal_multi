
undefined4 FUN_00475510(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint in_ECX;
  int *piVar8;
  uint uVar9;
  ushort local_28;
  byte local_24;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b913;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  cVar4 = FUN_004756b0(in_ECX);
  if (cVar4 == '\0') {
    ExceptionList = local_10;
    return 0;
  }
  local_14 = *(undefined4 *)(DAT_00fb1318 + 0xbfe8);
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(uVar5);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
    local_8 = 0xffffffff;
  }
  local_18 = in_ECX & 0xffff;
  FUN_008438c0(&local_18);
  if (local_1c == DAT_00f8d9b0) {
    ExceptionList = local_10;
    return 0;
  }
  puVar1 = *(uint **)(local_1c + 0x10);
  if (puVar1 == (uint *)0x0) {
    ExceptionList = local_10;
    return 0;
  }
  uVar5 = puVar1[2];
  if ((uVar5 - 1 < 0x2b) && (iVar6 = FUN_00520f40(), iVar6 != 0)) {
    uVar5 = *puVar1;
  }
  else {
    if ((uVar5 != 0x26) && (uVar5 != 0x27)) {
      ExceptionList = local_10;
      return 1;
    }
    piVar8 = (int *)puVar1[0x52];
    piVar2 = (int *)puVar1[0x53];
    if (piVar8 == piVar2) {
      ExceptionList = local_10;
      return 0;
    }
    iVar6 = FUN_006dd0e0();
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return 0;
    }
    param_2._3_1_ = local_24;
    for (iVar6 = (int)piVar2 - (int)piVar8 >> 2; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar3 = *piVar8;
      if (*(short *)(iVar3 + 8) == 0xd) {
        param_2._3_1_ = *(byte *)(iVar3 + 0xc);
      }
      else if (*(short *)(iVar3 + 8) == 0xe) {
        local_28 = *(ushort *)(iVar3 + 0xc);
      }
      piVar8 = piVar8 + 1;
    }
    uVar5 = (uint)local_28;
    uVar9 = uVar5;
    uVar7 = FUN_00474db0(uVar5);
    iVar6 = FUN_00826610(uVar7,uVar9);
    if (iVar6 != 0) {
      param_2._3_1_ = 0;
    }
    param_1 = (uint)param_2._3_1_;
    param_2 = 0;
  }
  FUN_006dc180(uVar5,param_1,param_2);
  ExceptionList = local_10;
  return 1;
}

