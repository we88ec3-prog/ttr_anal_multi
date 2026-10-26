
void FUN_0061a3a0(void)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946b5a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0061a40d;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_0061a40d:
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar1 != 0) {
      FUN_0040f060();
      iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      *(undefined1 *)(in_ECX + 0x104) = *(undefined1 *)(iVar1 + 0x88);
      FUN_006195a0(*(undefined4 *)(in_ECX + 0xfc));
      FUN_0061a500();
      if ((DAT_00fab29c & 1) == 0) {
        DAT_00fab29c = DAT_00fab29c | 1;
        local_c = 2;
        FUN_004ffe60();
        _atexit((_func_4879 *)&LAB_00bccf00);
        local_c = 0xffffffff;
      }
      FUN_00501650(5);
    }
  }
  ExceptionList = local_14;
  return;
}

