
void FUN_00656a70(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_10;
  int local_c;
  
  FUN_0040e370(1);
  FUN_00656ff0();
  FUN_0040e370(3);
  local_c = 12000;
  local_10 = (undefined4 *)(in_ECX + 0xe8);
  do {
    puVar2 = local_10;
    FUN_0040e370(local_c + -2000);
    FUN_0043c570(local_c);
    FUN_0040e370(local_c + 38000);
    iVar1 = local_c + 0xa08c;
    local_10 = (undefined4 *)0x5;
    do {
      FUN_00615fc0(iVar1);
      (**(code **)(*(int *)*puVar2 + 0x198))(iVar1 + 1);
      iVar1 = iVar1 + 1000;
      puVar2 = puVar2 + 1;
      local_10 = (undefined4 *)((int)local_10 + -1);
    } while (local_10 != (undefined4 *)0x0);
    local_c = local_c + 10000;
    local_10 = puVar2;
  } while (local_c < 52000);
  return;
}

