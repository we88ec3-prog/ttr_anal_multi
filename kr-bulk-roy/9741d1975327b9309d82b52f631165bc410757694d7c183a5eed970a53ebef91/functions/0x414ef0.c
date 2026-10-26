
void FUN_00414ef0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  *(int *)(param_1 + 0x1a0) = in_EAX;
  if (in_EAX != -1) {
    uVar2 = 0;
    puVar3 = (undefined4 *)(param_1 + 0x9c);
    do {
      iVar1 = *(int *)(param_1 + 0x1a0) + 0xe;
      if (uVar2 < (uint)(*(int *)(param_1 + 4 + iVar1 * 0x10) - *(int *)(param_1 + iVar1 * 0x10) >>
                        2)) {
        FUN_00757710();
        (**(code **)(*(int *)*puVar3 + 200))();
        (**(code **)(*(int *)*puVar3 + 0x94))(1);
      }
      else {
        (**(code **)(*(int *)*puVar3 + 0x94))(0);
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while ((int)uVar2 < 6);
  }
  *(int *)(param_1 + 0x1a4) = param_2;
  (**(code **)(**(int **)(param_1 + 0x9c + param_2 * 4) + 0xa0))(1);
  return;
}

