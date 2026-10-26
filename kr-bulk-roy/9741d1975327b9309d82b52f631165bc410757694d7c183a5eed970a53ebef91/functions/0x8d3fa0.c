
undefined4 * FUN_008d3fa0(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  int in_EAX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  iVar6 = 0;
  bVar2 = false;
  puVar7 = *(undefined4 **)(in_EAX + 0x11c);
  if (0 < *(int *)(in_EAX + 0x118)) {
    do {
      if (bVar2) goto LAB_008d400b;
      pbVar3 = (byte *)*puVar7;
      pbVar5 = param_1;
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_008d3ff0:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_008d3ff5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_008d3ff0;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_008d3ff5:
      if (iVar4 == 0) {
        bVar2 = true;
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 3;
    } while (iVar6 < *(int *)(in_EAX + 0x118));
    if (bVar2) {
LAB_008d400b:
      return *(undefined4 **)(in_EAX + 0x11c) + iVar6 * 3 + -3;
    }
  }
  return (undefined4 *)0x0;
}

