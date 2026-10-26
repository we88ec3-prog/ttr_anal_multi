
void FUN_005e0b80(void)

{
  int *unaff_ESI;
  
  (**(code **)(*unaff_ESI + 0x19c))(0xffffffff,0xffffffff,0,0);
  *(undefined1 *)(unaff_ESI + 0xaa) = 1;
  (**(code **)(*(int *)unaff_ESI[0xa9] + 0xa0))(0);
  (**(code **)(*(int *)unaff_ESI[0xa9] + 0x90))(0);
  return;
}

