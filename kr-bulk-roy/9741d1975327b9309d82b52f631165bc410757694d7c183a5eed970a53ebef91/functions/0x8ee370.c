
void FUN_008ee370(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *in_EAX;
  undefined4 uVar5;
  int unaff_ESI;
  
  uVar1 = *in_EAX;
  if ((uVar1 < *(ushort *)(unaff_ESI + 0x2c)) &&
     (*(uint *)(in_EAX + 2) < *(uint *)(unaff_ESI + 0x17c))) {
    (**(code **)(unaff_ESI + 0x250))();
    if (*(short *)(unaff_ESI + 0x158) == 0) {
      iVar4 = (uint)uVar1 * 8;
      uVar5 = FUN_008ec3a0();
      *(undefined4 *)(iVar4 + *(int *)(unaff_ESI + 0x30)) = uVar5;
      uVar5 = FUN_008ec3a0();
      *(undefined4 *)(*(int *)(unaff_ESI + 0x30) + 4 + iVar4) = uVar5;
      iVar2 = *(int *)(unaff_ESI + 0x30);
      iVar3 = *(int *)(unaff_ESI + 0x34);
      *(undefined4 *)(iVar3 + iVar4) = *(undefined4 *)(iVar2 + iVar4);
      *(undefined4 *)(iVar3 + 4 + iVar4) = *(undefined4 *)(iVar2 + 4 + iVar4);
    }
    (**(code **)(unaff_ESI + 0x23c))();
    if ((*(byte *)(unaff_ESI + 0x170) & 1) != 0) {
      (**(code **)(unaff_ESI + 0x238))();
    }
    (**(code **)(unaff_ESI + 0x248))();
    *(ushort *)(unaff_ESI + 0x11c) = uVar1;
    *(ushort *)(unaff_ESI + 0x11e) = uVar1;
    return;
  }
  if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  *(ushort *)(unaff_ESI + 0x11c) = uVar1;
  *(ushort *)(unaff_ESI + 0x11e) = uVar1;
  return;
}

