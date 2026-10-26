
void FUN_00615170(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int local_c;
  int *local_8;
  
  FUN_00755e50();
  local_8 = (int *)(in_ECX + 0xfc);
  iVar2 = 0x9c43;
  do {
    FUN_00615fc0(iVar2 + -1);
    FUN_0046b6f0(iVar2);
    FUN_0046b6f0(iVar2 + 2);
    (**(code **)(*(int *)*local_8 + 0x198))(iVar2 + 1);
    iVar1 = *local_8;
    local_8 = local_8 + 1;
    iVar2 = iVar2 + 100;
    *(undefined4 *)(iVar1 + 0x24c) = 1;
  } while (iVar2 < 0x9eff);
  local_c = 0x9cab;
  iVar2 = 41000;
  do {
    FUN_0046b6f0(iVar2);
    FUN_0046b6f0(local_c);
    local_c = local_c + 100;
    iVar2 = iVar2 + 1000;
  } while (iVar2 < 47000);
  FUN_0043c570(0x44c);
  FUN_0043c570(2000);
  FUN_00615fc0(3000);
  FUN_00615fc0(4000);
  return;
}

