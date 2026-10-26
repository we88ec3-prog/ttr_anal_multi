
void FUN_0050f320(int *param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_0050fa50(unaff_ESI,1,param_2);
    return;
  }
  piVar1 = *(int **)(in_EAX + 4);
  if (param_1 == (int *)*piVar1) {
    if (*(int *)(param_2 + 0xc) < param_1[3]) {
LAB_0050f360:
      FUN_0050fa50(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *(int *)(param_2 + 0xc)) {
LAB_0050f386:
      FUN_0050fa50(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    if ((*(int *)(param_2 + 0xc) < param_1[3]) &&
       (FUN_00536ea0(), param_1[3] < *(int *)(param_2 + 0xc))) {
      if (*(char *)(param_1[2] + 0x31) == '\0') {
        FUN_0050fa50(unaff_ESI,1,param_2);
        return;
      }
      goto LAB_0050f386;
    }
    if ((param_1[3] < *(int *)(param_2 + 0xc)) &&
       ((FUN_0050ef70(), param_1 == *(int **)(in_EAX + 4) || (*(int *)(param_2 + 0xc) < param_1[3]))
       )) {
      if (*(char *)(param_1[2] + 0x31) != '\0') {
        FUN_0050fa50(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_0050f360;
    }
  }
  puVar2 = (undefined4 *)FUN_0050f980(in_EAX,local_c);
  *unaff_ESI = *puVar2;
  return;
}

