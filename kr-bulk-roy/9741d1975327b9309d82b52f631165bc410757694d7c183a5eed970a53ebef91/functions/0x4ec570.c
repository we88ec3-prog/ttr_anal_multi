
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec570(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  *(undefined4 *)(unaff_ESI + 0x5ec4) = unaff_EDI;
  iVar1 = FUN_00404ba0();
  *(undefined4 *)(iVar1 + 0x6834) = unaff_EDI;
  if (*(int *)(unaff_ESI + 0x5ec4) != 0) {
    *(undefined4 *)(unaff_ESI + 0x5ec0) = 1;
    FUN_00404ba0();
    uVar2 = FUN_004ec270(1);
    *(undefined4 *)(unaff_ESI + 0x5ebc) = uVar2;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_6 = 0xbc1;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_6,2);
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_8 = 0xbc3;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_8,2);
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_a = 0xbc5;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_a,2);
    }
  }
  return;
}

