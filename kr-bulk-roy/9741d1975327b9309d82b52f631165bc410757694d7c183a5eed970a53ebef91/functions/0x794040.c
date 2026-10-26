
void FUN_00794040(void)

{
  float fVar1;
  int *in_EAX;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  uint in_ECX;
  bool bVar5;
  float10 fVar6;
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
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = (**(code **)(*in_EAX + 0x18))();
  local_14 = iVar2;
  if (iVar2 != 1) {
    if (in_ECX == 1) {
      fVar6 = (float10)FUN_00793920(0,1);
      local_c = (float)fVar6;
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c,1);
      pfVar4 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48,0);
      local_24 = *pfVar4 - *pfVar3;
      local_20 = pfVar4[1] - pfVar3[1];
      local_1c = pfVar4[2] - pfVar3[2];
      local_30 = local_24 / local_c;
      local_2c = local_20 / local_c;
      local_28 = local_1c / local_c;
      FUN_00794850(local_30,local_2c,local_28);
      bVar5 = iVar2 == 2;
    }
    else {
      fVar6 = (float10)FUN_00793920(in_ECX - 1,in_ECX);
      local_8 = (float)fVar6;
      fVar6 = (float10)FUN_00793920(in_ECX - 2,in_ECX - 1);
      local_c = (float)fVar6;
      if (local_8 == 0.0) {
        local_8 = 1.0;
      }
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      local_10 = local_c / (local_8 + local_c);
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48,in_ECX - 2);
      pfVar4 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c,in_ECX - 1);
      local_24 = *pfVar4 - *pfVar3;
      local_20 = pfVar4[1] - pfVar3[1];
      local_1c = pfVar4[2] - pfVar3[2];
      pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_48,in_ECX - 1);
      pfVar4 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_3c);
      fVar1 = (2.0 - local_10) / local_8;
      local_10 = (local_10 - 1.0) / local_c;
      local_30 = local_10 * local_24;
      local_2c = local_20 * local_10;
      local_28 = local_10 * local_1c;
      local_24 = local_30 + fVar1 * (*pfVar4 - *pfVar3);
      local_20 = local_2c + (pfVar4[1] - pfVar3[1]) * fVar1;
      local_1c = local_28 + fVar1 * (pfVar4[2] - pfVar3[2]);
      local_3c = -local_24;
      local_38 = -local_20;
      local_34 = -local_1c;
      FUN_00794850(local_3c,local_38,local_34);
      bVar5 = in_ECX == local_14 - 1U;
    }
    if (bVar5) {
      FUN_007948a0(0,0,0);
    }
    return;
  }
  iVar2 = in_EAX[6];
  local_24 = 0.0;
  local_20 = 0.0;
  local_1c = 0.0;
  if (in_ECX < (uint)((in_EAX[7] - iVar2) / 0x30)) {
    local_24 = 0.0;
    local_20 = 0.0;
    *(undefined4 *)(iVar2 + 0x18 + in_ECX * 0x30) = 0;
    local_1c = 0.0;
    *(undefined4 *)(iVar2 + 0x1c + in_ECX * 0x30) = 0;
    *(undefined4 *)(iVar2 + 0x20 + in_ECX * 0x30) = 0;
    iVar2 = in_EAX[6];
    if (in_ECX < (uint)((in_EAX[7] - iVar2) / 0x30)) {
      *(undefined4 *)(iVar2 + 0x24 + in_ECX * 0x30) = 0;
      *(undefined4 *)(iVar2 + 0x28 + in_ECX * 0x30) = 0;
      *(undefined4 *)(iVar2 + 0x2c + in_ECX * 0x30) = 0;
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid vector<T> subscript");
}

