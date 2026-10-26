
void FUN_007a5bb0(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x1c);
  if (iVar1 != 0) {
    if (((*(float *)(iVar1 + 0x28) != *(float *)(unaff_EDI + 0xec)) ||
        (*(float *)(iVar1 + 0x2c) != *(float *)(unaff_EDI + 0xf0))) ||
       (*(float *)(iVar1 + 0x30) != *(float *)(unaff_EDI + 0xf4))) {
      (**(code **)(*(int *)(unaff_EDI + 4) + 4))(unaff_EDI + 0xec);
      (**(code **)(*(int *)(unaff_EDI + 4) + 0xc))(*(undefined4 *)(unaff_EDI + 0xfc));
      (**(code **)(*(int *)(unaff_EDI + 4) + 0x14))(*(undefined4 *)(unaff_EDI + 0xf8));
      FUN_007d3bd0(*(undefined4 *)(unaff_EDI + 0x1c));
    }
  }
  return;
}

