
uint FUN_008ce2a0(char param_1)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  
  if ((int)in_EAX < 0x41) {
    uVar1 = 0x40;
    goto LAB_008ce2ff;
  }
  uVar1 = *(uint *)(in_ECX + 8);
  iVar2 = in_EAX - uVar1;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if ((iVar2 < 0x28) && (in_EAX = uVar1, (int)uVar1 < 0x30)) {
    in_EAX = 0x30;
  }
  else if (0xbf < (int)in_EAX) {
    uVar1 = in_EAX + 0x20 & 0xffffffc0;
    goto LAB_008ce2ff;
  }
  uVar3 = in_EAX & 0x3f;
  uVar1 = in_EAX & 0xffffffc0;
  if (9 < uVar3) {
    if (uVar3 < 0x20) {
      uVar1 = uVar1 + 10;
      goto LAB_008ce2ff;
    }
    if (uVar3 < 0x36) {
      uVar1 = uVar1 + 0x36;
      goto LAB_008ce2ff;
    }
  }
  uVar1 = uVar1 + uVar3;
LAB_008ce2ff:
  if (param_1 != '\0') {
    uVar1 = uVar1 + 0x20 & 0xffffffc0;
  }
  return uVar1;
}

