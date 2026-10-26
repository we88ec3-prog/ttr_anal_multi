
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b43d0(void)

{
  uint uVar1;
  int unaff_ESI;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  *(undefined1 *)(unaff_ESI + 0x310) = 1;
  (**(code **)(**(int **)(unaff_ESI + 0x164) + 0x19c))(uVar1);
  (**(code **)(**(int **)(unaff_ESI + 0x220) + 0x90))(0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  DAT_00f942c0 = *(undefined1 *)(unaff_ESI + 0x310);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&stack0xffffffe0,4);
  }
  ExceptionList = pvStack_18;
  return;
}

