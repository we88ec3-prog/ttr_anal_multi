
undefined4 * FUN_007b2aa0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cb41;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_007b2620();
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar1 + 0xe) = 0;
  local_8 = 1;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    FUN_007b3060(puVar1 + 3,param_1);
  }
  ExceptionList = local_10;
  return puVar1;
}

