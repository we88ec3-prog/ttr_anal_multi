
void FUN_00533840(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  undefined1 local_8 [4];
  
  piVar2 = *(int **)(unaff_ESI + 4);
  piVar3 = param_1;
  if ((param_1 == (int *)*piVar2) && (param_2 == piVar2)) {
    FUN_005337e0(piVar2[1]);
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(undefined4 *)*(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_EDI = **(undefined4 **)(unaff_ESI + 4);
    return;
  }
  while (piVar3 != param_2) {
    param_1 = piVar3;
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      param_1 = (int *)piVar3[2];
      if (*(char *)((int)param_1 + 0x35) == '\0') {
        cVar1 = *(char *)(*param_1 + 0x35);
        piVar2 = (int *)*param_1;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x35);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_1 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x35);
          piVar4 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
    FUN_00533900(unaff_ESI,local_8,piVar3);
    piVar3 = param_1;
  }
  *unaff_EDI = piVar3;
  return;
}

