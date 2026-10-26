
void FUN_0041ccf0(void)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927cce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  uVar2 = 0;
  iVar1 = DAT_00fb7280;
  if (DAT_00fb7284 - DAT_00fb7280 >> 2 != 0) {
    do {
      if (*(char *)(*(int *)(iVar1 + uVar2 * 4) + 8) != '\0') {
        (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xe0) + uVar2 * 4) + 0x94))(0);
        iVar1 = DAT_00fb7280;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(DAT_00fb7284 - iVar1 >> 2));
  }
  (**(code **)(**(int **)(unaff_EDI + 0xdc) + 0x94))(0);
  ExceptionList = local_10;
  return;
}

