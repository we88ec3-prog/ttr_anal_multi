
void FUN_00793d80(void)

{
  int *in_EAX;
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  uint in_ECX;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float fVar7;
  undefined1 local_48 [12];
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = (**(code **)(*in_EAX + 0x18))();
  if (iVar1 != 1) {
    if (in_ECX == iVar1 - 2U) {
      fVar6 = (float10)FUN_00793920(in_ECX,in_ECX + 1);
      local_c = (float)fVar6;
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c);
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48,in_ECX + 1);
      fVar7 = (*pfVar3 - *pfVar2) / local_c;
      fVar5 = (pfVar3[1] - pfVar2[1]) / local_c;
      fVar4 = (pfVar3[2] - pfVar2[2]) / local_c;
      local_30 = fVar7;
      local_2c = fVar5;
      local_28 = fVar4;
      local_24 = *pfVar3 - *pfVar2;
      local_20 = pfVar3[1] - pfVar2[1];
      local_1c = pfVar3[2] - pfVar2[2];
    }
    else {
      fVar6 = (float10)FUN_00793920(in_ECX,in_ECX + 1);
      local_c = (float)fVar6;
      fVar6 = (float10)FUN_00793920(in_ECX + 1,in_ECX + 2);
      local_8 = (float)fVar6;
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      if (local_8 == 0.0) {
        local_8 = 1.0;
      }
      local_10 = local_c / (local_8 + local_c);
      pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48);
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c,in_ECX + 1);
      local_24 = *pfVar3 - *pfVar2;
      local_20 = pfVar3[1] - pfVar2[1];
      local_1c = pfVar3[2] - pfVar2[2];
      pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48,in_ECX + 1);
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c,in_ECX + 2);
      local_34 = local_10 / local_8;
      local_3c = local_34 * (*pfVar3 - *pfVar2);
      local_38 = (pfVar3[1] - pfVar2[1]) * local_34;
      local_34 = local_34 * (pfVar3[2] - pfVar2[2]);
      local_10 = (local_10 + 1.0) / local_c;
      local_30 = local_10 * local_24;
      local_2c = local_20 * local_10;
      local_28 = local_10 * local_1c;
      fVar7 = local_30 - local_3c;
      fVar5 = local_2c - local_38;
      fVar4 = local_28 - local_34;
      local_24 = fVar7;
      local_20 = fVar5;
      local_1c = fVar4;
    }
    FUN_007948a0(fVar7,fVar5,fVar4);
    if (in_ECX == 0) {
      FUN_00794850(0,0,0);
    }
    return;
  }
  iVar1 = in_EAX[6];
  local_24 = 0.0;
  local_20 = 0.0;
  local_1c = 0.0;
  if (in_ECX < (uint)((in_EAX[7] - iVar1) / 0x30)) {
    local_24 = 0.0;
    local_20 = 0.0;
    *(undefined4 *)(iVar1 + 0x18 + in_ECX * 0x30) = 0;
    local_1c = 0.0;
    *(undefined4 *)(iVar1 + 0x1c + in_ECX * 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x20 + in_ECX * 0x30) = 0;
    iVar1 = in_EAX[6];
    if (in_ECX < (uint)((in_EAX[7] - iVar1) / 0x30)) {
      *(undefined4 *)(iVar1 + 0x24 + in_ECX * 0x30) = 0;
      *(undefined4 *)(iVar1 + 0x28 + in_ECX * 0x30) = 0;
      *(undefined4 *)(iVar1 + 0x2c + in_ECX * 0x30) = 0;
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid vector<T> subscript");
}

