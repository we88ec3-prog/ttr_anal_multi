
void FUN_008ee1e0(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  
  uVar1 = *param_1;
  if ((uVar1 < *(ushort *)(unaff_ESI + 0x50)) &&
     (uVar2 = *(ushort *)(unaff_ESI + 0x11c), uVar2 < *(ushort *)(unaff_ESI + 0x2c))) {
    if (*(short *)(unaff_ESI + 0x15a) == 0) {
      iVar3 = *(int *)(unaff_ESI + 0x54);
      iVar4 = *(int *)(unaff_ESI + 0x30);
      iVar5 = (uint)uVar1 * 8;
      *(undefined4 *)(iVar3 + iVar5) = *(undefined4 *)(iVar4 + (uint)uVar2 * 8);
      *(undefined4 *)(iVar3 + 4 + iVar5) = *(undefined4 *)(iVar4 + 4 + (uint)uVar2 * 8);
      (**(code **)(unaff_ESI + 0x24c))();
      iVar3 = *(int *)(unaff_ESI + 0x54);
      iVar4 = *(int *)(unaff_ESI + 0x58);
      *(undefined4 *)(iVar4 + iVar5) = *(undefined4 *)(iVar3 + iVar5);
      *(undefined4 *)(iVar4 + 4 + iVar5) = *(undefined4 *)(iVar3 + 4 + iVar5);
    }
    (**(code **)(unaff_ESI + 0x23c))();
    (**(code **)(unaff_ESI + 0x248))();
    *(undefined2 *)(unaff_ESI + 0x11e) = *(undefined2 *)(unaff_ESI + 0x11c);
    *(ushort *)(unaff_ESI + 0x120) = uVar1;
    if ((*(byte *)(unaff_ESI + 0x170) & 1) != 0) {
      *(ushort *)(unaff_ESI + 0x11c) = uVar1;
      return;
    }
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

