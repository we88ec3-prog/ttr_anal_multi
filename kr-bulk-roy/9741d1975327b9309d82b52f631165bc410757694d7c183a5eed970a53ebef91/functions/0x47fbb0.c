
void FUN_0047fbb0(void)

{
  short sVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  short *psVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  int local_18;
  
  piVar2 = (int *)FUN_0087dc3d(*(undefined4 *)(in_EAX + 2));
  iVar3 = FUN_00727190(piVar2);
  if (iVar3 == 0) {
    local_18 = *piVar2;
    piVar6 = piVar2 + 1;
    if (0 < local_18) {
      psVar7 = (short *)((int)piVar2 + 6);
      do {
        FUN_0047fe60();
        psVar4 = psVar7;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00402160(psVar7,(int)psVar4 - (int)(psVar7 + 1) >> 1);
        piVar6 = (int *)((int)piVar6 + 0x3e);
        psVar7 = psVar7 + 0x1f;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    local_18 = *piVar6;
    if (0 < local_18) {
      piVar6 = piVar6 + 2;
      do {
        FUN_0047fcd0();
        piVar5 = piVar6;
        do {
          iVar3 = *piVar5;
          piVar5 = (int *)((int)piVar5 + 2);
        } while ((short)iVar3 != 0);
        FUN_00402160(piVar6,(int)piVar5 - (int)((int)piVar6 + 2) >> 1);
        piVar6 = piVar6 + 0x10;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    FUN_00891d3d(piVar2);
    return;
  }
  FUN_00891d3d(piVar2);
  FUN_00891d3d(piVar2);
  return;
}

