
undefined4 FUN_00770810(int param_1)

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
  if (param_1 == 63000) {
    pvVar1 = _malloc(0x1c);
    local_8 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0077d360(pvVar1);
      ExceptionList = local_10;
      return uVar2;
    }
  }
  ExceptionList = local_10;
  return 0;
}

