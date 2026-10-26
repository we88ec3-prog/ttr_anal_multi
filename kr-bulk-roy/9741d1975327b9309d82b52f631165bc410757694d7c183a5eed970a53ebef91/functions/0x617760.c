
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00617760(int param_1)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  char local_19;
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
  if ((((*(byte *)(unaff_ESI + 0x10c) < 10) &&
       (iVar1 = (uint)*(byte *)(unaff_ESI + 0x10c) * 0x210 + DAT_00f94304,
       *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0)) && ((char *)(iVar1 + 500) != (char *)0x0)) {
    local_19 = *(char *)(iVar1 + 500);
    cVar2 = *(char *)(iVar1 + 0x1f5);
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(unaff_ESI + 0xec) + 0x20)) {
      if (local_19 == '\0') {
        ExceptionList = local_14;
        return;
      }
      local_19 = '\0';
    }
    else if (*(int *)(param_1 + 8) == *(int *)(*(int *)(unaff_ESI + 0xf0) + 0x20)) {
      if (cVar2 == '\0') {
        ExceptionList = local_14;
        return;
      }
      cVar2 = '\0';
    }
    iVar1 = FUN_00617880(1);
    if (iVar1 == 0) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      FUN_004a4690(*(undefined1 *)(unaff_ESI + 0x10c),local_19,cVar2);
    }
  }
  ExceptionList = local_14;
  return;
}

