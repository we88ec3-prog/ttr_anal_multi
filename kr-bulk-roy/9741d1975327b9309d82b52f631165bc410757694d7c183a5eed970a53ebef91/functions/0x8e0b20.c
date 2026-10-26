
void FUN_008e0b20(undefined1 *param_1)

{
  char *in_EAX;
  int iVar1;
  int in_ECX;
  int *unaff_ESI;
  int *unaff_EDI;
  
  *in_EAX = *(char *)(*(int *)(in_ECX + 8) + 0xa0);
  *param_1 = *(undefined1 *)(*(int *)(in_ECX + 8) + 0xa1);
  if (*in_EAX != '\0') {
    iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0xa4) + 0x20;
    *unaff_EDI = (int)(iVar1 + (iVar1 >> 0x1f & 0x3fU)) >> 6;
    iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0xa8) + 0x20;
    *unaff_ESI = (int)(iVar1 + (iVar1 >> 0x1f & 0x3fU)) >> 6;
    return;
  }
  *unaff_EDI = 0x400;
  *unaff_ESI = 0x400;
  return;
}

