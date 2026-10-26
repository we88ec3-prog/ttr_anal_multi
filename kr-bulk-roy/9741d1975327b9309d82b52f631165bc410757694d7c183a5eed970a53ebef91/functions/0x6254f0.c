
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006254f0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  byte bVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926d7c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(unaff_EDI + 0xec) + 0xa0))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  (**(code **)(**(int **)(unaff_EDI + 0xec) + 200))();
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  if (DAT_00fba80c == 0) {
    iVar2 = FUN_00891268(0x57c);
    if (iVar2 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  piVar3 = (int *)FUN_006f1640(DAT_00fba80c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x28))(1);
  }
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  FUN_006f3690();
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  FUN_006ccfc0();
  uVar1 = *(uint *)(*(int *)(unaff_EDI + 0xec) + 0x28);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  bVar4 = (uVar1 >> 9 & 1) != 0;
  if (DAT_00fb9113 < bVar4) {
    bVar4 = DAT_00fb9113;
  }
  DAT_00fb9111 = DAT_00fb9112;
  if (DAT_00fb9112 <= bVar4) {
    DAT_00fb9111 = bVar4;
  }
  ExceptionList = local_10;
  return;
}

