
void FUN_005e0d90(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 auStack_a4 [20];
  undefined4 uStack_90;
  undefined2 *puStack_8c;
  undefined1 auStack_88 [16];
  undefined4 uStack_78;
  undefined *puStack_74;
  int iStack_70;
  undefined1 *puStack_6c;
  uint uStack_68;
  uint uStack_64;
  undefined1 auStack_54 [4];
  undefined1 *puStack_50;
  int local_4c;
  undefined *puStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  int iStack_3c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009435e8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  uStack_64 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    uStack_68 = 0x5e0ded;
    local_4c = in_ECX;
    iVar2 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar2 == 0xf4245) {
      iVar2 = param_1[1];
      puVar7 = *(undefined1 **)(iVar2 + 0x2d0);
      iVar6 = *(int *)(iVar2 + 0x20) + 1;
      puStack_50 = puVar7;
      iStack_3c = iVar6;
      if (*(int *)(iVar2 + 0x25c) == 0) {
        iStack_44 = 0;
      }
      else if (*(int *)(*(int *)(iVar2 + 0x25c) + 8) - 1U < 0x2b) {
        uStack_68 = 0x5e0e29;
        iStack_44 = FUN_00520f40();
      }
      else {
        iStack_44 = 0;
      }
      puStack_48 = *(undefined **)(in_ECX + 0x298);
      if (((0 < iStack_44) && (0 < *(int *)(in_ECX + 0x29c))) &&
         (*(int *)(in_ECX + 0x29c) == iStack_44)) {
        uStack_68 = 0x5e0e68;
        iVar2 = FUN_00404ba0();
        puStack_6c = puVar7;
        if ((puVar7 == (undefined1 *)0x1) && (*(int *)(iVar2 + 0x6920) != -0x16f8)) {
          uStack_68 = 0x5e0ec7;
          iVar2 = FUN_00508da0();
          if (iVar2 == 0) {
            iStack_70 = *(int *)(local_4c + 0x29c);
            puStack_74 = &DAT_00c25e2c;
            uStack_68 = iVar6;
          }
          else {
            uStack_68 = *(int *)(iVar2 + 0x14);
            puStack_6c = *(undefined1 **)(iVar2 + 0x10);
            iStack_70 = 0x5e0eee;
            FUN_00409560();
            iStack_70 = 0x5e0ef5;
            iVar6 = FUN_004dc700();
            if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != 0)) goto LAB_005e0ea0;
            uStack_68 = *(undefined4 *)(iVar2 + 4);
            puStack_6c = (undefined1 *)0x5e0f08;
            FUN_004034e0();
            puStack_6c = (undefined1 *)0x5e0f0f;
            iVar2 = FUN_00523230();
            puVar1 = puStack_48;
            if ((*(undefined **)(iVar2 + 4) == (undefined *)0x0) ||
               (*(undefined **)(iVar2 + 4) == puStack_48)) {
              uStack_68 = 0x5e0f40;
              iVar6 = FUN_00404ba0();
              if (puVar1 < (undefined *)0xa) {
                uVar3 = (int)puVar1 * 0x210 + *(int *)(iVar6 + 0x6924);
                uVar3 = -(uint)(*(int *)(uVar3 + 0x5c) != 0) & uVar3;
              }
              else {
                uVar3 = 0;
              }
              iVar6 = *(int *)(iVar2 + 0x78);
              iVar2 = *(int *)(iVar2 + 0x7c);
              puStack_40 = (undefined1 *)0x0;
              puStack_6c = (undefined1 *)0x5e0f77;
              uStack_68 = uVar3;
              iVar4 = FUN_004d3f80();
              if (iVar4 != 0) {
                puVar7 = puStack_40;
                if (uVar3 != 0) {
                  puVar7 = *(undefined1 **)(uVar3 + 8);
                }
                if ((iVar6 == 0) || (iVar6 <= (int)puVar7)) {
                  if ((iVar2 == 0) || ((int)puVar7 <= iVar2)) {
                    uStack_68 = 0x5e1077;
                    FUN_0040b3c0();
                    uStack_c = 2;
                    uStack_68 = 0x5e1084;
                    uStack_68 = FUN_0040b3f0();
                    puStack_6c = (undefined1 *)0x5e108c;
                    piVar5 = (int *)FUN_0080ab00();
                    if (piVar5 != (int *)0x0) {
                      uStack_68 = 0x5e1099;
                      (**(code **)(*piVar5 + 0x14))();
                    }
                    uStack_c = 0xffffffff;
                    uStack_68 = 0x5e10aa;
                    FUN_007cf450();
                    uStack_68 = 0x5e10af;
                    FUN_00414680();
                    uStack_68 = iStack_3c;
                    puStack_6c = puStack_50;
                    iStack_70 = iStack_44;
                    puStack_74 = puStack_48;
                    uStack_78 = 0x5e10c8;
                    FUN_004a3840();
                    uStack_68 = 0x5e10d1;
                    FUN_005e0c40();
                    goto LAB_005e0ea0;
                  }
                  uStack_68 = 0x5e1025;
                  FUN_004054c0();
                  uStack_68 = 0;
                  puStack_6c = (undefined1 *)0x0;
                  puStack_40 = auStack_88;
                  puStack_8c = &DAT_00bed1fc;
                  uStack_90 = 0x5e103c;
                  FUN_00402250();
                  puStack_50 = auStack_a4;
                  uVar8 = 0xf8;
                  uStack_c = 1;
                  FUN_005854b0(0xf8);
                  FUN_00585330(uVar8);
                }
                else {
                  uStack_68 = 0x5e0fb4;
                  FUN_004054c0();
                  uStack_68 = 0;
                  puStack_6c = (undefined1 *)0x0;
                  puStack_40 = auStack_88;
                  puStack_8c = &DAT_00bed1fc;
                  uStack_90 = 0x5e0fcb;
                  FUN_00402250();
                  puStack_50 = auStack_a4;
                  uVar8 = 0xf7;
                  uStack_c = 0;
                  FUN_005854b0(0xf7);
                  FUN_00585330(uVar8);
                }
                FUN_004068f0();
                uStack_c = 0xffffffff;
                FUN_0058b270(0xca);
                goto LAB_005e0ea0;
              }
              uStack_68 = iStack_3c;
              iStack_70 = *(int *)(local_4c + 0x29c);
              puStack_6c = puStack_50;
              puStack_74 = &DAT_00c25e8c;
            }
            else {
              iStack_70 = *(int *)(local_4c + 0x29c);
              uStack_68 = iStack_3c;
              puStack_74 = &DAT_00c25e58;
              puStack_6c = puVar7;
            }
          }
        }
        else {
          iStack_70 = *(int *)(in_ECX + 0x29c);
          puStack_74 = &DAT_00c25e00;
          uStack_68 = iVar6;
        }
        uStack_78 = 0x5e0e9b;
        FUN_006edb60();
      }
    }
  }
LAB_005e0ea0:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_54);
  return;
}

