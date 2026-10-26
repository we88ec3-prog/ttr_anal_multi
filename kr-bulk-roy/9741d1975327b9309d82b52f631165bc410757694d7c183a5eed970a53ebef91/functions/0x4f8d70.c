
void FUN_004f8d70(int param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_004f9370(unaff_ESI,1,in_EAX);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) {
LAB_004f8db2:
      FUN_004f9370(unaff_ESI,1,in_EAX);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(in_EAX + 0xc)) {
      FUN_004f9370(unaff_ESI,0,in_EAX);
      return;
    }
  }
  else {
    if ((*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) &&
       (FUN_004f97f0(), (uint)param_2[3] < *(uint *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x75) == '\0') {
        FUN_004f9370(unaff_ESI,1,in_EAX);
        return;
      }
      FUN_004f9370(unaff_ESI,0,in_EAX);
      return;
    }
    if (((uint)param_2[3] < *(uint *)(in_EAX + 0xc)) &&
       ((FUN_004f8d20(), param_2 == *(int **)(param_1 + 4) ||
        (*(uint *)(in_EAX + 0xc) < (uint)param_2[3])))) {
      if (*(char *)(param_2[2] + 0x75) != '\0') {
        FUN_004f9370(unaff_ESI,0,in_EAX);
        return;
      }
      goto LAB_004f8db2;
    }
  }
  puVar2 = (undefined4 *)FUN_004f92c0(param_1,in_EAX);
  *unaff_ESI = *puVar2;
  return;
}

