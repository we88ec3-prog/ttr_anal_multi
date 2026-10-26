
void FUN_0072c2e0(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  iVar3 = *param_1;
  local_c = ((int *)param_1[2])[3];
  iVar7 = *(int *)param_1[2];
  iVar6 = -1;
  iVar5 = 0;
  local_8 = -1;
  *(undefined4 *)(unaff_ESI + 0x1450) = 0;
  *(undefined4 *)(unaff_ESI + 0x1454) = 0x23d;
  if (0 < local_c) {
    do {
      if (*(short *)(iVar3 + iVar5 * 4) == 0) {
        *(undefined2 *)(iVar3 + 2 + iVar5 * 4) = 0;
      }
      else {
        *(int *)(unaff_ESI + 0x1450) = *(int *)(unaff_ESI + 0x1450) + 1;
        *(int *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1450) * 4) = iVar5;
        *(undefined1 *)(iVar5 + 0x1458 + unaff_ESI) = 0;
        iVar6 = iVar5;
        local_8 = iVar5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < local_c);
  }
  iVar5 = *(int *)(unaff_ESI + 0x1450);
  while (iVar5 < 2) {
    if (iVar6 < 2) {
      iVar5 = iVar6 + 1;
      iVar6 = iVar5;
    }
    else {
      iVar5 = 0;
    }
    *(int *)(unaff_ESI + 0x1450) = *(int *)(unaff_ESI + 0x1450) + 1;
    *(int *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1450) * 4) = iVar5;
    *(undefined2 *)(iVar3 + iVar5 * 4) = 1;
    *(undefined1 *)(unaff_ESI + 0x1458 + iVar5) = 0;
    *(int *)(unaff_ESI + 0x16a8) = *(int *)(unaff_ESI + 0x16a8) + -1;
    if (iVar7 != 0) {
      *(int *)(unaff_ESI + 0x16ac) =
           *(int *)(unaff_ESI + 0x16ac) - (uint)*(ushort *)(iVar7 + 2 + iVar5 * 4);
    }
    local_8 = iVar6;
    iVar5 = *(int *)(unaff_ESI + 0x1450);
  }
  param_1[1] = iVar6;
  for (iVar7 = *(int *)(unaff_ESI + 0x1450) / 2; 0 < iVar7; iVar7 = iVar7 + -1) {
    FUN_0072bf70(iVar7);
  }
  do {
    uVar4 = *(undefined4 *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1450) * 4);
    iVar7 = *(int *)(unaff_ESI + 0xb60);
    *(int *)(unaff_ESI + 0x1450) = *(int *)(unaff_ESI + 0x1450) + -1;
    *(undefined4 *)(unaff_ESI + 0xb60) = uVar4;
    FUN_0072bf70(1);
    iVar6 = *(int *)(unaff_ESI + 0xb60);
    *(int *)(unaff_ESI + 0x1454) = *(int *)(unaff_ESI + 0x1454) + -1;
    *(int *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1454) * 4) = iVar7;
    *(int *)(unaff_ESI + 0x1454) = *(int *)(unaff_ESI + 0x1454) + -1;
    *(int *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1454) * 4) = iVar6;
    *(short *)(iVar3 + local_c * 4) = *(short *)(iVar3 + iVar6 * 4) + *(short *)(iVar3 + iVar7 * 4);
    bVar1 = *(byte *)(unaff_ESI + 0x1458 + iVar7);
    bVar2 = *(byte *)(unaff_ESI + 0x1458 + iVar6);
    if (bVar1 < bVar2) {
      bVar1 = bVar2;
    }
    *(byte *)(unaff_ESI + 0x1458 + local_c) = bVar1 + 1;
    *(short *)(iVar3 + 2 + iVar6 * 4) = (short)local_c;
    *(short *)(iVar3 + 2 + iVar7 * 4) = (short)local_c;
    *(int *)(unaff_ESI + 0xb60) = local_c;
    local_c = local_c + 1;
    FUN_0072bf70(1);
  } while (1 < *(int *)(unaff_ESI + 0x1450));
  *(int *)(unaff_ESI + 0x1454) = *(int *)(unaff_ESI + 0x1454) + -1;
  *(undefined4 *)(unaff_ESI + 0xb5c + *(int *)(unaff_ESI + 0x1454) * 4) =
       *(undefined4 *)(unaff_ESI + 0xb60);
  FUN_0072c050();
  FUN_0072c250(local_8);
  return;
}

