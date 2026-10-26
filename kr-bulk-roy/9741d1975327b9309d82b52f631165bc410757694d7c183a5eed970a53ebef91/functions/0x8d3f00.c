
undefined4 FUN_008d3f00(int param_1,int *param_2,int *param_3)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  int *piVar3;
  int unaff_EBX;
  int *unaff_EDI;
  
  uVar2 = 0;
  piVar3 = unaff_EDI;
  if (in_EAX != 0) {
    do {
      if (*piVar3 == unaff_EBX) {
        if ((*(uint *)(param_1 + 8) <= (uint)unaff_EDI[uVar2 * 4 + 3]) &&
           (iVar1 = FUN_008b9820(param_1,unaff_EDI[uVar2 * 4 + 3] - *(uint *)(param_1 + 8)),
           iVar1 == 0)) {
          *param_3 = unaff_EDI[uVar2 * 4 + 2];
          *param_2 = unaff_EDI[uVar2 * 4 + 1];
          return 0;
        }
        *param_3 = 0;
        return 0x53;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 4;
    } while (uVar2 < in_EAX);
  }
  *param_3 = 0;
  return 3;
}

