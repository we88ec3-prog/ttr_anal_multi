
void FUN_008f5430(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = in_ECX + 0x2c + in_EAX * 0x1c;
  piVar6 = *(int **)(iVar2 + 8);
  iVar3 = *(int *)(*(int *)(in_ECX + 0x6c) + 0x28);
  iVar1 = iVar3 * 8;
  local_8 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7ffU)) >> 0xb;
  piVar9 = piVar6 + *(int *)(in_ECX + 0x2c + in_EAX * 0x1c) * 0xc;
  if (local_8 == 0) {
    local_8 = 1;
  }
  iVar3 = iVar3 * 6000;
  if (piVar6 < piVar9) {
    iVar1 = (uint)((int)piVar9 + (-1 - (int)piVar6)) / 0x30 + 1;
    piVar7 = piVar6 + 10;
    local_10 = iVar1;
    do {
      if (((int)*(char *)((int)piVar7 + -0x27) == *(int *)(iVar2 + 0x18)) && (*piVar7 != piVar7[1]))
      {
        piVar8 = piVar6 + 1;
        local_c = iVar1;
        do {
          if (((int)*(char *)((int)piVar8 + -3) + (int)*(char *)((int)piVar7 + -0x27) == 0) &&
             ((int)*(short *)((int)piVar7 + -0x26) < (int)*(short *)((int)piVar8 + -2))) {
            iVar5 = (int)(short)piVar7[-9];
            if ((int)(short)piVar7[-9] < (int)(short)*piVar8) {
              iVar5 = (int)(short)*piVar8;
            }
            iVar4 = (int)*(short *)((int)piVar7 + -0x22);
            if ((int)*(short *)((int)piVar8 + 2) < (int)*(short *)((int)piVar7 + -0x22)) {
              iVar4 = (int)*(short *)((int)piVar8 + 2);
            }
            if (local_8 <= iVar4 - iVar5) {
              iVar5 = ((int)(iVar3 + (iVar3 >> 0x1f & 0x7ffU)) >> 0xb) / (iVar4 - iVar5) +
                      ((int)*(short *)((int)piVar8 + -2) - (int)*(short *)((int)piVar7 + -0x26));
              if (iVar5 < piVar7[-2]) {
                piVar7[-2] = iVar5;
                piVar7[-5] = (int)(piVar8 + -1);
              }
              if (iVar5 < piVar8[7]) {
                piVar8[7] = iVar5;
                piVar8[4] = (int)(piVar7 + -10);
              }
            }
          }
          piVar8 = piVar8 + 0xc;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      piVar7 = piVar7 + 0xc;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    if (piVar6 < piVar9) {
      piVar6 = piVar6 + 5;
      do {
        iVar1 = *piVar6;
        if ((iVar1 != 0) && (*(int **)(iVar1 + 0x14) != piVar6 + -5)) {
          *piVar6 = 0;
          piVar6[1] = *(int *)(iVar1 + 0x14);
        }
        piVar7 = piVar6 + 7;
        piVar6 = piVar6 + 0xc;
      } while (piVar7 < piVar9);
    }
  }
  return;
}

