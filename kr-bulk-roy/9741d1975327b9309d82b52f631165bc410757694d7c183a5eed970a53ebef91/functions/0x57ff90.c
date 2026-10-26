
void FUN_0057ff90(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(undefined4 **)(iVar1 + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(iVar1 + 0x20))(1);
    *(undefined4 *)(iVar1 + 0x20) = 0;
  }
  *(undefined4 *)(iVar1 + 0x60) = 0;
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}

