
uint * FUN_00503440(int param_1,uint *param_2,int *param_3)

{
  uint **ppuVar1;
  uint **ppuVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint *puVar8;
  int local_20;
  uint local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009400c9;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  local_8 = 0;
  FUN_00404ba0(uVar3);
  iVar4 = FUN_004d43d0();
  iVar5 = *param_3;
  local_18 = 0;
  if (param_3[1] - iVar5 >> 2 != 0) {
    do {
      local_14 = *(uint **)(iVar5 + local_18 * 4);
      iVar5 = *(int *)(param_1 + 0x5eac);
      FUN_00503d20(&local_14);
      if (local_20 == *(int *)(iVar5 + 4)) {
        puVar8 = (uint *)0x0;
      }
      else {
        puVar8 = (uint *)(local_20 + 0x10);
      }
      if ((puVar8 != (uint *)0x0) && ((int)puVar8[3] <= iVar4)) {
        uVar3 = *puVar8;
        iVar5 = 0;
        puVar7 = (ushort *)(param_1 + 0x5ed0);
        do {
          if (*puVar7 == uVar3) goto LAB_0050359e;
          iVar5 = iVar5 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 < 0x14);
        puVar7 = *(ushort **)(param_1 + 0x5eb4);
        puVar6 = *(ushort **)(param_1 + 0x5eb0);
        if (puVar6 == puVar7) {
LAB_0050353c:
          if (uVar3 != 0xea61) goto LAB_0050359e;
        }
        else {
          do {
            if (*puVar6 == uVar3) break;
            puVar6 = puVar6 + 1;
          } while (puVar6 != puVar7);
          if (puVar6 == puVar7) goto LAB_0050353c;
        }
        ppuVar1 = (uint **)param_2[1];
        local_14 = puVar8;
        if (&local_14 < ppuVar1) {
          ppuVar2 = (uint **)*param_2;
          if (ppuVar2 <= &local_14) {
            if (ppuVar1 == (uint **)param_2[2]) {
              FUN_004deab0();
            }
            if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
              *(undefined4 *)param_2[1] =
                   *(undefined4 *)(*param_2 + ((int)&local_14 - (int)ppuVar2 >> 2) * 4);
            }
            param_2[1] = param_2[1] + 4;
            goto LAB_0050359e;
          }
        }
        if (ppuVar1 == (uint **)param_2[2]) {
          FUN_004deab0();
        }
        if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_2[1] = puVar8;
        }
        param_2[1] = param_2[1] + 4;
      }
LAB_0050359e:
      iVar5 = *param_3;
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(param_3[1] - iVar5 >> 2));
  }
  ExceptionList = local_10;
  return param_2;
}

