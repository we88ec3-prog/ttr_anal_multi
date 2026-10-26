
undefined4 FUN_004c87d0(float param_1)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  int *piVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x370) != 0) {
    if (*(int *)(in_ECX + 0x15c) != 0) {
      FUN_007a5c50(*(int *)(in_ECX + 0x15c),param_1,0);
    }
    if ((*(int *)(in_ECX + 0x364) != 0) && (*(int *)(*(int *)(in_ECX + 0x364) + 0x24) != 0)) {
      FUN_007bd8d0(param_1);
    }
    piVar3 = (int *)(in_ECX + 0x164);
    local_8 = 0x80;
    do {
      if ((*piVar3 != 0) && (*(int *)(*piVar3 + 0x24) != 0)) {
        FUN_007bd8d0(param_1);
      }
      piVar3 = piVar3 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    if ((*(int *)(in_ECX + 0x368) != 0) && (*(int *)(in_ECX + 0x370) != 0)) {
      if (*(int *)(in_ECX + 0x15c) == 0) {
        local_14 = *(undefined4 *)(in_ECX + 0xa0);
        local_10 = *(undefined4 *)(in_ECX + 0xa4);
        local_c = *(undefined4 *)(in_ECX + 0xa8);
      }
      else {
        FUN_007a8630(0);
      }
      iVar1 = *(int *)(in_ECX + 0x368);
      *(undefined4 *)(iVar1 + 0x10) = local_14;
      *(undefined4 *)(iVar1 + 0x14) = local_10;
      *(undefined4 *)(iVar1 + 0x18) = local_c;
      iVar1 = *(int *)(in_ECX + 0x368);
      fVar2 = *(float *)(iVar1 + 0x2c) + param_1;
      *(float *)(iVar1 + 0x2c) = fVar2;
      if (1.0 < fVar2) {
        *(undefined4 *)(iVar1 + 0x2c) = 0;
      }
    }
  }
  (**(code **)(**(int **)(in_ECX + 0x158) + 8))(param_1);
  return 0;
}

