
/* WARNING: Removing unreachable block (ram,0x0056e308) */

void FUN_0056e2d0(void)

{
  int unaff_ESI;
  
  if (*(undefined4 **)(unaff_ESI + 0x1c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x1c))(1);
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  }
  if (*(int *)(unaff_ESI + 0x3c) != 0) {
    FUN_004a47d0(*(int *)(unaff_ESI + 0x3c));
    *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  if (*(int *)(unaff_ESI + 0x74) != *(int *)(unaff_ESI + 0x78)) {
    *(int *)(unaff_ESI + 0x78) = *(int *)(unaff_ESI + 0x74);
  }
  return;
}

