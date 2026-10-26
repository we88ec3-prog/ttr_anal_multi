
void FUN_008ee4a0(void)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *in_ECX;
  int unaff_ESI;
  int *piVar4;
  
  uVar2 = *in_ECX;
  if ((uVar2 < *(ushort *)(unaff_ESI + 0x50)) &&
     (*(ushort *)(unaff_ESI + 0x11c) < *(ushort *)(unaff_ESI + 0x2c))) {
    if ((*(short *)(unaff_ESI + 0x158) == 0) || (*(short *)(unaff_ESI + 0x15a) == 0)) {
      (**(code **)(unaff_ESI + 0x240))();
    }
    else {
      piVar4 = (int *)(*(int *)(unaff_ESI + 0x5c) + (uint)uVar2 * 8);
      piVar1 = (int *)(*(int *)(unaff_ESI + 0x38) + (uint)*(ushort *)(unaff_ESI + 0x11c) * 8);
      if (*(int *)(unaff_ESI + 0xdc) == *(int *)(unaff_ESI + 0xe0)) {
        uVar3 = (**(code **)(unaff_ESI + 0x240))();
        FUN_008b7f10(uVar3,*(undefined4 *)(unaff_ESI + 0xdc));
      }
      else {
        FUN_008b7f10(*piVar4 - *piVar1,*(int *)(unaff_ESI + 0xdc));
        FUN_008b7f10(piVar4[1] - piVar1[1],*(undefined4 *)(unaff_ESI + 0xe0));
        (**(code **)(unaff_ESI + 0x240))();
      }
    }
    if ((*(byte *)(unaff_ESI + 0x170) & 4) == 0) {
      FUN_008ec890();
    }
    else {
      (**(code **)(unaff_ESI + 0x238))();
    }
    (**(code **)(unaff_ESI + 0x23c))();
    (**(code **)(unaff_ESI + 0x248))();
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  *(undefined2 *)(unaff_ESI + 0x11e) = *(undefined2 *)(unaff_ESI + 0x11c);
  *(ushort *)(unaff_ESI + 0x120) = uVar2;
  if ((*(byte *)(unaff_ESI + 0x170) & 0x10) != 0) {
    *(ushort *)(unaff_ESI + 0x11c) = uVar2;
  }
  return;
}

