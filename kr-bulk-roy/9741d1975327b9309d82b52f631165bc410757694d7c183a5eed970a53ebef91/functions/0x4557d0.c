
void FUN_004557d0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x154);
  iVar2 = (*(int *)(in_ECX + 0x158) - *(int *)(in_ECX + 0x154) >> 2) + -1;
  *(undefined4 *)(in_ECX + 0x174) = *(undefined4 *)(iVar1 + in_EAX * 4);
  if (iVar2 != in_EAX) {
    *(undefined4 *)(iVar1 + in_EAX * 4) = *(undefined4 *)(iVar1 + iVar2 * 4);
  }
  if (*(int *)(in_ECX + 0x154) != *(int *)(in_ECX + 0x158)) {
    *(int *)(in_ECX + 0x158) = *(int *)(in_ECX + 0x158) + -4;
  }
  uVar3 = FUN_006bde40((undefined4 *)(in_ECX + 0x174));
  FUN_00436890(in_ECX + 0x164,uVar3);
  return;
}

