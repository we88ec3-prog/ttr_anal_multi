
void FUN_0067bfa0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932ec8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = 0;
  piVar5 = (int *)(param_1 + 300);
  while ((piVar5[-1] != -1 && (*piVar5 != -1))) {
    iVar2 = iVar2 + 1;
    piVar5 = piVar5 + 0xe;
    if (1 < iVar2) {
LAB_0067bff4:
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 0;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_8 = 0xffffffff;
      local_18 = *(int *)(param_1 + 300);
      FUN_008438c0(&local_18);
      if (local_14 == DAT_00f8d91c) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(local_14 + 0x10);
      }
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 1;
        FUN_00523540();
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      local_18 = *(int *)(iVar2 + 0x20);
      FUN_008438c0(&local_18);
      if (local_14 == DAT_00f8d9b0) {
        local_18 = 0;
      }
      else {
        local_18 = *(int *)(local_14 + 0x10);
      }
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 3;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      local_14 = *(int *)(param_1 + 0x164);
      FUN_008438c0(&local_14);
      if (local_1c == DAT_00f8d91c) {
        local_14 = 0;
      }
      else {
        local_14 = *(int *)(local_1c + 0x10);
      }
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 4;
        FUN_00523540();
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      if ((DAT_00fc0cf8 & 1) == 0) {
        DAT_00fc0cf8 = DAT_00fc0cf8 | 1;
        local_8 = 6;
        FUN_0052be80();
        _atexit((_func_4879 *)&LAB_00bcd790);
        local_8 = 0xffffffff;
      }
      uVar1 = DAT_00fc0cf8;
      local_1c = *(int *)(iVar2 + 0x20);
      FUN_0052cf40(&local_1c);
      if (local_20 == DAT_00fc0d24) {
        iVar2 = 0;
      }
      else {
        iVar2 = local_20 + 0x18;
      }
      if ((uVar1 & 1) == 0) {
        DAT_00fc0cf8 = uVar1 | 1;
        local_8 = 7;
        FUN_0052be80();
        _atexit((_func_4879 *)&LAB_00bcd790);
        local_8 = 0xffffffff;
        uVar1 = DAT_00fc0cf8;
      }
      local_20 = *(int *)(local_14 + 0x20);
      FUN_0052cf40(&local_20);
      if (local_1c == DAT_00fc0d24) {
        iVar10 = 0;
      }
      else {
        iVar10 = local_1c + 0x18;
      }
      if ((((*(int *)(iVar2 + 0x10) == *(int *)(iVar10 + 0x10)) &&
           (*(int *)(iVar2 + 0x14) == *(int *)(iVar10 + 0x14))) &&
          (*(int *)(iVar2 + 8) == *(int *)(iVar10 + 8))) &&
         (*(int *)(iVar2 + 0xc) == *(int *)(iVar10 + 0xc))) {
        if ((uVar1 & 1) == 0) {
          DAT_00fc0cf8 = uVar1 | 1;
          local_8 = 10;
          FUN_0052be80();
          _atexit((_func_4879 *)&LAB_00bcd790);
          local_8 = 0xffffffff;
        }
        local_20 = (uint)*(ushort *)(iVar10 + 4) + (uint)*(ushort *)(iVar2 + 4);
        FUN_0052ced0(&local_20);
        if (local_1c == DAT_00fc0d14) {
          local_14 = 0;
        }
        else {
          local_14 = local_1c + 0x10;
        }
        uVar3 = *(undefined4 *)(iVar2 + 8);
        if (*(int *)(iVar2 + 0x18) == 0) {
          uVar12 = *(undefined4 *)(local_18 + 0x6c);
          uVar11 = *(undefined4 *)(iVar2 + 0xc);
          uVar13 = *(undefined4 *)(iVar2 + 0x10);
          uVar14 = *(undefined4 *)(iVar2 + 0x14);
          uVar1 = (uint)(ushort)(*(short *)(iVar2 + 4) + 1);
          uVar4 = FUN_0045af80(uVar1,uVar3,uVar11,uVar13,uVar14,uVar12);
          uVar3 = FUN_0052cd10(uVar4,uVar1,uVar3,uVar11,uVar13,uVar14,uVar12);
        }
        else {
          uVar12 = *(undefined4 *)(iVar2 + 0xc);
          uVar11 = *(undefined4 *)(iVar2 + 0x10);
          uVar13 = *(undefined4 *)(iVar2 + 0x14);
          uVar1 = (uint)(ushort)(*(short *)(iVar2 + 4) + 1);
          FUN_0045af80(uVar1,uVar1,uVar3,uVar12,uVar11,uVar13);
          uVar3 = FUN_0052ccc0(uVar1,uVar3,uVar12,uVar11,uVar13);
        }
        *(undefined4 *)(param_1 + 0x194) = uVar3;
      }
      else {
        if ((uVar1 & 1) == 0) {
          DAT_00fc0cf8 = uVar1 | 1;
          local_8 = 8;
          FUN_0052be80();
          _atexit((_func_4879 *)&LAB_00bcd790);
          local_8 = 0xffffffff;
          uVar1 = DAT_00fc0cf8;
        }
        local_20 = (uint)*(ushort *)(iVar10 + 4) + (uint)*(ushort *)(iVar2 + 4);
        FUN_0052ced0(&local_20);
        if (local_1c == DAT_00fc0d04) {
          local_14 = 0;
        }
        else {
          local_14 = local_1c + 0x10;
        }
        uVar8 = *(uint *)(iVar10 + 0x10) | *(uint *)(iVar2 + 0x10);
        uVar6 = *(uint *)(iVar10 + 0x14) | *(uint *)(iVar2 + 0x14);
        uVar9 = *(uint *)(iVar2 + 8) | *(uint *)(iVar10 + 8);
        uVar7 = *(uint *)(iVar2 + 0xc) | *(uint *)(iVar10 + 0xc);
        if ((uVar1 & 1) == 0) {
          DAT_00fc0cf8 = uVar1 | 1;
          local_8 = 9;
          FUN_0052be80(uVar9,uVar7,uVar8,uVar6);
          _atexit((_func_4879 *)&LAB_00bcd790);
          local_8 = 0xffffffff;
        }
        uVar3 = FUN_0052ccc0(*(undefined2 *)(iVar2 + 4),uVar9,uVar7,uVar8,uVar6);
        *(undefined4 *)(param_1 + 0x194) = uVar3;
      }
      FUN_00444090();
      *(int *)(param_1 + 400) = local_14;
      ExceptionList = local_10;
      return;
    }
  }
  if (iVar2 != -1) {
    *(undefined4 *)(param_1 + 400) = 0;
    *(undefined4 *)(param_1 + 0x194) = 0;
    FUN_00757710(uVar1);
    ExceptionList = local_10;
    return;
  }
  goto LAB_0067bff4;
}

