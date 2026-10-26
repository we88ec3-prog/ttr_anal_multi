
undefined4 FUN_00496f60(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00925268;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar3);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar4 = (undefined4 *)FUN_00891268(0x18);
  iVar2 = (int)param_1;
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    iVar1 = *(int *)((int)param_1 + 6);
    puVar4[3] = 0;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[4] = 0xf4362;
    *puVar4 = FoxUI::FXUIEventB1::vftable;
    *(bool *)(puVar4 + 5) = iVar1 == 0;
    puVar5 = puVar4;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  param_1 = puVar5;
  FUN_00804260(&param_1);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 2;
    FUN_00587480(uVar3);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x18);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    iVar2 = *(int *)(iVar2 + 0xe);
    puVar4[3] = 0;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[4] = 0xf4363;
    *puVar4 = FoxUI::FXUIEventB1::vftable;
    *(bool *)(puVar4 + 5) = iVar2 != 0;
    puVar5 = puVar4;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 3;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  param_1 = puVar5;
  FUN_00804260(&param_1);
  ExceptionList = local_10;
  return 0;
}

