
void FUN_00750020(void)

{
  int in_EAX;
  int *unaff_ESI;
  
  if (*(int *)(in_EAX + 0x13c4) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x13c4) + 0x15c))();
  }
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x10))(1);
  }
  return;
}

