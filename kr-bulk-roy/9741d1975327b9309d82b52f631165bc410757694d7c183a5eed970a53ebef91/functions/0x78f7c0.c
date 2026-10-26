
void FUN_0078f7c0(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  while( true ) {
    iVar4 = in_EAX * 2 + 2;
    if (in_ECX <= iVar4) break;
    if (*(int *)(iVar4 * 0x2c + 8 + unaff_ESI) < *(int *)(iVar4 * 0x2c + -0x24 + unaff_ESI)) {
      iVar4 = in_EAX * 2 + 1;
    }
    iVar2 = iVar4 * 0x2c;
    *(undefined4 *)(in_EAX * 0x2c + 4 + unaff_ESI) = *(undefined4 *)(iVar2 + 4 + unaff_ESI);
    iVar3 = iVar2 + unaff_ESI;
    iVar1 = in_EAX * 0x2c + unaff_ESI;
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8 + unaff_ESI);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
    in_EAX = iVar4;
  }
  if (iVar4 == in_ECX) {
    *(undefined4 *)(in_EAX * 0x2c + 4 + unaff_ESI) =
         *(undefined4 *)(in_ECX * 0x2c + -0x28 + unaff_ESI);
    iVar4 = in_ECX * 0x2c + -0x2c + unaff_ESI;
    iVar1 = in_EAX * 0x2c + unaff_ESI;
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar4 + 8);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar4 + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar4 + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar4 + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar4 + 0x28);
  }
  FUN_007901d0();
  return;
}

