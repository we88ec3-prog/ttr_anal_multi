
void FUN_008cfb90(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  int unaff_EBX;
  uint uVar5;
  byte *unaff_EDI;
  bool bVar6;
  
  uVar5 = 0;
  do {
    pbVar2 = (byte *)("Delta" + (&DAT_00be77e0)[uVar5]);
    pbVar4 = unaff_EDI;
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_008cfbd0:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008cfbd5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_008cfbd0;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_008cfbd5:
    if (iVar3 == 0) {
      if (*(int *)(unaff_EBX + uVar5 * 4) == 0) {
        *(undefined4 *)(unaff_EBX + uVar5 * 4) = 1;
        *(undefined4 *)(param_2 + uVar5 * 4) = param_1;
      }
      return;
    }
    uVar5 = uVar5 + 1;
    if (9 < uVar5) {
      return;
    }
  } while( true );
}

