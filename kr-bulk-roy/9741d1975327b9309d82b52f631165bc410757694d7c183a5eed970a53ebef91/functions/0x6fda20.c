
int FUN_006fda20(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int unaff_ESI;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x38)) {
    piVar2 = (int *)(*(int *)(in_ECX + 0x18) + 8);
    do {
      if (unaff_ESI < piVar2[-1]) {
        return 0;
      }
      if ((unaff_ESI < *piVar2) && (param_1 = param_1 + -1, param_1 == 0)) {
        return *(int *)(*(int *)(in_ECX + 0x18) + iVar1 * 0xc) + 0x10;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar1 < *(int *)(in_ECX + 0x38));
  }
  return 0;
}

