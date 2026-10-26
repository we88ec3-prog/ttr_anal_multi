
void FUN_006b8df0(int param_1)

{
  code *pcVar1;
  int in_EAX;
  int iVar2;
  
  pcVar1 = *(code **)(**(int **)(param_1 + 0x88) + 0x94);
  if (in_EAX - 1U < 3) {
    (*pcVar1)(0);
    (**(code **)(**(int **)(param_1 + 0x8c) + 0x94))(1);
    iVar2 = *(int *)(param_1 + 0x8c);
    if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
       (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(**(int **)(param_1 + 0x8c) + 200))();
    return;
  }
  (*pcVar1)(in_EAX == 0);
  (**(code **)(**(int **)(param_1 + 0x8c) + 0x94))(0);
  return;
}

