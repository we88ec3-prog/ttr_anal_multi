
void FUN_0066b440(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int in_EDX;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933054;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))();
    if (iVar3 == 0x105b9) goto LAB_0066b498;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0066b498:
  uVar2 = DAT_00faadd4 & 1;
  *(int *)(in_EDX + 0x16c) = in_ECX[5];
  if (uVar2 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = FoxUI::FXUIEvent::vftable;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf43d5;
  }
  FUN_00402160();
  local_8 = 1;
  if (*(char *)(*(int *)(in_EDX + 0xfc) + 0x141) != '\0') {
    FUN_006edb10();
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_005740f0();
  if (local_18 != DAT_00fe5b10) {
    FUN_004ed610();
    local_8 = 0xffffffff;
    FUN_0058b270(0xcf);
    ExceptionList = local_10;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

