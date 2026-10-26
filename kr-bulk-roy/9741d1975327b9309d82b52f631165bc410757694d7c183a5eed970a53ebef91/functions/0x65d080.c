
void FUN_0065d080(int *param_1,int param_2,int param_3,int param_4)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  
  if (((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    uVar1 = 1;
  }
  (**(code **)(*param_1 + 0x94))(uVar1);
  iVar2 = param_1[0x20];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  iVar2 = param_1[0x21];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  (**(code **)(*(int *)param_1[0x20] + 200))();
  (**(code **)(*(int *)param_1[0x21] + 200))();
  iVar2 = param_1[0x22];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  iVar2 = param_1[0x23];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  (**(code **)(*(int *)param_1[0x22] + 200))();
  (**(code **)(*(int *)param_1[0x23] + 200))();
  iVar2 = param_1[0x24];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  iVar2 = param_1[0x25];
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      FUN_0077b200();
    }
  }
  (**(code **)(*(int *)param_1[0x24] + 200))();
  (**(code **)(*(int *)param_1[0x25] + 200))();
  return;
}

