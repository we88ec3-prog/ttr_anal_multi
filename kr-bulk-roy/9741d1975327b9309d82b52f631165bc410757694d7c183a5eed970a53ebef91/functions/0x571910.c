
void FUN_00571910(void)

{
  int *unaff_ESI;
  
  if ((int *)*unaff_ESI != (int *)0x0) {
    (**(code **)(*(int *)*unaff_ESI + 8))();
    *unaff_ESI = 0;
  }
  return;
}

