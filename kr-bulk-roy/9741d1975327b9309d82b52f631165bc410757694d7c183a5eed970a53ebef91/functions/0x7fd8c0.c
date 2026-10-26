
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007fd8c0(int param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  int aiStack_9c [9];
  undefined4 uStack_78;
  undefined *puStack_74;
  int local_58 [17];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar3 = param_1;
  puStack_c = &LAB_009372d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_58[0xb] = 0;
  local_58[0xc] = 0;
  local_58[0xd] = 0;
  local_8 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[10] = 1;
  local_58[6] = 0x3f800000;
  local_58[7] = 0x3f800000;
  local_58[8] = 0x3f800000;
  local_58[9] = 0x3f800000;
  piVar8 = local_58;
  piVar10 = aiStack_9c;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar10 = *piVar8;
    piVar8 = piVar8 + 1;
    piVar10 = piVar10 + 1;
  }
  FUN_007fd3d0(param_2);
  if (local_58[0xb] == local_58[0xc]) {
    if (local_58[0xb] != 0) {
      puStack_74 = (undefined *)0x7fd954;
      FUN_0089120c();
    }
    ExceptionList = local_10;
    return 0;
  }
  iVar6 = local_58[0xc] - local_58[0xb] >> 0x1f;
  local_14 = 0;
  if ((local_58[0xc] - local_58[0xb]) / 0x30 + iVar6 != iVar6) {
    puVar1 = (uint *)(param_1 + 0x1c);
    param_2 = 0;
    do {
      iVar6 = param_2;
      puStack_74 = (undefined *)0x7fd99a;
      iVar5 = FUN_00891268();
      iVar4 = local_58[0xb];
      local_8._0_1_ = 1;
      if (iVar5 == 0) {
        param_1 = 0;
      }
      else {
        puVar9 = (undefined4 *)(iVar6 + 4 + local_58[0xb]);
        piVar8 = aiStack_9c + 1;
        for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar8 = *puVar9;
          puVar9 = puVar9 + 1;
          piVar8 = piVar8 + 1;
        }
        aiStack_9c[0] = *(int *)(param_2 + iVar4);
        param_1 = FUN_007f3680(iVar5);
        iVar6 = param_2;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      puVar9 = *(undefined4 **)(iVar3 + 0x20);
      param_2 = param_1;
      if (&param_2 < puVar9) {
        puVar2 = (undefined4 *)*puVar1;
        if (&param_2 < puVar2) goto LAB_007fda1e;
        if (puVar9 == *(undefined4 **)(iVar3 + 0x24)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(iVar3 + 0x20) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar3 + 0x20) =
               *(undefined4 *)(*puVar1 + ((int)&param_2 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_007fda1e:
        if (puVar9 == *(undefined4 **)(iVar3 + 0x24)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(iVar3 + 0x20) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar3 + 0x20) = param_1;
        }
      }
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 4;
      if ((DAT_00fe3284 & 1) == 0) {
        DAT_00fe3284 = DAT_00fe3284 | 1;
        local_8._0_1_ = 2;
        FUN_007df1e0();
        puStack_74 = (undefined *)0x7fda5a;
        _atexit((_func_4879 *)&LAB_00bd0ad0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      puStack_74 = (undefined *)0x7fda72;
      param_2 = param_1;
      FUN_006bde40();
      puStack_74 = &DAT_00fe3290;
      uStack_78 = 0x7fda7c;
      FUN_0044bbd0();
      local_14 = local_14 + 1;
      _DAT_00fe32b0 = 1;
      *(undefined4 *)(*(int *)(iVar6 + local_58[0xb]) + 0x70) = 1;
      param_2 = iVar6 + 0x30;
    } while (local_14 < (uint)((local_58[0xc] - local_58[0xb]) / 0x30));
  }
  if (local_58[0xb] != 0) {
    puStack_74 = (undefined *)0x7fdac6;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return 1;
}

