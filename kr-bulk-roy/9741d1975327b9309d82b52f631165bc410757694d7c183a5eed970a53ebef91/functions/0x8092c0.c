
undefined4 FUN_008092c0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_c;
  
  uVar3 = param_1[1] - *param_1 >> 2;
  local_c = 0;
  if (uVar3 == 0) {
    return 0;
  }
  while( true ) {
    piVar1 = *(int **)(*param_1 + local_c * 4);
    uVar5 = 0;
    uVar6 = piVar1[1] - *piVar1 >> 2;
    bVar2 = false;
    if (uVar6 == 0) break;
    if (uVar6 != 0) {
      do {
        iVar4 = (**(code **)(**(int **)(*piVar1 + uVar5 * 4) + 4))(param_2);
        if (iVar4 == 0) {
          if (piVar1[8] != 0) goto LAB_0080936c;
        }
        else {
          bVar2 = true;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar6);
      if (bVar2) break;
    }
LAB_0080936c:
    local_c = local_c + 1;
    if (uVar3 <= local_c) {
      return 0;
    }
  }
  uVar5 = 0;
  uVar3 = piVar1[5] - piVar1[4] >> 2;
  if (uVar3 != 0) {
    do {
      (**(code **)(**(int **)(piVar1[4] + uVar5 * 4) + 0xc))(param_2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  return 1;
}

