
uint FUN_008e2010(int param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  iVar3 = *(int *)(param_1 + 0x290);
  iVar4 = FUN_008b8ff0(*(undefined4 *)(param_1 + 0x60),"postscript-cmaps");
  if (iVar4 == 0) {
    return 0;
  }
  uVar8 = 0;
  if (*(int *)(iVar3 + 0xc) != 0) {
    do {
      uVar2 = *(ushort *)(*(int *)(iVar3 + 0x488) + uVar8 * 2);
      if (uVar2 < 0x187) {
        pbVar5 = (byte *)(**(code **)(iVar4 + 0x14))(uVar2);
      }
      else {
        pbVar5 = (byte *)FUN_008de010();
      }
      pbVar6 = param_2;
      if (pbVar5 != (byte *)0x0) {
        do {
          bVar1 = *pbVar6;
          bVar9 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_008e2098:
            iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_008e209d;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar9 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_008e2098;
          pbVar5 = pbVar5 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar7 = 0;
LAB_008e209d:
        if (iVar7 == 0) {
          return uVar8;
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(iVar3 + 0xc));
  }
  return 0;
}

