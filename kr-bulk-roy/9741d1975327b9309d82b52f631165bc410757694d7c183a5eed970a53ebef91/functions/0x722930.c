
/* WARNING: Removing unreachable block (ram,0x00722a76) */

void FUN_00722930(uint *param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint *in_EAX;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  char cVar9;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint *local_8;
  
  local_8 = in_EAX + 2;
  local_c = in_EAX;
  do {
    if (local_8 == param_1) {
      return;
    }
    puVar4 = (uint *)local_8[1];
    puVar5 = local_8;
    if (puVar4 != (uint *)0x0) {
      local_10 = 0;
      puVar5 = &local_10;
    }
    pbVar1 = (byte *)*puVar5;
    if (pbVar1 == (byte *)0x0) {
      if (puVar4 == (uint *)0x0) goto LAB_007229a4;
      if ((*puVar4 & 0x10) == 0) {
        uVar8 = puVar4[1];
      }
      else {
        if ((*puVar4 & 8) != 0) goto LAB_007229a4;
        uVar8 = puVar4[2];
      }
    }
    else {
      uVar8 = *(uint *)(pbVar1 + 8);
      if (((uVar8 != 0) && ((*pbVar1 & 0x10) == 0)) ||
         ((uVar8 = *(uint *)(pbVar1 + 0xc), uVar8 != 0 && ((*pbVar1 & 8) == 0)))) goto LAB_007229a6;
LAB_007229a4:
      uVar8 = 0;
    }
LAB_007229a6:
    puVar5 = (uint *)local_c[1];
    puVar7 = local_c;
    if (puVar5 != (uint *)0x0) {
      local_14 = 0;
      puVar7 = &local_14;
    }
    pbVar1 = (byte *)*puVar7;
    if (pbVar1 == (byte *)0x0) {
      if (puVar5 == (uint *)0x0) goto LAB_007229d6;
      if ((*puVar5 & 0x10) == 0) {
        uVar6 = puVar5[1];
      }
      else {
        if ((*puVar5 & 8) != 0) goto LAB_007229d6;
        uVar6 = puVar5[2];
      }
    }
    else {
      uVar6 = *(uint *)(pbVar1 + 8);
      if (((uVar6 != 0) && ((*pbVar1 & 0x10) == 0)) ||
         ((uVar6 = *(uint *)(pbVar1 + 0xc), uVar6 != 0 && ((*pbVar1 & 8) == 0)))) goto LAB_007229d8;
LAB_007229d6:
      uVar6 = 0;
    }
LAB_007229d8:
    if ((uVar8 == 0) || (uVar6 == 0)) {
      puVar7 = local_8;
      if (puVar4 != (uint *)0x0) {
        local_18 = 0;
        puVar7 = &local_18;
      }
      uVar8 = *puVar7;
      puVar7 = local_c;
      if (puVar5 != (uint *)0x0) {
        local_1c = 0;
        puVar7 = &local_1c;
      }
      uVar6 = *puVar7;
      if (puVar4 == (uint *)0x0) {
LAB_00722a90:
        if (puVar5 != (uint *)0x0) {
          if (*local_c != *local_8) {
            uVar6 = *local_c;
            goto LAB_00722aa2;
          }
          goto LAB_00722b01;
        }
LAB_00722aa2:
        uVar3 = uVar8;
        if (uVar8 != uVar6) {
          while (uVar2 = uVar6, uVar3 != 0) {
            if (uVar3 == 0) {
              local_30 = 0;
              puVar4 = &local_30;
            }
            else {
              local_2c[0] = *(uint *)(uVar3 + 4);
              puVar4 = local_2c;
            }
            uVar3 = *puVar4;
          }
          while (uVar2 != 0) {
            if (uVar2 == 0) {
              local_38 = 0;
              puVar4 = &local_38;
            }
            else {
              local_34 = *(uint *)(uVar2 + 4);
              puVar4 = &local_34;
            }
            uVar2 = *puVar4;
          }
          cVar9 = FUN_0071c320(uVar8,uVar6);
          goto LAB_00722afa;
        }
      }
      else if (puVar5 == (uint *)0x0) {
        if (puVar4 == (uint *)0x0) goto LAB_00722a90;
        if (*local_8 != *local_c) {
          uVar8 = *local_8;
          goto LAB_00722aa2;
        }
      }
      else {
        uVar6 = *local_c;
        if (*local_8 != uVar6) {
          uVar8 = *local_8;
          goto LAB_00722aa2;
        }
        do {
          if (puVar4 == puVar5) goto LAB_00722b01;
          if (puVar4 == (uint *)0x0) {
            local_24 = 0;
            puVar4 = &local_24;
          }
          else {
            local_20 = puVar4[4];
            puVar4 = &local_20;
          }
          puVar4 = (uint *)*puVar4;
        } while (puVar4 != (uint *)0x0);
      }
    }
    else {
      cVar9 = uVar8 < uVar6;
LAB_00722afa:
      if (cVar9 != '\0') {
LAB_00722b01:
        local_c = local_8;
      }
    }
    local_8 = local_8 + 2;
  } while( true );
}

