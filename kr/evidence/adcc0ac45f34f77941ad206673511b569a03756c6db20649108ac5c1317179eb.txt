
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b6250(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uStack_20;
  undefined4 auStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009438ca;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  (**(code **)(**(int **)(param_1 + 0x21c) + 0xd4))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x20c);
  auStack_1c[0] = uVar9;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  iVar2 = FUN_004e2e70(&DAT_00f8d9e0,uVar9);
  uStack_20 = iVar2;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    uStack_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    uStack_c = 0xffffffff;
  }
  iVar5 = DAT_00fb7258;
  if (DAT_00fb7258 == 0) {
    if (iVar2 != 0) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_20._0_3_ = CONCAT12((undefined1)auStack_1c[0],0x3d);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_20,3);
      }
      ExceptionList = local_14;
      return;
    }
    auStack_1c[0] = 0x196;
    iVar2 = FUN_005854b0();
    FUN_005740f0(auStack_1c);
    if (uStack_20 != *(int *)(iVar2 + 4)) {
      if (*(uint *)(uStack_20 + 0x24) < 8) {
        iVar2 = uStack_20 + 0x10;
      }
      else {
        iVar2 = *(int *)(uStack_20 + 0x10);
      }
      auStack_1c[0] = 6;
      iVar5 = FUN_005854b0();
      FUN_005740f0(auStack_1c);
      if (uStack_20 != *(int *)(iVar5 + 4)) {
        puVar4 = (undefined4 *)(uStack_20 + 0x10);
        if (7 < *(uint *)(uStack_20 + 0x24)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        FUN_00404b10(0xca,puVar4,iVar2,0,0);
        ExceptionList = local_14;
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  iVar3 = FUN_00539aa0(DAT_00f93930);
  piVar6 = *(int **)(iVar5 + 0x28);
  uVar7 = 0;
  for (iVar2 = *(int *)(iVar5 + 0x2c) - (int)piVar6 >> 2; iVar2 != 0; iVar2 = iVar2 + -1) {
    if (*(char *)(*piVar6 + 10) != '\0') {
      uVar7 = uVar7 + 1;
    }
    piVar6 = piVar6 + 1;
  }
  if (iVar3 == 0) {
LAB_005b6494:
    if (uStack_20 == 0) {
      uVar9 = 0x196;
      FUN_005854b0(0x196,0,0);
      uVar9 = FUN_00585330(uVar9);
      uVar8 = 6;
      FUN_005854b0(6,uVar9);
      uVar9 = FUN_00585330(uVar8);
      FUN_00404b10(0xca,uVar9);
      ExceptionList = local_14;
      return;
    }
    FUN_00414680();
    FUN_004a3620(auStack_1c[0]);
    ExceptionList = local_14;
    return;
  }
  if (*(char *)(iVar3 + 6) == '\0') {
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      *puVar4 = FoxUI::FXUIEvent::vftable;
      puVar4[3] = 0;
      puVar4[4] = 0xf4391;
    }
  }
  else {
    iVar2 = FUN_00404ba0();
    if (*(int *)(iVar2 + 0x5f4c) != 5) {
      if ((*(char *)(iVar3 + 6) == '\0') || (uVar7 < 2)) goto LAB_005b6494;
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4391;
      }
      uVar9 = 0x196;
      FUN_005854b0(0x196,puVar4,param_1);
      uVar9 = FUN_00585330(uVar9);
      uVar8 = 0x31;
      goto LAB_005b6465;
    }
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = FoxUI::FXUIEvent::vftable;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4391;
    }
  }
  uVar9 = 0x196;
  FUN_005854b0(0x196,puVar4,param_1);
  uVar9 = FUN_00585330(uVar9);
  uVar8 = 0x3b;
LAB_005b6465:
  FUN_005854b0(uVar8,uVar9);
  uVar9 = FUN_00585330(uVar8);
  FUN_00404b10(0xcf,uVar9);
  ExceptionList = local_14;
  return;
}

