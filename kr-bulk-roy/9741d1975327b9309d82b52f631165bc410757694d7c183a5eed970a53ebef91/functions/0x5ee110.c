
void FUN_005ee110(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  int in_ECX;
  short *psVar5;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar5 = *(short **)(in_ECX + 0x180);
  if (psVar5 == (short *)0x0) {
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xac) < 8) {
      psVar5 = (short *)(iVar2 + 0x98);
    }
    else {
      psVar5 = *(short **)(iVar2 + 0x98);
    }
  }
  else if (7 < *(uint *)(psVar5 + 10)) {
    psVar5 = *(short **)psVar5;
  }
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  psVar4 = psVar5;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  local_14 = uVar3;
  FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  local_8 = 0;
  FUN_00757800(local_30);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

