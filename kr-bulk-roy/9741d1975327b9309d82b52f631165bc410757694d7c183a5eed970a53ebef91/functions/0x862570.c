
/* WARNING: Removing unreachable block (ram,0x008627be) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_00862570(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  size_t *psVar7;
  int *piVar8;
  int local_4c;
  int *local_34;
  int iStack_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00904ca8;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  if (param_1 != 0) {
    piVar8 = *(int **)(in_ECX + 0x48);
    iVar6 = *(int *)(in_ECX + 0x40);
    iVar1 = (*(int *)(in_ECX + 0x4c) - (int)piVar8) / 0x18;
    if ((*(int *)(in_ECX + 0x44) != 0) && (iVar6 != 0)) {
      local_34 = (int *)0x0;
      local_c = 0;
      ExceptionList = &local_14;
      FUN_00531860(*(undefined4 *)(iVar6 + 8));
      piVar2 = *(int **)(iVar6 + 4);
      piVar3 = (int *)*piVar2;
      while (piVar3 != piVar2) {
        iVar6 = piVar3[3];
        local_28 = iVar6;
        local_24 = FUN_00857b00(iVar6,piVar3[5]);
        switch(piVar3[4]) {
        case 0:
        case 4:
        case 5:
        case 6:
          local_20 = 4;
          break;
        case 1:
        case 7:
          local_20 = 8;
          break;
        case 2:
          local_20 = 0xc;
          break;
        case 3:
          local_20 = 0x10;
          break;
        default:
          local_20 = 0;
        }
        local_1c = piVar3[7];
        if ((param_2 != (int *)0x0) &&
           (((((iVar5 = *param_2, iVar5 != 0 && (iVar6 == 0)) ||
              ((iVar5 = param_2[1], iVar5 != 0 && (iVar6 == 3)))) ||
             ((iVar5 = param_2[3], iVar5 != 0 && (iVar6 == 6)))) ||
            ((iVar5 = param_2[2], iVar5 != 0 && (iVar6 == 7)))))) {
          local_1c = iVar5;
        }
        if (&local_28 < local_34) {
          if (local_34 == (int *)0x0) {
            FUN_007eee80(uVar4);
          }
          else {
            *local_34 = 0;
            local_34[1] = iStack_2c;
            local_34[2] = local_28;
            local_34[3] = local_24;
          }
        }
        else if (local_34 == (int *)0x0) {
          FUN_007eee80(uVar4);
        }
        else {
          *local_34 = iVar6;
          local_34[1] = local_24;
          local_34[2] = local_20;
          local_34[3] = local_1c;
        }
        local_34 = local_34 + 4;
        FUN_0085e240();
      }
      iVar6 = 0;
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        if ((int)local_34 >> 4 != 0) {
          psVar7 = (size_t *)0x8;
          local_4c = (int)local_34 >> 4;
          do {
            if ((piVar8[1] - *piVar8 & 0xfffffffcU) != 0) {
              FID_conflict__memcpy
                        ((void *)(iVar6 + param_1),
                         (void *)(*(int *)(*piVar8 + psVar7[-1] * 4) * *psVar7 + psVar7[1]),*psVar7)
              ;
            }
            iVar6 = iVar6 + *psVar7;
            psVar7 = psVar7 + 4;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
        piVar8 = piVar8 + 6;
      }
      ExceptionList = local_14;
      return 1;
    }
  }
  return 0;
}

