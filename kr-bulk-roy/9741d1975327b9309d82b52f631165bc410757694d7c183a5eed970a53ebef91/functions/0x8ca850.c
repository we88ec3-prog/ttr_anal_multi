
uint FUN_008ca850(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  byte *local_8;
  
  uVar4 = *(uint *)(param_1 + 0x10);
  if ((int)uVar4 < 0) {
    return 0;
  }
  uVar5 = 0xffffffff;
  if (uVar4 != 0xffffffff) {
    uVar5 = uVar4;
  }
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      iVar2 = FUN_008ca130(param_1,uVar4,&local_8);
      pbVar3 = param_2;
      if (iVar2 == 0) {
        do {
          bVar1 = *pbVar3;
          bVar6 = bVar1 < *local_8;
          if (bVar1 != *local_8) {
LAB_008ca8c0:
            iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_008ca8c5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar6 = bVar1 < local_8[1];
          if (bVar1 != local_8[1]) goto LAB_008ca8c0;
          local_8 = local_8 + 2;
          pbVar3 = pbVar3 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_008ca8c5:
        if (iVar2 == 0) {
          return uVar4;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return 0;
}

