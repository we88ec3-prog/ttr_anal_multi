
void FUN_007893d0(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint local_c;
  
  local_c = ((int)(param_3 - param_2) / 0xc0) * 0x60 + param_2;
  FUN_00789f90(param_2,local_c,param_3 - 0x60,param_4);
  uVar8 = local_c + 0x60;
  for (; param_2 < local_c; local_c = local_c - 0x60) {
    if ((*(int *)(local_c - 0x4c) < *(int *)(local_c + 0x14)) ||
       (*(int *)(local_c + 0x14) < *(int *)(local_c - 0x4c))) break;
  }
  uVar5 = uVar8;
  uVar7 = local_c;
  if (uVar8 < param_3) {
    do {
      uVar5 = uVar8;
      if ((*(int *)(uVar8 + 0x14) < *(int *)(local_c + 0x14)) ||
         (*(int *)(local_c + 0x14) < *(int *)(uVar8 + 0x14))) break;
      uVar8 = uVar8 + 0x60;
      uVar5 = uVar8;
    } while (uVar8 < param_3);
  }
joined_r0x0078945a:
  do {
    if (param_3 <= uVar5) {
LAB_0078948e:
      if (param_2 < local_c) {
        puVar9 = (undefined4 *)(local_c - 0xc);
        uVar6 = uVar7;
        do {
          uVar7 = uVar6;
          if (*(int *)(uVar6 + 0x14) <= (int)puVar9[-0x10]) {
            if (*(int *)(uVar6 + 0x14) < (int)puVar9[-0x10]) break;
            uVar7 = uVar6 - 0x60;
            FUN_007852a0();
            uVar1 = *(undefined4 *)(uVar6 - 0x10);
            uVar2 = *(undefined4 *)(uVar6 - 8);
            uVar3 = *(undefined4 *)(uVar6 - 4);
            uVar4 = *(undefined4 *)(uVar6 - 0xc);
            FUN_00788f50();
            *(undefined4 *)(uVar6 - 0x10) = puVar9[-1];
            *(undefined4 *)(uVar6 - 0xc) = *puVar9;
            *(undefined4 *)(uVar6 - 8) = puVar9[1];
            *(undefined4 *)(uVar6 - 4) = puVar9[2];
            FUN_00788f50();
            puVar9[-1] = uVar1;
            *puVar9 = uVar4;
            puVar9[1] = uVar2;
            puVar9[2] = uVar3;
          }
          local_c = local_c - 0x60;
          puVar9 = puVar9 + -0x18;
          uVar6 = uVar7;
        } while (param_2 < local_c);
      }
      if (local_c == param_2) {
        if (uVar5 == param_3) {
          param_1[1] = uVar8;
          *param_1 = uVar7;
          return;
        }
        if (uVar8 != uVar5) {
          FUN_007852a0();
          uVar1 = *(undefined4 *)(uVar7 + 0x50);
          uVar2 = *(undefined4 *)(uVar7 + 0x58);
          uVar3 = *(undefined4 *)(uVar7 + 0x5c);
          uVar4 = *(undefined4 *)(uVar7 + 0x54);
          FUN_00788f50();
          *(undefined4 *)(uVar7 + 0x50) = *(undefined4 *)(uVar8 + 0x50);
          *(undefined4 *)(uVar7 + 0x54) = *(undefined4 *)(uVar8 + 0x54);
          *(undefined4 *)(uVar7 + 0x58) = *(undefined4 *)(uVar8 + 0x58);
          *(undefined4 *)(uVar7 + 0x5c) = *(undefined4 *)(uVar8 + 0x5c);
          FUN_00788f50();
          *(undefined4 *)(uVar8 + 0x50) = uVar1;
          *(undefined4 *)(uVar8 + 0x54) = uVar4;
          *(undefined4 *)(uVar8 + 0x58) = uVar2;
          *(undefined4 *)(uVar8 + 0x5c) = uVar3;
        }
        FUN_007852a0();
        uVar2 = *(undefined4 *)(uVar7 + 0x54);
        uVar1 = *(undefined4 *)(uVar7 + 0x50);
        uVar3 = *(undefined4 *)(uVar7 + 0x58);
        uVar4 = *(undefined4 *)(uVar7 + 0x5c);
        FUN_00788f50();
        *(undefined4 *)(uVar7 + 0x50) = *(undefined4 *)(uVar5 + 0x50);
        *(undefined4 *)(uVar7 + 0x54) = *(undefined4 *)(uVar5 + 0x54);
        *(undefined4 *)(uVar7 + 0x58) = *(undefined4 *)(uVar5 + 0x58);
        *(undefined4 *)(uVar7 + 0x5c) = *(undefined4 *)(uVar5 + 0x5c);
        FUN_00788f50();
        *(undefined4 *)(uVar5 + 0x50) = uVar1;
        *(undefined4 *)(uVar5 + 0x54) = uVar2;
        *(undefined4 *)(uVar5 + 0x58) = uVar3;
        *(undefined4 *)(uVar5 + 0x5c) = uVar4;
        uVar8 = uVar8 + 0x60;
        uVar5 = uVar5 + 0x60;
        uVar7 = uVar7 + 0x60;
      }
      else {
        uVar6 = local_c - 0x60;
        if (uVar5 == param_3) {
          if (uVar6 != uVar7 - 0x60) {
            FUN_007852a0();
            uVar2 = *(undefined4 *)(local_c - 8);
            uVar1 = *(undefined4 *)(local_c - 0x10);
            uVar3 = *(undefined4 *)(local_c - 4);
            uVar4 = *(undefined4 *)(local_c - 0xc);
            FUN_00788f50();
            *(undefined4 *)(local_c - 0x10) = *(undefined4 *)(uVar7 - 0x10);
            *(undefined4 *)(local_c - 0xc) = *(undefined4 *)(uVar7 - 0xc);
            *(undefined4 *)(local_c - 8) = *(undefined4 *)(uVar7 - 8);
            *(undefined4 *)(local_c - 4) = *(undefined4 *)(uVar7 - 4);
            FUN_00788f50();
            *(undefined4 *)(uVar7 - 0x10) = uVar1;
            *(undefined4 *)(uVar7 - 0xc) = uVar4;
            *(undefined4 *)(uVar7 - 8) = uVar2;
            *(undefined4 *)(uVar7 - 4) = uVar3;
          }
          FUN_007852a0();
          uVar1 = *(undefined4 *)(uVar7 - 0x10);
          uVar2 = *(undefined4 *)(uVar7 - 8);
          uVar3 = *(undefined4 *)(uVar7 - 4);
          uVar4 = *(undefined4 *)(uVar7 - 0xc);
          FUN_00788f50();
          *(undefined4 *)(uVar7 - 0x10) = *(undefined4 *)(uVar8 - 0x10);
          *(undefined4 *)(uVar7 - 0xc) = *(undefined4 *)(uVar8 - 0xc);
          *(undefined4 *)(uVar7 - 8) = *(undefined4 *)(uVar8 - 8);
          *(undefined4 *)(uVar7 - 4) = *(undefined4 *)(uVar8 - 4);
          FUN_00788f50();
          *(undefined4 *)(uVar8 - 0x10) = uVar1;
          *(undefined4 *)(uVar8 - 0xc) = uVar4;
          *(undefined4 *)(uVar8 - 8) = uVar2;
          *(undefined4 *)(uVar8 - 4) = uVar3;
          uVar8 = uVar8 - 0x60;
          local_c = uVar6;
          uVar7 = uVar7 - 0x60;
        }
        else {
          FUN_007852a0();
          uVar2 = *(undefined4 *)(uVar5 + 0x54);
          uVar1 = *(undefined4 *)(uVar5 + 0x50);
          uVar3 = *(undefined4 *)(uVar5 + 0x58);
          uVar4 = *(undefined4 *)(uVar5 + 0x5c);
          FUN_00788f50();
          *(undefined4 *)(uVar5 + 0x50) = *(undefined4 *)(local_c - 0x10);
          *(undefined4 *)(uVar5 + 0x54) = *(undefined4 *)(local_c - 0xc);
          *(undefined4 *)(uVar5 + 0x58) = *(undefined4 *)(local_c - 8);
          *(undefined4 *)(uVar5 + 0x5c) = *(undefined4 *)(local_c - 4);
          FUN_00788f50();
          *(undefined4 *)(local_c - 0x10) = uVar1;
          *(undefined4 *)(local_c - 0xc) = uVar2;
          *(undefined4 *)(local_c - 8) = uVar3;
          *(undefined4 *)(local_c - 4) = uVar4;
          uVar5 = uVar5 + 0x60;
          local_c = uVar6;
        }
      }
      goto joined_r0x0078945a;
    }
    if (*(int *)(uVar5 + 0x14) <= *(int *)(uVar7 + 0x14)) {
      if (*(int *)(uVar5 + 0x14) < *(int *)(uVar7 + 0x14)) goto LAB_0078948e;
      uVar8 = uVar8 + 0x60;
      FUN_0078afd0();
    }
    uVar5 = uVar5 + 0x60;
  } while( true );
}

