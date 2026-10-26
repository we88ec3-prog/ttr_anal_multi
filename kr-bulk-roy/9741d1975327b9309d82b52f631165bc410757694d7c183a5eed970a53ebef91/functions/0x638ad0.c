
void FUN_00638ad0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_ECX + 0xc);
  iVar2 = 0x29;
  do {
    (**(code **)(*(int *)*puVar1 + 0x94))(0);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

