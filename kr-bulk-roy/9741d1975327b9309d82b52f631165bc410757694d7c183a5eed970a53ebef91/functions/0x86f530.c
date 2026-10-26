
void FUN_0086f530(uint param_1)

{
  byte bVar1;
  char ****ppppcVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  byte *pbVar6;
  uint extraout_EDX;
  bool bVar7;
  char ***local_128 [5];
  uint local_114;
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_0086d5d0();
    ppppcVar2 = (char ****)local_128[0];
    if (local_114 < 0x10) {
      ppppcVar2 = local_128;
    }
    iVar4 = -(int)ppppcVar2;
    do {
      bVar1 = *(byte *)ppppcVar2;
      *(byte *)((int)ppppcVar2 + (int)(local_10c + iVar4)) = bVar1;
      ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
    } while (bVar1 != 0);
    __strlwr((char *)local_10c);
    *(undefined4 *)(in_ECX + 0x40) = 0;
    pcVar5 = "scene";
    pbVar3 = local_10c;
    do {
      bVar1 = *pbVar3;
      param_1 = (uint)bVar1;
      bVar7 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_0086f5d0:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0086f5d5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      param_1 = (uint)bVar1;
      bVar7 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_0086f5d0;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_0086f5d5:
    if (iVar4 == 0) {
      *(undefined4 *)(in_ECX + 0x40) = 0;
    }
    else {
      pcVar5 = "geometry";
      pbVar3 = local_10c;
      do {
        bVar1 = *pbVar3;
        param_1 = (uint)bVar1;
        bVar7 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_0086f610:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0086f615;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        param_1 = (uint)bVar1;
        bVar7 = bVar1 < (byte)pcVar5[1];
        if (bVar1 != pcVar5[1]) goto LAB_0086f610;
        pbVar3 = pbVar3 + 2;
        pcVar5 = pcVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0086f615:
      if (iVar4 == 0) {
        *(undefined4 *)(in_ECX + 0x40) = 1;
      }
      else {
        pbVar3 = local_10c;
        pbVar6 = &DAT_00c54cb0;
        do {
          bVar1 = *pbVar3;
          param_1 = (uint)bVar1;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_0086f650:
            iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0086f655;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          param_1 = (uint)bVar1;
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_0086f650;
          pbVar3 = pbVar3 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_0086f655:
        if (iVar4 == 0) {
          *(undefined4 *)(in_ECX + 0x40) = 2;
        }
      }
    }
    *(undefined4 *)(in_ECX + 0x38) = 0;
    if (0xf < local_114) {
      FUN_0089120c(local_128[0]);
      param_1 = extraout_EDX;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,param_1);
  return;
}

