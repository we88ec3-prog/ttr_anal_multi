
undefined4 FUN_005486e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0xa0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xa0))(1);
    *(undefined4 *)(in_ECX + 0xa0) = 0;
  }
  FUN_007beae0();
  iVar1 = *(int *)(in_ECX + 0xb8);
  puVar2 = *(undefined4 **)(iVar1 + 4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  return 0;
}

