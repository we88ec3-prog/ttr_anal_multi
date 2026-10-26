
undefined4 * FUN_008bdd10(byte *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  puVar2 = *(undefined4 **)(in_EAX + 0xc);
  uVar4 = 0;
  bVar1 = *param_1;
  pbVar6 = param_1;
  while (bVar1 != 0) {
    pbVar7 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    uVar4 = (int)(char)bVar1 + uVar4 * 0x1f;
    bVar1 = *pbVar7;
  }
  uVar4 = uVar4 % *(uint *)(in_EAX + 4);
  puVar3 = (undefined4 *)puVar2[uVar4];
  puVar8 = puVar2 + uVar4;
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return puVar8;
    }
    pbVar6 = (byte *)*puVar3;
    pbVar7 = param_1;
    if (*pbVar6 == *param_1) {
      do {
        bVar1 = *pbVar6;
        bVar9 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_008bdd83:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_008bdd88;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar9 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_008bdd83;
        pbVar6 = pbVar6 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_008bdd88:
      if (iVar5 == 0) {
        return puVar8;
      }
    }
    puVar8 = puVar8 + -1;
    if (puVar8 < puVar2) {
      puVar8 = puVar2 + (*(uint *)(in_EAX + 4) - 1);
    }
    puVar3 = (undefined4 *)*puVar8;
  } while( true );
}

