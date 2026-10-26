
undefined4 FUN_00770e80(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907d78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 57000) {
    pvVar1 = _malloc(0xec);
    local_8 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0077b520(pvVar1);
      ExceptionList = local_10;
      return uVar2;
    }
  }
  ExceptionList = local_10;
  return 0;
}

