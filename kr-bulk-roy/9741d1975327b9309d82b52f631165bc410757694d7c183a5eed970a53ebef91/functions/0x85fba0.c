
undefined4 * FUN_0085fba0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906a41;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00570a10();
  *puVar1 = *(undefined4 *)(in_EDX + 4);
  puVar1[1] = *(undefined4 *)(in_EDX + 4);
  puVar1[2] = *(undefined4 *)(in_EDX + 4);
  *(undefined2 *)(puVar1 + 0x10) = 0;
  local_8 = 1;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    puVar1[3] = *in_ECX;
    FUN_008656c0();
  }
  ExceptionList = local_10;
  return puVar1;
}

