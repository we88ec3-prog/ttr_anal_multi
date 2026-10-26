
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007c3150(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_ESI;
  undefined1 local_8 [4];
  
  piVar3 = param_1;
  if ((param_1 == (int *)*DAT_00fe1e10) && (param_2 == DAT_00fe1e10)) {
    FUN_007b7d40(DAT_00fe1e10[1]);
    DAT_00fe1e10[1] = (int)DAT_00fe1e10;
    *DAT_00fe1e10 = (int)DAT_00fe1e10;
    DAT_00fe1e10[2] = (int)DAT_00fe1e10;
    _DAT_00fe1e14 = 0;
    *unaff_ESI = *DAT_00fe1e10;
    return;
  }
  while (piVar3 != param_2) {
    param_1 = piVar3;
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      param_1 = (int *)piVar3[2];
      if (*(char *)((int)param_1 + 0x2d) == '\0') {
        cVar1 = *(char *)(*param_1 + 0x2d);
        piVar2 = (int *)*param_1;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x2d);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_1 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x2d);
          piVar4 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
    FUN_007c2e30(&DAT_00fe1e0c,local_8,piVar3);
    piVar3 = param_1;
  }
  *unaff_ESI = (int)piVar3;
  return;
}

