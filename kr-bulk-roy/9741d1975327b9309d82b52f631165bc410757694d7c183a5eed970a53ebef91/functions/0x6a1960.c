
void FUN_006a1960(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *unaff_ESI;
  int unaff_EDI;
  uint uStack_34;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c65c;
  local_14 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (param_3 - 1U < 100) {
      iVar1 = param_3 * 0x20 + iVar2;
      if (((*(int *)(param_3 * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
         (iVar1 != 0)) {
        (**(code **)(**(int **)(param_1 + 0x110) + 0x1ac))
                  (*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                   *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),param_4);
        FUN_006a1c80(param_1,*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
        (**(code **)(**(int **)(param_1 + 0x110) + 200))();
        puVar6 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar6 != (undefined4 *)0x0) {
          uVar3 = *(undefined4 *)(param_1 + 0x120);
          uVar4 = *(undefined4 *)(param_1 + 0x11c);
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf4369;
          *puVar6 = FoxUI::FXUIEventI2::vftable;
          puVar6[5] = uVar4;
          puVar6[6] = uVar3;
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
        uVar5 = DAT_00f8d9a4 & 1;
        *(undefined4 *)(param_1 + 0x11c) = 1;
        *(int *)(param_1 + 0x120) = param_3;
        *(undefined4 *)(param_1 + 0x124) = param_4;
        *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(iVar1 + 0xc);
        if (uVar5 == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        uStack_34 = *(uint *)(iVar1 + 0xc);
        FUN_008438c0(&uStack_34);
        if ((unaff_EDI == DAT_00f8d91c) || (*(int *)(unaff_EDI + 0x10) == 0)) {
          iVar2 = *(int *)(param_1 + 0xf4);
          if (*(char *)(iVar2 + 0x141) == '\0') {
            FUN_00757710();
          }
          else {
            FUN_006edb10("Not supported operation");
          }
          *(undefined4 *)(iVar2 + 0x168) = 0;
          *(undefined4 *)(iVar2 + 0x160) = 0;
          *(undefined4 *)(iVar2 + 0x164) = 0;
          *(undefined4 *)(iVar2 + 0x14c) = 0;
        }
        else {
          FUN_0068ac30();
        }
        (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
        (**(code **)(**(int **)(param_1 + 0x108) + 0x90))(1);
        FUN_006a2340();
        ExceptionList = unaff_ESI;
        return;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
  }
  (**(code **)(**(int **)(param_1 + 0x110) + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
  FUN_006a1c80(param_1,0xffffffff,0xffffffff);
  (**(code **)(**(int **)(param_1 + 0x110) + 200))();
  FUN_006a2340();
  (**(code **)(**(int **)(param_1 + 0x108) + 0x90))(0);
  ExceptionList = unaff_ESI;
  return;
}

