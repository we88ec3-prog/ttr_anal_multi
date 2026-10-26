
void FUN_00759330(int param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  
  do {
    uVar5 = 0;
    while( true ) {
      if (*(uint *)(param_1 + 0x10) <= uVar5) {
        return;
      }
      psVar2 = (short *)FUN_004026d0();
      psVar4 = psVar2;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      iVar3 = FUN_0044df20(uVar5,psVar2,(int)psVar4 - (int)(psVar2 + 1) >> 1);
      if (iVar3 == 0) break;
      uVar5 = uVar5 + 1;
    }
    FUN_00757e40(*(undefined4 *)(param_2 + 0x10),uVar5);
    FUN_00757da0(param_1);
  } while( true );
}

