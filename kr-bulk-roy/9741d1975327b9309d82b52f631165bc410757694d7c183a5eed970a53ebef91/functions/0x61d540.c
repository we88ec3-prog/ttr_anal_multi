
void FUN_0061d540(int param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  
  if (in_EAX != 2) {
    cVar1 = *(char *)(*(int *)(param_1 + 0x130 + in_EAX * 0x1c) + 0x250);
    puVar2 = (undefined4 *)(param_1 + (in_EAX + 0x11) * 0x1c);
    iVar3 = 7;
    do {
      (**(code **)(*(int *)*puVar2 + 0x90))(cVar1 != '\0');
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  (**(code **)(**(int **)(param_1 + 0x210) + 0x90))(1);
  return;
}

