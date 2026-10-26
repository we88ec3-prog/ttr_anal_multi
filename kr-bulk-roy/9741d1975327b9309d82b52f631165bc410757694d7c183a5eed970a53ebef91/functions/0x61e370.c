
void FUN_0061e370(void)

{
  int in_ECX;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint local_8;
  
  FUN_00755e50();
  local_8 = 0x44c;
  puVar3 = (undefined4 *)(in_ECX + 0xf0);
  do {
    iVar1 = 6;
    uVar2 = local_8;
    do {
      FUN_00615fc0(uVar2);
      (**(code **)(*(int *)*puVar3 + 0x198))(uVar2 + 1);
      uVar2 = uVar2 + 100;
      puVar3 = puVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    local_8 = local_8 + 1000;
  } while (local_8 < 0x1004);
  FUN_0061e8b0();
  FUN_0061e9a0();
  return;
}

