
void FUN_00783630(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_007841f0(param_1);
  cVar1 = (**(code **)(*piVar2 + 4))();
  if (cVar1 != '\0') {
    *(undefined4 *)(in_ECX + 0x44) = 0;
    return;
  }
  *(int **)(in_ECX + 0x44) = piVar2;
  FUN_00730d00();
  return;
}

