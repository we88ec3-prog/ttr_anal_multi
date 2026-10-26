
undefined4 FUN_0050a470(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_14;
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
  local_14 = (undefined4 *)FUN_00891268(0x1c);
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    cVar1 = *(char *)(in_ECX + 2);
    uVar2 = *(undefined4 *)(in_ECX + 3);
    local_14[1] = 0xffffffff;
    local_14[2] = 0xffffffff;
    local_14[3] = 0;
    local_14[4] = 0xf427d;
    *local_14 = FoxUI::FXUIEventI2::vftable;
    local_14[5] = (int)cVar1;
    local_14[6] = uVar2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_14);
  ExceptionList = local_10;
  return 0;
}

