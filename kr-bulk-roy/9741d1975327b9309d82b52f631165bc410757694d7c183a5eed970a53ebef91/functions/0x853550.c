
undefined4 *
FUN_00853550(undefined4 *param_1,int *param_2,int *param_3,int param_4,int param_5,
            undefined4 param_6,int *param_7)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [8];
  
  puVar3 = param_1;
  if (param_2 != param_3) {
    do {
      if (param_4 == param_5) break;
      if ((uint)param_2[3] < *(uint *)(param_4 + 0xc)) {
        param_7 = (int *)FUN_00853b30(&param_1,param_7);
        param_7 = (int *)*param_7;
        if (*(char *)((int)param_7 + 0x11) == '\0') {
          piVar2 = (int *)param_7[2];
          if (*(char *)((int)piVar2 + 0x11) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x11);
            param_7 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x11);
              param_7 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(param_7[1] + 0x11);
            piVar2 = param_7;
            param_7 = (int *)param_7[1];
            while ((cVar1 == '\0' && (piVar2 == (int *)param_7[2]))) {
              cVar1 = *(char *)(param_7[1] + 0x11);
              piVar2 = param_7;
              param_7 = (int *)param_7[1];
            }
          }
        }
        if (*(char *)((int)param_2 + 0x11) == '\0') {
          piVar2 = (int *)param_2[2];
          if (*(char *)((int)piVar2 + 0x11) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x11);
            param_2 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x11);
              param_2 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(param_2[1] + 0x11);
            piVar4 = (int *)param_2[1];
            piVar2 = param_2;
            while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
              cVar1 = *(char *)(param_2[1] + 0x11);
              piVar4 = (int *)param_2[1];
              piVar2 = param_2;
            }
          }
        }
      }
      else {
        if (*(uint *)(param_4 + 0xc) < (uint)param_2[3]) {
          param_7 = (int *)FUN_00853b30(local_c,param_7);
          param_7 = (int *)*param_7;
        }
        else {
          param_7 = (int *)FUN_00853b30(&local_10,param_7);
          param_7 = (int *)*param_7;
          FUN_0079c460();
        }
        FUN_0079c460();
        FUN_0079c460();
      }
    } while (param_2 != param_3);
  }
  FUN_008546d0(param_2,param_3,param_6,param_7,param_2);
  param_7 = (int *)local_10;
  FUN_008546d0(param_4,param_5,local_14,local_10,param_2);
  puVar3[1] = local_10;
  *puVar3 = local_14;
  return puVar3;
}

