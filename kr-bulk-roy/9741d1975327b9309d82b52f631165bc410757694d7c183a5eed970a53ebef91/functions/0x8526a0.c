
void FUN_008526a0(int *param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_00852c10(unaff_ESI,1,param_2);
    return;
  }
  piVar1 = *(int **)(in_EAX + 4);
  if (param_1 == (int *)*piVar1) {
    if (*(uint *)(param_2 + 0xc) < (uint)param_1[3]) {
LAB_008526e0:
      FUN_00852c10(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(param_2 + 0xc)) {
LAB_00852706:
      FUN_00852c10(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    if ((*(uint *)(param_2 + 0xc) < (uint)param_1[3]) &&
       (FUN_008532f0(), (uint)param_1[3] < *(uint *)(param_2 + 0xc))) {
      if (*(char *)(param_1[2] + 0x35) == '\0') {
        FUN_00852c10(unaff_ESI,1,param_2);
        return;
      }
      goto LAB_00852706;
    }
    if (((uint)param_1[3] < *(uint *)(param_2 + 0xc)) &&
       ((FUN_00533bf0(), param_1 == *(int **)(in_EAX + 4) ||
        (*(uint *)(param_2 + 0xc) < (uint)param_1[3])))) {
      if (*(char *)(param_1[2] + 0x35) != '\0') {
        FUN_00852c10(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_008526e0;
    }
  }
  puVar2 = (undefined4 *)FUN_008525e0(in_EAX,local_c);
  *unaff_ESI = *puVar2;
  return;
}

