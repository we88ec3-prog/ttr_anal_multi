
void FUN_008db300(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x4c) != 0) {
    FUN_008bab90(*(undefined4 *)(unaff_ESI + 0x48),unaff_ESI + 0x4c);
  }
  (**(code **)(unaff_ESI + 0x18))();
  return;
}

