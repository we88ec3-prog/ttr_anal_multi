
void FUN_006d48a0(int *param_1,int param_2)

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
    if (*(uint *)(param_2 + 0xc) < (uint)param_1[3]) {
LAB_006d48e0:
      FUN_004dbe20(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(param_2 + 0xc)) {
LAB_006d4906:
      FUN_004dbe20(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    if ((*(uint *)(param_2 + 0xc) < (uint)param_1[3]) &&
       (FUN_008377c0(), (uint)param_1[3] < *(uint *)(param_2 + 0xc))) {
      if (*(char *)(param_1[2] + 0x21) == '\0') {
        FUN_004dbe20(unaff_ESI,1,param_2);
        return;
      }
      goto LAB_006d4906;
    }
    if (((uint)param_1[3] < *(uint *)(param_2 + 0xc)) &&
       ((FUN_0085e240(), param_1 == *(int **)(in_EAX + 4) ||
        (*(uint *)(param_2 + 0xc) < (uint)param_1[3])))) {
      if (*(char *)(param_1[2] + 0x21) != '\0') {
        FUN_004dbe20(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_006d48e0;
    }
  }
  puVar2 = (undefined4 *)FUN_007cd000(in_EAX,local_c);
  *unaff_ESI = *puVar2;
  return;
}

