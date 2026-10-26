
void FUN_00655ce0(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *in_EAX;
  int *unaff_ESI;
  
  puVar1 = (undefined1 *)unaff_ESI[1];
  if ((in_EAX < puVar1) && (puVar2 = (undefined1 *)*unaff_ESI, puVar2 <= in_EAX)) {
    if (puVar1 == (undefined1 *)unaff_ESI[2]) {
      FUN_00407cf0();
    }
    if ((undefined1 *)unaff_ESI[1] != (undefined1 *)0x0) {
      *(undefined1 *)unaff_ESI[1] = in_EAX[*unaff_ESI - (int)puVar2];
      unaff_ESI[1] = unaff_ESI[1] + 1;
      return;
    }
  }
  else {
    if (puVar1 == (undefined1 *)unaff_ESI[2]) {
      FUN_00407cf0();
    }
    if ((undefined1 *)unaff_ESI[1] != (undefined1 *)0x0) {
      *(undefined1 *)unaff_ESI[1] = *in_EAX;
    }
  }
  unaff_ESI[1] = unaff_ESI[1] + 1;
  return;
}

