
int FUN_008b9060(short *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int *local_c;
  byte *local_8;
  
  iVar5 = 0;
  if ((param_1 == (short *)0x0) || (param_2 == (undefined4 *)0x0)) {
    return 6;
  }
  iVar1 = param_2[5];
  uVar2 = param_2[4];
  local_14 = 0;
  if (*param_1 < 1) {
    return 0;
  }
  do {
    local_10 = (int)*(short *)(*(int *)(param_1 + 6) + local_14 * 2);
    if (local_10 < 0) {
      return 0x14;
    }
    iVar3 = *(int *)(param_1 + 2);
    local_c = (int *)(iVar3 + local_10 * 8);
    bVar4 = (byte)uVar2;
    local_24 = (*(int *)(iVar3 + 4 + iVar5 * 8) << (bVar4 & 0x1f)) - iVar1;
    local_28 = (*(int *)(iVar3 + iVar5 * 8) << (bVar4 & 0x1f)) - iVar1;
    local_30 = (*(int *)(*(int *)(param_1 + 2) + local_10 * 8) << (bVar4 & 0x1f)) - iVar1;
    local_2c = (*(int *)(*(int *)(param_1 + 2) + 4 + local_10 * 8) << (bVar4 & 0x1f)) - iVar1;
    local_8 = (byte *)(*(int *)(param_1 + 4) + iVar5);
    piVar6 = (int *)(*(int *)(param_1 + 2) + iVar5 * 8);
    if ((*local_8 & 3) == 2) {
      return 0x14;
    }
    local_20 = local_28;
    local_1c = local_24;
    if ((*local_8 & 3) == 0) {
      if ((*(byte *)(*(int *)(param_1 + 4) + local_10) & 3) == 1) {
        local_c = local_c + -2;
        local_1c = local_2c;
        local_20 = local_30;
      }
      else {
        local_20 = (local_28 + local_30) / 2;
        local_1c = (local_2c + local_24) / 2;
      }
      piVar6 = piVar6 + -2;
      local_8 = local_8 + -1;
    }
    iVar5 = (*(code *)*param_2)(&local_20,param_3);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (piVar6 < local_c) {
      do {
        piVar7 = piVar6 + 2;
        if ((local_8[1] & 3) == 0) {
          local_28 = (*piVar7 << (bVar4 & 0x1f)) - iVar1;
          local_24 = (piVar6[3] << (bVar4 & 0x1f)) - iVar1;
          local_8 = local_8 + 1;
          while( true ) {
            if (local_c <= piVar7) {
              iVar5 = (*(code *)param_2[2])(&local_28,&local_20,param_3);
              goto LAB_008b91a0;
            }
            piVar6 = piVar7 + 3;
            local_8 = local_8 + 1;
            local_18 = (int)(char)*local_8 & 3;
            piVar7 = piVar7 + 2;
            local_38 = (*piVar7 << (bVar4 & 0x1f)) - iVar1;
            local_34 = (*piVar6 << (bVar4 & 0x1f)) - iVar1;
            if (local_18 == 1) break;
            if (local_18 != 0) {
              return 0x14;
            }
            local_60 = (local_38 + local_28) / 2;
            local_5c = (local_34 + local_24) / 2;
            iVar5 = (*(code *)param_2[2])(&local_28,&local_60,param_3);
            if (iVar5 != 0) {
              return iVar5;
            }
            local_28 = local_38;
            local_24 = local_34;
          }
          iVar5 = (*(code *)param_2[2])(&local_28,&local_38,param_3);
        }
        else if ((local_8[1] & 3) == 1) {
          local_58 = (*piVar7 << (bVar4 & 0x1f)) - iVar1;
          local_54 = (piVar6[3] << (bVar4 & 0x1f)) - iVar1;
          local_8 = local_8 + 1;
          iVar5 = (*(code *)param_2[1])(&local_58,param_3);
        }
        else {
          if (local_c < piVar6 + 4) {
            return 0x14;
          }
          if ((local_8[2] & 3) != 2) {
            return 0x14;
          }
          local_8 = local_8 + 3;
          iVar5 = *piVar7;
          piVar7 = piVar6 + 6;
          local_48 = (iVar5 << (bVar4 & 0x1f)) - iVar1;
          local_44 = (piVar6[3] << (bVar4 & 0x1f)) - iVar1;
          local_40 = (piVar6[4] << (bVar4 & 0x1f)) - iVar1;
          local_3c = (piVar6[5] << (bVar4 & 0x1f)) - iVar1;
          if (local_c < piVar7) {
            iVar5 = (*(code *)param_2[3])(&local_48,&local_40,&local_20,param_3);
            goto LAB_008b91a0;
          }
          local_50 = (*piVar7 << (bVar4 & 0x1f)) - iVar1;
          local_4c = (piVar6[7] << (bVar4 & 0x1f)) - iVar1;
          iVar5 = (*(code *)param_2[3])(&local_48,&local_40,&local_50,param_3);
        }
        if (iVar5 != 0) {
          return iVar5;
        }
        piVar6 = piVar7;
      } while (piVar7 < local_c);
    }
    iVar5 = (*(code *)param_2[1])(&local_20,param_3);
LAB_008b91a0:
    if (iVar5 != 0) {
      return iVar5;
    }
    local_14 = local_14 + 1;
    iVar5 = local_10 + 1;
    if (*param_1 <= local_14) {
      return 0;
    }
  } while( true );
}

