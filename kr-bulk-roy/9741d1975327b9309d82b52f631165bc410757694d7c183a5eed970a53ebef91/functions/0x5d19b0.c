
void FUN_005d19b0(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  FUN_0046b6f0(11000);
  FUN_005d23e0();
  FUN_005d24d0();
  FUN_0046b6f0(0x2c24);
  FUN_0040f570(0x2f44);
  FUN_0040f570(0x332c);
  FUN_0040f570(0x3714);
  FUN_006ae700();
  local_8 = 0;
  iVar1 = 41000;
  piVar2 = (int *)(in_ECX + 0xc0);
  do {
    FUN_00615fc0(iVar1);
    local_8 = local_8 + 1;
    *(int *)(*piVar2 + 0x2a0) = local_8;
    (**(code **)(*(int *)*piVar2 + 0x198))(iVar1 + 1);
    iVar1 = iVar1 + 10000;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 81000);
  iVar1 = *(int *)(in_ECX + 0xb8);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  return;
}

