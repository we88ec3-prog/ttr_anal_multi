
void FUN_00523480(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *in_EAX;
  int *unaff_EDI;
  
  puVar1 = (undefined1 *)unaff_EDI[1];
  if ((in_EAX < puVar1) && (puVar2 = (undefined1 *)*unaff_EDI, puVar2 <= in_EAX)) {
    if (puVar1 == (undefined1 *)unaff_EDI[2]) {
      FUN_005234e0();
    }
    puVar1 = (undefined1 *)(*unaff_EDI + ((int)in_EAX - (int)puVar2 >> 1) * 2);
    puVar2 = (undefined1 *)unaff_EDI[1];
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      unaff_EDI[1] = unaff_EDI[1] + 2;
      return;
    }
  }
  else {
    if (puVar1 == (undefined1 *)unaff_EDI[2]) {
      FUN_005234e0();
    }
    puVar1 = (undefined1 *)unaff_EDI[1];
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = *in_EAX;
      puVar1[1] = in_EAX[1];
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 2;
  return;
}

