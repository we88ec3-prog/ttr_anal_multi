
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f310(void)

{
  int unaff_ESI;
  
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  if (DAT_00fdf3ac != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0xec) + 0x94))(*DAT_00fdf3ac == 0);
    FUN_0063ee00(*(undefined4 *)(unaff_ESI + 0x110));
    (**(code **)(**(int **)(unaff_ESI + 0x110) + 0x94))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x94))(0);
    return;
  }
  (**(code **)(**(int **)(unaff_ESI + 0xec) + 0x94))(1);
  (**(code **)(**(int **)(unaff_ESI + 0x110) + 0x94))(0);
  (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x94))(1);
  return;
}

