
void FUN_00626de0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  FUN_007459c0();
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00626e1c;
    iVar2 = FUN_00745c20();
  }
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) && ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar2);
  }
LAB_00626e1c:
  puVar1 = (undefined4 *)(in_ECX + 0x10c);
  iVar2 = 3;
  do {
    (**(code **)(*(int *)*puVar1 + 0x198))();
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(**(int **)(in_ECX + 0x118) + 0x198))();
  if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) != 0) &&
     (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) != 0)) {
    iVar2 = FUN_005f55a0();
    if (iVar2 != -1) {
      *(int *)(*(int *)(in_ECX + 0x10c + iVar2 * 4) + 0x114) = iVar2;
      FUN_0062b1d0();
    }
    if (iVar2 == 3) {
      FUN_0062b1d0();
    }
  }
  iVar2 = 3;
  do {
    FUN_0062b8c0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0062d050();
  return;
}

