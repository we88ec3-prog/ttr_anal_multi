
void FUN_007a2a10(int param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_007a2eb0(unaff_EDI,1,in_EAX);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) {
LAB_007a2a52:
      FUN_007a2eb0(unaff_EDI,1,in_EAX);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(in_EAX + 0xc)) {
      FUN_007a2eb0(unaff_EDI,0,in_EAX);
      return;
    }
  }
  else {
    if ((*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) &&
       (FUN_0081a1b0(), (uint)param_2[3] < *(uint *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x19) == '\0') {
        FUN_007a2eb0(unaff_EDI,1,in_EAX);
        return;
      }
      FUN_007a2eb0(unaff_EDI,0,in_EAX);
      return;
    }
    if (((uint)param_2[3] < *(uint *)(in_EAX + 0xc)) &&
       ((FUN_00406870(), param_2 == *(int **)(param_1 + 4) ||
        (*(uint *)(in_EAX + 0xc) < (uint)param_2[3])))) {
      if (*(char *)(param_2[2] + 0x19) != '\0') {
        FUN_007a2eb0(unaff_EDI,0,in_EAX);
        return;
      }
      goto LAB_007a2a52;
    }
  }
  puVar2 = (undefined4 *)FUN_007a2e00(param_1,in_EAX);
  *unaff_EDI = *puVar2;
  return;
}

