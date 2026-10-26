
void FUN_0078cf80(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar3 = param_2 + ((int)(param_3 - param_2) / 0x78) * 0x3c;
  FUN_0078f1b0(uVar3,param_3 - 0x3c,param_4);
  uVar2 = uVar3 + 0x3c;
  for (; param_2 < uVar3; uVar3 = uVar3 - 0x3c) {
    if ((*(int *)(uVar3 - 0x28) < *(int *)(uVar3 + 0x14)) ||
       (*(int *)(uVar3 + 0x14) < *(int *)(uVar3 - 0x28))) break;
  }
  local_10 = uVar2;
  local_c = uVar3;
  local_8 = uVar2;
  if (uVar2 < param_3) {
    do {
      local_10 = uVar2;
      local_8 = uVar2;
      if ((*(int *)(uVar2 + 0x14) < *(int *)(uVar3 + 0x14)) ||
         (*(int *)(uVar3 + 0x14) < *(int *)(uVar2 + 0x14))) break;
      uVar2 = uVar2 + 0x3c;
      local_10 = uVar2;
      local_8 = uVar2;
    } while (uVar2 < param_3);
  }
joined_r0x0078d016:
  do {
    if (param_3 <= uVar2) {
LAB_0078d057:
      local_10 = uVar2;
      if (param_2 < local_c) {
        puVar6 = (undefined4 *)(local_c - 0x34);
        puVar7 = (undefined4 *)(uVar3 + 8);
        do {
          puVar8 = puVar7;
          if ((int)puVar7[3] <= (int)puVar6[3]) {
            if ((int)puVar7[3] < (int)puVar6[3]) break;
            uVar3 = uVar3 - 0x3c;
            puVar8 = puVar7 + -0xf;
            FUN_007866a0();
            if (puVar7 + -0x10 != puVar6 + -1) {
              puVar7[-0xd] = puVar6[2];
              puVar7[-0x10] = puVar6[-1];
              *puVar8 = *puVar6;
              puVar7[-0xe] = puVar6[1];
            }
            puVar7[-0xc] = puVar6[3];
            puVar7[-0xb] = puVar6[4];
            if (puVar7 + -10 != puVar6 + 5) {
              puVar7[-7] = puVar6[8];
              puVar7[-10] = puVar6[5];
              puVar7[-9] = puVar6[6];
              puVar7[-8] = puVar6[7];
            }
            puVar1 = puVar6 + 9;
            if (puVar7 + -6 != puVar1) {
              puVar7[-3] = puVar6[0xc];
              puVar7[-6] = *puVar1;
              puVar7[-5] = puVar6[10];
              puVar7[-4] = puVar6[0xb];
            }
            if (puVar6 + -1 != &local_48) {
              puVar6[2] = local_3c;
              puVar6[-1] = local_48;
              *puVar6 = local_44;
              puVar6[1] = local_40;
            }
            puVar6[3] = local_38;
            puVar6[4] = local_34;
            if (puVar6 + 5 != &local_30) {
              puVar6[8] = local_24;
              puVar6[5] = local_30;
              puVar6[6] = local_2c;
              puVar6[7] = local_28;
            }
            if (puVar1 != &local_20) {
              puVar6[0xc] = local_14;
              *puVar1 = local_20;
              puVar6[10] = local_1c;
              puVar6[0xb] = local_18;
            }
          }
          local_c = local_c - 0x3c;
          puVar6 = puVar6 + -0xf;
          puVar7 = puVar8;
        } while (param_2 < local_c);
      }
      uVar5 = local_c;
      uVar2 = local_10;
      if (local_c == param_2) {
        if (local_10 == param_3) {
          *param_1 = uVar3;
          param_1[1] = local_8;
          return;
        }
        if (local_8 != local_10) {
          FUN_007866a0();
          puVar7 = (undefined4 *)(local_8 + 4);
          if ((undefined4 *)(uVar3 + 4) != puVar7) {
            *(undefined4 *)(uVar3 + 0x10) = *(undefined4 *)(local_8 + 0x10);
            *(undefined4 *)(uVar3 + 4) = *puVar7;
            *(undefined4 *)(uVar3 + 8) = *(undefined4 *)(local_8 + 8);
            *(undefined4 *)(uVar3 + 0xc) = *(undefined4 *)(local_8 + 0xc);
          }
          *(undefined4 *)(uVar3 + 0x14) = *(undefined4 *)(local_8 + 0x14);
          *(undefined4 *)(uVar3 + 0x18) = *(undefined4 *)(local_8 + 0x18);
          puVar6 = (undefined4 *)(local_8 + 0x1c);
          if ((undefined4 *)(uVar3 + 0x1c) != puVar6) {
            *(undefined4 *)(uVar3 + 0x28) = *(undefined4 *)(local_8 + 0x28);
            *(undefined4 *)(uVar3 + 0x1c) = *puVar6;
            *(undefined4 *)(uVar3 + 0x20) = *(undefined4 *)(local_8 + 0x20);
            *(undefined4 *)(uVar3 + 0x24) = *(undefined4 *)(local_8 + 0x24);
          }
          puVar8 = (undefined4 *)(local_8 + 0x2c);
          if ((undefined4 *)(uVar3 + 0x2c) != puVar8) {
            *(undefined4 *)(uVar3 + 0x38) = *(undefined4 *)(local_8 + 0x38);
            *(undefined4 *)(uVar3 + 0x2c) = *puVar8;
            *(undefined4 *)(uVar3 + 0x30) = *(undefined4 *)(local_8 + 0x30);
            *(undefined4 *)(uVar3 + 0x34) = *(undefined4 *)(local_8 + 0x34);
          }
          if (puVar7 != &local_48) {
            *(undefined4 *)(local_8 + 0x10) = local_3c;
            *puVar7 = local_48;
            *(undefined4 *)(local_8 + 8) = local_44;
            *(undefined4 *)(local_8 + 0xc) = local_40;
          }
          *(undefined4 *)(local_8 + 0x14) = local_38;
          *(undefined4 *)(local_8 + 0x18) = local_34;
          if (puVar6 != &local_30) {
            *(undefined4 *)(local_8 + 0x28) = local_24;
            *puVar6 = local_30;
            *(undefined4 *)(local_8 + 0x20) = local_2c;
            *(undefined4 *)(local_8 + 0x24) = local_28;
          }
          if (puVar8 != &local_20) {
            *(undefined4 *)(local_8 + 0x38) = local_14;
            *puVar8 = local_20;
            *(undefined4 *)(local_8 + 0x30) = local_1c;
            *(undefined4 *)(local_8 + 0x34) = local_18;
          }
        }
        uVar5 = local_10;
        local_8 = local_8 + 0x3c;
        local_10 = local_10 + 0x3c;
        uVar4 = uVar3 + 0x3c;
        FUN_007866a0();
        puVar7 = (undefined4 *)(uVar5 + 4);
        if ((undefined4 *)(uVar3 + 4) != puVar7) {
          *(undefined4 *)(uVar3 + 0x10) = *(undefined4 *)(uVar5 + 0x10);
          *(undefined4 *)(uVar3 + 4) = *puVar7;
          *(undefined4 *)(uVar3 + 8) = *(undefined4 *)(uVar5 + 8);
          *(undefined4 *)(uVar3 + 0xc) = *(undefined4 *)(uVar5 + 0xc);
        }
        *(undefined4 *)(uVar3 + 0x14) = *(undefined4 *)(uVar5 + 0x14);
        *(undefined4 *)(uVar3 + 0x18) = *(undefined4 *)(uVar5 + 0x18);
        puVar6 = (undefined4 *)(uVar5 + 0x1c);
        if ((undefined4 *)(uVar3 + 0x1c) != puVar6) {
          *(undefined4 *)(uVar3 + 0x28) = *(undefined4 *)(uVar5 + 0x28);
          *(undefined4 *)(uVar3 + 0x1c) = *puVar6;
          *(undefined4 *)(uVar3 + 0x20) = *(undefined4 *)(uVar5 + 0x20);
          *(undefined4 *)(uVar3 + 0x24) = *(undefined4 *)(uVar5 + 0x24);
        }
        puVar8 = (undefined4 *)(uVar5 + 0x2c);
        if ((undefined4 *)(uVar3 + 0x2c) != puVar8) {
          *(undefined4 *)(uVar3 + 0x38) = *(undefined4 *)(uVar5 + 0x38);
          *(undefined4 *)(uVar3 + 0x2c) = *puVar8;
          *(undefined4 *)(uVar3 + 0x30) = *(undefined4 *)(uVar5 + 0x30);
          *(undefined4 *)(uVar3 + 0x34) = *(undefined4 *)(uVar5 + 0x34);
        }
        if (puVar7 != &local_48) {
          *(undefined4 *)(uVar5 + 0x10) = local_3c;
          *puVar7 = local_48;
          *(undefined4 *)(uVar5 + 8) = local_44;
          *(undefined4 *)(uVar5 + 0xc) = local_40;
        }
        *(undefined4 *)(uVar5 + 0x14) = local_38;
        *(undefined4 *)(uVar5 + 0x18) = local_34;
        if (puVar6 != &local_30) {
          *(undefined4 *)(uVar5 + 0x28) = local_24;
          *puVar6 = local_30;
          *(undefined4 *)(uVar5 + 0x20) = local_2c;
          *(undefined4 *)(uVar5 + 0x24) = local_28;
        }
        uVar2 = local_10;
        uVar3 = uVar4;
        if (puVar8 != &local_20) {
          *(undefined4 *)(uVar5 + 0x38) = local_14;
          *puVar8 = local_20;
          *(undefined4 *)(uVar5 + 0x30) = local_1c;
          *(undefined4 *)(uVar5 + 0x34) = local_18;
        }
      }
      else if (local_10 == param_3) {
        local_c = local_c - 0x3c;
        uVar5 = uVar3 - 0x3c;
        if (local_c != uVar5) {
          FUN_007866a0();
          FUN_00789f20();
          if ((undefined4 *)(uVar3 - 0x38) != &local_48) {
            *(undefined4 *)(uVar3 - 0x2c) = local_3c;
            *(undefined4 *)(uVar3 - 0x38) = local_48;
            *(undefined4 *)(uVar3 - 0x34) = local_44;
            *(undefined4 *)(uVar3 - 0x30) = local_40;
          }
          *(undefined4 *)(uVar3 - 0x28) = local_38;
          *(undefined4 *)(uVar3 - 0x24) = local_34;
          if ((undefined4 *)(uVar3 - 0x20) != &local_30) {
            *(undefined4 *)(uVar3 - 0x14) = local_24;
            *(undefined4 *)(uVar3 - 0x20) = local_30;
            *(undefined4 *)(uVar3 - 0x1c) = local_2c;
            *(undefined4 *)(uVar3 - 0x18) = local_28;
          }
          if ((undefined4 *)(uVar3 - 0x10) != &local_20) {
            *(undefined4 *)(uVar3 - 4) = local_14;
            *(undefined4 *)(uVar3 - 0x10) = local_20;
            *(undefined4 *)(uVar3 - 0xc) = local_1c;
            *(undefined4 *)(uVar3 - 8) = local_18;
          }
        }
        uVar4 = local_8;
        local_8 = local_8 - 0x3c;
        FUN_007866a0();
        puVar7 = (undefined4 *)(uVar4 - 0x38);
        if ((undefined4 *)(uVar3 - 0x38) != puVar7) {
          *(undefined4 *)(uVar3 - 0x2c) = *(undefined4 *)(uVar4 - 0x2c);
          *(undefined4 *)(uVar3 - 0x38) = *puVar7;
          *(undefined4 *)(uVar3 - 0x34) = *(undefined4 *)(uVar4 - 0x34);
          *(undefined4 *)(uVar3 - 0x30) = *(undefined4 *)(uVar4 - 0x30);
        }
        *(undefined4 *)(uVar3 - 0x28) = *(undefined4 *)(uVar4 - 0x28);
        *(undefined4 *)(uVar3 - 0x24) = *(undefined4 *)(uVar4 - 0x24);
        puVar6 = (undefined4 *)(uVar4 - 0x20);
        if ((undefined4 *)(uVar3 - 0x20) != puVar6) {
          *(undefined4 *)(uVar3 - 0x14) = *(undefined4 *)(uVar4 - 0x14);
          *(undefined4 *)(uVar3 - 0x20) = *puVar6;
          *(undefined4 *)(uVar3 - 0x1c) = *(undefined4 *)(uVar4 - 0x1c);
          *(undefined4 *)(uVar3 - 0x18) = *(undefined4 *)(uVar4 - 0x18);
        }
        puVar8 = (undefined4 *)(uVar4 - 0x10);
        if ((undefined4 *)(uVar3 - 0x10) != puVar8) {
          *(undefined4 *)(uVar3 - 4) = *(undefined4 *)(uVar4 - 4);
          *(undefined4 *)(uVar3 - 0x10) = *puVar8;
          *(undefined4 *)(uVar3 - 0xc) = *(undefined4 *)(uVar4 - 0xc);
          *(undefined4 *)(uVar3 - 8) = *(undefined4 *)(uVar4 - 8);
        }
        if (puVar7 != &local_48) {
          *(undefined4 *)(uVar4 - 0x2c) = local_3c;
          *puVar7 = local_48;
          *(undefined4 *)(uVar4 - 0x34) = local_44;
          *(undefined4 *)(uVar4 - 0x30) = local_40;
        }
        *(undefined4 *)(uVar4 - 0x28) = local_38;
        *(undefined4 *)(uVar4 - 0x24) = local_34;
        if (puVar6 != &local_30) {
          *(undefined4 *)(uVar4 - 0x14) = local_24;
          *puVar6 = local_30;
          *(undefined4 *)(uVar4 - 0x1c) = local_2c;
          *(undefined4 *)(uVar4 - 0x18) = local_28;
        }
        uVar2 = local_10;
        uVar3 = uVar5;
        if (puVar8 != &local_20) {
          *(undefined4 *)(uVar4 - 4) = local_14;
          *puVar8 = local_20;
          *(undefined4 *)(uVar4 - 0xc) = local_1c;
          *(undefined4 *)(uVar4 - 8) = local_18;
        }
      }
      else {
        local_c = local_c - 0x3c;
        FUN_007866a0();
        puVar7 = (undefined4 *)(uVar5 - 0x38);
        if ((undefined4 *)(uVar2 + 4) != puVar7) {
          *(undefined4 *)(uVar2 + 0x10) = *(undefined4 *)(uVar5 - 0x2c);
          *(undefined4 *)(uVar2 + 4) = *puVar7;
          *(undefined4 *)(uVar2 + 8) = *(undefined4 *)(uVar5 - 0x34);
          *(undefined4 *)(uVar2 + 0xc) = *(undefined4 *)(uVar5 - 0x30);
        }
        *(undefined4 *)(uVar2 + 0x14) = *(undefined4 *)(uVar5 - 0x28);
        *(undefined4 *)(uVar2 + 0x18) = *(undefined4 *)(uVar5 - 0x24);
        puVar6 = (undefined4 *)(uVar5 - 0x20);
        if ((undefined4 *)(uVar2 + 0x1c) != puVar6) {
          *(undefined4 *)(uVar2 + 0x28) = *(undefined4 *)(uVar5 - 0x14);
          *(undefined4 *)(uVar2 + 0x1c) = *puVar6;
          *(undefined4 *)(uVar2 + 0x20) = *(undefined4 *)(uVar5 - 0x1c);
          *(undefined4 *)(uVar2 + 0x24) = *(undefined4 *)(uVar5 - 0x18);
        }
        puVar8 = (undefined4 *)(uVar5 - 0x10);
        if ((undefined4 *)(uVar2 + 0x2c) != puVar8) {
          *(undefined4 *)(uVar2 + 0x38) = *(undefined4 *)(uVar5 - 4);
          *(undefined4 *)(uVar2 + 0x2c) = *puVar8;
          *(undefined4 *)(uVar2 + 0x30) = *(undefined4 *)(uVar5 - 0xc);
          *(undefined4 *)(uVar2 + 0x34) = *(undefined4 *)(uVar5 - 8);
        }
        if (puVar7 != &local_48) {
          *(undefined4 *)(uVar5 - 0x2c) = local_3c;
          *puVar7 = local_48;
          *(undefined4 *)(uVar5 - 0x34) = local_44;
          *(undefined4 *)(uVar5 - 0x30) = local_40;
        }
        *(undefined4 *)(uVar5 - 0x28) = local_38;
        *(undefined4 *)(uVar5 - 0x24) = local_34;
        if (puVar6 != &local_30) {
          *(undefined4 *)(uVar5 - 0x14) = local_24;
          *puVar6 = local_30;
          *(undefined4 *)(uVar5 - 0x1c) = local_2c;
          *(undefined4 *)(uVar5 - 0x18) = local_28;
        }
        if (puVar8 != &local_20) {
          *(undefined4 *)(uVar5 - 4) = local_14;
          *puVar8 = local_20;
          *(undefined4 *)(uVar5 - 0xc) = local_1c;
          *(undefined4 *)(uVar5 - 8) = local_18;
        }
        uVar2 = uVar2 + 0x3c;
        local_10 = uVar2;
      }
      goto joined_r0x0078d016;
    }
    if (*(int *)(uVar2 + 0x14) <= *(int *)(uVar3 + 0x14)) {
      if (*(int *)(uVar2 + 0x14) < *(int *)(uVar3 + 0x14)) goto LAB_0078d057;
      local_8 = local_8 + 0x3c;
      FUN_007866a0();
      FUN_00789f20();
      FUN_00789f20();
    }
    uVar2 = uVar2 + 0x3c;
  } while( true );
}

