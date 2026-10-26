
uint FUN_006f9f10(void)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(in_EAX + 0x1c);
  if ((uVar4 == 0) || (*(int *)(*(int *)(in_EAX + 0xc) + -8 + uVar4 * 0x10) != 0)) {
    if (*(undefined **)(in_EAX + 0x10) == &DAT_00c0bfa8) {
      return uVar4;
    }
    uVar1 = FUN_006f9de0(uVar4);
  }
  else {
    uVar1 = 0;
    if (1 < uVar4) {
      do {
        uVar3 = uVar1 + uVar4 >> 1;
        uVar2 = uVar3;
        if (*(int *)(*(int *)(in_EAX + 0xc) + -8 + uVar3 * 0x10) == 0) {
          uVar2 = uVar1;
          uVar4 = uVar3;
        }
        uVar1 = uVar2;
      } while (1 < uVar4 - uVar2);
      return uVar2;
    }
  }
  return uVar1;
}

