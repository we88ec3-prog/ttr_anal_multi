
void FUN_00641d90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x138);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0x138) + 200))();
  return;
}

