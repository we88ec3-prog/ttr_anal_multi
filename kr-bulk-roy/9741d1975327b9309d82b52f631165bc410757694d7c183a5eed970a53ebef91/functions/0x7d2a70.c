
void FUN_007d2a70(int param_1)

{
  int *piVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  float *pfVar7;
  int in_ECX;
  int *piVar8;
  int iVar9;
  int in_EDX;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 local_7c [7];
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  uint local_40;
  int local_3c;
  float local_38;
  int local_34;
  uint local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914ab8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar9 = *(int *)(in_ECX + 0x18);
  local_40 = 0;
  local_3c = in_ECX;
  local_34 = in_EDX;
  local_14 = uVar4;
  if (*(int *)(in_ECX + 0x1c) - iVar9 >> 2 != 0) {
    do {
      piVar1 = *(int **)(iVar9 + local_40 * 4);
      if (param_1 == piVar1[10]) {
        piVar8 = piVar1 + 2;
        if (0xf < (uint)piVar1[7]) {
          piVar8 = (int *)*piVar8;
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        piVar5 = piVar8;
        do {
          iVar9 = *piVar5;
          piVar5 = (int *)((int)piVar5 + 1);
        } while ((char)iVar9 != '\0');
        FUN_00402a70(piVar8,(int)piVar5 - (int)((int)piVar8 + 1));
        local_8 = 0;
        local_38 = (float)FUN_007e8a00(local_30);
        if (local_38 == *(float *)(in_EDX + 4)) {
LAB_007d2b78:
          local_50 = *(float *)(in_EDX + 4);
          pfVar7 = &local_50;
        }
        else {
          uVar2 = *(uint *)((int)local_38 + 0x1c);
          uVar6 = local_20;
          if (uVar2 <= local_20) {
            uVar6 = uVar2;
          }
          uVar6 = FUN_00407e70(uVar6,uVar4);
          if (uVar6 == 0) {
            if (local_20 < uVar2) {
              uVar6 = 0xffffffff;
            }
            else {
              uVar6 = (uint)(local_20 != uVar2);
            }
          }
          in_EDX = local_34;
          if ((int)uVar6 < 0) goto LAB_007d2b78;
          pfVar7 = &local_38;
        }
        fVar3 = *pfVar7;
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        in_ECX = local_3c;
        if (fVar3 != *(float *)(in_EDX + 4)) {
          puVar10 = (undefined4 *)((int)fVar3 + 0x2c);
          puVar11 = local_7c;
          for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          local_38 = *(float *)(local_3c + 0x40);
          local_60 = local_38 * local_60;
          local_5c = local_5c * local_38;
          local_58 = local_38 * local_58;
          local_4c = local_60;
          local_48 = local_5c;
          local_44 = local_58;
          (**(code **)(*piVar1 + 0x1c))(local_7c);
          (**(code **)(*piVar1 + 0x28))();
          (**(code **)(*piVar1 + 0xc))(local_34);
          in_ECX = local_3c;
          in_EDX = local_34;
        }
      }
      iVar9 = *(int *)(in_ECX + 0x18);
      local_40 = local_40 + 1;
    } while (local_40 < (uint)(*(int *)(in_ECX + 0x1c) - iVar9 >> 2));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

