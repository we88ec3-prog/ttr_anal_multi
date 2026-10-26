
undefined4 FUN_008b93d0(short *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  if (param_1 != (short *)0x0) {
    iVar4 = (int)param_1[1];
    iVar5 = (int)*param_1;
    if (iVar4 == 0) {
      if (iVar5 == 0) {
        return 0;
      }
    }
    else if ((0 < iVar4) && (0 < iVar5)) {
      iVar1 = -1;
      iVar2 = 0;
      if (0 < iVar5) {
        psVar6 = *(short **)(param_1 + 6);
        iVar3 = -1;
        do {
          iVar1 = (int)*psVar6;
          if (iVar1 <= iVar3) {
            return 6;
          }
          if (iVar4 <= iVar1) {
            return 6;
          }
          iVar2 = iVar2 + 1;
          psVar6 = psVar6 + 1;
          iVar3 = iVar1;
        } while (iVar2 < iVar5);
      }
      if (iVar1 == iVar4 + -1) {
        return 0;
      }
    }
  }
  return 6;
}

