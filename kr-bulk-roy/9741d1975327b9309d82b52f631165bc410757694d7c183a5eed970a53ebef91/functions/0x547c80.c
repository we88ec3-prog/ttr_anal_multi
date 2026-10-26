
undefined4 FUN_00547c80(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  FUN_007beae0();
  iVar1 = *(int *)(in_ECX + 0xbc);
  puVar2 = *(undefined4 **)(iVar1 + 4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc0);
  puVar2 = *(undefined4 **)(iVar1 + 4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc4);
  puVar2 = *(undefined4 **)(iVar1 + 4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  return 0;
}

