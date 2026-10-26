
void FUN_008d6b00(void)

{
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x54) == '\0') {
    FUN_008b9f80(*(undefined4 *)(unaff_ESI + 0x10),*(undefined4 *)(unaff_ESI + 0x4c));
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  }
  (**(code **)(unaff_ESI + 0x18))();
  return;
}

