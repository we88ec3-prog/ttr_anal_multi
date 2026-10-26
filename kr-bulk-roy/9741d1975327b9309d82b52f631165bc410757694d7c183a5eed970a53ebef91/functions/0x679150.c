
void FUN_00679150(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&param_1);
  if ((in_ECX != DAT_00f8d91c) && (iVar1 = *(int *)(in_ECX + 0x10), iVar1 != 0)) {
    (**(code **)(**(int **)(unaff_EDI + 0x100 + unaff_ESI * 4) + 0x1ac))
              (*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x1c),0,0,param_2);
    (**(code **)(**(int **)(unaff_EDI + 0x100 + unaff_ESI * 4) + 200))();
  }
  ExceptionList = local_10;
  return;
}

