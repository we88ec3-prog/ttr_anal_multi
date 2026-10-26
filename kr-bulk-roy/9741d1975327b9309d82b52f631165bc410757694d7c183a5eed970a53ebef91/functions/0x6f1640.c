
undefined4 FUN_006f1640(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  iVar4 = 0;
  piVar6 = (int *)(param_1 + 8);
  do {
    if (*piVar6 != 0) {
      pbVar5 = &DAT_00c4081c;
      pbVar2 = (byte *)(**(code **)(*(int *)*piVar6 + 4))();
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_006f1683:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_006f1688;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_006f1683;
        pbVar2 = pbVar2 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_006f1688:
      if (iVar3 == 0) {
        return *(undefined4 *)(param_1 + 8 + iVar4 * 4);
      }
    }
    iVar4 = iVar4 + 1;
    piVar6 = piVar6 + 1;
    if (4 < iVar4) {
      return 0;
    }
  } while( true );
}

