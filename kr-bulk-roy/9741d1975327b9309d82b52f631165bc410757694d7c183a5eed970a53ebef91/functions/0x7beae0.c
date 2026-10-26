
void FUN_007beae0(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = 0;
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2 != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(unaff_ESI + 0x14) + uVar1 * 4) + 0x58) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2));
  }
  if (*(undefined4 **)(unaff_ESI + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 4))(1);
    *(undefined4 *)(unaff_ESI + 4) = 0;
  }
  return;
}

