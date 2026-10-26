
float10 FUN_00810ac0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    return (float10)*(int *)(*(int *)(in_ECX + 8) + 8);
  }
  return (float10)0;
}

