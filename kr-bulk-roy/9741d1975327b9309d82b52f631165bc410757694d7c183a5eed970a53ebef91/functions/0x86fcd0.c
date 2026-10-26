
void FUN_0086fcd0(uint param_1)

{
  byte bVar1;
  char ****ppppcVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  uint extraout_EDX;
  bool bVar6;
  undefined4 local_12c;
  char ***local_128 [5];
  uint local_114;
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x38) != 0) {
    local_12c = 0;
    FUN_0086d600(local_128,&local_12c);
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
    pcVar5 = "color";
    pbVar3 = local_10c;
    do {
      bVar1 = *pbVar3;
      param_1 = (uint)bVar1;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_0086fd77:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0086fd7c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      param_1 = (uint)bVar1;
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_0086fd77;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_0086fd7c:
    if (iVar4 == 0) {
      *(undefined4 *)(in_ECX + 0x40) = 0;
    }
    else {
      pcVar5 = "depth";
      pbVar3 = local_10c;
      do {
        bVar1 = *pbVar3;
        param_1 = (uint)bVar1;
        bVar6 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_0086fdb0:
          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_0086fdb5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        param_1 = (uint)bVar1;
        bVar6 = bVar1 < (byte)pcVar5[1];
        if (bVar1 != pcVar5[1]) goto LAB_0086fdb0;
        pbVar3 = pbVar3 + 2;
        pcVar5 = pcVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0086fdb5:
      if (iVar4 == 0) {
        *(undefined4 *)(in_ECX + 0x40) = 1;
      }
      else {
        pbVar3 = local_10c;
        pcVar5 = "stencil";
        do {
          bVar1 = *pbVar3;
          param_1 = (uint)bVar1;
          bVar6 = bVar1 < (byte)*pcVar5;
          if (bVar1 != *pcVar5) {
LAB_0086fdf0:
            iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_0086fdf5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          param_1 = (uint)bVar1;
          bVar6 = bVar1 < (byte)pcVar5[1];
          if (bVar1 != pcVar5[1]) goto LAB_0086fdf0;
          pbVar3 = pbVar3 + 2;
          pcVar5 = pcVar5 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_0086fdf5:
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

