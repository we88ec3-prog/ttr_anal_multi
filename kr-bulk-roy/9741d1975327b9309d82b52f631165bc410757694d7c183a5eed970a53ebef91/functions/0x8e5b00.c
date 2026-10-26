
void FUN_008e5b00(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x10);
  FUN_008b9f80(uVar1,*(undefined4 *)(unaff_ESI + 0x54));
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  if (*(char *)(unaff_ESI + 0x5d) == '\0') {
    FUN_008b9f80(uVar1,*(undefined4 *)(unaff_ESI + 0x4c));
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  }
  (**(code **)(unaff_ESI + 0x18))();
  return;
}

