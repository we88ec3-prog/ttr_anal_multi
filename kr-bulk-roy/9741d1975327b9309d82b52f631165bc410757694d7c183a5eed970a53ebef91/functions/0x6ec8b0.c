
int FUN_006ec8b0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_006ec850(in_EAX);
  if (iVar2 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(iVar2 + 0x13c)) {
      piVar4 = *(int **)(iVar2 + 0x138);
      do {
        iVar1 = *piVar4;
        if (((*(int *)(iVar1 + 8) == param_2) && (*(int *)(iVar1 + 0xc) == param_3)) &&
           (*(int *)(iVar1 + 0x10) == param_4)) {
          return iVar1;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar3 < *(int *)(iVar2 + 0x13c));
    }
  }
  return 0;
}

