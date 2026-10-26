
short * FUN_004e79c0(undefined4 *param_1,short *param_2)

{
  short *psVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  short sVar7;
  int iVar8;
  short *local_20;
  short *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940538;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  puVar6 = (undefined4 *)*param_1;
  uVar4 = param_1[1] - (int)puVar6 >> 2;
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      psVar1 = (short *)*puVar6;
      if ((*psVar1 == (short)DAT_00f94208) && (*(uint *)(psVar1 + 2) == ((uint)param_2 & 0xffff))) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
        }
        local_c = 0xffffffff;
        local_20 = *(short **)(psVar1 + 2);
        FUN_008438c0(&local_20);
        if (local_1c[0] == DAT_00fb7594) {
          iVar8 = 0;
        }
        else {
          iVar8 = *(int *)(*(int *)(local_1c[0] + 8) + 0x1c);
        }
        if ((int)(uint)(ushort)psVar1[1] < iVar8) {
          if (*(int **)(psVar1 + 0x16) != (int *)0x0) {
            (**(code **)(**(int **)(psVar1 + 0x16) + 8))();
            psVar1[0x16] = 0;
            psVar1[0x17] = 0;
          }
          psVar1[1] = (short)iVar8;
          psVar1[0x12] = 1;
          psVar1[0x13] = 0;
          psVar1[0x14] = 0;
          psVar1[0x15] = 0;
        }
        ExceptionList = local_14;
        return psVar1;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < uVar4);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar2 = DAT_00f94208;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  local_1c[0] = param_2;
  FUN_008438c0(local_1c);
  if (local_20 == DAT_00fb7594) {
    sVar7 = 0;
  }
  else {
    sVar7 = (short)*(undefined4 *)(*(int *)(local_20 + 8) + 0x1c);
  }
  local_20 = (short *)FUN_00891268(0x30);
  if (local_20 == (short *)0x0) {
    local_20 = (short *)0x0;
  }
  else {
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    local_20[0xe] = 7;
    local_20[0xf] = 0;
    local_20[0xc] = 0;
    local_20[0xd] = 0;
    local_20[4] = 0;
    local_20[0x12] = 0;
    local_20[0x13] = 0;
    local_20[0x14] = 0;
    local_20[0x15] = 0;
    local_20[0x16] = 0;
    local_20[0x17] = 0;
  }
  *local_20 = (short)uVar2;
  *(short **)(local_20 + 2) = param_2;
  local_20[1] = sVar7;
  local_20[0x12] = 1;
  local_20[0x13] = 0;
  FUN_00443d10();
  ExceptionList = local_14;
  return local_20;
}

