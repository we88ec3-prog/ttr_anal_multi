
void FUN_00711fe0(void)

{
  int in_EAX;
  int iVar1;
  int *in_EDX;
  uint uVar2;
  int *unaff_EDI;
  
  if (in_EAX != -1) {
    iVar1 = *in_EDX;
    if (iVar1 == -1) {
      *in_EDX = in_EAX;
      return;
    }
    do {
      uVar2 = *(uint *)(*(int *)(*unaff_EDI + 0xc) + iVar1 * 4) >> 0xe;
      if (uVar2 == 0x1fffe) break;
      iVar1 = (uVar2 - 0x1fffe) + iVar1;
    } while (iVar1 != -1);
    FUN_00711d40();
  }
  return;
}

