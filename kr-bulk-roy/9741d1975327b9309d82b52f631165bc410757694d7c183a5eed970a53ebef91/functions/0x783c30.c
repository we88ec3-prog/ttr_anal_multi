
void FUN_00783c30(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar2 = **(int **)(in_EAX + 0x10);
  iVar1 = in_EAX + 0x48;
  if (iVar2 != iVar1) {
    *(int *)(in_EAX + 0x3c) = iVar2;
    *(int *)(in_EAX + 0x40) = **(int **)(in_EAX + 0x30) + **(int **)(in_EAX + 0x20);
  }
  **(int **)(in_EAX + 0x10) = iVar1;
  **(int **)(in_EAX + 0x20) = iVar1;
  **(int **)(in_EAX + 0x30) = (in_EAX - iVar1) + 0x49;
  return;
}

