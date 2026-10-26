
void FUN_004210f0(void)

{
  int unaff_ESI;
  int *unaff_EDI;
  
  FUN_007598b0(0);
  FUN_007598b0(1);
  *(uint *)(*(int *)(unaff_ESI + 0xfc) + 0x154) = (-(uint)(*unaff_EDI != 0) & 0xff01ff00) - 0x10000;
  (**(code **)(**(int **)(unaff_ESI + 0xfc) + 200))();
  return;
}

