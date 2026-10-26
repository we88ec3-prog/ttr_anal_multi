
int FUN_008e58b0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint unaff_EDI;
  int local_8;
  
  iVar1 = FUN_008b97e0(param_1,0);
  if ((((iVar1 == 0) && (iVar1 = FUN_008e5850(&local_8), iVar1 == 0)) &&
      (((short)local_8 == -0x7fff || (iVar1 = FUN_008b97e0(param_1,0), iVar1 == 0)))) &&
     (local_8 = FUN_008babe0(param_1), iVar1 = local_8, local_8 == 0)) {
    piVar2 = *(int **)(param_1 + 0x20);
    for (; 3 < unaff_EDI; unaff_EDI = unaff_EDI - 4) {
      if (*piVar2 != *param_2) goto LAB_008e5958;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    }
    if ((unaff_EDI != 0) &&
       (((char)*param_2 != (char)*piVar2 ||
        ((1 < unaff_EDI &&
         ((*(char *)((int)param_2 + 1) != *(char *)((int)piVar2 + 1) ||
          ((2 < unaff_EDI && (*(char *)((int)param_2 + 2) != *(char *)((int)piVar2 + 2))))))))))) {
LAB_008e5958:
      local_8 = 2;
    }
    FUN_008baca0(param_1);
    iVar1 = local_8;
  }
  return iVar1;
}

