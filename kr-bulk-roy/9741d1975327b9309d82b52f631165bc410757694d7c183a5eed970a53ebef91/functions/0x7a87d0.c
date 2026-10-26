
void FUN_007a87d0(int param_1,float param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  undefined1 local_24 [12];
  undefined4 local_18;
  int local_14;
  float local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 0x2c))();
  if ((iVar6 != 0) && (*(int *)(param_1 + 0xb0) == 0)) {
    *(undefined4 *)(param_1 + 0xb0) = 1;
    fVar9 = (float10)(**(code **)(**(int **)(param_1 + 0xac) + 0xc))();
    fVar1 = (float)fVar9;
    *(float *)(param_1 + 0xb8) = fVar1;
    if (fVar1 < *(float *)(param_1 + 0xc0)) {
      *(float *)(param_1 + 0xc0) = fVar1;
      *(undefined4 *)(param_1 + 0xc4) = 0;
    }
    if (fVar1 < *(float *)(param_1 + 0xbc)) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
    FUN_007a6830(0);
    FUN_007a6830(param_3);
  }
  if ((*(int *)(param_1 + 0x11c) != 0) &&
     (iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 0x38))(), iVar6 == 0)) goto LAB_007a8df3;
  if ((*(int *)(param_1 + 0x124) != 0) || (10 < *(uint *)(param_1 + 0x140))) {
    (**(code **)(**(int **)(param_1 + 0xac) + 0x20))(*(undefined4 *)(param_1 + 0x1c),param_3);
  }
  if (*(int *)(param_1 + 0x108) != 0) {
    fVar9 = (float10)(**(code **)(*(int *)(param_1 + 4) + 0x10))();
    iVar6 = *(int *)(param_1 + 0x108);
    *(float *)(iVar6 + 0x3c) = (float)fVar9;
    *(undefined4 *)(iVar6 + 0x70) = 1;
    puVar7 = (undefined4 *)(**(code **)(*(int *)(param_1 + 4) + 8))(&local_18);
    iVar6 = *(int *)(param_1 + 0x108);
    *(undefined4 *)(iVar6 + 0x28) = *puVar7;
    *(undefined4 *)(iVar6 + 0x2c) = puVar7[1];
    *(undefined4 *)(iVar6 + 0x30) = puVar7[2];
    *(undefined4 *)(iVar6 + 0x70) = 1;
    FUN_007bd8d0(*(float *)(param_1 + 0x104) * param_2);
    FUN_007bdf00(*(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c));
  }
  iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 4))();
  if (iVar6 == 0) {
    fVar9 = (float10)(**(code **)(**(int **)(param_1 + 0xac) + 0x10))();
    fVar1 = (float)((float10)*(float *)(param_1 + 0x104) * (float10)param_2 * fVar9);
    fVar2 = *(float *)(param_1 + 0xb4);
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0xe8) = 1;
    if (*(int *)(param_1 + 0xcc) == 0) {
      local_10 = *(float *)(param_1 + 0xe0) / 10.0;
      *(float *)(param_1 + 0xe0) = *(float *)(param_1 + 0xe0) - local_10;
      *(float *)(param_1 + 0xb4) =
           (local_10 + fVar1) * *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0xb4);
    }
    else {
      fVar5 = fVar1 + *(float *)(param_1 + 0xdc);
      iVar8 = *(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xd0) * 6;
      *(float *)(param_1 + 0xdc) = fVar5;
      fVar3 = (float)(&DAT_00fbab8c)[iVar8];
      *(float *)(param_1 + 0xe0) =
           fVar1 * (float)(&DAT_00fbab8c)[iVar8] + *(float *)(param_1 + 0xe0);
      *(float *)(param_1 + 0xb4) =
           *(float *)(param_1 + 0xb4) + *(float *)(param_1 + 0xe4) * (1.0 - fVar3) * fVar1;
      if (*(float *)(param_1 + 0xd8) < fVar5 != (*(float *)(param_1 + 0xd8) == fVar5)) {
        *(undefined4 *)(param_1 + 0xcc) = 0;
      }
    }
    if (((*(int *)(param_1 + 0xc4) != 0) && (fVar2 < *(float *)(param_1 + 0xc0))) &&
       ((*(float *)(param_1 + 0xb4) < *(float *)(param_1 + 0xc0) !=
         (*(float *)(param_1 + 0xb4) == *(float *)(param_1 + 0xc0)) &&
        (iVar8 = FUN_0089289d(), *(int *)(param_1 + 0xc4) < iVar8)))) {
      iVar6 = 1;
    }
    if (*(float *)(param_1 + 0xb4) <= *(float *)(param_1 + 0xb8)) {
      if (*(float *)(param_1 + 0xb4) < 0.0) {
        iVar6 = 1;
        goto LAB_007a8aca;
      }
      if (iVar6 != 0) goto LAB_007a8aca;
    }
    else {
      iVar6 = 1;
LAB_007a8aca:
      if (*(int *)(param_1 + 200) == 0) {
        *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb8);
      }
      else {
LAB_007a8c91:
        *(undefined4 *)(param_1 + 0xcc) = 0;
        *(undefined4 *)(param_1 + 0xe0) = 0;
        *(undefined4 *)(param_1 + 0xd8) = 0;
        *(undefined4 *)(param_1 + 0xdc) = 0;
        *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xbc);
      }
    }
