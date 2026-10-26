
undefined4 FUN_004965b0(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
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
  puVar3 = (undefined4 *)FUN_00891268(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)((int)param_1 + 8);
    uVar1 = *(ushort *)((int)param_1 + 6);
    puVar3[6] = *(undefined4 *)((int)param_1 + 2);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = &DAT_000f4298;
    *puVar3 = FoxUI::FXUIEventI3::vftable;
    puVar3[5] = (uint)uVar1;
    puVar3[7] = uVar2;
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

