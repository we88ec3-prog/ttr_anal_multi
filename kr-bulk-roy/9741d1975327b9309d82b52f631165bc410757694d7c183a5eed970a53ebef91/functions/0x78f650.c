
void FUN_0078f650(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  int iVar3;
  int unaff_ESI;
  
  while( true ) {
    iVar3 = in_EAX * 2 + 2;
    if (unaff_ESI <= iVar3) break;
    if (*(int *)(in_ECX + 8 + iVar3 * 0x18) < *(int *)(in_ECX + -0x10 + iVar3 * 0x18)) {
      iVar3 = in_EAX * 2 + 1;
    }
    iVar1 = in_ECX + iVar3 * 0x18;
    iVar2 = in_ECX + in_EAX * 0x18;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 4 + iVar3 * 0x18);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    in_EAX = iVar3;
  }
  if (iVar3 == unaff_ESI) {
    iVar1 = in_ECX + -0x18 + unaff_ESI * 0x18;
    iVar3 = in_ECX + in_EAX * 0x18;
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(in_ECX + -0x14 + unaff_ESI * 0x18);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
  }
  FUN_00790100();
  return;
}

