
undefined4 * FUN_0080e410(void)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914323;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x2c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar1 != (undefined4 *)0x0) {
    local_8 = 1;
    *puVar1 = CSound::vftable;
    puVar1[1] = 0;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    FUN_0040b0b0(in_ECX + 8,0);
    DAT_00fba864 = DAT_00fba864 + 1;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[1] = puVar1[1] + 1;
    ExceptionList = local_10;
    return puVar1;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

