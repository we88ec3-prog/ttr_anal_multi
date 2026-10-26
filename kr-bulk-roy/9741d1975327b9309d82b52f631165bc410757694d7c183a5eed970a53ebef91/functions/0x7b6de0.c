
void FUN_007b6de0(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_ESI;
  undefined1 local_8 [4];
  
  piVar2 = param_1;
  if ((param_1 == (int *)*DAT_00fd9424) && (param_2 == DAT_00fd9424)) {
    FUN_007b6fc0();
    *unaff_ESI = *DAT_00fd9424;
    return;
  }
  while (piVar2 != param_2) {
    param_1 = piVar2;
    if (*(char *)((int)piVar2 + 0x15) == '\0') {
      param_1 = (int *)piVar2[2];
      if (*(char *)((int)param_1 + 0x15) == '\0') {
        cVar1 = *(char *)(*param_1 + 0x15);
        piVar3 = (int *)*param_1;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          param_1 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(piVar2[1] + 0x15);
        piVar4 = (int *)piVar2[1];
        piVar3 = piVar2;
        while ((param_1 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x15);
          piVar4 = (int *)param_1[1];
          piVar3 = param_1;
        }
      }
    }
    FUN_007b6890(&DAT_00fd9420,local_8,piVar2);
    piVar2 = param_1;
  }
  *unaff_ESI = (int)piVar2;
  return;
}

