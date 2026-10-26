
void FUN_00784410(int *param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_008454f0(unaff_ESI,1,param_2);
    return;
  }
  piVar1 = *(int **)(in_EAX + 4);
  if (param_1 == (int *)*piVar1) {
    if (*(uint *)(param_2 + 0xc) < (uint)param_1[3]) {
LAB_00784450:
      FUN_008454f0(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(param_2 + 0xc)) {
LAB_00784476:
      FUN_008454f0(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    if ((*(uint *)(param_2 + 0xc) < (uint)param_1[3]) &&
       (FUN_0053f8a0(), (uint)param_1[3] < *(uint *)(param_2 + 0xc))) {
      if (*(char *)(param_1[2] + 0x15) == '\0') {
        FUN_008454f0(unaff_ESI,1,param_2);
        return;
      }
      goto LAB_00784476;
    }
    if (((uint)param_1[3] < *(uint *)(param_2 + 0xc)) &&
       ((FUN_0049e6a0(), param_1 == *(int **)(in_EAX + 4) ||
        (*(uint *)(param_2 + 0xc) < (uint)param_1[3])))) {
      if (*(char *)(param_1[2] + 0x15) != '\0') {
        FUN_008454f0(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_00784450;
    }
  }
  puVar2 = (undefined4 *)FUN_00784330(local_c,param_2);
  *unaff_ESI = *puVar2;
  return;
}

