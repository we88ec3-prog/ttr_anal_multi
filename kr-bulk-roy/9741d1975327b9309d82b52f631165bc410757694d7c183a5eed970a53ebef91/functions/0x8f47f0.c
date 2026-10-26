
ushort * FUN_008f47f0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int in_ECX;
  ushort *puVar5;
  uint uVar6;
  int in_EDX;
  int iVar7;
  ushort *puVar8;
  
  piVar1 = (int *)(in_ECX + 0x2c + in_EDX * 0x1c);
  puVar4 = (ushort *)piVar1[2];
  puVar5 = puVar4 + *piVar1 * 0x18;
  if (in_EDX == 0) {
    if (puVar4 < puVar5) {
      puVar8 = puVar4 + 0x16;
      uVar6 = (int)puVar5 + (-1 - (int)puVar4);
      puVar4 = (ushort *)(uVar6 * -0x55555555);
      iVar7 = uVar6 / 0x30 + 1;
      do {
        iVar2 = *(int *)(puVar8 + -0x10);
        if (iVar2 != 0) {
          puVar4 = *(ushort **)(puVar8 + -2);
          puVar5 = *(ushort **)puVar8;
          uVar3 = *(undefined4 *)(iVar2 + 8);
          *puVar4 = *puVar4 | 0x40;
          *(undefined4 *)(puVar4 + 8) = uVar3;
          while (puVar4 != puVar5) {
            puVar4 = *(ushort **)(puVar4 + 0x10);
            *(undefined4 *)(puVar4 + 8) = *(undefined4 *)(iVar2 + 8);
            *puVar4 = *puVar4 | 0x40;
          }
        }
        puVar8 = puVar8 + 0x18;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return puVar4;
    }
  }
  else if (puVar4 < puVar5) {
    puVar8 = puVar4 + 0x16;
    uVar6 = (int)puVar5 + (-1 - (int)puVar4);
    puVar4 = (ushort *)(uVar6 * -0x55555555);
    iVar7 = uVar6 / 0x30 + 1;
    do {
      iVar2 = *(int *)(puVar8 + -0x10);
      if (iVar2 != 0) {
        puVar4 = *(ushort **)(puVar8 + -2);
        puVar5 = *(ushort **)puVar8;
        *(undefined4 *)(puVar4 + 10) = *(undefined4 *)(iVar2 + 8);
        *puVar4 = *puVar4 | 0x80;
        while (puVar4 != puVar5) {
          puVar4 = *(ushort **)(puVar4 + 0x10);
          *(undefined4 *)(puVar4 + 10) = *(undefined4 *)(iVar2 + 8);
          *puVar4 = *puVar4 | 0x80;
        }
      }
      puVar8 = puVar8 + 0x18;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return puVar4;
}

