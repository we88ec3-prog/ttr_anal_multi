
void FUN_006560e0(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00755e50();
  FUN_00656470();
  iVar1 = 0x2b66;
  puVar2 = (undefined4 *)(in_ECX + 0xf4);
  do {
    FUN_00615fc0(iVar1);
    (**(code **)(*(int *)*puVar2 + 0x198))(iVar1 + 1);
    iVar1 = iVar1 + 100;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x2d5a);
  return;
}

