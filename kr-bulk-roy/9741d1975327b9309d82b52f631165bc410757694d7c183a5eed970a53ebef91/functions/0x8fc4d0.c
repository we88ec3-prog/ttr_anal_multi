
uint FUN_008fc4d0(void)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  
  uVar5 = *(uint *)(in_EAX + 0x18);
  uVar8 = *(uint *)(in_EAX + 0x34);
  if (((*(char *)(in_EAX + 0x20) != '\0') || (*(int *)(in_EAX + 0x1c) <= (int)uVar5)) ||
     (*(uint *)(in_EAX + 0x3c) <= *(uint *)(in_EAX + 0x38))) {
    if (*(uint *)(in_EAX + 0x3c) <= *(uint *)(in_EAX + 0x38)) {
      uVar8 = uVar8 + 1;
      *(uint *)(in_EAX + 0x34) = uVar8;
      if (uVar8 < *(uint *)(in_EAX + 0x28)) {
        iVar3 = (1 << ((byte)uVar8 & 0x1f)) + -0x100;
      }
      else {
        iVar3 = *(int *)(in_EAX + 0x30) + 1;
      }
      *(int *)(in_EAX + 0x3c) = iVar3;
    }
    if (*(char *)(in_EAX + 0x20) != '\0') {
      uVar8 = 9;
      *(undefined4 *)(in_EAX + 0x34) = 9;
      *(undefined4 *)(in_EAX + 0x3c) = 0x100;
      *(undefined1 *)(in_EAX + 0x20) = 0;
    }
    iVar3 = FUN_008fc480();
    if (iVar3 < 0) {
      return 0xffffffff;
    }
    uVar5 = 0;
  }
  pbVar1 = (byte *)(((int)uVar5 >> 3) + 8 + in_EAX);
  *(uint *)(in_EAX + 0x18) = uVar5 + uVar8;
  iVar3 = -(uVar5 & 7);
  iVar7 = iVar3 + 8;
  uVar8 = uVar8 - iVar7;
  uVar5 = (uint)(*pbVar1 >> (sbyte)(uVar5 & 7));
  pbVar6 = pbVar1 + 1;
  if (7 < uVar8) {
    bVar2 = *pbVar6;
    bVar4 = (byte)iVar7;
    pbVar6 = pbVar1 + 2;
    iVar7 = iVar3 + 0x10;
    uVar5 = uVar5 | (uint)bVar2 << (bVar4 & 0x1f);
    uVar8 = uVar8 - 8;
  }
  if (uVar8 != 0) {
    uVar5 = uVar5 | ((1 << ((byte)uVar8 & 0x1f)) - 1U & (uint)*pbVar6) << ((byte)iVar7 & 0x1f);
  }
  return uVar5;
}

