
void FUN_005f52d0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 *puVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) == 0) ||
     (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) == 0)) {
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_005f55a0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar1 = DAT_00f94300;
  if ((iVar2 == 0) && (DAT_00f94300 != -0x16f8)) {
    if ((*(char *)(in_ECX + 0x124) != '\0') && (iVar2 = 1, 0 < *(int *)(DAT_00f94300 + 0x2398))) {
      puVar3 = (undefined1 *)(DAT_00f94300 + 0x1730);
      do {
        *puVar3 = 0;
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 0x20;
      } while (iVar2 <= *(int *)(iVar1 + 0x2398));
    }
    *(undefined1 *)(in_ECX + 0x124) = 1;
  }
  FUN_004067f0();
  ExceptionList = local_14;
  return;
}

