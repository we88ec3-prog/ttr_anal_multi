
void FUN_008f4c20(int param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort uVar6;
  int in_EAX;
  undefined4 *puVar7;
  ushort *puVar8;
  int iVar9;
  ushort *puVar10;
  
  puVar3 = *(ushort **)(in_EAX + 0x1c);
  puVar7 = *(undefined4 **)(in_EAX + 0x28);
  puVar1 = puVar3 + *(int *)(in_EAX + 0x18) * 0x14;
  puVar2 = puVar7 + *(int *)(in_EAX + 0x24);
  if (param_1 == 0) {
    uVar6 = 0x40;
    if (puVar3 < puVar1) {
      puVar8 = puVar3 + 0xc;
      iVar9 = (uint)((int)puVar1 + (-1 - (int)puVar3)) / 0x28 + 1;
      do {
        *(undefined4 *)puVar8 = *(undefined4 *)(puVar8 + -4);
        *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(puVar8 + -10);
        puVar8 = puVar8 + 0x14;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  else {
    uVar6 = 0x80;
    if (puVar3 < puVar1) {
      puVar8 = puVar3 + 0xc;
      iVar9 = (uint)((int)puVar1 + (-1 - (int)puVar3)) / 0x28 + 1;
      do {
        *(undefined4 *)puVar8 = *(undefined4 *)(puVar8 + -2);
        *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(puVar8 + -8);
        puVar8 = puVar8 + 0x14;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  do {
    if (puVar2 <= puVar7) {
      if (param_1 == 0) {
        if (puVar3 < puVar1) {
          puVar8 = puVar3 + 8;
          iVar9 = (uint)((int)puVar1 + (-1 - (int)puVar3)) / 0x28 + 1;
          do {
            *(undefined4 *)puVar8 = *(undefined4 *)(puVar8 + 4);
            puVar8 = puVar8 + 0x14;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          return;
        }
      }
      else if (puVar3 < puVar1) {
        puVar8 = puVar3 + 10;
        iVar9 = (uint)((int)puVar1 + (-1 - (int)puVar3)) / 0x28 + 1;
        do {
          *(undefined4 *)puVar8 = *(undefined4 *)(puVar8 + 2);
          puVar8 = puVar8 + 0x14;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      return;
    }
    puVar8 = (ushort *)*puVar7;
    puVar4 = *(ushort **)(puVar8 + 0x12);
    for (; puVar8 <= puVar4; puVar8 = puVar8 + 0x14) {
      puVar5 = puVar8;
      if ((uVar6 & *puVar8) != 0) {
        do {
          for (; (puVar10 = puVar5, puVar5 < puVar4 && ((uVar6 & puVar5[0x14]) != 0));
              puVar5 = puVar5 + 0x14) {
          }
          do {
            puVar10 = puVar10 + 0x14;
            if (puVar4 < puVar10) {
              if (puVar5 == puVar8) {
                FUN_008f4aa0();
              }
              else {
                if (puVar5 < puVar4) {
                  FUN_008f4af0(puVar8);
                }
                if (puVar3 < puVar8) {
                  FUN_008f4af0(puVar8);
                }
              }
              goto LAB_008f4d76;
            }
          } while ((uVar6 & *puVar10) == 0);
          FUN_008f4af0(puVar10);
          puVar5 = puVar10;
        } while( true );
      }
    }
LAB_008f4d76:
    puVar7 = puVar7 + 1;
  } while( true );
}

