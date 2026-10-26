
void FUN_00682250(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = *(int *)(in_EAX + 0x124);
  iVar2 = *(int *)(in_EAX + 0x120) + 1;
  if (iVar2 < iVar1) {
    *(int *)(in_EAX + 0x120) = iVar2;
    FUN_00682290();
    return;
  }
  if (0 < iVar1) {
    *(int *)(in_EAX + 0x120) = iVar1 + -1;
    FUN_00682290();
    return;
  }
  *(undefined4 *)(in_EAX + 0x120) = 0;
  FUN_00682290();
  return;
}

