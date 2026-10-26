
void FUN_00687e60(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_38;
  undefined2 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  piVar1 = *(int **)(in_EAX + 0x148);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
    local_8 = (float)piVar1[0x20];
    if (local_8 <= 0.0) {
      (**(code **)(*piVar1 + 0x94))(0);
    }
    else {
      local_8 = local_8 - 0.011666667;
      if (local_8 <= 0.0) {
        local_8 = 0.0;
      }
      (**(code **)(*piVar1 + 0xd8))(local_8);
      (**(code **)(**(int **)(in_EAX + 0x148) + 200))();
    }
  }
  if (*(int *)(*(int *)(in_EAX + 300) + 0x250) == -1) {
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_24 = 0;
    puVar3 = &local_38;
    puVar4 = (undefined4 *)(in_EAX + 0xfc);
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}

