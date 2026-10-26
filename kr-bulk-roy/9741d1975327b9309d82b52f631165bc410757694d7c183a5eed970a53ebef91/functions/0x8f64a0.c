
int FUN_008f64a0(void)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  int in_EAX;
  int iVar4;
  ushort *puVar5;
  int in_ECX;
  byte *pbVar6;
  byte *pbVar7;
  
  piVar1 = (int *)(in_ECX + 0x2c + in_EAX * 0x1c);
  pbVar7 = (byte *)piVar1[2];
  pbVar6 = pbVar7 + *piVar1 * 0x30;
  iVar4 = FUN_008f5160();
  if (iVar4 == 0) {
    for (; pbVar7 < pbVar6; pbVar7 = pbVar7 + 0x30) {
      puVar5 = *(ushort **)(pbVar7 + 0x28);
      uVar2 = *puVar5;
      *pbVar7 = *pbVar7 & 0xfe;
      if (puVar5 != *(ushort **)(pbVar7 + 0x2c)) {
        do {
          uVar3 = uVar2 & 3;
          puVar5 = *(ushort **)(puVar5 + 0x10);
          uVar2 = *puVar5;
          if ((uVar3 == 0) && ((uVar2 & 3) == 0)) goto LAB_008f6501;
        } while (puVar5 != *(ushort **)(pbVar7 + 0x2c));
        *pbVar7 = *pbVar7 | 1;
      }
LAB_008f6501:
    }
    iVar4 = 0;
  }
  return iVar4;
}

