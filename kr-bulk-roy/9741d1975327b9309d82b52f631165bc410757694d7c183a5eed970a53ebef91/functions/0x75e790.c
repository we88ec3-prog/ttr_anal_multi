
void FUN_0075e790(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8);
  iVar2 = FUN_0075e1c0();
  if (iVar2 < iVar1) {
    uVar3 = FUN_0075e1c0();
    *(undefined4 *)(in_ECX + 0xc4) = uVar3;
    return;
  }
  *(int *)(in_ECX + 0xc4) = iVar1;
  return;
}

