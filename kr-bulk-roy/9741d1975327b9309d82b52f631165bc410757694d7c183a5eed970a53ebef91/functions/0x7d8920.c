
void FUN_007d8920(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(unaff_ESI + 0x5c) + uVar2 * 4) != 0) {
        puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 0x5c) + uVar2 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(*(int *)(unaff_ESI + 0x5c) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c) >> 2));
  }
  return;
}

