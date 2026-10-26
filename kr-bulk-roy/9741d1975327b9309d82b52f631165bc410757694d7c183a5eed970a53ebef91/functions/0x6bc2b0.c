
void FUN_006bc2b0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  uint in_ECX;
  uint uVar3;
  
  uVar3 = (*(int *)(in_EAX + 0xf8) - *(int *)(in_EAX + 0xf4) >> 2) - 1;
  if (*(uint *)(in_EAX + 0xe0) <= in_ECX) {
    iVar1 = *(int *)(in_EAX + 0xf4);
    *(undefined4 *)(in_EAX + 0xdc) = *(undefined4 *)(iVar1 + in_ECX * 4);
    if (uVar3 != in_ECX) {
      *(undefined4 *)(iVar1 + in_ECX * 4) = *(undefined4 *)(iVar1 + uVar3 * 4);
    }
    if (*(int *)(in_EAX + 0xf4) != *(int *)(in_EAX + 0xf8)) {
      *(int *)(in_EAX + 0xf8) = *(int *)(in_EAX + 0xf8) + -4;
    }
    uVar2 = FUN_006bde40((undefined4 *)(in_EAX + 0xdc));
    FUN_00436890(in_EAX + 0xe4,uVar2);
  }
  return;
}

