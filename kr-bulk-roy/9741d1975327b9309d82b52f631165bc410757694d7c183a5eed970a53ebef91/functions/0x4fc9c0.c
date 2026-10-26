
void FUN_004fc9c0(int *param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_004dbe20(unaff_ESI,1,param_2);
    return;
  }
  piVar1 = *(int **)(in_EAX + 4);
  if (param_1 == (int *)*piVar1) {
    if (*(int *)(param_2 + 0xc) < param_1[3]) {
LAB_004fca00:
      FUN_004dbe20(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *(int *)(param_2 + 0xc)) {
LAB_004fca26:
      FUN_004dbe20(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    if ((*(int *)(param_2 + 0xc) < param_1[3]) &&
       (FUN_008377c0(), param_1[3] < *(int *)(param_2 + 0xc))) {
      if (*(char *)(param_1[2] + 0x21) == '\0') {
        FUN_004dbe20(unaff_ESI,1,param_2);
        return;
      }
      goto LAB_004fca26;
    }
    if ((param_1[3] < *(int *)(param_2 + 0xc)) &&
       ((FUN_0085e240(), param_1 == *(int **)(in_EAX + 4) || (*(int *)(param_2 + 0xc) < param_1[3]))
       )) {
      if (*(char *)(param_1[2] + 0x21) != '\0') {
        FUN_004dbe20(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_004fca00;
    }
  }
  puVar2 = (undefined4 *)FUN_004d3af0(in_EAX,local_c);
  *unaff_ESI = *puVar2;
  return;
}

