
void FUN_00422e30(uint *param_1)

{
  int unaff_ESI;
  uint *unaff_EDI;
  
  FUN_007598b0(0);
  FUN_007598b0(1);
  *(uint *)(*(int *)(unaff_ESI + 0xf0) + 0x154) = (-(uint)(*unaff_EDI != 0) & 0xff01ff00) - 0x10000;
  (**(code **)(**(int **)(unaff_ESI + 0xf0) + 200))();
  (**(code **)(**(int **)(unaff_ESI + 0xf8) + 0x90))(*unaff_EDI < *param_1);
  (**(code **)(**(int **)(unaff_ESI + 0xf8) + 200))();
  return;
}

