
void FUN_006a98d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b55e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006a9931;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_006a9931:
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  puVar2 = DAT_00fc0c0c;
  if (DAT_00fc0c20 < 8) {
    puVar2 = &DAT_00fc0c0c;
  }
  FUN_00765f70(*(undefined4 *)(in_ECX + 0xf4),puVar2);
  ExceptionList = local_10;
  return;
}

