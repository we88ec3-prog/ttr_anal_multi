
void FUN_0040c650(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int unaff_EDI;
  undefined4 uVar5;
  undefined4 uStack_2c;
  void *local_28;
  int local_24;
  int local_20 [2];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945ac8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar3 = FUN_0040ca50(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  if (iVar3 != 0) {
    local_28 = *(void **)(iVar3 + 0x10);
    local_24 = *(undefined4 *)(iVar3 + 0x14);
    iVar3 = FUN_00409560();
    FUN_004dd400(iVar3,local_20,&local_28);
    if (local_20[0] == *(int *)(iVar3 + 4)) {
      local_28 = (void *)0x0;
    }
    else {
      local_28 = *(void **)(local_20[0] + 0x18);
      if ((local_28 != (void *)0x0) && (*(int *)((int)local_28 + 0x30) == 3)) {
        FUN_0040c530();
        uVar5 = 0x1dd;
        FUN_005854b0(0x1dd);
        FUN_00585330(uVar5);
        FUN_0040c560();
        ExceptionList = local_14;
        return;
      }
    }
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      uVar5 = *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x29c);
      uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x298);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = uVar1;
      puVar4[6] = uVar5;
    }
    FUN_004072a0();
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4368;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = param_1;
      puVar4[6] = param_2;
    }
    FUN_004072a0();
    *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x298) = param_1;
    *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x29c) = param_2;
    FUN_0040bb20();
    if ((DAT_00faaffc & 1) == 0) {
      DAT_00faaffc = DAT_00faaffc | 1;
      local_c = 1;
      FUN_008132e0();
      _atexit((_func_4879 *)&LAB_00bccce0);
      local_c = 0xffffffff;
    }
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x19c))(DAT_00fab020,0xffffffff,0,0);
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    if (unaff_EDI == 0) {
      FUN_00409490();
      FUN_008438c0(&stack0xffffffd0);
    }
    else {
      FUN_00409490();
      FUN_008438c0(&stack0xffffffd0);
    }
    if ((DAT_00faaffc & 1) == 0) {
      DAT_00faaffc = DAT_00faaffc | 1;
      local_20[1] = 2;
      FUN_008132e0();
      _atexit((_func_4879 *)&LAB_00bccce0);
      local_20[1] = 0xffffffff;
    }
    uVar5 = DAT_00fab020;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_20[1] = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_20[1] = 0xffffffff;
    }
    if (DAT_00f94300 != -0x16f8) {
      FUN_00508e40(uVar5);
    }
    FUN_00757710();
    FUN_007597b0(0);
    FUN_007597b0(1);
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x104) + 0x90))(1);
    ExceptionList = local_28;
    return;
  }
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x108) + 0x94))(0);
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    puStack_10 = (undefined1 *)0x0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uStack_2c = 0x1b2;
  FUN_005740f0(&uStack_2c);
  if (local_24 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(uint *)(local_24 + 0x24) < 8) {
    FUN_0040c560();
    ExceptionList = pvStack_18;
    return;
  }
  FUN_0040c560();
  ExceptionList = pvStack_18;
  return;
}

