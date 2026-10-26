
void FUN_008546d0(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *unaff_ESI;
  undefined1 local_8 [4];
  
  while (param_1 != param_2) {
    param_4 = (int *)FUN_00853b30(local_8,param_4);
    param_4 = (int *)*param_4;
    if (*(char *)((int)param_4 + 0x11) == '\0') {
      piVar2 = (int *)param_4[2];
      if (*(char *)((int)piVar2 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x11);
        param_4 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          param_4 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_4[1] + 0x11);
        piVar2 = param_4;
        param_4 = (int *)param_4[1];
        while ((cVar1 == '\0' && (piVar2 == (int *)param_4[2]))) {
          cVar1 = *(char *)(param_4[1] + 0x11);
          piVar2 = param_4;
          param_4 = (int *)param_4[1];
        }
      }
    }
    if (*(char *)((int)param_1 + 0x11) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x11);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x11);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x11);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  *unaff_ESI = param_3;
  unaff_ESI[1] = param_4;
  return;
}

