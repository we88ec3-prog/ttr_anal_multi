
void FUN_008cdc10(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *unaff_ESI;
  
  *param_3 = 0;
  iVar1 = unaff_ESI[0x208];
  iVar3 = *unaff_ESI;
  piVar2 = unaff_ESI + 1;
  if (iVar3 != 0) {
    while (-unaff_ESI[0x207] <= param_1 - piVar2[3]) {
      if (param_1 <= piVar2[2] + unaff_ESI[0x207]) {
        if (((char)iVar1 != '\0') || (param_1 - piVar2[3] <= unaff_ESI[0x206])) {
          *param_3 = 1;
          param_3[1] = piVar2[4];
        }
        break;
      }
      piVar2 = piVar2 + 8;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) break;
    }
  }
  iVar3 = unaff_ESI[0x81];
  piVar2 = unaff_ESI + iVar3 * 8 + 0x7a;
  if (iVar3 != 0) {
    while (-unaff_ESI[0x207] <= piVar2[2] - param_2) {
      if (piVar2[3] - unaff_ESI[0x207] <= param_2) {
        if (((char)iVar1 == '\0') && (unaff_ESI[0x206] <= piVar2[2] - param_2)) {
          return;
        }
        *param_3 = *param_3 | 2;
        param_3[2] = piVar2[4];
        return;
      }
      piVar2 = piVar2 + -8;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return;
      }
    }
  }
  return;
}

