
/* WARNING: Removing unreachable block (ram,0x00429833) */

void FUN_004297b0(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *in_EDX;
  undefined1 *unaff_ESI;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e680;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar3 = in_EDX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  uVar4 = uVar2;
  FUN_00402160(in_EDX,(int)psVar3 - (int)(in_EDX + 1) >> 1);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  local_8 = 1;
  FUN_00429710(uVar4);
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

