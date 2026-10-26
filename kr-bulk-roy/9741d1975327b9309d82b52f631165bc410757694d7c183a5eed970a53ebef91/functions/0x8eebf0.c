
void FUN_008eebf0(void)

{
  ushort *in_EAX;
  int unaff_ESI;
  
  if ((*in_EAX < *(ushort *)(unaff_ESI + 0x50)) && (in_EAX[2] < *(ushort *)(unaff_ESI + 0x2c))) {
    (**(code **)(unaff_ESI + 0x23c))();
    (**(code **)(unaff_ESI + 0x248))();
    (**(code **)(unaff_ESI + 0x248))();
    return;
  }
  if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

