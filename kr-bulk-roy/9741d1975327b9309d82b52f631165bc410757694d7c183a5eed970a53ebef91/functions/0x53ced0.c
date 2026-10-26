
void FUN_0053ced0(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924e4c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_008438c0(&param_1);
  if (in_ECX == *(int *)(in_ECX + 0x5eb0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(in_ECX + 0x10);
  }
  uVar1 = DAT_00faadd4 & 1;
  *(undefined4 *)(in_ECX + 0x5ebc) = uVar3;
  if (uVar1 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
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
    puVar4[4] = 0xf43e2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  param_1 = puVar4;
  FUN_00804260(&param_1);
  ExceptionList = local_10;
  return;
}

