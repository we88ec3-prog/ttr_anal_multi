
void FUN_005af050(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x234);
  *(undefined1 *)(in_EAX + 0x230) = 1;
  (**(code **)(**(int **)(iVar1 + 0x88) + 0x94))(0);
  (**(code **)(**(int **)(iVar1 + 0x8c) + 0x94))(0);
  *(undefined4 *)(iVar1 + 0xf8) = 0;
  return;
}

