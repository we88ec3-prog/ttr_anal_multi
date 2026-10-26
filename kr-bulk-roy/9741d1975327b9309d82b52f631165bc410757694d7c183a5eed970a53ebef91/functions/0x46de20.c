
void FUN_0046de20(undefined1 param_1)

{
  int *piVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[5] == 0) {
    FUN_00402dc0(1,unaff_ESI[4]);
  }
  piVar1 = unaff_ESI;
  if (0xf < (uint)unaff_ESI[5]) {
    piVar1 = (int *)*unaff_ESI;
  }
  *(undefined1 *)piVar1 = param_1;
  unaff_ESI[4] = 1;
  if ((uint)unaff_ESI[5] < 0x10) {
    *(undefined1 *)((int)unaff_ESI + 1) = 0;
    return;
  }
  *(undefined1 *)(*unaff_ESI + 1) = 0;
  return;
}

