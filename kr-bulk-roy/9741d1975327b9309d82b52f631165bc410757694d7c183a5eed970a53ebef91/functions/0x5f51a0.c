
void FUN_005f51a0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  piVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 10) & 0x10) == 0) {
    if (in_ECX[0x18] == 0) goto LAB_005f5209;
    piVar1 = (int *)FUN_00745c20();
  }
  if ((((piVar1 != (int *)0x0) && (piVar1[0x18] != 0)) && (((uint)piVar1[10] >> 0xc & 1) == 0)) &&
     (piVar1[0x18] != 0)) {
    FUN_0074a010(piVar1);
  }
LAB_005f5209:
  if (in_ECX[0x47] == 1) {
    if ((*(int *)(in_ECX[0x3e] + 0xcc) == 0) || (*(int *)(in_ECX[0x3e] + 0xd8) == 0)) {
      iVar2 = -1;
    }
    else {
      iVar2 = FUN_005f55a0();
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    *(int *)(DAT_00f94300 + 0x50d8) = iVar2 + 1;
  }
  if ((*(int *)(in_ECX[0x3e] + 0xcc) == 0) || (*(int *)(in_ECX[0x3e] + 0xd8) == 0)) {
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_005f55a0();
  }
  in_ECX[0x48] = iVar2 + 1;
  (**(code **)(*in_ECX + 0x1b4))();
  (**(code **)(*in_ECX + 0x1b0))();
  ExceptionList = local_14;
  return;
}

