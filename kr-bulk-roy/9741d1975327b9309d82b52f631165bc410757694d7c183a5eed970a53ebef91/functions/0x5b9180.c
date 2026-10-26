
void FUN_005b9180(void)

{
  int in_EAX;
  int unaff_ESI;
  
  if ((*(uint *)(*(int *)(unaff_ESI + 0x274) + 0x28) >> 8 & 1) != 0) {
    FUN_006771d0(*(int *)(unaff_ESI + 0x274),*(undefined4 *)(in_EAX + 0x14),
                 *(undefined4 *)(in_EAX + 0x18),*(undefined4 *)(in_EAX + 0x1c));
    return;
  }
  if ((*(uint *)(*(int *)(unaff_ESI + 0x290) + 0x28) >> 8 & 1) != 0) {
    FUN_00607f30(*(undefined4 *)(in_EAX + 0x14),*(undefined4 *)(in_EAX + 0x18),
                 *(undefined4 *)(in_EAX + 0x1c));
  }
  return;
}

