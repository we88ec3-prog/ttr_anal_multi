
void FUN_007f8fc0(void)

{
  int *piVar1;
  int in_ECX;
  
  FUN_007f9bf0();
  piVar1 = *(int **)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x128) != 0) {
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x13,5);
    (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0x14,2);
    return;
  }
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xf,1);
  (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0x18,0x6f);
  (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0x19,5);
  (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0x13,5);
  (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0x14,6);
  return;
}

