
void FUN_00751800(void)

{
  int in_EAX;
  
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0);
  FUN_00753660(*(undefined4 *)(in_EAX + 0x1659c),in_EAX + 0x159c);
  FUN_00753700();
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0,0);
  *(undefined4 *)(in_EAX + 0x1659c) = 0;
  return;
}

