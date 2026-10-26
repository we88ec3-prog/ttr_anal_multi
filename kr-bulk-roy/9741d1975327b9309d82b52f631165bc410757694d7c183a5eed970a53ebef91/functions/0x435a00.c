
void FUN_00435a00(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x138);
  do {
    if (*piVar2 == param_2) {
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x138);
  do {
    if (*piVar2 == -1) {
      *(int *)(param_1 + 0x138 + iVar1 * 4) = param_2;
      FUN_00826660(&local_c,&param_2);
      FUN_004ca160(local_c,local_8);
      *(int *)(param_1 + 0x154) = param_2;
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  return;
}

