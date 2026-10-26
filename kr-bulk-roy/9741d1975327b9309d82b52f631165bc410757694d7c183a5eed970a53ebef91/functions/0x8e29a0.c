
void FUN_008e29a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int unaff_ESI;
  bool bVar9;
  int local_10;
  int local_c;
  bool local_5;
  
  uVar2 = *(undefined4 *)(unaff_ESI + 0x60);
  local_10 = *(int *)(unaff_ESI + 0x5c);
  *(undefined4 *)(unaff_ESI + 4) = 0;
  iVar3 = FUN_008e0ba0();
  bVar9 = *(int *)(unaff_ESI + 0x88) != iVar3;
  if (bVar9) {
    *(int *)(unaff_ESI + 0x88) = iVar3;
  }
  iVar3 = FUN_008e0bb0();
  local_5 = *(int *)(unaff_ESI + 0x54) != iVar3;
  if (local_5) {
    *(int *)(unaff_ESI + 0x54) = iVar3;
  }
  local_5 = local_5 || bVar9;
  *(byte *)(unaff_ESI + 0x8c) = *(byte *)(unaff_ESI + 8) & 1;
  piVar1 = (int *)(unaff_ESI + 0xc);
  uVar8 = 0x10;
  piVar7 = piVar1;
  do {
    if (*(int *)(((int)in_EAX - (int)piVar1) + (int)piVar7) != *piVar7) {
      *piVar1 = *in_EAX;
      *(int *)(unaff_ESI + 0x10) = in_EAX[1];
      *(int *)(unaff_ESI + 0x14) = in_EAX[2];
      *(int *)(unaff_ESI + 0x18) = in_EAX[3];
      *(int *)(unaff_ESI + 0x1c) = in_EAX[4];
      *(int *)(unaff_ESI + 0x20) = in_EAX[5];
      *(undefined4 *)(unaff_ESI + 0x20) = 0;
      *(undefined4 *)(unaff_ESI + 0x1c) = 0;
      *(int *)(unaff_ESI + 0x24) = *in_EAX;
      *(int *)(unaff_ESI + 0x28) = in_EAX[1];
      *(int *)(unaff_ESI + 0x2c) = in_EAX[2];
      *(int *)(unaff_ESI + 0x30) = in_EAX[3];
      *(int *)(unaff_ESI + 0x34) = in_EAX[4];
      iVar3 = in_EAX[5];
      *(undefined4 *)(unaff_ESI + 0x48) = 0x10000;
      *(undefined4 *)(unaff_ESI + 0x3c) = 0x10000;
      *(int *)(unaff_ESI + 0x38) = iVar3;
      *(undefined4 *)(unaff_ESI + 0x44) = 0;
      *(undefined4 *)(unaff_ESI + 0x40) = 0;
      local_5 = true;
      break;
    }
    uVar8 = uVar8 - 4;
    piVar7 = piVar7 + 1;
  } while (3 < uVar8);
  if (*(byte *)(unaff_ESI + 0x8e) == ((byte)*(undefined4 *)(unaff_ESI + 8) & 2)) {
    if (!local_5) {
      return;
    }
  }
  else {
    *(byte *)(unaff_ESI + 0x8e) = *(byte *)(unaff_ESI + 8) & 2;
  }
  iVar3 = *(int *)(unaff_ESI + 0x58);
  if (iVar3 == 0) {
    iVar3 = 1000;
  }
  local_c = 0x40000;
  if (0x3ffff < *(int *)(unaff_ESI + 0x54)) {
    local_c = *(int *)(unaff_ESI + 0x54);
  }
  uVar4 = (undefined4)(0x3e80000 / (longlong)iVar3);
  iVar5 = FUN_008e0bc0();
  *(int *)(unaff_ESI + 0xb0) = iVar5;
  if (iVar5 < 1) {
    uVar6 = FUN_008b7f40(0x4b0000,uVar4);
    *(undefined4 *)(unaff_ESI + 0xb0) = uVar6;
  }
  if (local_10 < 1) {
    uVar6 = *(undefined4 *)(unaff_ESI + 0xb0);
    local_10 = 0;
  }
  else {
    iVar5 = FUN_008b7f40(iVar3 << 0x10,local_c);
    if (local_10 <= iVar5) {
      local_10 = FUN_008b7f40(iVar3 << 0x10,local_c);
    }
    uVar6 = *(undefined4 *)(unaff_ESI + 0xb0);
  }
  FUN_008e0770(uVar4,local_c,uVar6,unaff_ESI + 0xb8,local_10);
  iVar3 = FUN_008e0bd0();
  if ((iVar3 < 1) || (*(int *)(unaff_ESI + 0xb0) <= iVar3 * 2)) {
    uVar6 = 0x6e0000;
  }
  else {
    uVar6 = 0x4b0000;
  }
  uVar6 = FUN_008b7f40(uVar6,uVar4);
  *(undefined4 *)(unaff_ESI + 0xb4) = uVar6;
  FUN_008e0770(uVar4,local_c,*(undefined4 *)(unaff_ESI + 0xb4),unaff_ESI + 0xbc,uVar2);
  if ((*(int *)(unaff_ESI + 0xb8) == 0) && (*(int *)(unaff_ESI + 0xbc) == 0)) {
    *(undefined1 *)(unaff_ESI + 0x8d) = 0;
  }
  else {
    *(undefined1 *)(unaff_ESI + 0x8d) = 1;
  }
  *(undefined1 *)(unaff_ESI + 0xc0) = 0;
  FUN_008e2340();
  return;
}

