
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b8dc0(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined1 local_12 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00944b9c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar4 = (short *)(param_1 + 2);
  FUN_00489ee0(uVar3);
  psVar5 = psVar4;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar4,(int)psVar5 - (iVar2 + 4) >> 1);
  FUN_00489ee0(uVar3);
  FUN_004e74d0();
  if ((DAT_00fe18fc & 1) == 0) {
    DAT_00fe18fc = DAT_00fe18fc | 1;
    local_8 = 0;
    FUN_004fa330();
    _atexit((_func_4879 *)&LAB_00bce900);
    local_8 = 0xffffffff;
  }
  psVar4 = (short *)(iVar2 + 0x104);
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160((short *)(iVar2 + 0x104),(int)psVar4 - (iVar2 + 0x106) >> 1);
  if ((DAT_00fe18fc & 1) == 0) {
    DAT_00fe18fc = DAT_00fe18fc | 1;
    local_8 = 1;
    FUN_004fa330();
    _atexit((_func_4879 *)&LAB_00bce900);
    local_8 = 0xffffffff;
  }
  FUN_004fabf0(&DAT_00fe1900);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  param_1 = CONCAT22(0xbcc,(undefined2)param_1);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,(int)&param_1 + 2,2);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,local_12,2);
  }
  ExceptionList = local_10;
  return 0;
}

