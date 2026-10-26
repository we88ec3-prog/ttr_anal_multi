
int FUN_008d4030(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  char *pcVar8;
  uint local_24;
  int local_1c;
  int local_14;
  uint local_10;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 100);
  local_1c = 0;
  local_14 = 0;
  local_8 = FUN_008d3f00();
  if (((local_8 == 0) && (uVar2 = FUN_008b9c70(), local_8 == 0)) && ((uVar2 & 0xffffff00) == 0)) {
    uVar2 = uVar2 >> 2 & 1;
    if (uVar2 == 0) {
      uVar3 = FUN_008b9c70();
    }
    else {
      uVar3 = FUN_008b9c00();
    }
    if (local_8 == 0) {
      if (uVar3 <= local_24 / 9) {
        *(uint *)(param_1 + 0x118) = uVar3;
        local_1c = FUN_008bc7d0(uVar1,0xc,0,uVar3,0,&local_8);
        if (local_8 != 0) goto LAB_008d42cd;
        local_10 = 0;
        iVar4 = local_8;
        if (uVar3 != 0) {
          do {
            local_8 = iVar4;
            local_8 = FUN_008bacd0();
            if (local_8 != 0) goto LAB_008d42cd;
            local_10 = local_10 + 1;
            iVar4 = 0;
          } while (local_10 < uVar3);
        }
        if (((uVar3 & 3) != 0) && (local_8 = FUN_008b9820(), local_8 != 0)) {
          local_8 = 0x53;
          goto LAB_008d42cd;
        }
        if (uVar2 == 1) {
          uVar2 = FUN_008b9c00();
        }
        else {
          uVar2 = FUN_008b9c70();
        }
        if (local_8 != 0) goto LAB_008d42cd;
        if (uVar2 <= local_24 + uVar3 * -9) {
          local_14 = FUN_008bc7d0(uVar1,1,0,uVar2 + 1,0,&local_8);
          if (((local_8 == 0) && (local_8 = FUN_008bab70(), local_8 == 0)) &&
             (iVar4 = FUN_008bc7d0(uVar1,0xc,0,uVar3,0,&local_8), local_8 == 0)) {
            uVar7 = 0;
            *(int *)(param_1 + 0x11c) = iVar4;
            if (uVar3 != 0) {
              puVar6 = (uint *)(iVar4 + 8);
              pcVar8 = (char *)(local_1c + 4);
              do {
                uVar5 = *(uint *)(pcVar8 + -4);
                if (((int)uVar5 < 0) || (uVar2 < uVar5)) {
LAB_008d42f1:
                  local_8 = 9;
                  goto LAB_008d42cd;
                }
                uVar5 = FUN_008ba000(uVar1,uVar5 + local_14,&local_8);
                puVar6[-2] = uVar5;
                if (local_8 != 0) goto LAB_008d42cd;
                pcVar8[iVar4 - local_1c] = *pcVar8;
                uVar5 = *(uint *)(pcVar8 + 4);
                if (*pcVar8 == '\0') {
                  *puVar6 = uVar5;
                }
                else {
                  if (((int)uVar5 < 0) || (uVar2 < uVar5)) goto LAB_008d42f1;
                  uVar5 = FUN_008ba000(uVar1,uVar5 + local_14,&local_8);
                  *puVar6 = uVar5;
                  if (local_8 != 0) goto LAB_008d42cd;
                }
                uVar7 = uVar7 + 1;
                pcVar8 = pcVar8 + 0xc;
                puVar6 = puVar6 + 3;
              } while (uVar7 < uVar3);
            }
            local_8 = 0;
          }
          goto LAB_008d42cd;
        }
      }
      local_8 = 8;
    }
  }
LAB_008d42cd:
  FUN_008b9f80(uVar1,local_1c);
  FUN_008b9f80(uVar1,local_14);
  return local_8;
}

