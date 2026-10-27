
void FUN_0066fb70(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) != 0) {
      iVar1 = FUN_00745c20();
      goto LAB_0066fbb9;
    }
  }
  else {
LAB_0066fbb9:
    if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
        ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
      FUN_0074a010(iVar1);
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  switch(DAT_00f9392c) {
  case 7:
    uVar2 = 0x2b7;
    break;
  default:
    goto switchD_0066fc1f_caseD_8;
  case 0x15:
    uVar2 = 0x2b8;
    break;
  case 0x17:
  case 0x18:
    uVar2 = 0x2b9;
  }
  FUN_00585620(uVar2);
  FUN_00585330(uVar2);
  FUN_00757710();
switchD_0066fc1f_caseD_8:
  iVar1 = DAT_00fe1aa0;
  *(undefined1 *)(DAT_00fe1aa0 + 0x20) = 1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  FUN_0066f750(in_ECX);
  ExceptionList = local_14;
  return;
}

