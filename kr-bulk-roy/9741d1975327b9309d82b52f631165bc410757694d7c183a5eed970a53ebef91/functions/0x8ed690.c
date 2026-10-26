
void FUN_008ed690(void)

{
  int in_EAX;
  uint uVar1;
  uint *unaff_ESI;
  
  if ((uint)*(ushort *)(in_EAX + 0x74) <= *unaff_ESI) {
    if (*(char *)(in_EAX + 0x231) != '\0') {
      *(undefined4 *)(in_EAX + 0xc) = 0x86;
    }
    *unaff_ESI = 0;
    return;
  }
  if ((*(byte *)(in_EAX + 0x170) & 1) != 0) {
    uVar1 = (**(code **)(in_EAX + 0x240))();
    *unaff_ESI = uVar1;
    return;
  }
  uVar1 = (**(code **)(in_EAX + 0x23c))();
  *unaff_ESI = uVar1;
  return;
}

