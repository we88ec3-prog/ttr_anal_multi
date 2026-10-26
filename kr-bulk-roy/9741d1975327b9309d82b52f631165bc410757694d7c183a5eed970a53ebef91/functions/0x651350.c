
void FUN_00651350(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  FUN_00755e50();
  FUN_00615fc0(12000);
  FUN_00615fc0(0x32c9);
  puVar1 = (undefined4 *)(in_ECX + 0xf8);
  iVar2 = 0x2cf7;
  do {
    FUN_0043c570(iVar2 + -0xb);
    FUN_00615fc0(iVar2 + -1);
    (**(code **)(*(int *)*puVar1 + 0x198))(iVar2);
    iVar2 = iVar2 + 100;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 0x2e87);
  return;
}

