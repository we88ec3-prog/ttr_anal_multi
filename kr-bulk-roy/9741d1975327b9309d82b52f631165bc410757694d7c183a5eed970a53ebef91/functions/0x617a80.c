
void FUN_00617a80(char param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 local_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (((*(byte *)(unaff_EDI + 0x10c) < 10) &&
      (iVar1 = (uint)*(byte *)(unaff_EDI + 0x10c) * 0x210 + DAT_00f94304,
      *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0)) {
    puVar2 = (undefined1 *)(iVar1 + 500);
  }
  else {
    puVar2 = (undefined1 *)0x0;
  }
  if ((unaff_ESI != 0) && (puVar2 != (undefined1 *)0x0)) {
    local_19 = *puVar2;
    uVar3 = *(undefined1 *)(unaff_ESI + 0x261);
    if (param_1 == '\0') {
      uVar3 = puVar2[1];
      local_19 = *(undefined1 *)(unaff_ESI + 0x261);
    }
    iVar1 = FUN_00617880(1);
    if (iVar1 == 0) {
      FUN_00414680();
      FUN_004a4690(*(undefined1 *)(unaff_EDI + 0x10c),local_19,uVar3);
    }
  }
  ExceptionList = local_14;
  return;
}

