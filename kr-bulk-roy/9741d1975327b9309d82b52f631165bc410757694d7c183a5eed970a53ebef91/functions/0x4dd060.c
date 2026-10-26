
undefined4 FUN_004dd060(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924e4c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    cVar1 = *(char *)((int)param_1 + 2);
    puVar2[3] = 0;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[4] = 0xf427c;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = (int)cVar1;
    puVar3 = puVar2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  param_1 = puVar3;
  FUN_00804260(&param_1);
  ExceptionList = local_10;
  return 0;
}

