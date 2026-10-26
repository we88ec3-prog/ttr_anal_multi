
undefined4 FUN_004ebd80(int param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092598e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 2) == *(int *)(in_ECX + 0x5ec4)) {
    if ((*(char *)(in_ECX + 0x5f34) != *(char *)(param_1 + 6)) &&
       (param_1 = CONCAT22(0xee,(undefined2)param_1), DAT_00fba798 == 0)) {
      (**(code **)(*DAT_00fba854 + 0x10))
                (0,(int)&param_1 + 2,2,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    *(undefined1 *)(in_ECX + 0x5f34) = *(undefined1 *)(iVar1 + 6);
    *(int *)(in_ECX + 0x5f38) = (int)*(short *)(iVar1 + 7);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4259);
  }
  ExceptionList = local_10;
  return 0;
}

