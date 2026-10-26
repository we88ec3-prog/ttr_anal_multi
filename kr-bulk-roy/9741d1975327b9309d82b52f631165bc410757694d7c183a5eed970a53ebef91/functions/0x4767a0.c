
void FUN_004767a0(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094509a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00476808;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_00476808:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00f942c8;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 1;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
    local_c = 0xffffffff;
  }
  local_20 = FUN_00822660(uVar1);
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 2;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
    local_c = 0xffffffff;
  }
  FUN_0062db10(&local_20);
  if (local_1c == DAT_00fb9384) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(local_1c + 0x14);
  }
  FUN_00477b20();
  FUN_004777b0(in_ECX,uVar3);
  ExceptionList = local_14;
  return;
}

