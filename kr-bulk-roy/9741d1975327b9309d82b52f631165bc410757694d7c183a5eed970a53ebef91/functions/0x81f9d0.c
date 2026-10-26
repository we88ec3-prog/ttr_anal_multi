
undefined4 * FUN_0081f9d0(int param_1)

{
  undefined4 *puVar1;
  undefined1 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e971;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_007b2620();
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xe) = 0;
  local_8 = 1;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 3) = *in_ECX;
    *(undefined1 *)(puVar1 + 4) = in_ECX[4];
    puVar1[5] = *(undefined4 *)(in_ECX + 8);
    *(undefined1 *)(puVar1 + 6) = in_ECX[0xc];
    puVar1[0xc] = 7;
    puVar1[0xb] = 0;
    *(undefined2 *)(puVar1 + 7) = 0;
    FUN_004026e0(in_ECX + 0x10,0,0xffffffff);
  }
  ExceptionList = local_10;
  return puVar1;
}

