
undefined4 * FUN_0081e110(void)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914291;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00570a10();
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar1 + 0x10) = 0;
  local_8 = 1;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    FUN_0081e440(puVar1 + 3);
  }
  ExceptionList = local_10;
  return puVar1;
}

