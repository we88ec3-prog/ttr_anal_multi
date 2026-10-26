
undefined4 FUN_0050c830(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924d9e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)((uint)*(byte *)(in_ECX + 4) * 0x10 + param_1);
  if (*(ushort *)(in_ECX + 2) == 0) {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
  }
  else {
    puVar2[1] = (uint)*(ushort *)(in_ECX + 2);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4277);
  ExceptionList = local_10;
  return 0;
}

