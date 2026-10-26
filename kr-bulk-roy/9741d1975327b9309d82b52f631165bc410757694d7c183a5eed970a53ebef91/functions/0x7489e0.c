
void FUN_007489e0(void)

{
  int in_EAX;
  int *unaff_ESI;
  
  if (*(int *)(in_EAX + 0x60) != 0) {
    unaff_ESI[1] = *(int *)(in_EAX + 0x20);
    unaff_ESI[2] = *(int *)(in_EAX + 0x48);
    (**(code **)(**(int **)(in_EAX + 0x60) + 0x148))();
  }
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x10))(1);
  }
  return;
}

