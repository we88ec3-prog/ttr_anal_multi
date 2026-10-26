
undefined4 * FUN_00533ea0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ff81;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_006db770();
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar1 + 0xd) = 0;
  local_8 = 1;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    puVar1[3] = *param_1;
    puVar1[4] = param_1[1];
    puVar1[5] = param_1[2];
    puVar1[0xb] = 7;
    puVar1[10] = 0;
    *(undefined2 *)(puVar1 + 6) = 0;
    FUN_004026e0(param_1 + 3,0,0xffffffff);
  }
  ExceptionList = local_10;
  return puVar1;
}

