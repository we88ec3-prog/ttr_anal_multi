
void FUN_00819e30(int param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  if (*(int *)(param_1 + 8) == 0) {
    param_2 = *(int **)(param_1 + 4);
LAB_00819e47:
    FUN_005181e0(unaff_ESI,1,param_2,in_EAX);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3)) {
      FUN_005181e0(unaff_ESI,1,param_2,in_EAX);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(ushort *)(piVar1[2] + 0xc) < *(ushort *)(in_EAX + 0xc)) {
      FUN_005181e0(unaff_ESI,0,piVar1[2],in_EAX);
      return;
    }
  }
  else {
    if ((*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3)) &&
       (FUN_008377c0(), *(ushort *)(param_2 + 3) < *(ushort *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_005181e0(unaff_ESI,1,param_2,in_EAX);
        return;
      }
      FUN_005181e0(unaff_ESI,0,param_2,in_EAX);
      return;
    }
    if ((*(ushort *)(param_2 + 3) < *(ushort *)(in_EAX + 0xc)) &&
       ((FUN_0085e240(), param_2 == *(int **)(param_1 + 4) ||
        (*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3))))) {
      if (*(char *)(param_2[2] + 0x21) != '\0') {
        FUN_005181e0(unaff_ESI,0,param_2,in_EAX);
        return;
      }
      goto LAB_00819e47;
    }
  }
  puVar2 = (undefined4 *)FUN_0081a0b0(param_1,in_EAX);
  *unaff_ESI = *puVar2;
  return;
}

