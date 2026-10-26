
void FUN_00783c00(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  if (**(int **)(in_EAX + 0x10) == in_EAX + 0x48) {
    uVar1 = *(undefined4 *)(in_EAX + 0x40);
    **(int **)(in_EAX + 0x10) = *(int *)(in_EAX + 0x3c);
    **(undefined4 **)(in_EAX + 0x20) = uVar1;
    **(undefined4 **)(in_EAX + 0x30) = 0;
  }
  return;
}

