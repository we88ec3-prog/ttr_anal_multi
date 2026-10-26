
void FUN_006ee0d0(int param_1,uint param_2)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  uint unaff_EDI;
  
  if (*in_EAX == 0) {
    iVar1 = FUN_0087dc3d(4);
    *in_EAX = iVar1;
    in_EAX[1] = 2;
    in_EAX[2] = 0;
  }
  if ((param_1 != 0) && (param_2 <= (uint)in_EAX[2])) {
    uVar2 = in_EAX[2] + 1U + unaff_EDI;
    if ((uint)in_EAX[1] < uVar2) {
      FUN_006edf50(uVar2);
    }
    FUN_006ee010(in_EAX[2] - param_2);
    uVar2 = 0;
    if (unaff_EDI != 0) {
      iVar1 = param_2 * 2;
      do {
        *(ushort *)(iVar1 + *in_EAX) =
             ((short)uVar2 + 1 + (short)param_2) * 0xde ^ *(ushort *)(param_1 + uVar2 * 2);
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + 2;
      } while (uVar2 < unaff_EDI);
    }
    in_EAX[2] = in_EAX[2] + unaff_EDI;
  }
  return;
}

