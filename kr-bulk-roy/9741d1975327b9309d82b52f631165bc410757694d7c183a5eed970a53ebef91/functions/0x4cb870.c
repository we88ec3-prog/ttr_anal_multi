
void FUN_004cb870(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x418) = 300;
  (**(code **)(**(int **)(in_ECX + 4) + 0x68))(*(undefined4 *)(in_ECX + 0x38),0x3f800000);
  return;
}

