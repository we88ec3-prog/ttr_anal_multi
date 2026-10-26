
undefined4 FUN_004c4550(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 local_1a [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  iVar1 = DAT_00fe18f8;
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947a0e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) != '\0') {
    FUN_006edb60(&DAT_00c0732c);
    local_1a[0] = 0x19;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,local_1a,2);
    }
    ExceptionList = local_14;
    return 0x80004005;
  }
  *(undefined4 *)(DAT_00fe18f8 + 0x24) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(iVar1 + 0x34) = *(undefined2 *)(param_1 + 0x14);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  FUN_0058aad0(0xf4297);
  FUN_004ba8c0(*(char *)(param_1 + 4) == '\0');
  FUN_006df020();
  ExceptionList = local_14;
  return 0;
}

