
void FUN_006797b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_EDI;
  undefined4 uVar7;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cd2c;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  uVar3 = DAT_00f94390 & 1;
  *(undefined1 *)(param_1 + 0x124) = 0;
  if (uVar3 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (iVar5 = DAT_00f94300 + 0x16f8, iVar5 != 0)) {
    if (99 < param_3 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = param_3 * 0x20 + iVar5;
    if (((*(int *)(param_3 * 0x20 + 0xc + iVar5) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar1 != 0)) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 1;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_c = 0xffffffff;
      local_28 = *(int *)(iVar1 + 0xc);
      FUN_008438c0(&local_28);
      if (local_24 == DAT_00f8d91c) {
        local_28 = 0;
      }
      else {
        local_28 = *(int *)(local_24 + 0x10);
      }
      if (*(int *)(local_28 + 0x3c) == 0) {
        uVar7 = 0xc0;
        FUN_005854b0(0xc0);
        FUN_00585330(uVar7);
        FUN_00679d40();
        ExceptionList = local_14;
        return;
      }
      local_20 = *(undefined4 *)(iVar1 + 0x10);
      local_1c = *(undefined4 *)(iVar1 + 0x14);
      iVar5 = FUN_00409560();
      FUN_004dd400(iVar5,&local_24,&local_20);
      if ((local_24 != *(int *)(iVar5 + 4)) && (iVar5 = *(int *)(local_24 + 0x18), iVar5 != 0)) {
        *(bool *)(param_1 + 0x125) = 0 < *(int *)(iVar5 + 0x30);
        *(bool *)(param_1 + 0x124) = *(int *)(iVar5 + 0x48) - *(int *)(iVar5 + 0x44) >> 3 != 0;
      }
      puVar6 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar6 != (undefined4 *)0x0) {
        uVar7 = *(undefined4 *)(param_1 + 0x11c);
        uVar2 = *(undefined4 *)(param_1 + 0x118);
        puVar6[1] = 0xffffffff;
        puVar6[2] = 0xffffffff;
        puVar6[3] = 0;
        puVar6[4] = 0xf4369;
        *puVar6 = FoxUI::FXUIEventI2::vftable;
        puVar6[5] = uVar2;
        puVar6[6] = uVar7;
      }
      FUN_004072a0();
      puVar6 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar6 != (undefined4 *)0x0) {
        puVar6[1] = 0xffffffff;
        puVar6[2] = 0xffffffff;
        puVar6[3] = 0;
        puVar6[4] = 0xf4368;
        *puVar6 = FoxUI::FXUIEventI2::vftable;
        puVar6[5] = 1;
        puVar6[6] = param_3;
      }
      FUN_004072a0();
      *(int *)(param_1 + 0x11c) = param_3;
      *(undefined4 *)(param_1 + 0x118) = 1;
      (**(code **)(**(int **)(param_1 + 0xf8) + 0x19c))
                (*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                 *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
      (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
      FUN_006794e0(unaff_EDI,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                   *(undefined4 *)(param_1 + 0xfc));
      puVar6 = (undefined4 *)(param_1 + 0x100);
      iVar5 = 5;
      do {
        (**(code **)(*(int *)*puVar6 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
        (**(code **)(*(int *)*puVar6 + 200))();
        puVar6 = puVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      (**(code **)(**(int **)(param_1 + 0x114) + 0x90))(1);
    }
  }
  ExceptionList = local_14;
  return;
}

