
void FUN_007aee20(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xa8) != 0) {
    FUN_0089120c(*(int *)(in_EAX + 0xa8));
  }
  *(undefined4 *)(in_EAX + 0xa8) = 0;
  *(undefined4 *)(in_EAX + 0xac) = 0;
  *(undefined4 *)(in_EAX + 0xb0) = 0;
  FUN_007ac410();
  return;
}

