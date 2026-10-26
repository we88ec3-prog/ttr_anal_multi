
int FUN_004311c0(uint param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if ((param_1 < *(uint *)(iVar2 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(iVar2 + 8) + param_1 * 4), iVar1 != 0)) {
    return iVar1;
  }
  if ((*(char *)(iVar2 + 0x14) != '\0') &&
     (iVar2 = FUN_0087ded7(), param_1 < *(uint *)(iVar2 + 0xc))) {
    return *(int *)(*(int *)(iVar2 + 8) + param_1 * 4);
  }
  return 0;
}

