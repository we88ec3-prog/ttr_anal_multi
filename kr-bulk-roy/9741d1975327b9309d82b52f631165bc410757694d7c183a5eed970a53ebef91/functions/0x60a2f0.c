
void FUN_0060a2f0(void)

{
  int iVar1;
  int in_EAX;
  
  (**(code **)(**(int **)(in_EAX + 0x108) + 0x94))(1);
  (**(code **)(**(int **)(in_EAX + 0xfc) + 0x90))(0);
  iVar1 = *(int *)(in_EAX + 0xf8);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  return;
}

