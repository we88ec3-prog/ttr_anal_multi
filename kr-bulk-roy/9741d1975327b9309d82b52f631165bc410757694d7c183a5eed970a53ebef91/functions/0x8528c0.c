
void FUN_008528c0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined1 local_c [8];
  
  if (*(int *)(param_1 + 8) == 0) {
    param_2 = *(int **)(param_1 + 4);
LAB_008528d4:
    FUN_00852dc0(unaff_ESI,1,param_2,unaff_EDI);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(uint *)(unaff_EDI + 0xc) < (uint)param_2[3]) {
      FUN_00852dc0(unaff_ESI,1,param_2,unaff_EDI);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(unaff_EDI + 0xc)) {
      FUN_00852dc0(unaff_ESI,0,piVar1[2],unaff_EDI);
      return;
    }
  }
  else {
    if ((*(uint *)(unaff_EDI + 0xc) < (uint)param_2[3]) &&
       (FUN_008377c0(), (uint)param_2[3] < *(uint *)(unaff_EDI + 0xc))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_00852dc0(unaff_ESI,1,param_2,unaff_EDI);
        return;
      }
      FUN_00852dc0(unaff_ESI,0,param_2,unaff_EDI);
      return;
    }
    if (((uint)param_2[3] < *(uint *)(unaff_EDI + 0xc)) &&
       ((FUN_0085e240(), param_2 == *(int **)(param_1 + 4) ||
        (*(uint *)(unaff_EDI + 0xc) < (uint)param_2[3])))) {
      if (*(char *)(param_2[2] + 0x21) != '\0') {
        FUN_00852dc0(unaff_ESI,0,param_2,unaff_EDI);
        return;
      }
      goto LAB_008528d4;
    }
  }
  puVar2 = (undefined4 *)FUN_008527c0(local_c,unaff_EDI);
  *unaff_ESI = *puVar2;
  return;
}

