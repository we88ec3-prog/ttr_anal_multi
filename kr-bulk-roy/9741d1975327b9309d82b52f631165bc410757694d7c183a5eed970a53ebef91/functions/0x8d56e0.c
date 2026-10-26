
int FUN_008d56e0(void)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  
  iVar2 = FUN_008b97e0();
  if ((iVar2 != 0) || (iVar2 = FUN_008bacd0(), iVar2 != 0)) {
    return iVar2;
  }
  sVar1 = *(short *)(in_EAX + 4);
  if (((sVar1 == 0x200) || (sVar1 == 0x300)) &&
     (((*(short *)(in_EAX + 4) != 0x300) - 1 & 0x1e) + 0x76 <= *(uint *)(in_EAX + 8))) {
    if (sVar1 == 0x200) {
      *(undefined4 *)(in_EAX + 0x84) = 0;
      *(undefined4 *)(in_EAX + 0x88) = 0;
      *(undefined4 *)(in_EAX + 0x8c) = 0;
    }
    if ((*(byte *)(in_EAX + 0x48) & 1) == 0) {
      iVar2 = FUN_008b97e0();
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_008bc7a0();
      return iVar2;
    }
  }
  return 2;
}

