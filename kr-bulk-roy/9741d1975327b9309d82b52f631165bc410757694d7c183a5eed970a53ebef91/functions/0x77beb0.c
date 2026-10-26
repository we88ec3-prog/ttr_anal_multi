
undefined4 FUN_0077beb0(int param_1)

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
  if (param_1 == 0xee49) {
    pvVar1 = _malloc(0x5c);
    local_8 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0077e210(pvVar1);
      ExceptionList = local_10;
      return uVar2;
    }
  }
  ExceptionList = local_10;
  return 0;
}

