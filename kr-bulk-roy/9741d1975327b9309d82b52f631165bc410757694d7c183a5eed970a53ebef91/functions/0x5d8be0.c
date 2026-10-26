
void FUN_005d8be0(int param_1)

{
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_ESI + 0x2c0) = 0;
  (**(code **)(**(int **)(unaff_ESI + 0x2ac) + 0x94))(0 < param_1);
  if ((*(uint *)(*(int *)(unaff_ESI + 0x2ac) + 0x28) >> 8 & 1) != 0) {
    *(bool *)(unaff_ESI + 0x2c0) = unaff_EDI < 1;
    *(uint *)(*(int *)(unaff_ESI + 0x2ac) + 0x154) = (-(uint)(unaff_EDI < 1) & 0xffff0001) - 1;
    FUN_007597b0(0);
    FUN_007597b0(1);
  }
  (**(code **)(**(int **)(unaff_ESI + 0x2ac) + 200))();
  return;
}

