
undefined4 FUN_004e2b30(int param_1)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b93c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x5f50) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 0x6874) = *(undefined4 *)(param_1 + 6);
  *(undefined4 *)(in_ECX + 0x6864) = *(undefined4 *)(param_1 + 10);
  *(undefined4 *)(in_ECX + 0x686c) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x6868) = *(undefined4 *)(param_1 + 0x16);
  *(undefined4 *)(in_ECX + 0x6870) = *(undefined4 *)(param_1 + 0x1a);
  *(uint *)(in_ECX + 0x687c) = (uint)*(ushort *)(param_1 + 0x1f);
  *(undefined4 *)(in_ECX + 0x6880) = *(undefined4 *)(param_1 + 0x21);
  *(undefined4 *)(in_ECX + 0x6884) = *(undefined4 *)(param_1 + 0x25);
  *(undefined4 *)(in_ECX + 0x6888) = *(undefined4 *)(param_1 + 0x29);
  *(undefined4 *)(in_ECX + 0x688c) = *(undefined4 *)(param_1 + 0x2d);
  *(undefined4 *)(in_ECX + 0x6890) = *(undefined4 *)(param_1 + 0x31);
  *(undefined4 *)(in_ECX + 0x6894) = *(undefined4 *)(param_1 + 0x35);
  *(undefined2 *)(in_ECX + 0x68e8) = *(undefined2 *)(param_1 + 0x3b);
  piVar2 = (int *)FUN_0040f060(uVar1);
  uVar1 = DAT_00fbad10 & 1;
  *(undefined2 *)(*piVar2 + 0x5eb4) = *(undefined2 *)(param_1 + 0x39);
  if (uVar1 == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  FUN_004ec570();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf42a1);
  ExceptionList = local_10;
  return 0;
}

