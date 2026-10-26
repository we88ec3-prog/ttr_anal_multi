
void FUN_00804650(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  DWORD DVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c499;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00fe3354 & 1;
  *(undefined4 *)(unaff_EDI + 0x8c) = 0;
  if (uVar1 == 0) {
    DAT_00fe3354 = DAT_00fe3354 | 1;
    local_8 = 0;
    FUN_00807120(uVar2);
    _atexit((_func_4879 *)&LAB_00bd0b90);
  }
  local_8 = 0xffffffff;
  if (DAT_00fba858 == 0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  FUN_00805720(DAT_00fba858);
  piVar3 = (int *)FUN_00891268(0x5c);
  local_8 = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00803d60(piVar3);
    *piVar3 = (int)CIocpNetwork::vftable;
  }
  local_8 = 0xffffffff;
  DAT_00fba854 = piVar3;
  (**(code **)(*piVar3 + 8))();
  DVar4 = timeGetTime();
  *(DWORD *)(unaff_EDI + 0x60) = DVar4;
  DVar4 = timeGetTime();
  *(DWORD *)(unaff_EDI + 0x34) = DVar4;
  ExceptionList = local_10;
  return;
}