LAB_007a8cc9:
    *(int *)(param_1 + 0x11c) = iVar6;
  }
  else {
    iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 4))();
    if (iVar6 == 1) {
      piVar4 = *(int **)(param_1 + 0xac);
      iVar6 = (**(code **)(*piVar4 + 0x40))();
      if (*(int *)(iVar6 + 0xa8) != *(int *)(iVar6 + 0xac)) {
        fVar9 = (float10)(**(code **)(*piVar4 + 0x10))();
        fVar1 = (float)((float10)*(float *)(param_1 + 0x104) * (float10)param_2 * fVar9);
        fVar2 = *(float *)(param_1 + 0xb4);
        iVar6 = 0;
        *(undefined4 *)(param_1 + 0xe8) = 1;
        if (*(int *)(param_1 + 0xcc) == 0) {
          local_10 = *(float *)(param_1 + 0xe0) / 10.0;
          *(float *)(param_1 + 0xe0) = *(float *)(param_1 + 0xe0) - local_10;
          *(float *)(param_1 + 0xb4) =
               (local_10 + fVar1) * *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0xb4);
        }
        else {
          fVar3 = fVar1 + *(float *)(param_1 + 0xdc);
          iVar8 = *(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xd0) * 6;
          *(float *)(param_1 + 0xdc) = fVar3;
          local_10 = 1.0 - (float)(&DAT_00fbab8c)[iVar8];
          *(float *)(param_1 + 0xe0) =
               (float)(&DAT_00fbab8c)[iVar8] * fVar1 + *(float *)(param_1 + 0xe0);
          *(float *)(param_1 + 0xb4) =
               *(float *)(param_1 + 0xb4) + *(float *)(param_1 + 0xe4) * local_10 * fVar1;
          if (*(float *)(param_1 + 0xd8) < fVar3 != (*(float *)(param_1 + 0xd8) == fVar3)) {
            *(undefined4 *)(param_1 + 0xcc) = 0;
          }
        }
        if ((((*(int *)(param_1 + 0xc4) != 0) && (fVar2 < *(float *)(param_1 + 0xc0))) &&
            (*(float *)(param_1 + 0xb4) < *(float *)(param_1 + 0xc0) !=
             (*(float *)(param_1 + 0xb4) == *(float *)(param_1 + 0xc0)))) &&
           (iVar8 = FUN_0089289d(), *(int *)(param_1 + 0xc4) < iVar8)) {
          iVar6 = 1;
        }
        if (*(float *)(param_1 + 0xb4) <= *(float *)(param_1 + 0xb8)) {
          if (0.0 <= *(float *)(param_1 + 0xb4)) {
            if (iVar6 == 0) goto LAB_007a8cc9;
          }
          else {
            iVar6 = 1;
          }
        }
        else {
          iVar6 = 1;
        }
        if (*(int *)(param_1 + 200) == 0) {
          *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb8);
          goto LAB_007a8cc9;
        }
        goto LAB_007a8c91;
      }
    }
  }
  if (*(int *)(param_1 + 0x11c) != 0) {
    iVar6 = **(int **)(param_1 + 0xac);
    fVar9 = (float10)(**(code **)(iVar6 + 0xc))();
    (**(code **)(iVar6 + 0x20))(*(undefined4 *)(param_1 + 0x1c),(float)fVar9);
    iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 0x38))();
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x108);
      if (iVar6 != 0) {
        if (*(int *)(iVar6 + 0x6c) != 0) {
          FUN_007be5f0();
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
        local_10 = *(float *)(param_1 + 0x120);
        local_14 = iVar6;
        FUN_0075a6f0(param_1 + 0x10c);
        *(undefined4 *)(param_1 + 0x108) = 0;
        *(undefined4 *)(param_1 + 0x120) = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x108) != 0) {
        FUN_007be5b0();
      }
      if ((*(int *)(param_1 + 0x120) != 0) &&
         (iVar6 = (**(code **)(**(int **)(param_1 + 0xac) + 0x1c))(), iVar6 == 0)) {
        iVar6 = FUN_007a7b30(&local_18,0);
        if (iVar6 == 0) {
          puVar7 = (undefined4 *)(**(code **)(*(int *)(param_1 + 4) + 8))(local_24);
          local_18 = *puVar7;
          local_14 = puVar7[1];
          local_10 = (float)puVar7[2];
        }
        (**(code **)(**(int **)(param_1 + 0x120) + 0xc))(&local_18);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_007a8df3:
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

