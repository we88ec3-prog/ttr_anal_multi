
void FUN_008ef2a0(void)

{
  short sVar1;
  uint uVar2;
  uint *in_EAX;
  int iVar3;
  int unaff_ESI;
  uint uVar4;
  uint local_8;
  
  uVar2 = *in_EAX;
  local_8 = 1;
  if (uVar2 == 0) {
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
    return;
  }
  do {
    if (*(int *)(unaff_ESI + 0x1c) < 2) {
      if (*(char *)(unaff_ESI + 0x231) != '\0') {
        *(undefined4 *)(unaff_ESI + 0xc) = 0x81;
      }
      *(undefined4 *)(unaff_ESI + 0x1c) = 0;
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
      return;
    }
    iVar3 = *(int *)(unaff_ESI + 0x1c) + -2;
    *(int *)(unaff_ESI + 0x1c) = iVar3;
    if (*(ushort *)(*(int *)(unaff_ESI + 0x18) + iVar3 * 4 + 4) < *(ushort *)(unaff_ESI + 0x2c)) {
      uVar4 = *(uint *)(*(int *)(unaff_ESI + 0x18) + iVar3 * 4) >> 4 & 0xf;
      if (*(char *)(unaff_ESI + 0x170) == 'q') {
        uVar4 = uVar4 + 0x10;
      }
      else if (*(char *)(unaff_ESI + 0x170) == 'r') {
        uVar4 = uVar4 + 0x20;
      }
      sVar1 = *(short *)(unaff_ESI + 0x14c);
      iVar3 = FUN_008ec500();
      if (iVar3 == uVar4 + (int)sVar1) {
        (**(code **)(unaff_ESI + 0x248))();
      }
    }
    else if (*(char *)(unaff_ESI + 0x231) != '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    }
    local_8 = local_8 + 1;
  } while (local_8 <= uVar2);
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
  return;
}

