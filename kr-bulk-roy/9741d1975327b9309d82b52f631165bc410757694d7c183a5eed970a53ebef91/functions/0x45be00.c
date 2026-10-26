
void FUN_0045be00(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_7c [76];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00945afe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_2c = 0x45be35;
  cVar2 = FUN_0045bc30();
  if (cVar2 == '\0') {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      uStack_2c = 0x45be61;
      FUN_00584c40();
      uStack_2c = 0x45be6b;
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    uStack_2c = 0x45be8d;
    FUN_005740f0();
    if (param_2 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(param_2 + 0x24) < 8) {
      FUN_0045b330();
      ExceptionList = local_10;
      return;
    }
    FUN_0045b330();
    ExceptionList = local_10;
    return;
  }
  iVar3 = FUN_0045ab20();
  if (-1 < iVar3) {
    uStack_2c = 0x45bf6a;
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 != (undefined4 *)0x0) {
      uVar6 = *(undefined4 *)(param_1 + 0x108);
      uStack_30 = 0x45bf83;
      uStack_2c = uVar6;
      uVar5 = FUN_0045aa90();
      uStack_30 = 0x45bf8d;
      uStack_2c = uVar6;
      uVar6 = FUN_0045aa00();
      puVar4[5] = uVar6;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[6] = uVar5;
    }
    FUN_004072a0();
    uStack_2c = 0x45bfc6;
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4368;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = param_2;
      puVar4[6] = param_3;
    }
    FUN_004072a0();
    FUN_0045b670(auStack_7c,param_2);
    FUN_0045a860(*(undefined4 *)(param_1 + 0x108),iVar3);
    uStack_2c = *(undefined4 *)(param_1 + 0x108);
    uStack_30 = 0x45c035;
    FUN_0045ab80();
    ExceptionList = local_10;
    return;
  }
  iVar3 = FUN_005854b0();
  uStack_2c = 0x45bf10;
  FUN_005740f0();
  if (param_2 == *(int *)(iVar3 + 4)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(param_2 + 0x24) < 8) {
    FUN_0045b330();
    ExceptionList = local_10;
    return;
  }
  FUN_0045b330();
  ExceptionList = local_10;
  return;
}

