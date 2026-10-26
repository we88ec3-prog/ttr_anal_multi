
void FUN_0072f760(int *param_1)

{
  int *piVar1;
  char cVar2;
  int in_ECX;
  
  cVar2 = (**(code **)(*param_1 + 8))();
  if (cVar2 != '\0') {
    piVar1 = *(int **)(in_ECX + 0x18);
    while ((piVar1 != (int *)0x0 && (cVar2 = (**(code **)(*piVar1 + 0x40))(param_1), cVar2 != '\0'))
          ) {
      piVar1 = (int *)piVar1[0x10];
    }
  }
  (**(code **)(*param_1 + 0x10))();
  return;
}

