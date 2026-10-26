
void FUN_0061b930(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int local_10;
  int local_c;
  
  FUN_00755e50();
  FUN_0043c570(0x44c);
  FUN_0061df00();
  FUN_00615fc0(10000);
  FUN_00615fc0(20000);
  FUN_00615fc0(30000);
  local_c = 0x13ef;
  piVar3 = (int *)(in_ECX + 0x118);
  do {
    local_10 = 7;
    iVar2 = local_c;
    do {
      FUN_00615fc0(iVar2 + -1);
      FUN_0046b6f0(iVar2);
      FUN_0043c570(iVar2 + 5);
      (**(code **)(*(int *)*piVar3 + 0x198))(iVar2 + 1);
      *(undefined4 *)(*piVar3 + 0x25c) = 1;
      iVar1 = *piVar3;
      iVar2 = iVar2 + 100;
      piVar3 = piVar3 + 1;
      local_10 = local_10 + -1;
      *(undefined4 *)(iVar1 + 0x260) = 1;
    } while (local_10 != 0);
    local_c = local_c + 1000;
  } while (local_c < 0x1fa7);
  return;
}

