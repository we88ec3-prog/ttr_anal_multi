
void FUN_00409da0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00945afe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar3 = FUN_00409c60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar4 = param_1;
  if (cVar3 == '\0') {
    FUN_00757710();
    (**(code **)(**(int **)(iVar4 + 0xfc) + 0x94))(0);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    param_1 = 0x1b2;
    FUN_005740f0(&param_1);
    if (param_2 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(param_2 + 0x24) < 8) {
      FUN_0040a370();
      ExceptionList = local_10;
      return;
    }
    FUN_0040a370();
    ExceptionList = local_10;
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x100);
  if (-1 < iVar1) {
    puVar5 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar5 != (undefined4 *)0x0) {
      uVar7 = *(undefined4 *)(iVar4 + 0x100);
      uVar6 = FUN_00408580(uVar7,iVar1);
      uVar7 = FUN_004084f0(uVar7,iVar1);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4369;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = uVar7;
      puVar5[6] = uVar6;
    }
    FUN_004072a0();
    puVar5 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4368;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = param_2;
      puVar5[6] = param_3;
    }
    FUN_004072a0();
    iVar4 = FUN_00408660(param_2,param_3);
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar5 != (undefined4 *)0x0) {
        uVar7 = *(undefined4 *)(param_1 + 0x100);
        param_1 = FUN_00408580(uVar7,iVar1);
        uVar7 = FUN_004084f0(uVar7,iVar1);
        puVar5[5] = uVar7;
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf4368;
        *puVar5 = FoxUI::FXUIEventI2::vftable;
        puVar5[6] = param_1;
      }
      FUN_004072a0();
      puVar5 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar5 != (undefined4 *)0x0) {
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf4369;
        *puVar5 = FoxUI::FXUIEventI2::vftable;
        puVar5[5] = param_2;
        puVar5[6] = param_3;
      }
      FUN_004072a0();
    }
    ExceptionList = local_10;
    return;
  }
  FUN_00757710();
  (**(code **)(**(int **)(iVar4 + 0xfc) + 0x94))(0);
  param_1 = 0xbe;
  iVar4 = FUN_005854b0();
  FUN_005740f0(&param_1);
  if (param_2 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(uint *)(param_2 + 0x24) < 8) {
    FUN_0040a370();
    ExceptionList = local_10;
    return;
  }
  FUN_0040a370();
  ExceptionList = local_10;
  return;
}

