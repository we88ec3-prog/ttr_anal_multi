
void FUN_005a40a0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int *in_ECX;
  short *psVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092e2de;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((in_ECX != (int *)0x0) && (iVar2 = (**(code **)(*in_ECX + 4))(), iVar2 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  psVar3 = (short *)FUN_004f6a30();
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  FUN_00641e00();
  ExceptionList = local_14;
  return;
}

