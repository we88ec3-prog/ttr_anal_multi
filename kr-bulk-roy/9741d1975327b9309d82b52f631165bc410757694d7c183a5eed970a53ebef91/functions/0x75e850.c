
void FUN_0075e850(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 0xd8) + *(int *)(in_ECX + 0xc4);
  iVar3 = *(int *)(in_ECX + 0xb8);
  if (iVar1 < *(int *)(in_ECX + 0xb8)) {
    iVar3 = iVar1;
  }
  *(int *)(in_ECX + 0xc4) = iVar3;
  iVar1 = FUN_0075e270();
  if (iVar3 < iVar1) {
    *(int *)(in_ECX + 0xc4) = iVar3;
    return;
  }
  uVar2 = FUN_0075e270();
  *(undefined4 *)(in_ECX + 0xc4) = uVar2;
  return;
}

