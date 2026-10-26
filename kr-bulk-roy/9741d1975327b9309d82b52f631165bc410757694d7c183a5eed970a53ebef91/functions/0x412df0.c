
void FUN_00412df0(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  undefined2 extraout_DX;
  undefined2 *unaff_ESI;
  undefined4 uVar5;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar5 = 0;
  psVar3 = (short *)FUN_00412d70();
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,extraout_DX,uVar5);
  return;
}

