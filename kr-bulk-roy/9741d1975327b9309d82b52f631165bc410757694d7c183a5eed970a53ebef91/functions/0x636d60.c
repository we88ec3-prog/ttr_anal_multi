
void FUN_00636d60(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(int *)(in_EAX + 0xac) != 0) && (*(int *)(in_EAX + 0xac) != 0)) {
    *(int *)(in_EAX + 0xa8) = *(int *)(in_EAX + 0xa8) + 1;
    if ((uint)(*(int *)(in_EAX + 0xa4) * 4) <= *(uint *)(in_EAX + 0xa8)) {
      *(undefined4 *)(in_EAX + 0xa8) = 0;
    }
    iVar1 = *(int *)(in_EAX + 0xac) + -1;
    *(int *)(in_EAX + 0xac) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(in_EAX + 0xa8) = 0;
    }
  }
  FUN_00636050(in_EAX);
  return;
}

