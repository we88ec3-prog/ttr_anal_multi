
void FUN_00745100(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(char *)(in_EAX + 0xa4) != '\0') && (*(int *)(in_EAX + 0x94) != 0)) {
    iVar1 = (**(code **)(**(int **)(in_EAX + 0x94) + 4))();
    if (iVar1 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  return;
}

