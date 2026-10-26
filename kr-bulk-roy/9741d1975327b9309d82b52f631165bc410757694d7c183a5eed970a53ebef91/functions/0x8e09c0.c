
undefined4 FUN_008e09c0(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  if ((*unaff_ESI < 1) || (unaff_ESI[3] < 1)) {
    return 0x24;
  }
  if (in_EAX < 0x8000) {
    iVar1 = FUN_008b7f40(0x7d00000,in_EAX << 0x10);
    if ((*unaff_ESI <= iVar1) && (unaff_ESI[3] <= iVar1)) {
      return 0;
    }
  }
  return 0xa4;
}

