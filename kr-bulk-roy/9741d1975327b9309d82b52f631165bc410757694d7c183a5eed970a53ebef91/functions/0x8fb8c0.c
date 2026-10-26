
int FUN_008fb8c0(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  while( true ) {
    uVar2 = *(int *)(in_ECX + 0x2050) - *(int *)(in_ECX + 0x204c);
    if (in_EAX <= uVar2) {
      uVar2 = in_EAX;
    }
    *(int *)(in_ECX + 0x2048) = *(int *)(in_ECX + 0x2048) + uVar2;
    in_EAX = in_EAX - uVar2;
    *(uint *)(in_ECX + 0x204c) = *(int *)(in_ECX + 0x204c) + uVar2;
    if (in_EAX == 0) break;
    iVar1 = FUN_008fb850();
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}

