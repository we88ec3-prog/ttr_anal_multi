
undefined4 FUN_004b78a0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924d9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar1 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf42d1;
    *(undefined1 *)(puVar1 + 5) = 1;
    *puVar1 = FoxUI::FXUIEventB2::vftable;
    *(undefined1 *)(puVar1 + 6) = 0;
  }
  FUN_0058b1a0(0x4b,puVar1);
  ExceptionList = local_10;
  return 0;
}

