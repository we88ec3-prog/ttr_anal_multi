
undefined4 FUN_00860080(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint local_68;
  uint local_64 [12];
  undefined1 auStack_34 [48];
  
  if (in_ECX[0x1c] != 0) {
    return 0;
  }
  piVar1 = (int *)in_ECX[0x1f];
  for (piVar5 = (int *)in_ECX[0x1e]; piVar5 != piVar1; piVar5 = piVar5 + 1) {
    if (*(int *)(*piVar5 + 0xac) == 0) {
      *(int **)(*piVar5 + 0xac) = in_ECX + 0x26;
    }
    (**(code **)(*(int *)*piVar5 + 0x24))(param_1,param_2);
  }
  uVar3 = in_ECX[0x23] - in_ECX[0x22] >> 2;
  local_68 = 0;
  local_64[0] = uVar3;
  if (uVar3 != 0) {
    do {
      piVar5 = *(int **)(in_ECX[0x22] + local_68 * 4);
      uVar4 = 0;
      uVar6 = piVar5[0x37] - piVar5[0x36] >> 2;
      if (uVar6 != 0) {
        do {
          uVar2 = (**(code **)(*piVar5 + 0x24))(auStack_34,param_1);
          FUN_0077e910(local_64,uVar2);
          (**(code **)(*in_ECX + 0x24))(local_64,param_2);
          uVar4 = uVar4 + 1;
          uVar3 = local_64[0];
        } while (uVar4 < uVar6);
      }
      local_68 = local_68 + 1;
    } while (local_68 < uVar3);
  }
  return 1;
}

