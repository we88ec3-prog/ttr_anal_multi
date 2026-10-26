
void FUN_0044bf30(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_00755e50();
  iVar2 = 100;
  do {
    FUN_00615fc0(iVar2);
    iVar2 = iVar2 + 100;
  } while (iVar2 < 900);
  *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0x14);
  iVar2 = *(int *)(in_ECX + 0x108);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(in_ECX + 0x124) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(in_ECX + 0x128) = *(undefined4 *)(iVar2 + 0x10);
  iVar1 = *(int *)(in_ECX + 0x10c);
  *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(iVar2 + 0x14);
  *(undefined4 *)(in_ECX + 0x130) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(in_ECX + 0x134) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(in_ECX + 0x138) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(in_ECX + 0x13c) = *(undefined4 *)(iVar1 + 0x14);
  return;
}

