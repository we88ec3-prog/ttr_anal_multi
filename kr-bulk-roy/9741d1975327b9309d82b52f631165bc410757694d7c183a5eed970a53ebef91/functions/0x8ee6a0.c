
void FUN_008ee6a0(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *in_EAX;
  int iVar4;
  int unaff_ESI;
  
  uVar1 = *in_EAX;
  if (((uVar1 < *(ushort *)(unaff_ESI + 0x50)) &&
      (*(int *)(in_EAX + 2) + 1U < *(int *)(unaff_ESI + 0x17c) + 1U)) &&
     (*(ushort *)(unaff_ESI + 0x11c) < *(ushort *)(unaff_ESI + 0x2c))) {
    if (*(int *)(in_EAX + 2) != -1) {
      (**(code **)(unaff_ESI + 0x250))();
    }
    if (*(short *)(unaff_ESI + 0x15a) == 0) {
      iVar3 = (uint)uVar1 * 8;
      iVar4 = FUN_008ec3a0();
      *(int *)(iVar3 + *(int *)(unaff_ESI + 0x54)) =
           iVar4 + *(int *)(*(int *)(unaff_ESI + 0x30) + (uint)*(ushort *)(unaff_ESI + 0x11c) * 8);
      iVar4 = FUN_008ec3a0();
      *(int *)(iVar3 + 4 + *(int *)(unaff_ESI + 0x54)) =
           iVar4 + *(int *)(*(int *)(unaff_ESI + 0x30) + 4 +
                           (uint)*(ushort *)(unaff_ESI + 0x11c) * 8);
      iVar4 = *(int *)(unaff_ESI + 0x54);
      iVar2 = *(int *)(unaff_ESI + 0x58);
      *(undefined4 *)(iVar2 + iVar3) = *(undefined4 *)(iVar3 + iVar4);
      *(undefined4 *)(iVar2 + 4 + iVar3) = *(undefined4 *)(iVar3 + 4 + iVar4);
    }
    (**(code **)(unaff_ESI + 0x240))();
    (**(code **)(unaff_ESI + 0x23c))();
    if ((*(byte *)(unaff_ESI + 0x170) & 4) == 0) {
      FUN_008ec890();
    }
    else {
      (**(code **)(unaff_ESI + 0x238))();
    }
    (**(code **)(unaff_ESI + 0x248))();
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  *(undefined2 *)(unaff_ESI + 0x11e) = *(undefined2 *)(unaff_ESI + 0x11c);
  *(ushort *)(unaff_ESI + 0x120) = uVar1;
  if ((*(byte *)(unaff_ESI + 0x170) & 0x10) != 0) {
    *(ushort *)(unaff_ESI + 0x11c) = uVar1;
  }
  return;
}

