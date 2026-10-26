
void FUN_008ee2f0(void)

{
  ushort uVar1;
  ushort *in_EAX;
  int unaff_ESI;
  
  uVar1 = *in_EAX;
  if (uVar1 < *(ushort *)(unaff_ESI + 0x2c)) {
    if ((*(byte *)(unaff_ESI + 0x170) & 1) != 0) {
      (**(code **)(unaff_ESI + 0x23c))();
      (**(code **)(unaff_ESI + 0x238))();
    }
    (**(code **)(unaff_ESI + 0x248))();
    *(ushort *)(unaff_ESI + 0x11c) = uVar1;
    *(ushort *)(unaff_ESI + 0x11e) = uVar1;
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    return;
  }
  return;
}

