
void FUN_007eee20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  uint *unaff_EDI;
  
  puVar1 = (undefined4 *)unaff_EDI[1];
  if ((in_EAX < puVar1) && (puVar2 = (undefined4 *)*unaff_EDI, puVar2 <= in_EAX)) {
    if (puVar1 == (undefined4 *)unaff_EDI[2]) {
      FUN_007eee80();
    }
    in_EAX = (undefined4 *)(((int)in_EAX - (int)puVar2 & 0xfffffff0U) + *unaff_EDI);
  }
  else if (puVar1 == (undefined4 *)unaff_EDI[2]) {
    FUN_007eee80();
  }
  puVar1 = (undefined4 *)unaff_EDI[1];
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *in_EAX;
    puVar1[1] = in_EAX[1];
    puVar1[2] = in_EAX[2];
    puVar1[3] = in_EAX[3];
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x10;
  return;
}

