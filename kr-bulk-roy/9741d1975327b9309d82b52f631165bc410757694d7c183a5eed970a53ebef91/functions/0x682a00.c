
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00682a00(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  uVar1 = *(undefined1 *)(unaff_ESI + 0x164);
  uVar2 = *(undefined4 *)(unaff_ESI + 0x160);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  FUN_004a3720(*(undefined4 *)(unaff_ESI + 0xd0),uVar2,uVar1);
  return;
}

