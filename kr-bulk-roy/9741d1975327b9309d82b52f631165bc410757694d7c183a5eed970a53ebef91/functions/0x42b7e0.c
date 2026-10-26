
void FUN_0042b7e0(void)

{
  void *pvVar1;
  void *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  pvVar1 = in_ECX;
  if ((*(byte *)((int)in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)((int)in_ECX + 0x60) == 0) goto LAB_0042b846;
    pvVar1 = (void *)FUN_00745c20();
  }
  if ((((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 0x60) != 0)) &&
      ((*(uint *)((int)pvVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)((int)pvVar1 + 0x60) != 0)) {
    FUN_0074a010(pvVar1);
  }
LAB_0042b846:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  (**(code **)(**(int **)((int)in_ECX + 0xf8) + 0x90))(DAT_00f9392c != 5);
  (**(code **)(**(int **)((int)in_ECX + 0xf8) + 200))();
  FUN_0042bfe0(in_ECX,0);
  ExceptionList = in_ECX;
  return;
}

