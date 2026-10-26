
void FUN_0071cf20(int param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *in_EDX;
  undefined4 *unaff_ESI;
  
  if (in_EAX != in_EDX) {
    if (param_1 == 0) {
      puVar1 = (undefined4 *)FUN_00722930();
      *unaff_ESI = *puVar1;
      unaff_ESI[1] = puVar1[1];
      return;
    }
    if (param_1 == 1) {
      *unaff_ESI = *in_EAX;
      unaff_ESI[1] = in_EAX[1];
      return;
    }
    if (param_1 == 2) {
      *unaff_ESI = in_EDX[-2];
      unaff_ESI[1] = in_EDX[-1];
      return;
    }
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  return;
}

