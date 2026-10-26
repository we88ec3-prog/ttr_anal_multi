
uint FUN_008d0c60(void)

{
  byte bVar1;
  int in_EAX;
  byte *pbVar2;
  uint uVar3;
  uint in_ECX;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  if (0xff < in_ECX) {
    return 0xffffffff;
  }
  pbVar2 = (byte *)(**(code **)(*(int *)(in_EAX + 0x544) + 0x14))
                             (*(undefined2 *)
                               (*(int *)(*(int *)(in_EAX + 0x544) + 0x18) + in_ECX * 2));
  uVar3 = 0;
  if (*(uint *)(in_EAX + 0x548) != 0) {
    puVar7 = *(undefined4 **)(in_EAX + 0x54c);
    do {
      pbVar4 = (byte *)*puVar7;
      if ((pbVar4 != (byte *)0x0) && (pbVar6 = pbVar2, *pbVar4 == *pbVar2)) {
        do {
          bVar1 = *pbVar4;
          bVar8 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_008d0cd0:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_008d0cd5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar8 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_008d0cd0;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_008d0cd5:
        if (iVar5 == 0) {
          return uVar3;
        }
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < *(uint *)(in_EAX + 0x548));
  }
  return 0xffffffff;
}

