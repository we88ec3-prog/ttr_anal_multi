
void FUN_006b5bc0(int *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c0fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe18fc & 1) == 0) {
    DAT_00fe18fc = DAT_00fe18fc | 1;
    local_8 = 0;
    FUN_004fa330(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce900);
  }
  local_8 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
  puVar1 = &DAT_00fe1910;
  do {
    FUN_00757710();
    FUN_007597b0(0);
    puVar1 = puVar1 + 8;
  } while ((int)puVar1 < 0xfe1a50);
  (**(code **)(*param_1 + 200))();
  ExceptionList = local_10;
  return;
}

