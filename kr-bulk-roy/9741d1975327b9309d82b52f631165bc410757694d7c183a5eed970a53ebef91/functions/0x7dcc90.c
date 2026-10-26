
void FUN_007dcc90(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint in_ECX;
  int *in_EDX;
  int iVar6;
  undefined4 *puVar7;
  int *unaff_FS_OFFSET;
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904790;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  if (in_ECX != 0) {
    iVar6 = in_EDX[1];
    iVar4 = iVar6 - *in_EDX >> 2;
    if (0x3fffffffU - iVar4 < in_ECX) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar2 = iVar4 + in_ECX;
    local_18 = in_EDX[2] - *in_EDX >> 2;
    if (local_18 < uVar2) {
      if (0x3fffffff - (local_18 >> 1) < local_18) {
        local_18 = 0;
      }
      else {
        local_18 = local_18 + (local_18 >> 1);
      }
      if (local_18 < uVar2) {
        local_18 = uVar2;
      }
      iVar5 = FUN_007d01e0();
      local_8 = 0;
      FUN_007b8830(iVar5 + ((int)param_1 - *in_EDX >> 2) * 4,param_1);
      FUN_00552ec0(*in_EDX,param_1);
      FUN_00552ec0(param_1,param_1);
      iVar6 = *in_EDX;
      iVar4 = in_EDX[1];
      if (iVar6 != 0) {
        FUN_0089120c(iVar6);
      }
      in_EDX[2] = iVar5 + local_18 * 4;
      in_EDX[1] = iVar5 + (in_ECX + (iVar4 - iVar6 >> 2)) * 4;
      *in_EDX = iVar5;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    if ((uint)(iVar6 - (int)param_1 >> 2) < in_ECX) {
      uVar3 = *param_2;
      FUN_00552ec0(param_1,param_1);
      local_8 = 2;
      FUN_007b8830(in_EDX[1],param_1);
      in_EDX[1] = in_EDX[1] + in_ECX * 4;
      puVar7 = (undefined4 *)(in_EDX[1] + in_ECX * -4);
      if (param_1 != puVar7) {
        do {
          *param_1 = uVar3;
          param_1 = param_1 + 1;
        } while (param_1 != puVar7);
        *unaff_FS_OFFSET = local_10;
        return;
      }
    }
    else {
      uVar3 = *param_2;
      puVar7 = (undefined4 *)(iVar6 + in_ECX * -4);
      iVar4 = FUN_00552ec0(puVar7,param_1);
      in_EDX[1] = iVar4;
      if (param_1 != puVar7) {
        iVar6 = iVar6 - (int)puVar7;
        do {
          puVar1 = puVar7 + -1;
          puVar7 = puVar7 + -1;
          *(undefined4 *)(iVar6 + (int)puVar7) = *puVar1;
        } while (param_1 != puVar7);
      }
      puVar7 = param_1;
      if (param_1 != param_1 + in_ECX) {
        do {
          *puVar7 = uVar3;
          puVar7 = puVar7 + 1;
        } while (puVar7 != param_1 + in_ECX);
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

