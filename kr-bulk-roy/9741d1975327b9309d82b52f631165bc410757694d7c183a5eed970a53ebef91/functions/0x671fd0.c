
void FUN_00671fd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00932fe0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      iVar1 = *(int *)(in_ECX + 0xf0);
      if (*(char *)(iVar1 + 0x141) != '\0') {
        FUN_006edb10();
      }
      if (*(int *)(iVar1 + 0x118) == 0) {
        FUN_004054c0();
        FUN_00402250();
        local_c = 1;
        FUN_005854b0();
        uVar3 = FUN_00585330();
        FUN_00402250(uVar3);
        local_c = 0xffffffff;
        FUN_0058b270(0xca);
        ExceptionList = local_14;
        return;
      }
      FUN_004054c0();
      puVar2 = (undefined4 *)FUN_00891268();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4244;
      }
      FUN_00402250();
      local_c = 0;
      FUN_00761520();
      uVar3 = 1;
      FUN_005854b0(1);
      FUN_00585330(uVar3);
      FUN_004ed610();
      local_c = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_14;
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0xf4244) && (*(int *)(param_1 + 0x14) == 0x6a7)) {
    FUN_00672180();
  }
  ExceptionList = local_14;
  return;
}

