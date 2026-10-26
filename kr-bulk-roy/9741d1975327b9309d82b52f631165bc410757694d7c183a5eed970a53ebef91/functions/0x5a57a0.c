
void FUN_005a57a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x158) == 1) {
    (**(code **)(**(int **)(in_ECX + 0x140) + 0xb4))();
  }
  else if (*(int *)(in_ECX + 0x158) == 2) {
    (**(code **)(**(int **)(in_ECX + 0x148) + 0xb4))();
    return;
  }
  return;
}

