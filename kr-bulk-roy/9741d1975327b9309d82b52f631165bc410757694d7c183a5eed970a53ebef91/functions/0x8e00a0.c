
void FUN_008e00a0(int param_1,char param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  *(undefined2 *)(unaff_ESI + 0x10) = 0x100;
  unaff_ESI[1] = in_EAX;
  unaff_ESI[2] = unaff_EDI;
  *unaff_ESI = *(undefined4 *)(in_EAX + 100);
  if (unaff_EDI != 0) {
    iVar1 = **(int **)(unaff_EDI + 0x9c);
    unaff_ESI[3] = iVar1;
    unaff_ESI[4] = iVar1 + 0x14;
    unaff_ESI[5] = iVar1 + 0x38;
    FUN_008b82d0(iVar1);
    unaff_ESI[0x12] = 0;
    unaff_ESI[0x11] = 0;
    if ((param_2 != '\0') && (param_1 != 0)) {
      unaff_ESI[0x12] = **(undefined4 **)(param_1 + 0x28);
      unaff_ESI[0x11] = *(undefined4 *)(*(int *)(unaff_EDI + 0x9c) + 0x24);
    }
  }
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  return;
}

