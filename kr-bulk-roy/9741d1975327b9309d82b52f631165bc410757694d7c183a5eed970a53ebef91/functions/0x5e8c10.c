
void FUN_005e8c10(undefined4 param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  short *psVar4;
  int in_ECX;
  short *psVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009164ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = 0;
  if (*(int *)(param_2 + 8) - 1U < 0x2b) {
    uVar3 = FUN_00520f40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  switch(uVar3) {
  case 1:
  case 2:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xe:
  case 0xf:
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    param_2 = 0x310;
    FUN_005740f0(&param_2);
    if (in_ECX == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(in_ECX + 0x10);
    if (7 < *(uint *)(in_ECX + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  }
  ExceptionList = local_10;
  return;
}

