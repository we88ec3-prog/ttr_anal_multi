
void FUN_00517830(int param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00517f40(unaff_ESI,1,in_EAX);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) {
      FUN_00517f40(unaff_ESI,1,in_EAX);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(byte *)(piVar1[2] + 0xc) < *(byte *)(in_EAX + 0xc)) {
      FUN_00517f40(unaff_ESI,0,in_EAX);
      return;
    }
  }
  else {
    if ((*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) &&
       (FUN_008377c0(), *(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_00517f40(unaff_ESI,1,in_EAX);
        return;
      }
      FUN_00517f40(unaff_ESI,0,in_EAX);
      return;
    }
    if ((*(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc)) &&
       ((FUN_0085e240(), param_2 == *(int **)(param_1 + 4) ||
        (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3))))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_00517f40(unaff_ESI,1,in_EAX);
        return;
      }
      FUN_00517f40(unaff_ESI,0,in_EAX);
      return;
    }
  }
  puVar2 = (undefined4 *)FUN_00517e80(param_1,local_c);
  *unaff_ESI = *puVar2;
  return;
}

