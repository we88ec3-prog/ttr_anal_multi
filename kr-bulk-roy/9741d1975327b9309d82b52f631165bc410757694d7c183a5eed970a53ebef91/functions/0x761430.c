
/* WARNING: Removing unreachable block (ram,0x007614cf) */
/* WARNING: Removing unreachable block (ram,0x007614b5) */

void FUN_00761430(short *param_1)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar1 = param_1 + 1;
  do {
    sVar2 = *param_1;
    param_1 = param_1 + 1;
  } while (sVar2 != 0);
  local_8 = 0;
  FUN_00402340((int)param_1 - (int)psVar1 >> 1,0x2a);
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

