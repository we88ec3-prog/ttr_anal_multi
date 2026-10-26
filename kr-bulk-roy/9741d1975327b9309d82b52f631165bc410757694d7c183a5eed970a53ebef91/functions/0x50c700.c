
undefined4 FUN_0050c700(int param_1)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092598e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(short *)(in_ECX + 0x22) == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined1 *)(param_1 + 0x1c) = 0;
  }
  else {
    *(uint *)(param_1 + 0x10) = (uint)*(ushort *)(in_ECX + 0x18);
    *(uint *)(param_1 + 0x14) = (uint)*(ushort *)(in_ECX + 0x22);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(in_ECX + 6);
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  if (*(short *)(in_ECX + 0x24) == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x2c) = 0;
  }
  else {
    *(uint *)(param_1 + 0x20) = (uint)*(ushort *)(in_ECX + 0x1a);
    *(uint *)(param_1 + 0x24) = (uint)*(ushort *)(in_ECX + 0x24);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(in_ECX + 10);
    *(undefined1 *)(param_1 + 0x2c) = 1;
  }
  if (*(short *)(in_ECX + 0x26) == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  else {
    *(uint *)(param_1 + 0x30) = (uint)*(ushort *)(in_ECX + 0x1c);
    *(uint *)(param_1 + 0x34) = (uint)*(ushort *)(in_ECX + 0x26);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(in_ECX + 0xe);
    *(undefined1 *)(param_1 + 0x3c) = 1;
  }
  if (*(short *)(in_ECX + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined1 *)(param_1 + 0x4c) = 0;
  }
  else {
    *(uint *)(param_1 + 0x40) = (uint)*(ushort *)(in_ECX + 0x1e);
    *(uint *)(param_1 + 0x44) = (uint)*(ushort *)(in_ECX + 0x28);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(in_ECX + 0x12);
    *(undefined1 *)(param_1 + 0x4c) = 1;
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

