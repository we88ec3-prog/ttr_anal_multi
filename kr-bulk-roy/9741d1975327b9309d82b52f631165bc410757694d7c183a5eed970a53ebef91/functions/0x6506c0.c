
void FUN_006506c0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d6aa;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00650729;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_00650729:
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_c = 0xffffffff;
  }
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(DAT_00fc0bd8 == 1);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar1 = DAT_00f9420c;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00507a30(DAT_00f94208,uVar1);
  FUN_00759ac0(0);
  *(undefined4 *)(*(int *)(in_ECX + 0x154) + 0x154) = 0xff5aff78;
  ExceptionList = pvStack_18;
  return;
}

