
void FUN_00652420(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_EAX + 0xf8);
  iVar2 = 4;
  do {
    (**(code **)(*(int *)*puVar1 + 0x90))(0);
    (**(code **)(*(int *)*puVar1 + 200))();
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

