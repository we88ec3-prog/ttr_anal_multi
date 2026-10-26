
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005ddfc0(void)

{
  uint uVar1;
  int unaff_ESI;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091272e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_8 = 0xffffffff;
  local_1c = *(undefined4 *)(unaff_ESI + 0x248);
  local_18 = *(undefined4 *)(unaff_ESI + 0x24c);
  FUN_004dd400(&DAT_00fab0dc,&local_14,&local_1c);
  if (((local_14 != DAT_00fab0e0) && (uVar1 = *(uint *)(local_14 + 0x18), uVar1 != 0)) &&
     (*(char *)(uVar1 + 0x15) != '\0')) {
LAB_005de061:
    ExceptionList = local_10;
    return uVar1 & 0xffffff00;
  }
  if (*(int *)(unaff_ESI + 600) != 0) {
    uVar1 = FUN_0051bf00(*(int *)(unaff_ESI + 600));
    if (uVar1 != 0) goto LAB_005de061;
  }
  ExceptionList = local_10;
  return 1;
}

