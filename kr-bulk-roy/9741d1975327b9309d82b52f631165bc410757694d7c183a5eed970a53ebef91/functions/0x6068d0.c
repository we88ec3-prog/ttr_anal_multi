
void FUN_006068d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_004067f0();
  if (*(int *)(in_ECX + 0x104) != *(int *)(in_ECX + 0x108)) {
    uVar2 = FUN_00606b70(*(int *)(in_ECX + 0x108),in_ECX);
    *(undefined4 *)(in_ECX + 0x108) = uVar2;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (iVar1 != 0) {
    FUN_006438f0(iVar1);
  }
  return;
}

