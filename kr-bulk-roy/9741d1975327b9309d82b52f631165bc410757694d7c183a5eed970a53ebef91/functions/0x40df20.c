
void FUN_0040df20(int param_1)

{
  char in_AL;
  undefined4 uVar1;
  char in_CL;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (in_AL == '\0') {
    if (in_CL == '\0') {
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
    *(char *)(param_1 + 0xb4) = in_CL;
  }
  else {
    if (*(char *)(param_1 + 0xb5) == '\0') {
      *(char *)(param_1 + 0xb5) = in_AL;
      FUN_0040f230();
      piVar2 = *(int **)(param_1 + 0x9c);
    }
    else {
      *(char *)(param_1 + 0xb6) = in_AL;
      FUN_0040f230();
      piVar2 = *(int **)(param_1 + 0xa0);
    }
    (**(code **)(*piVar2 + 0x90))(0);
  }
  iVar3 = 0;
  puVar4 = (undefined4 *)(param_1 + 0xa4);
  do {
    if ((*(char *)(param_1 + 0xb4) == '\0') && (*(char *)(iVar3 + 0xb5 + param_1) == '\0')) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    (**(code **)(*(int *)*puVar4 + 0x94))(uVar1);
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 < 2);
  return;
}

