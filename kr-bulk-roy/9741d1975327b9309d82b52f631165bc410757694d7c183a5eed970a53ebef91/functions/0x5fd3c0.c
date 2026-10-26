
void FUN_005fd3c0(void)

{
  code *pcVar1;
  int in_EAX;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  *(int *)(in_ECX + 0x140) = in_EAX;
  pcVar1 = *(code **)(**(int **)(in_ECX + 300) + 0x90);
  if (in_EAX == 0) {
    (*pcVar1)(1);
    (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(1);
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(1);
    puVar2 = (undefined4 *)(in_ECX + 0x170);
    iVar3 = 5;
    do {
      (**(code **)(*(int *)*puVar2 + 0x90))(1);
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  (*pcVar1)(0);
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(0);
  (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(0);
  puVar2 = (undefined4 *)(in_ECX + 0x170);
  iVar3 = 5;
  do {
    (**(code **)(*(int *)*puVar2 + 0x90))(0);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

