
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b3c30(void)

{
  uint uVar1;
  int in_ECX;
  undefined4 uStack_30;
  undefined **ppuStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f68e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (*(char *)(in_ECX + 0x310) != '\0') {
    *(undefined1 *)(in_ECX + 0x310) = 0;
    (**(code **)(**(int **)(in_ECX + 0x164) + 0x1a0))(uVar1);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    DAT_00f942c0 = *(undefined1 *)(in_ECX + 0x310);
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    uStack_30 = 0x49;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_30,4);
    }
  }
  FUN_005c2a60();
  iStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  ppuStack_2c = FUI::CFXUIBinder::vftable;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  uStack_c = 2;
  FUN_004095e0(0x54);
  FUN_004095e0(0x37);
  FUN_004095e0(0x38);
  FUN_004095e0(0x1f);
  FUN_004095e0(0x45);
  ppuStack_2c = FoxUI::FXUIBinderBase::vftable;
  if (iStack_28 != 0) {
    FUN_0089120c(iStack_28);
  }
  ExceptionList = local_14;
  return;
}

