
void FUN_0080df70(void)

{
  uint uVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  int iVar2;
  
  uVar1 = in_EAX[8];
  in_ECX[8] = uVar1;
  if (uVar1 != 0) {
    if (uVar1 == 0x3fff) {
      for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
        *in_ECX = *in_EAX;
        in_EAX = in_EAX + 1;
        in_ECX = in_ECX + 1;
      }
      return;
    }
    if ((uVar1 & 1) != 0) {
      in_ECX[9] = in_EAX[9];
    }
    if ((uVar1 & 2) != 0) {
      in_ECX[10] = in_EAX[10];
    }
    if ((uVar1 & 4) != 0) {
      in_ECX[0xb] = in_EAX[0xb];
    }
    if ((uVar1 & 8) != 0) {
      in_ECX[0xc] = in_EAX[0xc];
    }
    if ((uVar1 & 0x20) != 0) {
      in_ECX[0xe] = in_EAX[0xe];
    }
    if ((uVar1 & 0x40) != 0) {
      in_ECX[0xf] = in_EAX[0xf];
    }
    if ((uVar1 & 0x80) != 0) {
      in_ECX[0x10] = in_EAX[0x10];
    }
    if ((uVar1 & 0x100) != 0) {
      in_ECX[0x11] = in_EAX[0x11];
    }
    if ((uVar1 & 0x200) != 0) {
      in_ECX[0x12] = in_EAX[0x12];
    }
    if ((uVar1 & 0x400) != 0) {
      in_ECX[0x13] = in_EAX[0x13];
    }
    if ((uVar1 & 0x800) != 0) {
      in_ECX[0x16] = in_EAX[0x16];
    }
    if ((in_ECX[8] & 0x1000) != 0) {
      in_ECX[0x14] = in_EAX[0x14];
    }
    if ((in_ECX[8] & 0x2000) != 0) {
      in_ECX[0x15] = in_EAX[0x15];
    }
  }
  return;
}

