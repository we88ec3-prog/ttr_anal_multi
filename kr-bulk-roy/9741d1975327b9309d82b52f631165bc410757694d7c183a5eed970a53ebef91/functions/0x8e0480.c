
uint FUN_008e0480(void)

{
  short sVar1;
  uint in_EAX;
  uint uVar2;
  int in_ECX;
  int extraout_ECX;
  short *extraout_EDX;
  short *psVar3;
  
  if ((*(int *)(in_ECX + 0x488) != 0) && (in_EAX < 0x100)) {
    sVar1 = FUN_008dd980();
    uVar2 = 0;
    psVar3 = extraout_EDX;
    if (*(uint *)(extraout_ECX + 0xc) != 0) {
      do {
        if (*psVar3 == sVar1) {
          return uVar2;
        }
        uVar2 = uVar2 + 1;
        psVar3 = psVar3 + 1;
      } while (uVar2 < *(uint *)(extraout_ECX + 0xc));
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

